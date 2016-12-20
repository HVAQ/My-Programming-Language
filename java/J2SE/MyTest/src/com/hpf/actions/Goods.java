package com.hpf.actions;
/**
 * 货物类
 * @author whoami
 * 2016.12.04
 */
public class Goods {
	private String name;
	private String describe;
	private boolean label = true;
	// label 为 true 时，能够生产，不能取货
	// label 为 false 时，能够取货，不能生产
	/**
	 * 设置为 synchronized 以防止数据的设置，取出关系混乱
	 * @param name
	 * @param describe
	 */
	public synchronized void set(String name, String describe) {
		if (label == false) {
			try {
				// 利用 Object 类中的 wait() 方法等待
				super.wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		this.name = name;
		this.describe = describe;
		this.label = false;
		super.notify();		// 唤醒 --> Object 类
	}
	public synchronized void get() {
		if (label == true) {
			try {
				super.wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println(this.name + " --> " + this.describe);
		this.label = true;
		super.notify();
	}
}
