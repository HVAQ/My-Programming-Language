package com.study.three;

public class Six {

	public static void main(String[] args) {
		int sum = 0;
		for (int num = 13, index = 0; num < 1003; num += 10, index++) {
			if (index % 2 == 0) {
				sum += num;
			} else {
				sum -= num;
			}
		}
		System.out.println(sum);
	}

}
