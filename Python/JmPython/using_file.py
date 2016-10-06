#!/usr/bin/env python
#_*_ coding:utf-8 _*_
#Filename: using_file.py

poem = '''\
Programming is fun
When the word is done
if you wanna make you work also fun:
	use Python!
'''

f = file('poem.txt', 'w')
f.write(poem)
f.close()

f = file('poem.txt')
while True:
	line = f.readline()
	if len(line) == 0:
		break
	#因为读文件会读取文件每一行的换行符，故使用逗号消除print自动打印的换行符
	print line,
f.close()