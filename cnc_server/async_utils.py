"""
Description: contains utils to use async function easily
Usage: from async_utils import ...
Name: async_utils.py
Author: Eli Gurevich
Date: 14/03/2021
"""

import asyncio


def run_async_with_output(function):
    """
    :param function: function you want to run
    :return: the output of the function
    """
    loop = asyncio.new_event_loop()
    asyncio.set_event_loop(loop)
    task = (function(),)
    output = loop.run_until_complete(asyncio.gather(*task))[0]
    loop.close()
    return output
