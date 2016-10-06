#!/usr/bin/python
#coding=utf-8
#Filename using_list.py

#This is shopping list
shoplist = ['apple', 'mango', 'carrot', 'banana']

print 'I have', len(shoplist), 'items to purchase.'

print 'These items are', #Notice the comma at end of the line
for item in shoplist:
	print item,

print '\nI also have to buy rice' #这里使用换行符是因为前面的for循环语句中使用了逗号
shoplist.append('rice')
print 'My shopping list is now', shoplist

print 'I will sort my list now'
shoplist.sort()
print 'Sorted shopping list is', shoplist

print 'The first item i will buy is', shoplist[0]
olditem = shoplist[0]
del shoplist[0]
print 'I bought the', olditem
print 'My shopping list is now', shoplist