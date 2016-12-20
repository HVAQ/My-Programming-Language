package com.hpf.Test;

import com.hpf.tools.Link;

public class TestLink {

	public static void main(String[] args) {
		Link<String> school = new Link<String>("山西工程技术学院");
		school.add("采矿系");
		school.add("地测系");
		school.add("建工系");
		school.add("机电系");
		school.add("管理系");
		school.add("社科系");
		school.add("信息系");
		school.add("经贸系");
//		school.change("不知系", "矿业系");
//		System.out.println(school.find("不知系"));
//		print(school);
		school.showAll();
		System.out.println("有成员数" + school.getNum());
	}
	
	public static void print(Link<?> link) {
		for (int index = 0; index < link.getNum(); index++) {
			System.out.println(index + 1 + "\t" + link.find(index));
		}
	}
}
