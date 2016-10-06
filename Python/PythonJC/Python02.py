#!/usr/bin/env python
#coding=utf-8

"""
列表和元组
"""

#列表的一种写法
edward = ['Edward Gumby', 42]
print 'edward = ', edward
john = ['John Smith', 50]
print 'john = ', john
database = [edward, john]
print 'database = [adward, john]\n' + ' ' * (len('database') + 1) + '=', database

'''
索引操作
索引第一个为0，最后一个为-1
'''
greeting = 'Hello'
print 'greeting = ', greeting
print 'greeting[0] = ', greeting[0]
print 'greeting[-1] = ', greeting[-1]
print 'Hello[1] = ' + 'Hello'[1]
#以下操作会在列表索引不足3时出现错误
fourth_one = raw_input('Year: ')[0]
print fourth_one
fourth_two = raw_input('Year: ')
print 'fourth_two = ', fourth_two[:]
print 'fourth_two[0] = ', fourth_two[0]

#索引示例
'''
会在输入月份大于12或小于1
日期大于31或小于1时
出现错误
'''
#根据给定的年月日以数字形式打印日期
months = [
    'January',
    'February',
    'March',
    'April',
    'May',
    'June',
    'July',
    'August',
    'September',
    'October',
    'November',
    'December'
    ]
#以1～31的数字作为结尾的列表
endings = ['st', 'nd', 'rd'] + 17 * ['th']\
        + ['st', 'nd', 'rd'] + 7 * ['th']\
        + ['st']
year = raw_input('Year: ')
month = raw_input('Month (1-12): ')
day = raw_input('Day (1-31): ')

month_number = int(month)
day_number = int(day)

#记得要讲月份和天数减1，以获得正确的索引
month_name = months[month_number - 1]
ordinal = day + endings[day_number - 1]

print month_name + ' ' + ordinal + ', ' + year

#分片
'''
分片需要2个索引作为边界
第一个索引的元素包含在分片内
第二个则不包含在分片内
'''
tag = '<a href="http://www.python.org">Python web site</a>'
print tag[9:30]
print tag[32:-1]
#分片中，只要最左边的索引比它右边的晚出现在序列中，结果就是一个空序列
print tag[31:0]
#分片所得部分要包括序列结尾的元素，只需置空最后一个索引即可，如下：
print tag[32:]

#置空索引的操作
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print numbers[:3]
print numbers[:]
'''
分片的步长
分片默认步长为1
'''
print numbers[0:10:1]
print numbers[0:10:2]
print numbers[::4]
#步长不能为0，可以为负数
print numbers[10:0:-1]
print numbers[::-1]
print numbers[0:10:-1] #得到的是一个空的序列

#序列相加
print [1, 2, 3] + [4, 5, 6]
print 'Hello, ' + 'world!'
#这是错的 print [1, 2, 3] + 'world!'，因为[1, 2, 3]和'world'，虽然都是序列，但二者类型不同

#序列的乘法
print 'Python' * 5
print [42] * 10

#in成员资格
string_one = 'Python'
print 'P' in string_one
print 'p' in string_one
print 'q' in string_one
print 'hello' in 'hello world'

#检查用户名和PIN码
database = [
	['albert', '1234'],
	['dilbert', '4242'],
	['smith', '7524'],
	['jones', '9843'],
	]
username = raw_input('User name: ')
pin = raw_input('PIN code: ')

if [username, pin] in database:
	print 'Access granted'

#len函数返回序列中所包含元素的数量
numbers = [100, 34, 678]
string_two = ['hello', 'world', '12345']
print len(numbers)
print len(string_two)
print len('hello')
#min函数返回序列中最小元素
print min(numbers)
print min(string_two)
#max函数返回序列中最大元素
print max(numbers)
print max(string_two)

'''
列表
可以被修改
'''

#list根据字符串创建列表(适用于所有类型的序列)
print list('Hello')
#列表的元素赋值
x = [1, 1, 1]
x[1] = 2
print x
#del删除列表元素
name = ['Alice', 'Beth', 'Cecil', 'Dee-Dee', 'Earl']
print 'name = ', name
del name[2]
print 'del name[2] = ', name

#分片赋值(可以使用与原序列不等长的序列进行分片替换)