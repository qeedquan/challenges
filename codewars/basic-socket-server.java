/*

Create a tcp socket that listens on port 80 on local host,

When a user connects to the socket, the following should happen:

- If the user sends a string containing only the word "exit", the socket and connection should close
  and the function should end.
- For any other string the user sends, the server should send a copy of the string back to the user.

you can assume short strings all ending in "\n" other than "exit"

*/

import java.net.ServerSocket;

class Server {
	public static void main(String[] args) {
		try (ServerSocket server = new ServerSocket(1111)) {
			var socket = server.accept();
			var buffer = new byte[1024];
			var stdin = socket.getInputStream();
			var stdout = socket.getOutputStream();
			while (true) {
				int length = stdin.read(buffer);
				String message = new String(buffer, 0, length);
				message = message.strip();
				if (message.equals("exit")) {
					socket.close();
					break;
				}
				stdout.write(buffer, 0, length);
			}
		} catch (Exception e) {
			throw new IllegalStateException(e);
		}
	}
}
