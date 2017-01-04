package com.hpf.test;

public class TestStringBuffer {

	public static void main(String[] args) {
		StringBuffer str = new StringBuffer();
		str.append("no,name,note,");
		System.out.println(str);
		int len = str.length();
		str.replace(len - 1, len, "");
		String sb[] = str.toString().split(",");
		for (int index = 0; index < sb.length; index++) {
			System.out.print(sb[index] + "\t");
			System.out.println(sb[index].length());
		}
		System.out.println(str);
	}

}
