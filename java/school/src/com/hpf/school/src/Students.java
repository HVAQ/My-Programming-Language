package com.hpf.school.src;

public class Students {
	
	private String SchoolNumber;
	private String StudentsName;
	private String Sex;
	private String LearnState;  //状态——在读、休学、退学、毕业

	public Students (String schoolNumber, String studentsName,
			String sex, String learnState) {
		this.SchoolNumber = schoolNumber;
		this.StudentsName = studentsName;
		this.Sex = sex;
		this.LearnState = learnState;
	}
	
	public String getSchoolNumber() {
		return SchoolNumber;
	}
	
	public String getStdentsName() {
		return StudentsName;
	}
	
	public String getSex() {
		return Sex;
	}
	
	public String getLearnState() {
		return LearnState;
	}
}
