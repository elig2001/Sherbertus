"""
Description: The file contains the main logic of the command and
control REST server to Sherbertus
Author: Eli Gurevich
Date: 19/02/2021
"""


from flask import Flask

app = Flask(__name__)


@app.route("/read_commands")
def read_commands():
    return "aaaa"


if __name__ == '__main__':
    app.run()
