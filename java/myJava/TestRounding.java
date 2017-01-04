package com.hpf.test;

import com.hpf.actions.Rounding;

public class TestRounding {
	public static void main(String[] args) {
		System.out.println(Rounding.round("15.5", 0));
		System.out.println(Rounding.round("-15.5", 0));
	}
}
