package com.study.eleven;

class IsIpv4 {
	public static boolean isIpv4(String str) {
		if (str.trim().isEmpty() || str == null) {
			return false;
		}
		String regex = "(\\d{1,3}\\.){3}\\d{1,3}";
		if (!str.matches(regex)) {
			return false;
		}
		String []value = str.split("\\.");
		for (int index = 0; index < value.length; index++) {
			Integer num = Integer.parseInt(value[index]);
			if (num < 0 || num > 255) {
				return false;
			}
		}
		return true;
	}
}
public class Five {

	public static void main(String[] args) {
		String str = "255.255.255.255";
		System.out.println(IsIpv4.isIpv4(str));
	}

}
