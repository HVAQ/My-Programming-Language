package com.hpf.math;
/*
 * 打印空心菱形
 */
public class Diamond {
	public static void main(String[] args) {
		printHellowRhombus(10);
	}
	/**
	 * 通过循环实现菱形的打印
	 * @param size 菱形的宽、高的长度
	 */
	public static void printHellowRhombus(int size) {
		if (size <= 0) {
			/*
			 * 控制打印边界
			 */
			System.out.println("不能打印长、宽为" + size + "菱形。");
			System.exit(1);
		}
		if (size % 2 == 0) {
			size += 1;		// 使size为奇数，达到能上下、左右对齐的目的
		}
		/*
		 * 菱形上部
		 */
		for (int count = 0; count <= size / 2; count++) {
			print(count, size);
		}
		/*
		 * 菱形下部
		 */
		for (int count = size / 2 - 1; count >= 0; count--) {
			print(count, size);
		}			
	}	
	public static void print(int count, int size) {
		/*
		 * 左边空格数为：size / 2 - count
		 * 右边空格数为：size / 2 - count
		 * 因为size为奇数，故而（size - 左边空格数 - 右边空格数）= 1
		 * 即，不为首行、尾行时，中间空格数为（size - 2 (size / 2 - count) - 2 + 1 )
		 * 为：2 * count - 1
		 */
		for (int index = 0; index < size / 2 - count; index++) {
			System.out.print(" ");
		}
		System.out.print("*");
		/*
		 * 不为首行、尾行时，打印中间空格
		 * 打印中间空格
		 */
		if (count != 0) {
			for (int index = 0; index < count * 2 - 1; index++) {
				System.out.print(" ");
			}
			System.out.print("*");
		}
		System.out.println();
	}
}
