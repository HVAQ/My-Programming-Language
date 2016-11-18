public class ForXin {
	public static void main(String args[]) {
		int max = 6;

		for (int index = 1; index <= max; index++) {
			// 打印空格
			for (int num = 0; num < max - index; num++)
				System.out.print(" ");
			// 打印 * 号
			for (int count = 0; count < 2 * index - 1; count++) {
				System.out.print("*");
			}
			System.out.println();
		}
	}
}
