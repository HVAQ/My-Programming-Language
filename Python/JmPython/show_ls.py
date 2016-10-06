#!/usr/bin/env pthon
#coding=utf-8
#Filename:show_cd.py

"""
在指定文件夹执行ls -al命令
"""
#导入必要的模块
import os

file_pwd = raw_input('Please enter the pwd of dictory: ')
os.system('ls -al ' + file_pwd)