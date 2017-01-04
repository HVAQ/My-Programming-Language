package com.hpf.test;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

class UserInfo {
	private String username;
	private String password;
	public UserInfo(String username, String password) {
		this.username = username;
		this.password = password;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public boolean equals() {
		if ("whoami".equals(this.username) && 
				"950916Pf,.".equals(this.password)) {
			return true;
		}
		return false;
	}
}
public class TestServer {

	public static void main(String[] args) {
		ServerSocket ss = null;
		Socket socket = null;
		int port = 10000;
		OutputStream output = null;
		InputStream input = null;
		try {
			ss = new ServerSocket(port);			// 建立连接
			System.out.println("服务器已启动。");
			socket = ss.accept();					// 获得连接
			byte data[] = new byte[1024];
			input = socket.getInputStream();
			int len = input.read(data);
			String userIp = new String(data, 0 ,len);
			System.out.println("客户端" + userIp + "连接。");
			int index = 0;
			for (index = 0; index < 5; index++) {
				len = input.read(data);
				String username = new String(data, 0, len);
//				System.out.println("username = " + username);
				len = input.read(data);
				String password = new String(data, 0, len);
//				System.out.println("password = " + password);
				output = socket.getOutputStream();
				if (new UserInfo(username, password).equals()) {
					output.write("登录成功.".getBytes());
					System.out.println(username + "在" + userIp + "成功登录。");
					break;
				} else {
					if (index != 4) {
						output.write("登录失败".getBytes());
						System.out.println(userIp + "登录失败" + (index + 1) + "次。");
					} else {
						output.write("登录次数达到限制".getBytes());
						System.out.println("ip: " + userIp + "登录次数达到限制");
						break;
					}
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				input.close();
				output.close();
				socket.close();
				ss.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}

}