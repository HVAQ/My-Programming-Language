package com.hpf.test;

import java.util.Date;
import com.hpf.actions.Goods;
class ForTest {
	public ForTest() {
		System.out.println("调用了 ForTest 的构造方法，实例化了一个对象");
	}
	@Override
	public String toString() {
		return "这是 Fortest 了的 toString 方法";
	}
}
public class TestReflex {

	public static void main(String[] args) {
		/**
		 * Reflex to
		 * 当此文件与要调用的类不在同一个包中时，必须进行导包操作
		 * 必须通过实例化有一个对象进行调用
		 */
		System.out.println(new Goods().getClass());
		System.out.println(new Date().getClass());
		/**
		 * Reflex two
		 * 当此文件与要调用的类不在同一个包中时，必须进行导包操作
		 * 不需要实例化对象，直接通过类名称进行调用
		 */
		System.out.println(Date.class);
		System.out.println(Goods.class);
		/**
		 * Reflex three
		 * 此方法可不使用 import 进行导包操作
		 */
		try {
			System.out.println(Class.forName("java.text.SimpleDateFormat"));
			System.out.println(Class.forName("com.hpf.actions.Goods"));
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		/**
		 * 利用 Class 的 forName() 和 newInstance() 方法进行对象实例化操作
		 */
		try {
			Class<?> cls = Class.forName("com.hpf.test.ForTest");
			Object obj = cls.newInstance();		// 此处开始实例化对象
			System.out.println(obj);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
