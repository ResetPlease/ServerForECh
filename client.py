#!/usr/bin/env python
# -*- coding: utf-8 -*-
import socket
sock = socket.socket()
sock.connect(("130.193.36.74", 8000))
sock.send("hello, world!".encode())
data = sock.recv(1024)
sock.close()
print(data.decode())