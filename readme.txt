1. Intro



There are four code files in the folder: client_A.c server_A.c client_B.c server_B.c
For client_A.c and server_A.c, they are solutions for problem Part A. And for client_B.c
and server_B.c, they are solutions for problem Part B. File names show whether it is client
or server.



2. Steps



Part A:



(a)First, makefile helps to compile four codes. So just input "make" first, then you could see
codes are compiled successfully. 

(b)Then, set up connection. Input "./server_A", server is waiting for client. And input "./client_A 127.0.0.1"
to connect with server. (Here I set 8000 as default port, so you don't need to input port number)
(c)You can input strings from client to get echo response from server. For example, input "apple" from client, 
then you could see "apple" received from server and then response to client "apple". Then connection ends.

(d)If you want to send another message to server, please reconnect with "./client_A 127.0.0.1".



Part B:


(a)Makefile helps to compile four codes. So just input "make" first, then you could see
codes are compiled successfully. 

(b)Then, set up connection. Input "./server_B", server is waiting for client. And input "./client_B 127.0.0.1"
to connect with server. (Here I set 8000 as default port, so you don't need to input port number)
(c)If client sends "hello" (no matter the case), the server would get it and response with "Welcome!".

(d)You can also input strings from client to get echo response from server. For example, input "apple" from client, 
then you could see "apple" received from server and then response to client "apple". Then connection ends.

(e)If you want to send another message to server, please reconnect with "./client_B 127.0.0.1".



3. Memo


If the port is occupied, please use the command to release:
netstat -ano | grep 8000
