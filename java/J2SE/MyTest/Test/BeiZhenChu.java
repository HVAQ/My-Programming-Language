public class BeiZhenChu {
	public static void main(String args[]) {
		int num = 1;

		if (num % 3 == 0 && num % 5 == 0 && num % 7 == 0) {
			System.out.println("能被3、5、7同时整除。");
		} else {
			System.out.println("不能被3、5、7同时整除。");
		}
	}
}
