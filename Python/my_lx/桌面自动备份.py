#!/usr/bin/env python
# -*- coding: UTF-8 -*-
#filename: text.py

"""
备份桌面
"""

import os
import datetime

now_time = datetime.datetime.now().strftime('%Y%m%d%H%M%S')
backup = '/Users/hpf/Backup/'
backup_filename = backup + now_time

os.mkdir(backup)
os.mkdir(backup_filename)
os.system('cp -fr /Users/hpf/Desktop/ %s' %backup_filename)
print '备份成功!'