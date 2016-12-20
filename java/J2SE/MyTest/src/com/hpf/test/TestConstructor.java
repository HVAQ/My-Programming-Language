package com.hpf.test;

class Constructor {
	{	// 定义构造块
		System.out.println("构造块 1");
	}
	public Constructor() {	// 定义构造块
		System.out.println("构造方法 2");
	}
	static {		// 定义静态块
		System.out.println("静态块");
	}
}
public class TestConstructor {
	public static void main(String[] args) {
		new Constructor();
		new Constructor();
		new Constructor();
	}
}
