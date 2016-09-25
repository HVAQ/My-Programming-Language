#!/usr/bin/python2.7
userinfo = [
        ['hello', '123'],
        ['vaq', '0900']
        ]
username = raw_input("Please enter you username: ")
password = raw_input("Password: ")
if [username, password] in userinfo:
    print "Welcome " + username
else:
    print "Faild"
