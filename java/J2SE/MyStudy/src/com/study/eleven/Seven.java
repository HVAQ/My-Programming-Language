package com.study.eleven;

import java.util.Locale;
import java.util.ResourceBundle;

public class Seven {

	public static void main(String[] args) {
		if (args.length != 1) {
			System.out.println("参数设置错误。");
			System.exit(1);
		}
		String language = null;
		String country = null;
		switch(args[0]) {
		case "1":
			language = "zh";
			country = "CN";
			break;
		case "2":
			language = "en";
			country = "US";
			break;
		default:
			System.out.println("参数设置错误。");
			System.exit(1);
		}
		ResourceBundle rb = ResourceBundle.getBundle("com.study.eleven.Message", new Locale(language, country));
		System.out.println(rb.getString("info"));
	}

}
