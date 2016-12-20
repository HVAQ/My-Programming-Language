package com.hpf.actions;

public class ForTestReflexTwo {
	private String title;
	private double price;
	public ForTestReflexTwo(String title, double price) {
		this.title = title;
		this.price = price;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public String getTitle() {
		return this.title;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public double getPrice() {
		return this.price;
	}
	@Override
	public String toString() {
		return "名称:" + this.title + ", 价格" + this.price;
	}
}
