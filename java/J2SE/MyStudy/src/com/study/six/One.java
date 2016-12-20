package com.study.six;
interface ClassName {
	Class<?> getClassName();
}
class Company implements ClassName {
	@Override
	public Class<?> getClassName() {
		return this.getClass();
	}
}
public class One {

	public static void main(String[] args) {
		System.out.println(new Company().getClassName());
	}

}
