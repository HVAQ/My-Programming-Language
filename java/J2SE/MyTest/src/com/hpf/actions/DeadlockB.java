package com.hpf.actions;
/**
 * 多线程死锁模拟
 * @author whoami
 * 2016.12.04
 */
public class DeadlockB {
	public synchronized void say(DeadlockA a) {
		System.out.println("他说：把你的笔给我，我就给你书，否则不给");
		a.get();
	}
	public synchronized  void get() {
		System.out.println("他：得到了笔，付出了书，还是什么都干不成");
	}
}
