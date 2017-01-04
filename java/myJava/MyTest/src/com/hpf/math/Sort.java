package com.hpf.math;

public class Sort {
	public static void main(String[] args) {
		int array[] = {4, 78, 82, 75, 22, 92, 12, 25, 66, 8, 3};
		insertSort(array);
		print(array);
	}
	/**
	 * 冒泡排序法
	 * 原理：将相邻的两个值进行比较，如果前面的值大于后面的值，则进行位置交换<br>
	 * <li>其思想在于，相邻两个值中，较小值每次向前移动的步长为1<br>
	 * <li>序列分为有序区和无序区，随着比较的进行，有序区逐渐扩大，无序区逐渐减小<br>
	 * <li>直到整个序列变得有序<br>
	 * <li>时间复杂度为
	 * <li>O(n * (n - 1))，n = array.length<br>
	 */
	public static void bubbleSort(int[] array) {
		for (int index = 0; index < array.length; index++) {
			for (int count = 0; count < array.length - 1; count++) {
				if (array[count] > array[count + 1]) {
					forTemp(array, count, count + 1);
				}
			}
		}
	}
	/**
	 * 快速排序法
	 * 原理：在序列中确定一个轴值，将序列分为左右区域<br>
	 * <li>轴值作为排序的基准<br>
	 * <li>轴值的左边都应小于或等于轴值<br>
	 * <li>轴值的右边都应大于或等于轴值<br>
	 * <li>依次对由轴值划分的序列左右区域进行上述步骤<br>
	 * <li>直到序列全部排序<br>
	 */
	public static void quickSort(int[] array, int first, int end) {
		if (first < end) {
			int middle = forQuickSort(array, first, end);
			quickSort(array, first, middle - 1);		// 利用递归，为轴值左边进行排序
			quickSort(array, middle + 1, end);		// 利用递归，为轴值右边进行排序
		}
	}
	private static int forQuickSort(int[] array, int first, int end) {
		int middle = array[first];	// 将序列首元素作为轴值
		while (first < end) {
			while (first < end && array[end] >= middle) {	// 右区域扫描
				end--;
			}
			if (first < end) {
				forTemp(array, first, end);
			}
			while (first < end && array[first] <= middle) {	// 左区域扫描
				first++;
			}
			if (first < end) {
				forTemp(array, first, end);
			}
		}
		return first;		// 返回轴值所在的位置
	}
	/**
	 * 选择排序法
	 * 原理：在序列中划分有序区和无序区<br>
	 * <li>在无序区中选择最小值，插入到有序区<br>
	 * <li>期间，最小值的最大移动步长为：无序区的长度 -1<br> 
	 * <li>直到序列全部变为有序区<br>
	 * <li>时间复杂度为<br>
	 * <li>O(n - 1), n = array.length<br>
	 */
	public static void selectSort(int []array) {
		for (int index = 0; index < array.length - 1; index++) {
			int min = index;		// 记录无序区最小值的索引
			/*
			 * 其起始循环节点索引为无序区的首节点 
			 * 循环极限为序列（无序区）的尾节点的索引
			 */
			for (int count = index; count < array.length; count++) {		// 遍历无序区
				if (array[count] < array[min]) {
					min = count;
				}
			}
			if (min != index) {		// 将最小值与array[index]交换
				forTemp(array, min, index);
			}
		}
	}
	/**
	 * 插入排序法
	 * 原理：
	 * <li>设置要插入值的前一个元素为关键码（初始化为数组的首元素）<br>
	 * <li>依照关键码，将数组分为有序区与无序区<br>
	 * <li>遍历有序区，寻找适合于值插入的位置，将值插入<br>
	 * <li>直到关键码为数组的尾元素，无序区为空<br>
	 * @param array 待排序数组
	 */
	public static void insertSort(int[] array) {
		for (int index = 1; index < array.length; index++) {
			int temp = array[index];		// 要插入的值
			int count;		// count + 1 用于记录要插入值的插入位置
			for (count = index - 1; count >= 0 
					&& temp < array[count]; count--) {		// 遍历有序区
				array[count + 1] = array[count];
			}
			array[count + 1] = temp;		// 此处的count + 1为上部循环中的count，从位置此时为空
		}
	}
 		
	private static void forTemp(int []array, int first, int end) {
		array[first] = array[first] ^ array[end];
		array[end] = array[first] ^ array[end];
		array[first] = array[first] ^ array[end];
	}
	private static void print(int []array) {
		for (int num: array) {
			System.out.print(num + " ");
		}
		System.out.println();
	}
}
