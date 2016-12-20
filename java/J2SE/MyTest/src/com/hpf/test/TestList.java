package com.hpf.test;

import java.util.ArrayList;
import java.util.List;

public class TestList {
	public static void main(String[] args) {
		List<String> list = new ArrayList<String>();
		list.add("矿业系");
		list.add("地环系");
		list.add("信息系");
		list.add("管理系");
		for (int index = 0; index < list.size(); index++) {
			System.out.println(list.get(index));
		}
	}
}
