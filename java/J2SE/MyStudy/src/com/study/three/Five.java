package com.study.three;

public class Five {
	public static void main(String[] args) {
		int sum_one = 0;
		int num_one = 100;
		while (num_one <= 200) {
			sum_one += num_one;
			num_one++;
		}
		System.out.println("100到200的累加和是" + sum_one);
		int sum_two = 0;
		int num_two = 100;
		do {
			sum_two += num_two;
			num_two++;
		} while (num_two <= 200);
		System.out.println("100到200的累加和是" + sum_two);
		int sum_three = 0;
		for (int num_three = 100; num_three <= 200; num_three++) {
			sum_three += num_three;
		}
		System.out.println("100到200的累加和是" + sum_three);
	}
}
