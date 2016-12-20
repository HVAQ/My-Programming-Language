package com.hpf.actions;
/**
 * 消费者类
 * @author whoami
 * 2016.12.04
 */
public class Consumer implements Runnable {
	private Goods goods;
	public Consumer(Goods goods) {
		this.setGoods(goods);
	}
	@Override
	public void run() {
		for (int index = 0; index < 100; index++) {
			this.goods.get();
		}
	}
	public Goods getGoods() {
		return goods;
	}
	public void setGoods(Goods goods) {
		this.goods = goods;
	}
}
