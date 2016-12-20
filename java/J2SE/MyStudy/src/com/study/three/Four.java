package com.study.three;

public class Four {

	public static void main(String[] args) {
		int a = 105;
		if (a % 3 == 0 && a % 5 == 0 && a % 7 == 0) {
			System.out.println(a + "能同时被3、5、7整除");
		} else {
			System.out.println(a + "不能同时被3、5、7整除");
		}
	}

}
