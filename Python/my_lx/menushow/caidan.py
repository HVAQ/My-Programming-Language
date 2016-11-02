#!/usr/bin/env python
# -*- coding: UTF-8 -*-
#filename: caidan.py

import menushow

"""
这是一个可拓展的自动化多级菜单
利用的是Python的 字典及循环
"""
cd = {
        "beijin": {
            "chaoyang": {
                "chaoyang1": {"chaoyang1-1":None , "chaoyang1-2": None},
                "chaoyang2": {"chaoyang2-1":None, "hcoayang2-2": None}
                },
            "changpin": {
                "changpin1": {"changpin1-1":None, "changpin1-2":None},
                "changpin2": {"changpin2-1":None, "changpin2-2":None}
                }
            },
        "shanxi": {
            "taiyuan": {
                "taiyuan1": {"taiyuan1-1":None, "taiyuan1-2":None},
                "taiyuan2": {"taiyuan2-1":None, "taiyuan2-2":None}
                },
            "lvliang": {
                "lvliang1": {"lvliang1-1":None, "lvliang1-2":None},
                "lvliang2": {"lvliang2-1":None, "lvliang2-2":None}
                }
            }
        }

menushow.menushow(cd, 3)
