package com.sims.dao.domain;

public class School extends AInfo {
	public static final String childTableNmae = "departments";
	private static School school = new School();
	
	private School(){
		super("045000", "山西工程技术学院", "山西省阳泉市");
	}
	public static School getSchool() {
		return school;
	}
}