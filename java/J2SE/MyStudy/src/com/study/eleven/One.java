package com.study.eleven;

public class One {

	public static void main(String[] args) {
		StringBuffer str = new StringBuffer("");
		char ch = 'a';
		for (int index = 0; index < 26; index++) {
			str.append(ch++);
		}
		System.out.println(str.reverse().delete(0, 5));
	}

}
