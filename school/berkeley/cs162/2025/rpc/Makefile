CFLAGS=-I/usr/include/tirpc
LIBS=-ltirpc

all: rpc client server

rpc: kv_store.x
	rpcgen kv_store.x

server.c client.c: kv_store.h

client: client.o kv_store_clnt.o
	cc $(CFLAGS) -o client client.o kv_store_clnt.o $(LIBS)

server: server.o kv_store_svc.o
	cc $(CFLAGS) -o server server.o kv_store_svc.o $(LIBS)

.PHONY: clean

clean:
	-rm -f *.o
	-rm -f client server
	-rm -f kv_store_*.c kv_store*.h
