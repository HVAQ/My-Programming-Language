package com.hpf.math;

public class YangHuiTriangle {

	public static void main(String[] args) {
	/**
	 * 杨辉三角
	 */
		int triangle[][] = new int[8][];		// 创建二位数组
		for (int index = 0; index < triangle.length; index++) {
			triangle[index] = new int[index + 1];	// 初始化第二层数组大小
			for (int count = 0; count < triangle[index].length; count++) {
				if (index == 0 || count == 0 || count == triangle[index].length - 1) {
					triangle[index][count] = 1;
				} else {
					triangle[index][count] = triangle[index - 1][count] + triangle[index -1][count - 1];
				}
				System.out.print(triangle[index][count] + "\t");
			}
			System.out.println();
		}
	}

}
