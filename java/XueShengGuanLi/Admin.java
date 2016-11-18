class Admin {
	private String aid;
	private String name;
	private String password;

	public Admin() {}

	public Admin(String name, String password) {
		this.name = name;
		this.password = password;
	}

	public Admin(String aid, String name, String password) {
		this.aid = aid;
		this.name = name;
		this.password = password;
	}

	public void setAid(String aid) {
		this.aid = aid;
	}

	public String getAid() {
		return this.aid;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getName() {
		return this.name;
	}

	public void setpassword(String password) {
		this.password = password;
	}

	public String getPassword() {
		return this.password;
	}

	public String getInfo() {
		return "用户ID" + this.aid +
			"用户名：" + this.name;
	}
}
