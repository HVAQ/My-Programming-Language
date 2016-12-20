package com.hpf.tools;
/**
 * 我的工具类——数组操作
 * @author whoami
 * 2016.12.05
 */
public class MyArrays {
	/**
	 * int 型数组排序功能
	 * @param arrays 要排序的数组
	 */
	public static void arraysSort(int[] arrays) {
		for (int index = 0; index < arrays.length - 1; index++) {
			for (int count = index; count < arrays.length; count++) {
				try {
					int min = arrays[index];
					if (arrays[count] < min) {
						int temp = arrays[count];
						arrays[count] = arrays[index];
						arrays[index] = temp;
						}
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
	}
	/**
	 * 二分查找
	 * @param arrays 要查找的数组
	 * @param num 要查找的值
	 * @return 当 num 在 arrays 数组中存在时，返回其对应索引，否则返回-1
	 */
	public static int twoPointSearch(int[] arrays, int num) {
		// 设置数组长度下限
		if (arrays.length < 1) {
			return -1;
		}
		try {
			if (arrays.length == 1) {
				if (num == arrays[0]) {
					return 0;
				} else {
					return -1;
				}
			}
			arraysSort(arrays);		// 调用本类排序方法对数组进行排序
			int minIndex = 0;
			int maxIndex = arrays.length - 1;
			for (int index = 0; index < arrays.length / 2; index++) {
				// 理论上，通过与二分首尾相比较，可以在数组长度足够长时，提升一定的性能
				if (num == arrays[minIndex]) {
					return minIndex;
				} else if (num == arrays[maxIndex]) {
					return maxIndex;
				}
				int middleIndex = (minIndex + maxIndex) / 2;
				int middle = arrays[middleIndex];		// 设置中间值
				if (num > middle) {
					minIndex = middleIndex;
				} else if (num < middle) {
					maxIndex = middleIndex;
				} else {
					return middleIndex;
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return -1;
	}
}
