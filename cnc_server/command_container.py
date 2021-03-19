"""
Description: contains class for saving and using commands in a convenient way
Usage:
Author: Eli Gurevich
Date: 14/03/2021
Name: command_container.py
"""

import asyncio

from asyncio import Lock, run
from queue import Queue

from command import Command
from async_utils import run_async_with_output


class CommandContainer:
    def __init__(self):
        self.commands = Queue()
        self.commands_lock = Lock()

    def insert_random_commands(self):
        for i in range(12):
            self.commands.put(Command(name=f"on{i}"))

    async def get_command(self) -> Command:
        async with self.commands_lock:
            return self.commands.get()

    async def put_command(self, new_command: Command):
        async with self.commands_lock:
            self.commands.put(new_command)

    def get_commands(self) -> [Command]:
        commands = []
        while not self.commands.empty():
            commands.append(run_async_with_output(self.get_command))
        return commands
