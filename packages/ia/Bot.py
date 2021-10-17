from Socket import Socket

#TODO 
#Je sais pas comment gérer le temps et la nourriture

MAX_LEVEL = 8
MAX_PLAYER = 100
STONES = ["linemates", "deraumere", "sibur", "mendiane", "phiras", "thystame"]
ELEVATION = [
    {},
    {
        'player': 1,
        'linemates': 1, 
        'deraumere': 0, 
        'sibur': 0,
        'mendiane': 0,
        'phiras': 0,
        'thystame': 0
    },
    {
        'player': 2,
        'linemates': 1, 
        'deraumere': 1, 
        'sibur': 1,
        'mendiane': 0,
        'phiras': 0,
        'thystame': 0
    },
    {
        'player': 2,
        'linemates': 2, 
        'deraumere': 0, 
        'sibur': 1,
        'mendiane': 0,
        'phiras': 2,
        'thystame': 0
    },
    {
        'player': 4,
        'linemates': 1, 
        'deraumere': 1, 
        'sibur': 2,
        'mendiane': 0,
        'phiras': 1,
        'thystame': 0
    },
    {
        'player': 4,
        'linemates': 1, 
        'deraumere': 2, 
        'sibur': 1,
        'mendiane': 3,
        'phiras': 0,
        'thystame': 0
    },
    {
        'player':6,
        'linemates': 1, 
        'deraumere': 2, 
        'sibur': 3,
        'mendiane': 0,
        'phiras': 1,
        'thystame': 0
    },
    {
        'player': 6,
        'linemates': 2, 
        'deraumere': 2, 
        'sibur': 2,
        'mendiane': 2,
        'phiras': 2,
        'thystame': 1
    },
]
SERVER_RESPONSE = ["ok", "ko"]

class Bot():
    def __init__(self):
        self.sock = None
        self.level = 1
        self.team = ""
        self.client_num = 0
        self.pos = {'x': 0, 'y':0}
        self.last_look = None
        self.inventory = {
			"linemate": 0,
			"deraumere": 0,
			"sibur": 0,
			"mendiane": 0,
			"phiras": 0,
			"thystame": 0
        }
#SOCKET
    def connect(self, ip: str, port: int):
        '''Create the Socket and connect the bot to the server'''
        self.sock = Socket(ip, port)
        self.sock.connect()
    def send(self, message: str):
        '''Send a message to the server'''
        self.sock.send(message)
    def recv(self):
        '''Receive message from the server'''
        return self.sock.recv()
    def disconnect(self):
        '''Disconnect the bot from the server'''
        self.sock.disconnect(self)
#SETTERS
    def set_team(self, name: str):
        '''Set a new team name'''
        self.team_name = name
    def set_level(self, level: int):
        '''Set a new level'''
        self.level = level
#METHOD
    def start(self):
        '''Get informations from the server and send the team name'''
        if self.recv() == "WELCOME\n":
            self.send(self.team)
        self.client_num = self.recv().strip()
        try:
            if len((coord := self.recv().strip().split(' '))) == 2:
                self.pos['x'], self.pos['y'] = coord[0], coord[1]
        except IndexError as e:
            print(f"[Invalid Format] {e}")
            exit(84)
    def get_server_response(self, msg):
        with msg.split("\n") as message:
            if message == "dead":
                print("You're dead")
                exit(0)
            else:
                return message
    def move(self, direction: str):
        self.send(direction)
        while True:
			if (ret :=self.get_server_response(self.recv())) in SERVER_RESPONSE:
				return ret
#COMMANDS
    def forward(self):
        return self.move("Forward")
    def right(self):
        return self.move("Right")
    def left(self):
        return self.move("Left")
    def inventory(self):
        ret = {}
        self.send("Inventory")
        while True:
            with self.get_server_response(self.recv()) as response:
                if len(response) > 5 and response[0] == "[" and response[-1] == "]":
                    response = response.replace(' ,', '').replace('[', '').replace(']', '').replace(', ', ',')
                    for i in response.split(','):
                        ret[i.split(' ')[0]] = i.split(' ')[1]
                    return ret
    def look(self):
        ret = []
        self.send("Look")
        while True:
            with self.get_server_response(self.recv()) as response:
                if len(response) > 5 and response[0] == "[" and response[-1] == "]":
                    response = response.replace(' ,', '').replace('[', '').replace(']', '').replace(', ', ',')
                    for i in response.split(','):
                        ret.append(i)
                    self.last_look = ret
                    return self.last_look
    def broadcast(self, msg: str):
        self.send(f"Broadcast {msg}")
        while True:
			if (ret :=self.get_server_response(self.recv())) in SERVER_RESPONSE:
				return ret
    def fork(self):
        self.send("Fork")
        while True:
            if (ret :=self.get_server_response(self.recv())) in SERVER_RESPONSE:
                return ret
    def connect_nbr(self):
        self.send("Connect_nbr")
        while True:
            try:
                if (ret := int(self.get_server_response(self.recv()))) in range(MAX_PLAYER):
                    return ret
            except ValueError:
                exit("Invalid server response")
    def eject(self):
        self.send("Eject")
        while True:
            if (ret :=self.get_server_response(self.recv())) in SERVER_RESPONSE:
                return ret
    def take_obj(self, obj: str):
        self.send(f'Take {obj}')
        while True:
            if (ret :=self.get_server_response(self.recv())) in SERVER_RESPONSE:
                break
        if (status := ret == "ok"):
            self.inventory[obj] += 1
        return status
    def set_obj(self, obj: str):
        self.send(f'Set {obj}')
        while True:
            if (ret :=self.get_server_response(self.recv())) in SERVER_RESPONSE:
                break
        if (status := ret == "ok"):
            self.inventory[obj] -= 1
        return status
    def incantation(self):
