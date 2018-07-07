# QuarkChat

Quark Chat is a multi-user chat system that can be used within teams for shared communication. The Server requires a port number to initiate socket connection. 

![alt text](https://lh4.googleusercontent.com/FDPquImggxeG477_k9IDRuakEFfsAO7_QykUVeetCt1k8_m0PVsac36LAi7l0WEGJ-bQJ1bgGZNTEUTwsHjL=w1440-h706) 

The client can enter a username, IP address and the port number to connect to the Server and start data transfer. 
I incorporated multithreading to let multiple clients connect to the server and talk at the same time. Both Server and the client were built on Visual Studio C++ with Microsoft Foundation Classes (MFC). 

![alt text](https://lh3.googleusercontent.com/UHeq7ALKqsaDuqLRNotkuYOqu163PlFGFxBP4N0sgXsvmikrJ5tmIGobZ0hCQ3OkWLzeXHFpB95wfxHU--zD=w1440-h706) 

![alt text](https://lh4.googleusercontent.com/cwR2-Wd79DJI1se2bu_uDsiTKui6UQauEfh0ZCiJUm6EUFNSoGwpk4RVT_Z7aBMWbexL2SS7MX3cic4bdM9o=w1440-h706) 

TIP: To make message transfer between two clients exclusive, I recommend passing a Structure of SOCKET and IP address in the message pump of thread in the Server side, instead of just passing the SOCKET. In the child thread, match the IP addresses before sending out the message to clients. 
