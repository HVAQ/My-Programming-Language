package com.hpf.actions;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class StringToDate {
	/**
	 * 将字符串转换为日期
	 * @param str 要转换为日期的字符串
	 * @return 当转换失败时，返回当前日期
	 */
	public static Date stringToDate(String str) {
		Date date = new Date();
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS");
		try {
			date = sdf.parse(str);
		} catch (ParseException e) {
			e.printStackTrace();
		}
		return date;
	}
}
