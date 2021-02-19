"""
Description: The file contains the main logic of the command and
control REST server to Sherbertus
Author: Eli Gurevich
Date: 19/02/2021
"""

import json
import asyncio

from asyncio import Lock, run
from flask import Flask
from queue import Queue

from command import Command



app = Flask(__name__)
g_commands = Queue()
g_commands_lock = Lock()

for i in range(12):
    g_commands.put(Command(name=f"on{i}"))
print(g_commands)


async def get_commands():
    async with g_commands_lock:
        commands = []
        while g_commands.empty() is not True:
            commands.append(g_commands.get().to_dict())
    return commands


def run_async_with_output(function):
    loop = asyncio.new_event_loop()
    asyncio.set_event_loop(loop)
    task = (function(),)
    output = loop.run_until_complete(asyncio.gather(*task))[0]
    loop.close()
    return output


@app.route("/read_commands")
def read_commands():
    commands_to_send = run_async_with_output(get_commands)
    return json.dumps(commands_to_send)


if __name__ == '__main__':
    app.run()
