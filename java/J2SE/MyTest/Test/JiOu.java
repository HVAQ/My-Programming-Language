public class JiOu {
	public static void main(String args[]) {
		int array[] = {23, 45, 67, 88, 65, 45, 32, 12};
		System.out.println("有偶数" + OuNum(array) + "个，基数" + JiNum(array) + "个。");
	}

	public static int JiNum(int array[]) {
		int num = 0;
		for (int index = 0; index < array.length; index++) {
			if (array[index] % 2 != 0)
				num++;
		}
		return num;
	}

	public static int OuNum(int array[]) {
		int num = 0;
		for (int index = 0; index < array.length; index++) {
			if (array[index] % 2 == 0)
				num++;
		}
		return num;
	}
}

