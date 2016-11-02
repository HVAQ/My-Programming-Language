# -*- coding: UTF-8 -*-
# filename: menushow.py
# verson 1.0
# 2016.10.24 by HanPengfei

def menushow(fathermenu, menucount = 1):
    """
    This is a module that provides the display menu，
    you shoule give me the fathermenu'name and menucount,
    or default menucount is 1
    """
    index = 0
    max_count = int(menucount)

    while index <= max_count:

        for son_menu in fathermenu.keys():
            print son_menu

        if index == max_count:
            break

        son_menu = raw_input ('Next: ').lower()

        if fathermenu.has_key(son_menu):
            fathermenu = fathermenu[son_menu]
        else:
            break

        index += 1
