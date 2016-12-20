package com.hpf.test;
/**
 * 生产者-消费者模型
 * @author whoami
 * 2016.12.04
 */
import com.hpf.actions.Consumer;
import com.hpf.actions.Goods;
import com.hpf.actions.Producer;

public class TestProAndCon {

	public static void main(String[] args) {
		Goods goods = new Goods();	// 创建一个货物类，用以存放和取出数据
		new Thread(new Producer(goods)).start();
		new Thread(new Consumer(goods)).start();
	}

}
