package com.hpf.math;

public class MultiplicationTable {

	public static void main(String[] args) {
	/**
	 * 九九乘法表
	 */
		for (int index = 1; index <= 9; index++) {
			for (int count = 1; count <= index; count++) {
				System.out.print(count + " * " + index + " = " + (index * count) + "\t");
			}
			System.out.println();
		}
	}

}
