public class XinShuZu {
	public static void main(String args[]) {
		int oldArr[] = {2, 3, 4, 0, 7, 0, 5, 9, 4, 0, 23, 0};
		System.out.print("新数组是：");
		for (int index = 0; index < noZero(oldArr).length; index++)
			System.out.print(noZero(oldArr)[index] + "\t");
		System.out.println();
	}

	public static int [] noZero(int []array) {
		int num = 0;

		for (int index = 0; index < array.length; index++)
			if (array[index] != 0)
				num++;
		int newArr[] = new int[num];
		for (int index = 0, count = 0; index < array.length; index++)
			if (array[index] != 0) {
				newArr[count] = array[index];
				count++;
			}
		return newArr;
	}
}
