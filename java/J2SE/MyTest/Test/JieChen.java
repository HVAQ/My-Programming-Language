public class JieChen {
	public static void main(String args[]) {
		int max = 1;
		long product = 0;

		while (max <= 20) {
			long sum = 1;
			for (int num = 1; num <= max; num++)
				sum *= num;
			product += sum;
			max++;
		}
		System.out.println("1! + 2! + 3! ... 20! = " + product);
	}
}
