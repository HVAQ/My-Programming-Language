package com.hpf.test;

/**
 * 多线程测试
 */
import com.hpf.actions.MyRunnable;

public class TestRunnable {

	public static void main(String[] args) {
		MyRunnable m1 = new MyRunnable("线程 A");
		MyRunnable m2 = new MyRunnable("线程 B");
		MyRunnable m3 = new MyRunnable("线程 C");
		new Thread(m1).start();
		new Thread(m2).start();
		new Thread(m3).start();
	}

}
