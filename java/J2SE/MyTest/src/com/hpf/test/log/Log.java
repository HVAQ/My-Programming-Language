package com.hpf.test.log;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ResourceBundle;

public class Log {
	private File logName;		// 当前日志文件绝对路径
	private File catchFile;		// 缓冲监视路径
	private ResourceBundle rb;	// 当前国家化语言
	private int waitTime;		// 监视延时
	private boolean lable;		// 为 true 时，能够读取日志，为 false 时，能够写入日志
	
	public Log(File logName, ResourceBundle rb, int waitTime) {
		this.logName = logName;
		this.catchFile = new File(this.logName.getParent() + File.separator + "catch.catch");
		this.rb = rb;
		this.waitTime = waitTime;
		this.lable = false;
	}
	public synchronized void write(String str) {
		 if (this.lable == true) {
			 try {
				super.wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		 }
		 try {
			 OutputStream output = new FileOutputStream(this.logName, true);
			 OutputStream theCatch = new FileOutputStream(catchFile);
			 output.write(str.getBytes());
			 theCatch.write(str.getBytes());
			 output.close();
			 theCatch.close();
		 } catch (Exception e) {
			 e.printStackTrace();
		 }
		 this.lable = true;
		 super.notify();
	}
	public synchronized void read() {
		if (this.lable = false) {
			try {
				super.wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		try {
			InputStream input = new FileInputStream(this.catchFile);
			byte []data = new byte[1024];
			int len = input.read(data);
			input.close();
			System.out.println(new String(data, 0, len));
		} catch (Exception e) {
			e.printStackTrace();
		}
		this.lable = false;
		super.notify();
	}
	public File getLogName() {
		return logName;
	}
	public void setLogName(File logName) {
		this.logName = logName;
	}
	public ResourceBundle getRb() {
		return rb;
	}
	public void setRb(ResourceBundle rb) {
		this.rb = rb;
	}
	public boolean getLable() {
		return lable;
	}
	public void setLable(boolean lable) {
		this.lable = lable;
	}
	public File getCatchFile() {
		return catchFile;
	}
	public void setCatchFile(File catchFile) {
		this.catchFile = catchFile;
	}
	public int getWaitTime() {
		return waitTime;
	}
	public void setWaitTime(int waitTime) {
		this.waitTime = waitTime;
	}
}
