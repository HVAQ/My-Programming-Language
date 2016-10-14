import java.util.Scanner;

public class Index {

	static Scanner sc = new Scanner(System.in);

	public static int Getchoose() {

		System.out.println("**********************");
		System.out.println("       请选择");
		System.out.println("1) 登录     2) 设置用户");
		System.out.println("3) 退出");
		System.out.println("**********************");
		
		int choose = sc.nextInt();

		return choose;
	}

	public static void main(String[] args) {

		int choose = 2;
		String username;
		String password;

		UserInfo info = new UserInfo();
		
		while (choose != 3) {
			if (choose == 1) {
				System.out.println("请输入用户名");
				username = sc.nextLine();
				System.out.println("请输入密码");
				password = sc.nextLine();

				if (!info.equals(username) || !info.equals(password))
					System.out.println("用户名或密码错误");
				else
					System.out.println(username + "登录成功");
			} else if (choose == 2) {
				System.out.println("请设置用户名");
				username = sc.nextLine();

				if (info.setUserName(username)) {
					System.out.println("请设置用户密码");
					password = sc.nextLine();

					if (password == null)
						System.out.println("默认密码为password");
					else
						info.setPassword(password);
				}
				else
					System.out.println("账户设置错误，请检查");
			}
			choose = Getchoose();
		}

		if (choose == 3)
			System.out.println("再见");
	}
}