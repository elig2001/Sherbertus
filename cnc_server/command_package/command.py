"""
Description: contains implementation of command data class
Author: Eli Gurevich
Date: 19/02/2021
"""

from dataclasses import dataclass
from dataclasses_json import dataclass_json



@dataclass_json
@dataclass
class Command:
    """
    commands for sherbertus
    @name: the name of the command
    @duration: duration of the command, not mandatory
    """
    name: str
    duration: int = None