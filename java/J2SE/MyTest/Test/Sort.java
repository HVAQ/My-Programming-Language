public class Sort {
	public static void main(String args[]) {
		int arr_one[] = {1, 7, 9, 11, 13, 15, 17, 19};
		int arr_two[] = {2, 4, 6, 8, 10};
		int arr_three[] = addArray(arr_one, arr_two);
		java.util.Arrays.sort(arr_three);
		print(arr_three);
	}

	public static int [] addArray(int arr_one[], int arr_two[]) {
		int arr_three[] = new int[arr_one.length + arr_two.length];
		System.arraycopy(arr_one, 0, arr_three, 0, arr_one.length);
		System.arraycopy(arr_two, 0, arr_three, arr_one.length, arr_two.length);
		return arr_three;
	}

	public static void print(int arr[]) {
		for (int index = 0; index < arr.length; index++) {
			System.out.print(arr[index] + "\t");
		}
		System.out.println();
	}
}
