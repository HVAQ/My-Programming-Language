#!/usr/bin/env python
#_*_ coding: utf-8 _*_
#filename: Python03.py

"""
第三章：使用字符串

字符串都是不可变的
"""
#格式化包含%的字符串
print '格式化包含%%的字符串: %s' % '这是一个包含%的字符串'
'''
字符串格式化方法一：与C语言中的相同
格式化方法二：
'''
import string
s = string.Template('$x, glorious $x!')
print s.substitute(x = 'slurm')
#如果替换字段是单词的一部分，参数名用括号括起来，从而准确指明结尾
s = string.Template("It's ${x}tastic")
print s.substitute(x = 'slurm')
#用$$插入美元符号
s = string.Template("Make $$ selling $x!")
print s.substitute(x = 'slurm')
#使用字典变量提供值／名称对
s = string.Template('A $thing must never $action.')
d = {}
d['thing'] = 'gentleman'
d['action'] = 'show his socks'
print s.substitute(d)

'''
字符串方法
'''
#find在字符串中查找子串，并返回子串所在位置最左端索引，没有反回-1
print 'With a moo-moo here, and a moo-moo there'.find('moo')

title = "Monty Python's Flying Circus"
print title.find('Monty'), title.find('Python'), title.find('Flying'), title.find('Zirquss')
#接受可选起始、结束点作为参数
subject = '$$$ Get rich now!!! $$$'
print subject.find('$$$'), subject.find('$$$', 1) #只提供起点
print subject.find('!!!'), subject.find('!!!', 0, 16) #提供起点和结束点

#join是split方法的逆方法，用来连接序列中的元素
#被连接元素必须都是字符串
'''
这是错的，因为seq中元素不是字符串
seq = [1, 2, 3, 4]
sep = '+'
print sep.join(seq)
'''
seq = ['1', '2', '3', '4']
sep = '+'
print sep.join(seq)

dirs = '', 'usr', 'bin', 'env'
print '/'.join(dirs)

print 'C:' + '\\'.join(dirs)

#lower返回字符串的小写字母版
print 'Trondheim Hammer Dance'.lower()

name = 'Gumby'
names = ['gumby', 'smith', 'jones']
if name.lower() in names:
	print 'Found it!'

#replace返回字符串中所有匹配项被替换之后的字符串
str_one = 'This is a test'
print str_one.replace('is', 'eez')
print str_one
'''
输出：
Theez eez a test
This is a test
证明原字符串没有被改变
'''

#split是join的逆方法，将字符串分割为序列
print '1+2+3+4+5'.split('+')
print '/usr/bin/env'.split('/')
print 'using the default'.split()

#strip返回去除两侧(不包括内部)空格的字符串
print '        internal whitespace is kept          '.strip()
'''
指定要去除的字符
'''
print '*** SPAM * for * everyone!!! ***'.strip(' *!') #去除两侧空格、*和！

#translate替换字符串中的某些字符(只处理单个字符)
'''
在使用translate转换之前，需先完成一张转换表
可以导入string模块中的maketrans函数
'''
from string import maketrans
table = maketrans('cs', 'kz')
print len(table), table[97:123]
print 'this is an incredible test'.translate(table)
#第二个参数是可选的，用来指定要删除的字符
print 'this is an incredible test'.translate(table, ' ')

"""
string.capwords[， sep] 使用split函数分割字符串s(以sep为分隔符)，使用capitalize函数将分割得到的
                       各单词首字母大写，并且使用join函数以sep为分隔符将各单词连接起来
string.maketrans(from, to) 创建用于转换的转换表
"""