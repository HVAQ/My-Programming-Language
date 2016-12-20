package com.study.eleven;

import java.util.Arrays;

class Student implements Comparable<Object> {
	private String name;
	private int age;
	private int achievement;
	public Student(String name, int age, int achievement) {
		this.setName(name);
		this.setAge(age);
		this.setAchievement(achievement);
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public int getAchievement() {
		return achievement;
	}
	public void setAchievement(int achievement) {
		this.achievement = achievement;
	}
	@Override
	public int compareTo(Object o) {
		Student student = (Student) o;
		if (this.getAchievement() > student.getAchievement()) {
			return -1;
		} else if (this.getAchievement() < student.getAchievement()) {
			return 1;
		} else if (this.getAge() > student.getAge()) {
			return 1;
		} else if (this.getAge() < student.getAge()) {
			return -1;
		} else {
			return 0;
		}
	}
	@Override
	public String toString() {
		return this.getName() + ":" + this.getAge() + ":" + this.getAchievement();
	}
}
public class Eight {

	public static void main(String[] args) {
		Student []students = new Student[] {
				new Student("张三", 21, 89),
				new Student("李四", 22, 98),
				new Student("王五", 20, 70),
				new Student("赵六", 19, 89),
				new Student("孙七", 19, 70),
				};
		Arrays.sort(students);
		for (int index = 0; index < students.length; index++) {
			System.out.print(students[index].toString());
			if (index != students.length - 1) {
				System.out.print("|");
			}
		}
		System.out.println();
	}

}
