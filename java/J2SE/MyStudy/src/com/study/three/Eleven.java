package com.study.three;

public class Eleven {

	public static void main(String[] args) {
		int sum = 0;
		for (int index = 1; index <= 20; index++) {
			for (int count = 1; count < index; count++) {
				sum += count;
			}
			System.out.print(index);
			if (index != 20) {
				System.out.print("! + ");
			} else {
				System.out.print("! = ");
			}
		}
		System.out.println(sum);
	}

}
