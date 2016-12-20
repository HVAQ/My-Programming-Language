package com.hpf.ui;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Point;
import javax.swing.JFrame;

public class MyFirstUi {
	public static void main(String[] args) {
		JFrame f = new JFrame("My Frist JAVA UI");	// 实例化窗口对象
		Dimension d = new Dimension();		// 实例化 Dimension 对象
		d.setSize(230, 80);		// 设置窗体大小
		f.setSize(d);		// 设置组件大小
		f.setBackground(Color.WHITE);	// 设置窗体背景色
		Point p = new Point(300, 280);	// 设置显示的坐标点
		f.setLocation(p);		// 设置窗体显示位置
		f.setVisible(true);		// 让组件显示
	}
}
