#!/usr/bin/python
from math import sqrt
for n in range(80, 5, -1):
	root = sqrt(n)
	if root == int(root):
		print n
		break
	else:
		print "Didn't find it!"