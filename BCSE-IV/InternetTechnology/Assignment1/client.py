import getpass
import json
import socket
import sys


class Client:
    def __init__(self, host='127.0.0.1', port=8000):
        self.host = host
        self.port = port
        self.token = ""
        return

    def _receive_request(self, connection):
        data = ""
        while True:
            buffer = connection.recv(16)
            if buffer:
                data += buffer.decode('utf-8')
                if data[-2:] == '}$':
                    break

        return json.loads(data[:-1])

    def terminate(self):
        print(f"Terminating Client listening to {self.host}:{self.port}")
        del self

    def handle_response(self, resp):
        code = resp["status"]
        if code == 200:
            print(resp["body"])
        elif code == 201:
            pass
        elif code == 203:
            print("User promoted to Manager")
        elif code == 204:
            print("GET Error: New User, token generated")
        elif code == 501:
            print("Internal Error:", resp["body"])
        else:
            print(code, resp["body"])

    def send_request(self, message):
        sock = socket.socket()
        sock.connect((self.host, self.port))
        message["token"] = self.token
        try:
            message = (json.dumps(message)+'$').encode('utf-8')
            sock.sendall(message)
            response = self._receive_request(sock)
            if "token" in response:
                self.token = response["token"]
            self.handle_response(response)
        finally:
            sock.close()


def main(tokens_arr, host, port):
    client = Client(host, port)
    try:
        for tokens in tokens_arr:
            if tokens[0] == 'GET':
                client.send_request({
                    "method": 'GET',
                    "query": tokens[1]
                })
            elif tokens[0] == 'PUT':
                client.send_request({
                    "method": 'PUT',
                    "key": tokens[1],
                    "value": tokens[2]
                })
            elif tokens[0] == 'PROMOTE':
                password = getpass.getpass(prompt="> Enter password : ")
                client.send_request({
                    "method": 'PROMOTE',
                    "pswd": password
                })

    except KeyboardInterrupt:
        client.terminate()


def tokenizer(arr):
    tokens = []
    idx = 0
    while idx < len(arr):
        elem = arr[idx].upper()
        token = []
        if elem == "GET":
            token = ["GET", arr[idx+1]]
            idx += 1
        elif elem == "PUT":
            token = ["PUT", arr[idx+1], arr[idx+2]]
            idx += 2
        elif elem == "PROMOTE":
            token = ["PROMOTE"]

        tokens.append(token)
        idx += 1
    return tokens


if __name__ == '__main__':
    args = sys.argv
    if len(args) < 3:
        print('Please run the program as below')
        print('python3 client.py <HOST_IP> <HOST_PORT> <INSTRUCTIONS>')
    else:
        host = args[1]
        port = int(args[2])    
        main(tokenizer(args[3:]), host, port)
