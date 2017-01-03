package com.sims.dao.domain;

public class Classes extends AInfo {
	public static final String childTableNmae = "students";

	public Classes() {
	}

	public Classes(String no, String name, String specialityNo) {
		this(no, name, specialityNo, "");
	}

	public Classes(String no, String name, String specialityNo, String note) {
		super(no, name, specialityNo, note);
	}
}
