package com.hpf.test;

class Single {
	private String name;
	private int age;
	private static final Single singleCase = new Single("韩鹏飞", 21);
	private Single(String name, int age) {
		this.setName(name);
		this.setAge(age);
	}
	public static Single getSingle() {
		return singleCase;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getName() {
		return name;
	}
	public int getAge() {
		return age;
	} 
	@Override
	public String toString() {
		return "姓名: " + this.getName() + ", 年龄: " + this.getAge();
	}
}
public class SingleCase {

	public static void main(String[] args) {
		Single s1 = Single.getSingle();
		Single s2 = Single.getSingle();
		Single s3 = Single.getSingle();
		System.out.println(s1);
		System.out.println(s2);
		System.out.println(s3);
	}

}
