/*

There are two most common ways of exchanging data in computer networks, namely TCP and UDP. The first of them underlies the familiar HTTP for example, i.e. the most of WWW functions with its help. Let's have a closer look.

With both protocols one side, the server is working continuously, listening for incoming requests. The other side, client (usually, many clients) may start and stop at random, sending to or requesting from server whenever they want. Addressing requires server address and port number. In this way, many servers may run on the same address but on different ports. Most popular usage for it is seen when some website (like this one) could be accessed via plain HTTP (on port 80) or via encrypted HTTPS (on port 443).

So to start the server we only specify the port to listen on. Actually some auxiliary settings could be specified, for example it is possible to limit from which addresses we accept requests. But in simple cases it is all right to accept from any address.

When client wants to exchang with the server, it should specify both address and port. And next comes the difference between UDP and TCP:

With UDP we don't establish connection beforehand, just throw data packet into the network (specifying target address and port for every packet) - we do not check whether this packet reach destination and there are no guarantee in which order several packets may reach it - and we don't expect response.

On contrary TCP firstly wants us to connect to the server (at this initial phase we specify address and port) - and then we can send and recieve packets over this established connection - so the protocol takes care of the order and consistency of packets.

Here is a live example (actually coming from one industrial project I worked for in the past). There is a LoRaWAN server which collects data sent by various sensor and devices through gateways. These gateways are small things similar to WiFi router - they get wireless data from the sensor (in LoRa protocol) and then retransmit them over conventional internet in form of UDP packets.

Why UDP is chosen here? because neither sensor nor gateway really cares whether data were received or not. They could be lost even in the air, before reaching the gateway - thus no sense in any further checks. And anyway, if (hypothetically) device or gateway is able to figure out when packet is lost -what should it do? No, there is no any obvious logic to follow. Thus UDP being much more lightweight protocol, suits ideally.

However, data are somehow collected/aggregated by the server and now we want to work with them - this is done by user requests sent over TCP (and actually in HTTP or GRPC form).

In the program code both sending and receiving interface is called socket - we say that we open server socket at the given port to listen - and on the other side we create client socket to send / connect to server.

The problem
Write a server code which listens both for UDP and TCP. When UDP packet comes, it is simply expected to contain integer value - you need keep total count of such packets - and sum of values in them.

Meanwhile TCP socked could be used by client to send request of any of 3 types:

sending word count wants the server to respond with total count of values received "from sensors" (i.e. via the UDP socket) - response should come in the form CNT=5.
sending word sum wants the server to report total of values in the same manner - response should be in the form SUM=99.
sending word stop wants the server to stop, expected response is EXIT=OK.
The numbers of ports to be opened for listening are passed via environment variables named TCP_PORT and UDP_PORT respectively.

For example, suppose that server has just started and the following exchanges happen:

we send a word count to TCP socket and receive CNT=0 as response
we send a word sum to TCP socket and receive SUM=0 as response
we send 123 to UDP socket
we send 601 to UDP socket
after this sending sum to TCP socket is answered with SUM=724
while sending count gets CNT=2 in response
we send stop to TCP socket and server responds EXIT=OK and stops (all further requests are not handled)
How to start with it
While it is not the only way, but you may look at socketserver package of python standard library. Scroll the page down to "Example" of TCP server - here we get it in slightly shortened form:

import socketserver

class MyHandler(socketserver.BaseRequestHandler):
    def handle(self):
        data = self.request.recv(1024).strip()
        print('Got request with: ' + str(data, 'ascii'))
        self.request.sendall(data.upper())

server = socketserver.TCPServer(('localhost', 9999), MyHandler)
server.serve_forever()
Start this program, it will print nothing yet - it just waits for requests. Go to the other console window and send something using telnet program (which is usually installed by default in linux and OsX, but could be disabled in windows - google about enabling it or download handy putty program instead).

telnet localhost 9999
Generally "localhost" is defined somewhere to be substitued with address 127.0.0.1 which means "this same machine". Thus the following interchange may occur:

Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
hello world                                     <-- only this line is typed in by user
HELLO WORLDConnection closed by foreign host.
Meanwhile you'll see Got request with: hello world in the window where server is running. You can connect with telnet multiple times.

Now you only need to improve this program:

it shouldn't run "forever", there should be way to stop it
it should listen to UDP at the same time, and count incoming values
it should be able to serve concurrent requests (try connecting with two telnets and investigate how the example above behaves)
When you submit your code, it is checked by really creating several requests to it so you'll see various verdicts depending on how well your server behaves. Keep in mind that checking system couldn't usually tell what exactly causes the specific error as it only "sees" it from client side.

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"net"
	"os"
	"strconv"
	"strings"
	"sync/atomic"
)

type Server struct {
	tcpaddr string
	udpaddr string
	count   uint64
	sum     int64
	done    chan bool
}

var flags struct {
	tcpport string
	udpport string
}

func main() {
	parseflags()

	server := NewServer(flags.tcpport, flags.udpport)
	server.Run()
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	flags.tcpport = os.Getenv("TCP_PORT")
	flags.udpport = os.Getenv("UDP_PORT")
	if flags.tcpport == "" {
		flags.tcpport = "9999"
	}
	if flags.udpport == "" {
		flags.udpport = "9999"
	}

	flag.StringVar(&flags.tcpport, "tcpport", flags.tcpport, "specify TCP port")
	flag.StringVar(&flags.udpport, "udpport", flags.udpport, "specify UDP port")
	flag.Parse()
}

func NewServer(tcpport, udpport string) *Server {
	return &Server{
		tcpaddr: fmt.Sprintf(":%s", tcpport),
		udpaddr: fmt.Sprintf(":%s", udpport),
		done:    make(chan bool),
	}
}

func (s *Server) Run() {
	log.Println("Serving...")
	go s.serveUDP()
	go s.serveTCP()
	<-s.done
}

func (s *Server) serveUDP() {
	addr, err := net.ResolveUDPAddr("udp", s.udpaddr)
	check(err)

	conn, err := net.ListenUDP("udp", addr)
	check(err)
	defer conn.Close()

	var data [128]byte
	for {
		size, addr, err := conn.ReadFromUDP(data[:])
		check(err)

		atomic.AddUint64(&s.count, 1)

		line := strings.TrimSpace(string(data[:size]))
		log.Printf("udp: %v %q\n", addr, line)

		value, err := strconv.ParseInt(line, 0, 64)
		if err != nil {
			log.Println(err)
			continue
		}
		atomic.AddInt64(&s.sum, value)
	}
}

func (s *Server) serveTCP() {
	addr, err := net.ResolveTCPAddr("tcp", s.tcpaddr)
	check(err)

	ln, err := net.ListenTCP("tcp", addr)
	check(err)

	for {
		conn, err := ln.AcceptTCP()
		check(err)
		go s.handleTCP(conn)
	}
}

func (s *Server) handleTCP(conn net.Conn) {
	defer conn.Close()

	scanner := bufio.NewScanner(conn)
	for scanner.Scan() {
		line := strings.TrimSpace(scanner.Text())
		log.Printf("tcp: %v: %q\n", conn.RemoteAddr(), line)
		switch line {
		case "count":
			count := atomic.LoadUint64(&s.count)
			fmt.Fprintf(conn, "CNT=%d\n", count)
		case "sum":
			sum := atomic.LoadInt64(&s.sum)
			fmt.Fprintf(conn, "SUM=%d\n", sum)
		case "stop":
			fmt.Fprintf(conn, "EXIT=OK\n")
			s.done <- true
			return
		}
	}
}
