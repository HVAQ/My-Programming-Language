package com.study.three;

public class Three {

	public static void main(String[] args) {
		int []a = new int[] {8, 10, 5};
		int max = a[0];
		for (int index = 1; index < a.length; index++) {
			if (max < a[index]) {
				max = a[index];
			}
		}
		System.out.println(max);
	}

}
