package com.hpf.test.log;

import java.text.SimpleDateFormat;
import java.util.Date;

public class WriteLog implements Runnable {
	private Log log;
	public WriteLog(Log log) {
		this.log = log;
	}
	@Override
	public void run() {
		for (int index = 0; index < 100; index++) {
			String sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss:SSS").format(new Date());	// 设置日期格式
			// 利用国际化配置文件进行输出字符串配置
			String sb = (index % 2 == 0) ? this.log.getRb().getString("error") + "\t" + sdf + "\t" + this.log.getRb().getString("errorLog") : 
				this.log.getRb().getString("log") + "\t" + sdf + "\t" + this.log.getRb().getString("logLog");
			this.log.write(sb);
		}
	}
	public Log getLog() {
		return log;
	}
	public void setLog(Log log) {
		this.log = log;
	}
}