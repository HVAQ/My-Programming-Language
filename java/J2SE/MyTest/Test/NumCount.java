public class NumCount {
	public static void main(String args[]) {
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 
			0, 5, 2, 5, 7, 8, 2, 3, 2, 4, 
			5, 6, 7, 1, 0, 5, 6, 7, 8, 9};
		Count(arr);
	}

	public static void Count(int arr[]) {
		for (int index = 0; index <= 9; index++) {
			int num = 0;
			for (int count = 0; count < arr.length; count++) {
				if (index == arr[count])
					num++;
			}
			System.out.println(index + "出现" + num + "次");
		}
	}
}
