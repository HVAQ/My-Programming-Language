package com.hpf.actions;
/**
 * 多线程死锁模拟
 * @author whoami
 * 2016.12.04
 */
public class DeadlockA {
	public synchronized void say(DeadlockB b) {
		System.out.println("我说：把你的书给我，我就给你笔，否则不给");
		b.get();
	}
	public synchronized void get() {
		System.out.println("我：得到了书，付出了笔，还是什么都干不成");
	}
}
