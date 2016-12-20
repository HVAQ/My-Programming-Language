package com.study.eleven;

import java.util.Random;

public class Four {

	public static void main(String[] args) {
		final int MAX = 1000;
		Random rd = new Random();
		int count = 0;
		for (int index = 0; index < MAX; index++) {
			if (rd.nextInt(2) == 0) {
				count++;
			}
		}
		System.out.println("正面次数" + count);
		System.out.println("反面次数" + (MAX - count));
	}

}
