public class ShuZuChaoZuo {
	public static void main(String args[]) {
		int array[] = {23, 45, 67, 89, 21, 32, 45, 65};
		System.out.println("数组元素和为" + sum(array) + "，最大值为" + getMax(array) + "，最小值为" + getMin(array));
	}

	public static int sum(int array[]) {
		int sum = 0;
		for (int index = 0; index < array.length; index++)
			sum += array[index];
		return sum;
	}

	public static int getMin(int array[]) {
		int min = array[0];
		for (int index = 0; index < array.length; index++) {
			if (array[index] < min)
				min = array[index];
		}
		return min;
	}

	public static int getMax(int array[]) {
		int max = array[0];
		for (int index = 0; index < array.length; index++) {
			if (array[index] > max)
				max = array[index];
		}
		return max;
	}
}
