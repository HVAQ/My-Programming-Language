public class QiuHe {
	public static void main(String args[]) {
		int sum = 0;
		
		int num = 100;
		while (num < 200) {
			sum += num;
			num++;
		}
		System.out.println("while循环和" + sum);

		num = 100;
		sum = 0;
		do {
			sum += num;
			num++;
		} while(num < 200);
		System.out.println("do...while循环和" + sum);

		for (num = 100, sum = 0; num < 200; num++) {
			sum += num;
		}
		System.out.println("for循环和"+ sum);
	}
}
