# -*- coding: UTF-8 -*-
#filename: UserGl.py

import AllUser
import UserPt

class UserGl(object):
    """
    管理员
    权限级别2
    特有权限
    1.修改权限为3的用户密码
    2.增加权限为3的用户
    3.删除权限为3的用户
    """

    def __init__(self, username):
        self.username = username

    def setUserPassword(self, username, password):
        if AllUser.AllUser.getUserPermissions(username) == '3':
            AllUser.AllUser.setUserpassword(username, password)
            return True
        else:
            return False

    def addUser(self, username, password): 
        if AllUser.AllUser.addAUser(username, password = '123456', permissions = '3'):
            return True
        else:
            False

    def delUser(self, username):
        if username != self.username and AllUser.AllUser.getUserPermissions(username) == '3':
            AllUser.AllUser.delAUser(username)
            return True
        else:
            return False
