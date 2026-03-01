#!/usr/bin/perl -w

=begin comment

Write a pair of programs that communicate with one another through socket connections. AKA a client-server connection.

Your server should be an echo server that simply echoes any information it receives back to the client.

For bonus points, your server should take a special command that will echo the subsequent information in reverse.

=end comment
=cut

use strict;
use IO::Socket; 

my $socket = IO::Socket::INET->new(
	Listen => 128,
	LocalAddr=>'localhost',
	LocalPort => 24601,
	Proto => 'tcp'
); 

while (my $client = $socket->accept) {
	while ($_ = <$client>) {
		s/^rev(.*)\n/\n$1/ 
		? print reverse split //, $_ 
		: print;
	}
}
