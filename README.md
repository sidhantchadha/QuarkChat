# QuarkChat

Quark Chat is a multi-user chat system that can be used within teams for shared communication. The Server requires a port number to initiate socket connection. 

![alt text](https://image.ibb.co/bHJY48/Server.png) 

The client can enter a username, IP address and the port number to connect to the Server and start data transfer. 
I incorporated multithreading to let multiple clients connect to the server and talk at the same time. Both Server and the client were built on Visual Studio C++ with Microsoft Foundation Classes (MFC). 

![alt text](https://image.ibb.co/cAY0j8/Client1.png) 

![alt text](https://image.ibb.co/cAnhxT/Client2.png) 

TIP: To make message transfer between two clients exclusive, I recommend passing a Structure of SOCKET and IP address in the message pump of thread in the Server side, instead of just passing the SOCKET. In the child thread, match the IP addresses before sending out the message to clients. 

