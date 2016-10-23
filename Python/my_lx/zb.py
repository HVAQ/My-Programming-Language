#!/usr/bin/env python
#coding=utf-8
#filename: demo.py

import urllib2

url = raw_input('请输入网址: ')

request = urllib2.Request(url)
response = urllib2.urlopen(request)
print response.read()