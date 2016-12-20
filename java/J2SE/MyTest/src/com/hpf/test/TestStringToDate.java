package com.hpf.test;

import java.util.Date;

import com.hpf.actions.StringToDate;

public class TestStringToDate {

	public static void main(String[] args) {
		Date date = StringToDate.stringToDate("1995-11-08 10:10:10:999");
		System.out.println(date);
	}

}
