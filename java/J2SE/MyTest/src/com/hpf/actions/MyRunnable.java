package com.hpf.actions;
/**
 * 多线程测试
 * @author whoami
 * 2016.12.04
 */
public class MyRunnable implements Runnable {
	private String name;
	public MyRunnable(String name) {
		this.name = name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getName() {
		return this.name;
	}
	@Override
	public void run() {
		for (int index = 0; index < 200; index++) {
			System.out.println(this.name + " --> " + index);
		}
	}
}
