package com.hpf.school.ui;

import com.hpf.school.src.Login;
import com.hpf.school.src.School;
import com.hpf.school.src.Students;

public class Text {

	private static String username;
	private static String password;
	
	public static void main(String[] args) {
		username = "system";
		password = "123";
		
		Login login = new Login();
		
		if (username.equals(login.getUsername()) && password.equals(login.getPassword())) {
			
			School school = new School("山西工程技术学院");
			Students s1 = new Students("140421041", "韩鹏飞", "男", "在读");
			
			System.out.println("    " + school.getName() + "学生信息管理系统");
			System.out.println("   学号       姓名     性别   状态");
			System.out.println(s1.getSchoolNumber() + "    " + s1.getStdentsName() + "    " + s1.getSex() + "    " + s1.getLearnState());
		} else {
			System.out.println("用户名或密码错误");
		}
	}
}
