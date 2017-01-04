package com.hpf.math;

import java.math.BigDecimal;

public class Example {

	public static void main(String[] args) {
	/**
	 * 计算1+1/2!+1/3!...1/20!
	 */
		BigDecimal sum = new BigDecimal(0.0);	// 和
		BigDecimal factorial = new BigDecimal(1.0);	// 阶乘计算结果
		int index = 1;
		while (index <= 20) {
			sum = sum.add(factorial);
			index++;
			// 阶乘的计算
			factorial = factorial.multiply(new BigDecimal(1.0 / index));
		}
		System.out.println("1+1/2!+1/3!...1/20!的结果是\n" + sum);
	}

}
