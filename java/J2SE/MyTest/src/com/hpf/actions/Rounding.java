package com.hpf.actions;

import java.math.BigDecimal;

public class Rounding {
	/**
	 * 对大浮点数进行精确的四舍五入操作
	 * @param num 要进行四舍五入的值
	 * @param digit 要保留的四舍五入后的小数位数
	 * @return 四色五入后的值
	 */
	public static double round(String num, int scale) {
		BigDecimal b1 = new BigDecimal(num);
		BigDecimal b2 = new BigDecimal(1);
		return b1.divide(b2, scale, BigDecimal.ROUND_HALF_UP).doubleValue();
	}
}
