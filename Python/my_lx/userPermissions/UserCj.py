# -*- coding: UTF-8 -*-
#filename: UserCj.py

import AllUser

class UserCj(object):

    """
    超级用户
    用户权限为1
    拥有权限
    继承
    1.查看自己用户名和权限
    2.修改自己密码
    自身
    1.查看所有用户名和权限
    2.修改所有用户密码
    3.删除除自己之外的任意用户
    4.将除自己之外的用户权限修改为2或3
    5.增加权限为2和3的用户
    """

    def __init__(self, username = 'root'):
        self.username = username

    def getPermissionsList(self):
        for username in AllUser.AllUser.userinfo.keys() and permissions in AllUser.AllUser.userinfo[username][1]:
            print username + '----' + 'permissions'

    def setUserPassword(self, username, password):
        if username != self.username and AllUser.AllUser.setUserpassword(username, password):
            return True
        else:
            return False

    def setOtherPermissions(self):
        AllUser.AllUser.setUserPermissions
