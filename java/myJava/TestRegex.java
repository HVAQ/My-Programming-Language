package com.hpf.test;

import com.hpf.actions.Regex;

public class TestRegex {
	public static void main(String[] args) {
		String str = "fei776525061@qq.com";
		System.out.println(Regex.isEmail(str));
	}
}
