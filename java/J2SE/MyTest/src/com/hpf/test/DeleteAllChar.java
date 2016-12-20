package com.hpf.test;

public class DeleteAllChar {

	public static void main(String[] args) {
		String str = "Java技术学习班 20070326 MLDN 老师";
		System.out.println(str.replaceAll(" ", ""));
	}
}
