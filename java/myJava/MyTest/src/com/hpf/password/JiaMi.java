package com.hpf.password;

import java.util.Scanner;

public class JiaMi {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入要加密或解密的字符串：");
		String password = sc.nextLine();
		char[] array = password.toCharArray();
		for (int index = 0; index < array.length; index++) {
			array[index] =  (char)(array[index] ^ 1314521);
		}
		sc.close();
		System.out.println("加密或解密结果如下：");
		System.out.println(new String(array));
	}

}
