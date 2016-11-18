public class TestOne {
	public static void main(String args[]) {
		int array[] = new int[10];
		ChuShiHua(array);
		print(array);
		System.out.println("================================= 转换后 =======================================");
		ZhuanHuan(array);
		print(array);
	}
	
	public static void print (int arr[]) {
		for (int index = 0; index < arr.length; index++) {
			System.out.print(arr[index] + "\t");
		}
		System.out.println();
	}

	public static void ChuShiHua(int arr[]) {
		for (int index = 0; index < arr.length; index++) {
			arr[index] = index;
		}
	}

	public static void ZhuanHuan(int arr[]) {
		for (int count = 0, index = arr.length - 1; index >= arr.length / 2; count++, index--) {
			int temp = arr[count];
			arr[count] = arr[index];
			arr[index] = temp;
		}
	}
}
