import random
import socket
import threading

List of quotes
quotes = [
    "All our dreams can come true, if we have the courage to pursue them. —Walt Disney",
    "The secret of getting ahead is getting started.” —Mark Twain",
    "if people are doubting how far you can go, go so far that you can’t hear them anymore -Michele Ruiz",
   

def handle_client(client_socket):
    """Handles a single client's request for a quote"""
    Send a random quote to the client
    client_socket.send(random.choice(quotes).encode())
    client_socket.close()

def main():
    Create a TCP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    Bind the socket to the port
    server_socket.bind(("192.168.56.102", 8080))

    Listen for incoming connections
    server_socket.listen()

    while True:
        Accept a new client connection
        client_socket, client_address = server_socket.accept()

        Handle the client in a new thread
        client_thread = threading.Thread(target=handle_client, args=(client_socket,))
        client_thread.start()

if name == "main":
    main()