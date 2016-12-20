package com.hpf.Test;

import com.hpf.tools.MyArrays;

public class TestArraysSort {

	public static void main(String[] args) {
		int num[] = new int[] {1, 5, 6, 3, 2, 9, 666, 532, 10, 35, 88, 62, 32};
		int num_two[] = new int[]{3, 6};
		MyArrays.arraysSort(num);
		for (int index = 0; index < num.length; index++) {
			System.out.print(num[index]);
			if (index != num.length - 1) {
				System.out.print("、");
			}
		}
		System.out.println();
		System.out.println(MyArrays.twoPointSearch(num_two, 6));
	}
}
