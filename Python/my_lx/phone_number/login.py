#!/usr/bin/env python
#coding = utf-8
#filename: login.py

"""
Get username and password
"""

class getUserInfo(object):

    def __init__(self, username, password):
        self.username = username
        self.password = password

    def IsSame(self):
        if self.username == "admin" and self.password == "admin":
            return True
        else:
            return False
