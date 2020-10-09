Assignment 1
---

### Problem
Implement a TCP-based key-value store. The server implements the key-value store and clients make use of it. The server must accept clients’ connections and serve their requests for ‘get’ and ‘put’ key value pairs. All key-value pairs should be stored by the server only in memory. Keys and values are strings. The client accepts a variable no of command line arguments where the first argument is the server hostname followed by port no. It should be followed by any sequence of `get <key>` and/or `put <key> <value>`.
```
./client 192.168.124.5 5555 put city Kolkata put country India get country get city get Institute
India
Kolkata
<blank>
```
The server should be running on a TCP port. The server should support multiple clients and maintain their key-value stores separately. Implement authorization so that only few clients having the role **manager** can access other’s key-value stores. A user is assigned the **guest** role by default. The server can upgrade a **guest** user to a **manager** user.

### Implementation
The program is developed using socket programing in Python
1. When a new Client is detected by server, the Client is provided with a token which will be stored by Client and will be used in all future interactions
2. The in memory database maintains a Key-Value map as below.
```
 <key> : {
     <token> : <value>
        .
        .
 }
```
3. An Array is maintained with the tokens of Clients who have **Manager** access.
4. Manager password is `123456`

### How to Run
1. Start server , HOST IP and PORT  will be shown in terminal  
    `python3 server.py`
2. In another terminal start the client  
    `python3 client.py <HOST_IP> <HOST_PORT> <INSTRUCTIONS>`