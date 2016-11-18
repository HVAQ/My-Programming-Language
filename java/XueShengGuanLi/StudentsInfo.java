public class StudentsInfo {

	private String school;
	private String xibie;
	private String zhuanye;
	private int banji;
	private String snum;
	private String sname;
	private int sage;

	// 系别、专业、学号、姓名
	public Students(String xibie, String zhuanye, String snum, String sname) {
		Students("山西工程技术学院", xibie, zhuanye, 1, snum, sname, 0);
	}

	// 系别、专业、班级、学号、姓名
	public Students(String xibie, String zhuanye, int banji, String snum, String sname) {
		Students("山西工程技术学院", xibie, zhuanye, banji, snum, sname, 0);
	}
	
	// 系别、专业、班级、学号、姓名、年龄
	public Students(String xibie, String zhuanye, int banji, String snum, String sname, int sage) {
		Students("山西工程技术学院", xibie, zhuanye, banji, snum, sname, sage);
	}

	// 学校、系别、专业、班级、学号、姓名
	public Students(String school, String xibie, String banji, String snum, String sname) {
		Students(school, xibie, zhuanye, banji, snum, sname, 0);
	}

	// 学校、系别、专业、班级、学号、姓名、年龄
	public Students(String school, String xibie, String zhuanye，int banji, String snum, String sname, int sage) {
		this.school = school;
		this.xibie = xibie;
		this.zhuanye = zhuanye;
		this.banji = banji;
		this.snum = snum;
		this.sname = sname;
		this.sage = sage;
	}

	public void setSchool(String school) {
		this.school = school;
	}

	public String getSchool() {
		return this.school;
	}

	public void setXiebie(String xibie) {
		this.xibie = xibie;
	}

	public String getXiebie() {
		return this.xibie;
	}
	
	public void setZhuanye(String zhuanye) {
		this.zhuanye = zhuanye;
	}

	public String getZhuanye() {
		return this.zhuanye;
	}

	public void setBanji(int banji) {
		if (banji >= 1 && banji % 1 == 0)
			this.banji = banji;
	}

	public int getBanji() {
		return this.banji;
	}
	
	public void setSnum(String snum) {
		this.snum = snum;
	}

	public String getSnum() {
		return this.snum;
	}
	
	public void setSname(String sname) {
		this.sname = sname;
	}

	public String getSname() {
		return this.sname;
	}

	public void setSage(int sage) {
		if (sage >= 0)
			this.sage = sage;
	}

	public int getSage() {
		return this.sage;
	}

	public String getInfo() {
		return "学校：" + this.school + 
			"系别：" + this.xibie +
			"专业：" + this.zhuanye +
			"班级：" + this.banji +
			"学号：" + this.snum +
			"姓名：" + this.sname +
			"年龄：" + this.sage;
	}
}
