public class QiuHeTwo {
	// 求13 - 23 + 33 - 43 +...+ 973 - 983 + 993 - 1003的值
	public static void main(String args[]) {
		int shi = 1;
		int ge = 3;
		int sum = 0;

		while (shi <= 100) {
			int num = shi * 10 + ge;
			if (shi % 2 == 0)
				sum -= num;
			else
				sum += num;
			shi++;
		}
		System.out.println("累加和是: " + sum);
	}
}
