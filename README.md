# cwebserver: Minimalist web-server
*cwebserver* is a minimalist web-server implemented in C. It is just intended
as a basic to understand the basics of the underlying socket, that can be
easily extended to build an HTTP server, to include some logic in the
processing of the incoming messages, to introduce concurrency in the processing
of incoming connections etc.

# Code structure
- *server.c* and *client.c* implement the web-server resp. -client.
- *common.h* defines imports for both the server and the client + configuration
  (type, protocol, port...) of their
  [socket](https://man7.org/linux/man-pages/man7/socket.7.html) and [address](https://man7.org/linux/man-pages/man7/ip.7.html) in order to ensure 
  consistency between them
- *print_error.c* has just a function `print_error()` printing out the message
  corresponding to [errno](https://man7.org/linux/man-pages/man3/errno.3.html).
