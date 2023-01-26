import socket

def main():
    # Create a TCP socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connect to the server
    client_socket.connect(("192.168.56.102", 8080))

    # Receive the quote from the server
    quote = client_socket.recv(1024).decode()
    print("Received quote:", quote)

    # Close the socket
    client_socket.close()

if name == "main":
    main()