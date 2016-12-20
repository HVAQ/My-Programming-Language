package com.hpf.test;

public class getCharNum {

	public static void main(String[] args) {
		String str = "want you to know one thing";
		System.out.println("字母 n 出现" + charNum(str, "n") + "次");
		System.out.println("字母 o 出现" + charNum(str, "o") + "次");
	}
	// 利用切片方法 split 计算字母出现的次数
	private static int charNum(String str, String ch) {
		String []strArray = str.split(ch);
		return strArray.length - 1;
	}
}
