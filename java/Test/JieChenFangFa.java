public class JieChenFangFa {
	public static void main(String args[]) {
		System.out.println("1! + 2! + ...... + 30! = " + Sum(30));
	}

	public static long JieChen(int index) {
		// 计算index 的阶乘
		long product = 1;
		for(int num = 1; num <= index; num++)
			product *= num;
		return product;
	}

	public static long Sum(int num) {
		int index = 1;
		// 阶乘结果的累加
		long sum = 0;
		while (index < num) {
			sum += JieChen(index);
			index++;
		}
		return sum;
	}
}
