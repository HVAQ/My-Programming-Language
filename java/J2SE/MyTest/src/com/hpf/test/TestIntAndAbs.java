package com.hpf.test;
interface MyInt {
	void printOne();
	
	// 内部定义一个内部抽象类
	public abstract class IntterClass {
		private String name;
		public IntterClass(String name) {
			this.name = name;
		}
		// 内部抽象类中定义抽象方法
		public abstract void printTwo();
		
		// 内部抽象类中定义一个普通方法
		public void printThree() {
			System.out.println("This is print three.");
		}
		public void setName(String name) {
			this.name = name;
		}
		public String getName() {
			return this.name;
		}
	}
}
class Test implements MyInt {
	@Override
	public void printOne() {
		System.out.println("This is print one.");
	}
	class IntterClassTwo extends IntterClass {
		public IntterClassTwo(String name) {
			super(name);
		}
		@Override
		public void printTwo() {
			System.out.println("This is print two --> name = " + super.getName());
		}
	}
}
class Two extends Test {}
public class TestIntAndAbs {

	public static void main(String[] args) {
		new Test().printOne();
		Test.IntterClassTwo n1 = new Test().new IntterClassTwo("N1");
		n1.printTwo();
		n1.printThree();
		System.out.println(new Two() instanceof Object);
	}

}
