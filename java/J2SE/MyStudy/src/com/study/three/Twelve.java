package com.study.three;

public class Twelve {

	public static void main(String[] args) {
		int max = 5;
		for (int index = 0; index < max; index++) {
			printSpace(index, max);
			print(index);
		}
	}
	public static void printSpace(int index, int max) {
		int num = ((2 * max - 1) - 2 * index) / 2;
		for (int count = 0; count < num; count++) {
			System.out.print(" ");
		}
	}
	public static void print(int index) {
		for (int count = 0; count < index + 1; count++) {
			System.out.print("* ");
		}
		System.out.println();
	}

}
