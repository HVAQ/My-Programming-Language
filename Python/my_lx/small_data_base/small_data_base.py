# -*- coding: UTF-8 -*-
#filename: small_data_base.py

class SJ(object):
    '''
    When you user this at first time, you must to add a user as admin.
    If you don't dou it, you wouldn't user this.
    '''
    __userinfo = {}

    def __init__(self, username = 'system'):
        self.__username = username

    def getUsername(self):
        if SJ.getUserCount() == 0:
            SJ.__waringForAdmin()
        else:
            return self.__username

    def getPermissions(self, username):
        if SJ.getUserCount() == 0:
            SJ.__waringForAdmin()
        else:
            return SJ.__userinfo[username][1]
   
    def setPassword(self, username, password):
        if SJ.getUserCounti() == 0:
            SJ.__waringForAdmin()
            return False
        elif SJ.getUserCount() == 1:
            username = self.username
        elif username != self.__username:
            othper = SJ.getPermissions(username)
            myper = SJ.getPermissions(self.__username)
            if int(myper) > othper:
                return False
        else:
            SJ.__userinfo[username] = [password, othper]
            return True

    def addUser(self, username, password = '123456'):
        '''
        If the username of you provide in userinfo'keys, 
        it will return False, else return True
        '''
        if SJ.__userinfo.has_key(username):
            return False
        elif len(SJ.__userinfo) == 0:
            permissions = '1'
        else:
            permissions = '3'
        
        SJ.__userinfo[username] = [password, permissions]
        return True
        
    def getUserCount(self):
        return len(SJ.__userinfo)

    def __waringForAdmin(self):
        print 'You must add a user as admin.'

    def delUser(self, username):
        if username == self.__username:
            '''
            Everyone can't delete hisself or herself
            '''
            return False
        if SJ.__userinfo.has_key(username):
            othper = SJ.getPermissions(username)
            myper = SJ.getPermissions(self.__username)
            if othper < myper:
                return False
            else:
                del SJ.__userinfo[username]

    def login(self, username, password):
        if SJ.__userinfo.has_key(username):
            if SJ.__userinfo[username][0] == password:
                return True
        else:
            return False

    def userList(self):
        print SJ.__userinfo.keys()
