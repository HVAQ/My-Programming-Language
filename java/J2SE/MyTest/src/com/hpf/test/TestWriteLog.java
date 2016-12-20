package com.hpf.test;
/**
 * 国际化输出监控日志
 */
import java.io.File;
import java.util.Locale;
import java.util.ResourceBundle;
import com.hpf.test.log.Log;
import com.hpf.test.log.ReadLog;
import com.hpf.test.log.WriteLog;

public class TestWriteLog {

	public static void main(String[] args) {
		ResourceBundle rb = setLocale("com.hpf.test.International.log.Message", "zh", "CN");
		int waitTime = 100;
		if (waitTime < 100) {
			System.out.println(rb.getString("waring") + " " + rb.getString("timeShort"));
		}
		Log log = new Log(setFile(), rb, waitTime);
		new Thread(new WriteLog(log)).start();
		new Thread(new ReadLog(log)).start();
	}
	public static File setFile() {
		return new File(File.separator + "Users" + File.separator + "whoami" 
				 + File.separator + "Desktop" + File.separator +"App.log");		//  要进行操作的文件路径
	}
	public static ResourceBundle setLocale(String message, String language, String country) {
		return ResourceBundle.getBundle(message, new Locale(language, country));	// 设置国际化程序包
	}
}