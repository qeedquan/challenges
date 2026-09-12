#!/bin/sh

cat << EOF >/dev/null

Write a program, that sends its own source code over network.
Network example is TCP/UDP or web socket. Ethernet, Bluetooth, Wi-Fi and internet over USB are allowed.

No need to write receiver program. You can use any encoding protocol, but decoder will be realizable.

Rules
Network is not a stdout, screen, USB, UART, GPIO or same.
The program must be at least 1 byte long.
No input or accessing source from file system.
No extra software to send stdout to network like ssh.
This is code-golf, shortest code wins.

EOF

socat -v tcp-l:1234,fork exec:"/bin/cat $0"
