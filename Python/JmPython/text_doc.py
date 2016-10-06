#!/usr/bin/env python
#_*_ coding:utf-8 _*_

"""
This is a class for text __doc__ and class
"""
class Text:
	"""
	这是一个类，用来测试__doc__和类
	"""
	#初始化对象／实例
	def __init__(self, name):
		self.name = name

	#定义一个方法
	def Aff(self):
		print '这是一个方法'