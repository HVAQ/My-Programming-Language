public class User {

	private String userName;
	private String userPwd;
	private enum quanXian = {noramlUser, normalAdmin, superAdmin};

	public UserSet(String userName) {
		this(userName, "password", noramlUser);
	}

	public UserSet(String userName, String userPwd) {
		this(userName, userPwd, noramlUser);
	}

	private UserSet(String userName, String userPwd, int quanXian) {
		this.userName = userName;
		this.userPwd = userPwd;
		this.quanXian = quanXian;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public String getUserName() {
		return this.userName;
	}
	
	public void setUserPwd(String userPwd) {
		if (!isDefault(userPwd))
			this.userPwd = userPwd;
	}

	public String getUserPwd() {
		return this.userPwd;
	}

	public String getInfo() {
		return "用户名：" + this.userName +
			"密码：" + this.userPwd;
	}

	public void addUser(String userName, String userPwd) {
	}

	private boolen isDefault(String userPwd) {
		if (userPwd.equals("password"))
			return false;
		else
			return false;
	}
}
