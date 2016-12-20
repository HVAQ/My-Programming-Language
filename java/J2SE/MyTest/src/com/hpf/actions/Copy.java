package com.hpf.actions;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

public class Copy {
	public static long copy(String inputStr, String outputStr) 
			throws Exception {
		File inputStream = new File(inputStr);
		File outputStream = new File(outputStr);
		if (!inputStream.exists()) {
			System.out.println("源文件不存在！");
			System.exit(1);
		}
		if (!outputStream.getParentFile().exists()) {
			if(!outputStream.getParentFile().mkdirs()) {
				System.out.println("拷贝失败，请检查拷贝路径是否正确！");
				System.exit(1);
			}
		}
		InputStream input = new FileInputStream(inputStream);
		OutputStream output = new FileOutputStream(outputStream);
		byte data[] = new byte[2048];
		int len = 0;
		long start = System.currentTimeMillis();
		while ((len = input.read(data)) != -1) {
			output.write(data, 0, len);
		}
		input.close();
		output.close();
		long end = System.currentTimeMillis();
		return end - start;
	}
}
