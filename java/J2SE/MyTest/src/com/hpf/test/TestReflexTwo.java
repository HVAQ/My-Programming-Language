package com.hpf.test;

//import java.lang.reflect.Constructor;

/**
 * 调用类的无参构造
 * @author whoami
 * 2016.12.06
 */
public class TestReflexTwo {
	public static void main(String[] args) {
		try {
			Class<?> cls = Class.forName("com.hpf.actions.ForTestReflexTwo");
			/**
			 * 在 com.hpf.actions.ForTestreflexTwo 类中没有提供无参构造
			 * 故而，不能调用 Class.newInstance() 实例化对象
			 * 只能调用 Constructor 类的 getConstructor() 方法，以传入参数的形式
			 * 获取 com.hpf.actions.ForTestreflexTwo 的构造方法
			 * 此时，已经明确调用了构造方法
			 * 便可以通过调用 Constructor 类的 newInstance() 方法进行对象实例化
			 */
//			Constructor<?> con = cls.getConstructor(String.class, double.class);
//			Object obj = con.newInstance("JAVA开发", 79.8);
//			System.out.println(obj);
			System.out.println(cls.getConstructor(String.class, double.class).newInstance("JAVA 开发", 79.8));
			} catch (Exception e) {
				e.printStackTrace();
		}
	}
}
