CPP=g++
CPPFLAGS=-Wall -Wextra -pedantic

PROTOC=protoc

BIN=database

all:
	$(PROTOC) --cpp_out=. database.proto
	$(CPP) $(CPPFLAGS) -o $(BIN) *.cc -lprotobuf

clean:
	rm -f $(BIN) database.pb.*
