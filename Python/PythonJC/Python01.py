#!/usr/bin/env python
#coding=utf-8

"""
本程序供初学者使用
所有注释均为代码段的解释说明

Python基础教程第一章知识点总结
"""

#打印字符串
print 'hello world'
#单引号与双引号及转义序列的使用
print 'let\'s go'
print "let's go"
#这是错的 print 'let's go'

#拼接字符串
print 'hello' + ' ' + 'world'
x = 'hello'
y = 'world'
#这是错的 print x y
print x + ' ' + y

#str函数(把值转换为合理的字符串，便于用户理解)
print str('Hello, world')
print str(10000L)
'''
打印结果：
Hello, world
10000
'''
#repr函数(创建一个字符串，以合法的Python表达式的形式表示值)
print repr('Hello, world')
print repr(10000L)
'''
打印结果：
'Hello, world'
10000L
'''
#repr(x) = `x`(在Python3.0中不再使用反引号)
temp = 42
#这是错的 print 'The number is' + temp
print 'The number is ' + `temp`
print 'The number is ' + repr(temp)

'''
input与raw_input的区别在与
input要求用户输入的是合法的Python表达式
raw_input没有这一要求

如果用户想要输入名字--Anne
input要求输入‘Anne', 否则就会报错
raw_input输入Anne即可
'''
name_one = input("Please enter you name: ")
#除非必要，不使用这种获取输入的方法
print 'Your name is ' + name_one + '!'
name_two = raw_input("Please enter you name: ")
print 'Your name is ' + name_two + '!'

#原始字符串(在书写正则表达式中特别有用)
print r'C:\nowhere'
#r'字符串'没有将字符串中的\n转义
#这是错的 print r'C:\nowhere\' 原始字符串最后一个字符不能为反斜线\
#如果需要原始字符串最后一个字符为反斜线
print r'C:\nowhere''\\'
#Unicode字符串, u'字符串'

"""
新函数
abs(number): 返回数字的绝对值
cmath.sqrt(number): 返回平方根，可应用于负数
math.sqrt(number): 返回平方根，不适用于负数
math.ceil(number): 返回数的上入整数，返回值为浮点数
math.floor(number): 返回值的下舍整数，返回值为浮点数
pow(x, y[, z]): 返回x的y次幂(所得结果对z取模)
round(number[, ndigits]): 根据给定的精度对数字进行四舍五入
str(object): 将值转换为字符串
"""