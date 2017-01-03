package com.sims.dao.domain;

import java.util.Date;

public class Students extends AInfo {

	public Students() {
	}

	public Students(String no, String name, String ClassNo, Date year, Integer duration, Integer war, Date birthday) {
		this(no, name, ClassNo, year, duration, war, birthday, "");
	}

	public Students(String no, String name, String ClassNo, Date year, Integer duration, Integer war, Date birthday,
			String picture) {
		this(no, name, ClassNo, year, duration, war, birthday, picture, "");
	}

	public Students(String no, String name, String ClassNo, Date year, Integer duration, Integer war, Date birthday,
			String picture, String note) {
		super(no, name, ClassNo, year, duration, war, birthday, picture, note);
	}

}
