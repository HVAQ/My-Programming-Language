public class AddNum {
	public static void main(String args[]) {
		int arr[] = {2, 34, 56, 87, 59, 32, 46, 22};
		int array[] = contact(arr);
		java.util.Arrays.sort(array);
		print(array);
	}

	public static int [] contact (int arr[]) {
		int x = 35;
		int array[] = new int[arr.length + 1];
		System.arraycopy(arr, 0, array, 0, arr.length);
		array[arr.length] = x;
		return array;
	}

	public static void print(int arr[]) {
		for (int index = 0; index < arr.length; index++) {
			System.out.print(arr[index] + "\t");
		}
		System.out.println();
	}
}
