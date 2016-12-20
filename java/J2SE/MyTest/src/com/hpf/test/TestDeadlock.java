package com.hpf.test;
/**
 * 多线程死锁模拟
 */
import com.hpf.actions.DeadlockA;
import com.hpf.actions.DeadlockB;

public class TestDeadlock implements Runnable{
	private DeadlockA a = new DeadlockA();
	private DeadlockB b = new DeadlockB();
	public static void main(String[] args) {
		new TestDeadlock();
	}
	public TestDeadlock() {
		new Thread(this).start();
		a.say(b);
	}
	@Override
	public void run() {
		b.say(a);
	}
}
