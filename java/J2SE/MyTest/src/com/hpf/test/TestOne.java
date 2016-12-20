package com.hpf.test;

import java.text.SimpleDateFormat;
import java.util.Date;

public class TestOne {

	public static void main(String[] args) {
		int a = 8888888;
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS");
		System.out.println(sdf.format(new Date()));
		System.out.println(a >> 33);
		System.out.println(sdf.format(new Date()));
		System.out.println(a / 2);
		System.out.println(sdf.format(new Date()));
	}

}
