package com.hpf.test;

import com.hpf.actions.Copy;

public class TestCopy {

	public static void main(String[] args) throws Exception {
		if (args.length != 2) {
			System.out.println("参数设置错误");
			System.exit(1);
		}
		long time = Copy.copy(args[0], args[1]);
		System.out.println("拷贝完成, 耗时" + time + "毫秒。");
	}

}
