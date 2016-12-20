public class ChaShu {
	public static void main(String args[]) {
		int arr[] = {23, 45, 67, 89, 76, 54, 32, 21, 55, 66};
		int num = 99;
		if (inArray(num, arr)) {
			System.out.println("数字 " + num + " 在数组中存在。");
		} else {
			System.out.println("数字 " + num + " 在数组中不存在。");
		}
	}

	public static boolean inArray(int num, int array[]) {
		for (int index = 0; index < array.length; index++) {
			if (num == array[index])
				return true;
		}
		return false;
	}
}
