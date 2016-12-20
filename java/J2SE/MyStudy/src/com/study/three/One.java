package com.study.three;

public class One {
	public static void main(String[] args) {
		System.out.print("1-10000内的水仙花数有：");
		for (int index = 1; index < 10000; index++) {
			int temp_one = index / 1000;					// 千位
			int temp_two = (index % 1000) / 100;			// 百位
			int temp_three = ((index % 1000) % 100) / 10; 	// 十位
			int temp_four = ((index % 1000) % 100) % 10;		// 个位
			if (count(temp_one) + count(temp_two) + count(temp_three) + count(temp_four) == index) {
				System.out.print(index + "、");
			}
		}
		System.out.println();
	}
	public static int count(int num) {
		return num * num * num;
	}
}
