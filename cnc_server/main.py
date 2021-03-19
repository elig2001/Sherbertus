"""
Description: The file contains the main logic of the command and
control REST server to Sherbertus
Author: Eli Gurevich
Date: 19/02/2021
"""

import json

from flask import Flask, request

from command_container import CommandContainer

app = Flask(__name__)
g_command_container = CommandContainer()
g_command_container.insert_random_commands()


@app.route("/read_commands")
def read_commands():
    commands_to_send = [command.to_dict() for command in g_command_container.get_commands()]
    return json.dumps(commands_to_send)


@app.route("/write_commands", methods=['POST'])
def write_commands():
    return request.form


if __name__ == '__main__':
    app.run()
