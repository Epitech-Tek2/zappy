import socket

MAX_RECV = 2048

class Socket():
    def __init__(self, ip: str, port: int):
        self.ip = ip
        self.port = port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    def connect(self):
        try:
            self.sock.connect((ip,port))
        except Exception as e:
            print(f'[Socket Error] {e}')
            exit(84)
    def send(self, message):
        self.sock.send(str.encode(f'{message}\n'))
    def recv(self):
        return self.sock.recv(MAX_RECV).decode()
    def disconnect(self):
        self.sock.close()
