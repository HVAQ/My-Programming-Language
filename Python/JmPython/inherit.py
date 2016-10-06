#!/usr/bin/env python
#_*_ coding:utf-8 _*_
#Filename: inherit.py

#父类SchoolMember是子类Teacher和Student相同属性的一个集合
class SchoolMember:
	'''Repressents any school member.'''
	def __init__(self, name, age):
		self.name = name
		self.age = age
		print '(Initialized SchoolMember: %s)' %self.name

	def tell(self):
		'''Tell my details'''
		print 'Name: "%s" Age: "%s"' %(self.name, self.age),

#对父类SchoolMember的继承
#当继承的不仅仅是一个父类时，就叫做多态
class Teacher(SchoolMember):
	'''Repressents a teacher'''
	def __init__(self, name, age, salary):
		#调用父类SchoolMember的方法
		SchoolMember.__init__(self, name, age)
		self.salary = salary
		print '(Initialized Teacher: %s)' %self.name

	def tell(self):
		SchoolMember.tell(self)
		print 'Salary: "%d"' %self.salary

class Student(SchoolMember):
	'''Repressents a student.'''
	def __init__(self, name, age, marks):
		SchoolMember.__init__(self, name, age)
		self.marks = marks
		print '(Initialized Student: %s)' %self.name

	def tell(self):
		SchoolMember.tell(self)
		print 'Marks: "%d"' %self.marks

#创建元组
t = Teacher('Mrs. Shrividya', 40, 30000)
s = Student('Swaroop', 22, 75)

print #print a blank line

members = [t, s]
for member in members:
	'''
	调用父类SchoolMember的方法，如下：
	可以在父类SchoolMember中增加方法，如：
	def hello(self):
		print 'Hello world'
	并在如下代码中调用
	member.hello()
	在每一次循环中输出
	Hello world
	得到例证
	'''
	member.tell() #works for both Teachers and Students