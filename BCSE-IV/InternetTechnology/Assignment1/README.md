
Internet Technology Lab : Assignment 1 Report
---
Name: *Rohit Rajat Chattopadhyay*  
Roll: *001710501073*  
Date: *12th October, 2020*  
Batch: *A3*  

## Problem Statement
Implement a TCP-based key-value store. The server implements the key-value store and clients make use of it. The server must accept clients’ connections and serve their requests for ‘get’ and ‘put’ key value pairs. All key-value pairs should be stored by the server only in memory. Keys and values are strings. The client accepts a variable no of command line arguments where the first argument is the server hostname followed by port no. It should be followed by any sequence of `get <key>` and/or `put <key> <value>`.
```sh
./client 192.168.124.5 5555 put city Kolkata put country India get country get city get Institute
India
Kolkata
<blank>
```
The server should be running on a TCP port. The server should support multiple clients and maintain their key-value stores separately. Implement authorization so that only few clients having the role **manager** can access other’s key-value stores. A user is assigned the **guest** role by default. The server can upgrade a **guest** user to a **manager** user.

## Solution Approach
For this assignment the implementation follows Transmission Control Protocol as shown in the flowchart.
![](https://i.imgur.com/nTFHdFw.png)

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

Following instructions are supported:
* `PUT <key> <value>` : To insert/update the key-value pair to database, update can be done by owner and `Manager`
* `GET <key>` : To read the value in database using key, `READ` access with owner and `Manager`s
* `PROMOTE` : To promote a Client from `Guest` to `Manager`  
  Password: **123456**

#### How to Run
1. Start server , HOST IP and PORT  will be shown in terminal  
    `python3 server.py <PORT>`
2. In another terminal start the client  
    `python3 client.py <HOST_IP> <HOST_PORT> <INSTRUCTIONS>`

## Salient Features
1. Command Line Interface with arguments
2. User identification is done using session tokens
3. Manager authentication done using password
4. Data is stored in JSON files which is restored restored when server is restarted
5. Supports Multi Clients
6. Simultaneously multiple servers can be run at seperate ports
7. Seperate namespace for each client at each server.

## Sample I/O

1. **Server Startup**  
    ![](https://i.imgur.com/zkHALrB.png)  
    Started server in `127.0.0.1:8000`
    
2. **New Guest Client Connection**  
    ![](https://i.imgur.com/Ypm6DzV.png)  
    Setting following keys
    * `city`: Kolkata
    * `country`: India  
    Get `Institute` failed as the key was not set

3. **Access Restriction for Other Guest**  
    ![](https://i.imgur.com/UUN4Kqb.png)  
    New Guest sets Mumbai for key `city`.    
    On performing Get for key `country` **Key doesn't exists** is returned as country is not set in the namespace for this client.  
    Get `city` returns Mumbai.
    
4. **Manager Access**  
    ![](https://i.imgur.com/fi9LS03.png)  
    As **Guest** the new user sets "Delhi" for key `city` and attempts to Get `country` which fails.  
    Using `promote` instruction the user is promoted to **Manager** using the password.  
    As *Manager* the user Gets `country` and `city` which returns values of all the users. 
    
5. **Failed Manager `promote` Attempt**  
    ![](https://i.imgur.com/0Bz7z8p.png)  
    On entering wrong password, suitable message is returned. 
    The requested keys are not found in the namespace of the user.
