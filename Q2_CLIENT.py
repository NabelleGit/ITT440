import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = '192.168.56.102'
port = 8080

sock = socket.socket()
sock.connect((host, port))
print("Connection established with server.\n")

try:
    temperature = float(input("Enter temperature (Fahrenheit): "))
    sock.sendall(str(temperature).encode())

    amount_received = 0
    amount_expected = len(str(temperature))

    while amount_received < amount_expected:
        data = sock.recv(5555)
        amount_received += len(data)
        celcius = float(data.decode())
        print("Temperature (Celcius): %.2f" % celcius)

finally:
    print('\nClosing socket')
    sock.close()
