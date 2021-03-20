"""
Description: contains class for saving and using commands in a convenient way
Usage:
Author: Eli Gurevich
Date: 14/03/2021
Name: command_container.py
"""

from asyncio import Lock
from queue import Queue

from cnc_server.command_package.command import Command
from cnc_server.async_utils import run_async_with_output


class CommandContainer:
    def __init__(self):
        self.commands = Queue()
        self.commands_lock = Lock()

    def insert_random_commands(self):
        for i in range(12):
            self.commands.put(Command(name=f"on{i}"))

    async def _get_command(self) -> Command:
        async with self.commands_lock:
            return self.commands.get()

    def get_command(self):
        return run_async_with_output(self._get_command)

    def get_commands(self) -> [Command]:
        commands = []
        while not self.commands.empty():
            commands.append(self.get_command())
        return commands

    async def _put_command(self, new_command: Command):
        async with self.commands_lock:
            self.commands.put(new_command)

    def put_command(self, command: Command):
        run_async_with_output(self._put_command, command)
