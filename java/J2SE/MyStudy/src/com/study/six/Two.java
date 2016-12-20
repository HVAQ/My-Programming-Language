package com.study.six;

import java.io.File;
import java.math.BigDecimal;
import java.text.SimpleDateFormat;
import java.util.Date;

class Picture {
	private long size;
	private long date;
	private String name;
	private String position;
	private String read;
	private String write;
	public Picture(String position, String name) {
		this.setName(name);
		this.setPosition(position);
	}
	private void getInfo() {
		File picture = new File(this.position, this.name);
		if (!picture.exists()) {
			System.out.println("文件不存在");
			System.exit(1);
		}
		this.setName(picture.getName());
		this.setPosition(picture.getParent());
		this.setSize(picture.length());
		this.setDate(picture.lastModified());
		this.setRead((picture.canRead()) ? "是" : "否");
		this.setWrite((picture.canWrite()) ? "是" : "否");
	}
	public long getSize() {
		return size;
	}
	public void setSize(long size) {
		this.size = size;
	}
	public long getDate() {
		return date;
	}
	public void setDate(long date) {
		this.date = date;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getPosition() {
		return position;
	}
	public void setPosition(String position) {
		this.position = position;
	}
	public String isRead() {
		return read;
	}
	public void setRead(String read) {
		this.read = read;
	}
	public String isWrite() {
		return write;
	}
	public void setWrite(String write) {
		this.write = write;
	}
	@Override
	public String toString() {
		this.getInfo();
		return "名称: " + this.getName()
			+ "\n大小: " + new BigDecimal(this.getSize()).divide(new BigDecimal(1024 * 1024), 2, BigDecimal.ROUND_HALF_UP)
			+ "M\n日期: " + new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss").format(new Date(this.getDate()))
			+ "\n路径: " + this.getPosition() 
			+ "\n可读: " + this.isRead() 
			+ "\n可写: " + this.isWrite();
	}
}
public class Two {

	public static void main(String[] args) {
		Picture pic = new Picture("/Users/whoami/Documents/Others", "1.png");
		System.out.println(pic.toString());
	}

}
