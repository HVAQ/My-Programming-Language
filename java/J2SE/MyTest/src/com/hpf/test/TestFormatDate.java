package com.hpf.test;

import java.util.Date;

import com.hpf.actions.FormatDate;

public class TestFormatDate {

	public static void main(String[] args) {
		Date date = new Date();
		System.out.println(FormatDate.formatDate(date));
	}

}
