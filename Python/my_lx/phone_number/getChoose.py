#!/usr/bin/env python
#coding=utf-8
#filename: getChoose.py

def mean():
	print ('******************************')
	print ('           电话簿')
	print ('1) 新建联系人    2) 查找联系人')
	print ('3) 删除联系人    4) 退出')
	print ('******************************')

	choose = raw_input('请选择: ')
	while not ('0' < choose < '5'):
		choose = raw_input('请选择: ')

	return choose
