# -*- coding: UTF-8 -*-
# filename: AllUser.py

import AllUser

class UserPt(object):
    """
    普通用户
    权限级别3
    权限
    1.获取自身用户名和权限
    2.修改自身密码
    """

    def __init__(self, username):
        self.__username = username

    def getUsername(self):
        return self.__username

    def getPermissions(self, username):
        AllUser.AllUser.getUserPermissions(username)

    def setPassword(self, password = '123456'):
        if AllUser.AllUser.setUserpassword(self.__username, password):
            return True
        else:
            return False
