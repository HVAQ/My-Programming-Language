public class UserInfo {

	private String username;
	private String password;

	public UserInfo() {

		this.username = "admin";
		this.password = "admin";
	}

	public boolean setUserName(String username) {

		if (username != null) {
			this.username = username;
			System.out.println("用户名是: " + username);
			return true;
		}
		else
			return false;
	}

	public String getUserName() {
		return username;
	}

	public void setPassword(String password) {

		if (password != null){
			this.password = password;
			System.out.println("用户密码是: " + password);
		}
	}

	public String getPassword() {
		return password;
	}
}