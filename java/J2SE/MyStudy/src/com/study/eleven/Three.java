package com.study.eleven;

class IsEmail {
	public static boolean isEmail(String str) {
		if (str.trim().isEmpty() || str == null) {
			return false;
		}
		// email: 776525061@qq.com 
		// .com		.cn 		.com.cn 		.net 	.net.cn 		.org
		// .gov		.edu	
		String regex = "\\w+@\\w+\\.((com|net)(.cn)?|cn|org|gov|edu)";
		if (!str.matches(regex)) {
			return false;
		}
		return true;
	}
}
public class Three {

	public static void main(String[] args) {
		String str = "776525061@qq.com";
		if (IsEmail.isEmail(str)) {
			System.out.println("Is email.");
		} else {
			System.out.println("Isn't email.");
		}
	}

}
