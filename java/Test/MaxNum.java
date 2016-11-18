public class MaxNum {
	public static void main(String args[]) {
		int arr[] = {12, 34, 56, 78, 98, 65, 43, 45, 87, 31};
		print(arr);
		System.out.println("================================= 置换后 =================================");
		max(arr);
		print(arr);
	}

	public static void print(int array[]) {
		for (int index = 0; index < array.length; index++) {
			System.out.print(array[index] + "\t");
		}
		System.out.println();
	}

	public static void max(int array[]) {
		int count = 0;
		for (int index = 0; index < array.length; index++) {
			int max = array[count];
			if (array[index] > max) {
				max = array[index];
				count = index;
			}
		}
		int temp = array[count];
		array[count] = array[0];
		array[0] = temp;
	}
}
