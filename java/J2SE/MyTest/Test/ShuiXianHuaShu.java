public class ShuiXianHuaShu {
	// 打印1~1000范围内的水仙花数
	// 水仙花数是指一个三位数，其各位数字的立方和等于该数本身
	public static void main(String args[]) {
		int count = 0;

		System.out.println("1~1000内的水仙花数有:");
		for (int bai = 0; bai < 10; bai++) {
			for (int shi = 0; shi < 10; shi++) {
				for (int ge = 0; ge < 10; ge++) {
					int num = bai * 100 + shi * 10 + ge;

					if (num == bai * bai * bai + shi * shi * shi + ge * ge * ge) {
						System.out.println("num = " + num);
						count++;
					}
				}
			}
		}
		System.out.println("一共是" + count + "个。");
	}
}
