package com.hpf.math;

import java.util.Scanner;

public class Hanoi {
	/**
	 * 汉诺塔
	 * 古典数学问题：古代有一个梵塔，塔内有3个座，即A、B、C<br>
	 * <li>有64个盘子，大小不等，大的在最下面，小的在最上面<br>
	 * <li>现要将64个盘子从A座移到C座<br>
	 * <li>每次只能移一个盘子，且移动过程中，在3座上都要保持大的在下，小的在上<br>
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入要移动的盘子个数");
		int count = sc.nextInt();
		sc.close();
		hanoi(count, 'A', 'B', 'C');
	}
	/**
	 * 移动盘子
	 * @param x 现在盘子在x塔上
	 * @param y 盘子移动到y塔上
	 */
	public static void move(char x, char y) {
		System.out.printf("%c --> %c", x, y);
		System.out.println();
	}
	/**
	 * 借助塔B将盘子由A塔移动到B塔
	 * @param count 要移动的盘子的个数
	 * @param x,y,z A、B、C三座塔
	 */
	public static void hanoi(int count, char one, char two, char three) {
		/*
		 * 利用了递归的先进后出的机制
		 */
		if (count == 1) {
			move(one, three);
		} else {
			hanoi(count - 1, one, three, two);		// 借助C座将盘子由A移动到B
			move(one, three);
			hanoi(count - 1, two, one, three);		// 借助A座将盘子由B移动到C
		}
	}
}
