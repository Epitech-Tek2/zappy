import sys

def usage(exit_code):
    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("\tport is the port number")
    print("\tname is the name of the team")
    print("\tmachine is the name of the machine; localhost by default")
    exit(exit_code)

def parse_arg(config):
    if len(sys.argv) < 2:
        usage(84)
    if "-p" and "-n" in sys.argv:
        for i in sys.argv:
            try:
                if i == "-help":
                    usage(0)
                elif i == "-n":
                    config['name'] = sys.argv[sys.argv.index(i) + 1]
                elif i == "-h":
                    config['machine'] = sys.argv[sys.argv.index(i) + 1]
                elif i == "-p":
                    config['port'] = int(sys.argv[sys.argv.index(i) + 1])
            except IndexError:
                usage(84)
            except ValueError:
                usage(84)
    else:
        usage(84)