package com.sims.dao.domain;

public class Specialities extends AInfo {
	public static final String childTableNmae = "classes";

	public Specialities() {
	}

	public Specialities(String no, String name, String departmentNo) {
		this(no, name, departmentNo, "");
	}

	public Specialities(String no, String name, String departmentNo, String note) {
		super(no, name, departmentNo, note);
	}

}
