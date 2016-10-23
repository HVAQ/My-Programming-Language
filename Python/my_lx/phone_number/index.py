#!/usr/bin/env python
# -*- coding:UTF-8 -*-
#filename: index.py

import login
import phone_numbers

username = ''
password = ''

while username == '':
    username = raw_input ('请输入用户名: ')

while password == '':
    password = raw_input ('请输入密码: ')

gui = login.getUserInfo(username, password)

if not gui.IsSame():
    print '登录失败'
else:
    themain = phone_numbers.Phone_numbers()
    themain.theMain();
