#!/usr/bin/env python
#coding=utf-8
#filename: phont_numbers.py

import getChoose

class Phone_numbers:
    
    def __init__(self):
        pass
    
    def theMain(self):
        user_num = 0
        userinfo = {}
        ch = getChoose.mean()
        
        while ch != '4':
            if ch == '1':
                name = str(raw_input('姓   名: '))
                num = str(raw_input('电话号码: '))
                
                if name in userinfo:
                    userinfo[name] = num
                    print ('更新联系人' + name + '成功')
                else:
                    userinfo[name] = num
                    user_num += 1
                    print ('新建联系人' + name + '成功')
                    print ('现有联系人%d个' %user_num)
            elif ch == '2':
                name = str(raw_input('姓名: '))
                
                if name in userinfo:
                    print ('电话号码: ' + userinfo[name])
                else:
                    print ('联系人' + name + '不存在')
            elif ch == '3':
                name = str(raw_input('请输入要删除的联系人姓名: '))
                
                if name in userinfo:
                    del userinfo[name]
                    user_num -= 1;
                    print ('联系人' + name + '删除成功')
                    print ('现有联系人%d个' %user_num)
                else:
                    print ('联系人' + name + '不存在')
            else:
                break
            ch = getChoose.mean()
            
        print ('再见')
