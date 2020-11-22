import json
import logging as log
import os
import socket
import sys

log.getLogger().setLevel(log.INFO)


class Server:

    def __init__(self, host='127.0.0.1', port=8000):
        self.in_memory_db = {}
        self.password = "123456"
        self.managers = set()
        self.token_counter = 0
        self.port = port

        self.socket = socket.socket()
        self.socket.bind((host, port))
        self.socket.listen(5)
        log.info(f"Server started on host {host} port {port}")

    def _recv_req(self, connection):
        data = ""
        while True:
            buffer = connection.recv(16)
            if buffer:
                data += buffer.decode('utf-8')
                if data[-2:] == '}$':
                    break

        return json.loads(data[:-1])

    def _send_res(self, connection, data="", token=None, status=200):
        log.info(f"{status}\t{token}\t{data}")
        log.debug(self.in_memory_db)
        payload = {
            "status": int(status),
            "body": data
        }
        if token:
            payload["token"] = token
        response = (json.dumps(payload)+'$').encode('utf-8')
        connection.sendall(response)

    def start(self):
        try:
            db_file = f"db:{self.port}"
            try:
                with open(db_file, "r") as f:
                    backup = json.load(f)
                    self.in_memory_db = backup["db"]
                    self.managers = set(backup["access"])
                    del backup
            except:
                pass
            while True:
                connection, client_address = self.socket.accept()
                connection.setblocking(1)
                log.info(f'Connection established with {client_address}')
                self.handle_connection(connection)
        except KeyboardInterrupt:
            log.warning("Stopping Server")
            with open(db_file, "w") as f:
                f.write(json.dumps({
                    "db": self.in_memory_db,
                    "access": list(self.managers)
                }))
            del self

    def handle_connection(self, connection):
        try:
            req = self._recv_req(connection)
            log.debug(f"Received request: {req}")

            if req["method"] == "GET":
                try:
                    self._send_res(connection, self.get(
                        req["query"], req["token"]))
                except IOError as e:
                    self._send_res(
                        connection, "GET Error: {}".format(e), status=400)
                except ReferenceError as e:
                    self._send_res(
                        connection, "New Client created",  str(e), status=401)

            elif req["method"] == "PUT":
                self._send_res(connection, "Success",  token=self.put(
                    req["key"], req["value"], req["token"]), status=201)

            elif req["method"] == "PROMOTE":
                token = req.get("token", "")
                if token == "":
                    self.token_counter += 1
                    token = str(self.token_counter)
                if req["pswd"] == self.password:
                    self.managers.add(token)
                    self._send_res(connection, "Promoted", token, 203)
                else:
                    self._send_res(connection, "Unauthorized", token, 403)

            else:
                log.error('Invalid Request type')
                raise IOError('Request type must be GET/PUT or PROMOTE')
        except Exception as e:
            self._send_res(connection, "Bad Request: {}".format(e), status=501)
        finally:
            connection.close()

    def get(self, key, token):
        if token == "":
            self.token_counter += 1
            raise ReferenceError(str(self.token_counter))
        if key in self.in_memory_db:
            if token in self.managers:
                return json.dumps(self.in_memory_db[key])
            elif token in self.in_memory_db[key]:
                return self.in_memory_db[key][token]
            else:
                log.error('Unauthorized Access')
                raise IOError("Key doesn't exists")
        else:
            log.error('KEY not found')
            raise IOError("Key doesn't exists")

    def put(self, key, value, token):
        if token == "":
            self.token_counter += 1
            token = str(self.token_counter)
        if key in self.in_memory_db:
            self.in_memory_db[key][token] = value
        else:
            self.in_memory_db[key] = {
                token: value
            }
        return token


def main():
    port = int(sys.argv[1])
    Server(port=port).start()


if __name__ == '__main__':
    main()
