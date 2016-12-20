package com.hpf.actions;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Regex {
	public static boolean isIpv4(String str) {
		String regex = "(\\d{1,3}\\.){3}\\d{1,3}";
		if (!str.matches(regex)) {
			return false;
		}
		String[] result = str.split("\\.");
		for (int index = 0; index < result.length; index++) {
			Integer num = Integer.parseInt(result[index]);
			if (num < 0 || num > 255) {
				return false;
			}
		}
		return true;
	}
	public static boolean isDate(String str) {
		String regex_one = "\\d{2,4}(\\.?\\d{2}){2}";
		String regex_two = "\\d{2,4}(-\\d{2}){2}";
		if (!str.matches(regex_one) && !str.matches(regex_two)) {
			return false;
		}
		try {
			Date date = new Date();
			if (str.matches(regex_one)) {
				date = new SimpleDateFormat("yyyy.MM.dd").parse(str);
			} else {
				date = new SimpleDateFormat("yyyy-MM-dd").parse(str);
			}
			System.out.println(date);
		} catch (ParseException e) {
			e.printStackTrace();
		}
		return true;
	}
	public static boolean isPhoneNum(String str) {
		String regex = "((\\d{3,4}|\\(\\d{3,4}\\))(-)?)?\\d{7,8}";
		if (str.matches(regex)) {
			return true;
		}
		return false;
	}
	public static boolean isEmail(String str) {
		String regex = "[a-zA-z](\\w*\\.*){0,28}[a-zA-Z0-9]@\\w+\\.((com|net)(\\.cn)?|gov|edu|cn|org)";
		if (str.matches(regex)) {
			return true;
		}
		return false;
	}
}
