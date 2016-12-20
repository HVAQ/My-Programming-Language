package com.hpf.test.log;

public class ReadLog implements Runnable {
	private Log log;
	public ReadLog(Log log) {
		this.log = log;
	}
	@Override
	public void run() {
		for (int index = 0; index < 100; index++) {
			/**
			 * 通过测试，发现如何 WriteLog 与 ReadLog 都不设置延迟，或延迟设置相同时，程序会出现缓冲读入错误
			 * 由此可见，java 输入、输出流的程序运行消耗时间时不能忽略不计的
			 */
			try {
				Thread.sleep(this.log.getWaitTime());	// 设置监控读取延时
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			this.log.read();
		}
	}
	public Log getLog() {
		return log;
	}
	public void setLog(Log log) {
		this.log = log;
	}
}
