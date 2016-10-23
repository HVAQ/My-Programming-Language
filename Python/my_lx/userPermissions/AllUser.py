# -*- coding: UTF-8 -*-
#filename: AllUser.py

class AllUser(object):

    userinfo = {}

    def __init__(self, username = 'root', password = '123456', permissions = '1'):
        self.__username = username
        self.password = password
        self.permissions = permissions
        AllUser.userinfo[self.__username] = [self.password, self.permissions]

    def getUserPermissions(self, username):
        return AllUser.userinfo[username][1]

    def getUsernameList(self):
        return AllUser.userinfo.keys()

    def setUserpassword(self, username, password):
        permissions = AllUser.userinfo[username][1]
        AllUser.userinfo[username] = [password, permissions]
        return True

    def setUserPermissions(self, username, permissions):
        AllUser.userinfo[username][1] = permissions
        return True

    def delAUser(self, username):
        if len(AllUser.userinfo) > 1:
            del AllUser.userinfo[username]
            return True
        else:
            return False

    def addAUser(self, username, password = '123456', permissions = '3'):
        if not AllUser.userinfo.has_key(username):
            AllUser.userinfo[username] = [password, permissions]
            return True
        else:
            return False
