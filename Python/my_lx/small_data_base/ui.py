#!/usr/bin/env python
# -*- coding: UTF-8 -*-
#filename: ui.py

import small_data_base

def setAdmin():
    system = small_data_base.SJ()
    usercount = system.getUserCount()
    
    if usercount == 0:
        print 'You must set admin username and password'
        
        admin_name = ''
        admin_password = ''
        while len(admin_name) < 5:
            admin_name = raw_input ('Please enter admin name: ')
            if len(admin_name) < 5:
                print 'The long of name must longer than five'
                
        while len(admin_password) < 6:
            admin_password = raw_input ('Please enter admin password: ')
            if len(admin_password) < 6:
                print 'The long of password must longer than six.'
                
        if system.addUser(admin_name, admin_password):
            print "Set admin successfully."
            print 'Admin name is', admin_name
            print 'Admin password is', admin_password

setAdmin()
print 'Login...'
username = raw_input ('Username: ')
password = raw_input ('Password: ')

user = small_data_base.SJ(username)

if user.login(username, password):
    print 'Welcome', username
else:
    print 'Login FAILD'
