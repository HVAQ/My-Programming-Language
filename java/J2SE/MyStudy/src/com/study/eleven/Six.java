package com.study.eleven;

class ChangeHtml {
	public static String[] changHtml(String str) {
		String regex = "=\"|\"|>|<";
		String temp[] = str.split(" ");
		for (int index = 0; index < temp.length; index++) {
			temp[index] = temp[index].replaceAll(regex, " ");
		}
		String value[] = new String[temp.length - 1];
		for (int index = 0, count = 1; index < value.length; index++) {
			value[index] = temp[count++];
		}
		return value;
	}
}
public class Six {

	public static void main(String[] args) {
		String str = "<font face=\"Arial,Serif\" size=\"+2\" color=\"red\">";
		String value[] = ChangeHtml.changHtml(str);
		for (int index = 0; index < value.length; index++) {
			System.out.println(value[index]);
		}
	}

}
