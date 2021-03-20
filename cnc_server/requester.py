import requests

from cnc_server.command_package.command import Command


def send_post():
    url = 'http://127.0.0.1:5000/write_commands'
    data = Command("FUCK", 30).to_dict()
    print(requests.post(url, data=data).text)


def send_get():
    url = 'http://127.0.0.1:5000/read_commands'
    print(requests.get(url).text)


def main():
    send_get()
    # send_post()
    # send_post()
    # send_post()

if __name__ == '__main__':
    main()
