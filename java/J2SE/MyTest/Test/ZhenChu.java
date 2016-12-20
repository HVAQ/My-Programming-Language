public class ZhenChu {
	public static void main(String args[]) {
		int num = 0;
		int count = 0;

		System.out.println("1~1000内能同时被3、5、7整除的数有: ");
		while (num <= 1000) {
			if (num % 3 == 0 && num % 5 == 0 && num % 7 == 0) {
				System.out.print(num + "\t");
				count++;
			}
			num++;
		}
		System.out.println("\n一共有" + count + "个。");
	}
}
