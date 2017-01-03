package com.sims.dao.domain;

import java.util.Date;

public class AInfo {
	private String no; // 组织机构编号或学号
	private String name; // 名字
	private String note; // 备注
	private String picture; // 照片存储路径
	private Date birthday; // 出生年月
	private Date year; // 入学年份
	private Integer duration; // 学制
	private Integer war; // 在校、休学、退学、毕业
	private String superior; // 上级组织编号

	public AInfo() {
	}

	/*
	 * 参数数为3的构造方法 为专业、班级类对象调用
	 */
	public AInfo(String no, String name, String superior) {
		this(no, name, superior, "");
	}

	/*
	 * 参数数为4的构造方法
	 */
	public AInfo(String no, String name, String superior, String note) {
		this.setNo(no);
		this.setName(name);
		this.setSuperior(superior);
		this.setNote(note);
	}

	/*
	 * 参数数为7的构造方法 为学生类服务
	 */
	public AInfo(String no, String name, String superior, Date year, Integer duration, Integer war, Date birthday) {
		this(no, name, superior, year, duration, war, birthday, "");
	}

	/*
	 * 参数数为8的构造方法
	 */
	public AInfo(String no, String name, String superior, Date year, Integer duration, Integer war, Date birthday,
			String picture) {
		this(no, name, superior, year, duration, war, birthday, picture, "");
	}

	/*
	 * 参数数为9的构造方法
	 */
	public AInfo(String no, String name, String superior, Date year, Integer duration, Integer war, Date birthday,
			String picture, String note) {
		this.setNo(note);
		this.setName(name);
		this.setNote(note);
		this.setBirthday(birthday);
		this.setYear(year);
		this.setDuration(duration);
		this.setWar(war);
		this.setSuperior(superior);
		this.setPicture(picture);
	}

	public String getNo() {
		return no;
	}

	public void setNo(String no) {
		this.no = no;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getNote() {
		return note;
	}

	public void setNote(String note) {
		this.note = note;
	}

	public String getPicture() {
		return picture;
	}

	public void setPicture(String picture) {
		this.picture = picture;
	}

	public java.sql.Date getBirthday() {

		return new java.sql.Date(birthday.getTime());
	}

	public void setBirthday(Date birthday) {
		this.birthday = birthday;
	}

	public java.sql.Date getYear() {
		return new java.sql.Date(year.getTime());
	}

	public void setYear(Date year) {
		this.year = year;
	}

	public int getDuration() {
		return duration;
	}

	public void setDuration(Integer duration) {
		this.duration = duration;
	}

	public int getWar() {
		return war;
	}

	public void setWar(Integer war) {
		this.war = war;
	}

	public String getSuperior() {
		return superior;
	}

	public void setSuperior(String superior) {
		this.superior = superior;
	}

}
