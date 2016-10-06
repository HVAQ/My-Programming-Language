#!/usr/bin/env python
#coding=utf-8
#Filename:using_name.py

#测试、使用模块的__name__
if __name__ == '__main__':
	print 'This program is being run by itself.'
else:
	print "I'm being improted from another module."
