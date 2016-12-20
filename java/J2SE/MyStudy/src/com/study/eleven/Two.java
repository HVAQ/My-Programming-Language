package com.study.eleven;

import java.util.Random;

public class Two {

	public static void main(String[] args) {
		Random rd = new Random();
		int index = 0;
		while (index < 5) {
			System.out.print(rd.nextInt(31));
			if (index != 4) {
				System.out.print("、");
			}
			index++;
		}
	}

}
