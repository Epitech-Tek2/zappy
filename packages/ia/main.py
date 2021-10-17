from Bot import Bot
from utils import parse_arg, usage

CONFIG = {
    'port' : 0,
    'name' : "",
    'machine': 'localhost'
}


parse_arg(CONFIG)

bot = Bot()
bot.set_team(CONFIG['name'])
bot.connect(CONFIG['machine'], CONFIG['port'])
bot.start()