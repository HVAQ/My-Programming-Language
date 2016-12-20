package com.hpf.actions;
/**
 * 本地格式化输出日期
 */
import java.text.SimpleDateFormat;
import java.util.Date;

public class FormatDate {
	public static String formatDate(Date date) {
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS");
		return sdf.format(date);
	}
}
