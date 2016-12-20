package com.hpf.actions;
/**
 * 生产者类
 * @author whoami
 * 2016.12.04
 */
public class Producer implements Runnable {
	private Goods goods;	// 当前数据设置区域
	public Producer(Goods goods) {
		this.setGoods(goods);
	}
	@Override
	public void run() {
		for (int index = 0; index < 100; index++) {
			// 根据 index % 2 的结果决定如何设置数据
//			try {
//				Thread.sleep(1000);
//			} catch (InterruptedException e) {
//				e.printStackTrace();
//			}
			if (index % 2 == 0) {
				this.goods.set("手机", "001");
			} else {
				this.goods.set("电脑", "002");
			}
		}
	}
	public Goods getGoods() {
		return goods;
	}
	public void setGoods(Goods goods) {
		this.goods = goods;
	}
}
