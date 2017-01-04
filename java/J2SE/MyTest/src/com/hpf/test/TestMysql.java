package com.hpf.test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class TestMysql {
	private static final String MYSQLDRIVER = "com.mysql.jdbc.Driver";
	private static final String MYSQLURL = "jdbc:mysql://localhost:3306/test";
	private static final String USER = "root";
	private static final String PASSWORD = "950916Pf,.";
	public static void main(String[] args) {
		Connection conn = null;
		// 第一步、加载数据库驱动程序，此时不需要实例化，因为会由容器自己负责管理
		try {
			Class.forName(MYSQLDRIVER);
			// 第二步、连接数据库
			conn = DriverManager.getConnection(MYSQLURL, USER, PASSWORD);
			Statement stmt =  conn.createStatement();
			String sql = " INSERT INTO user(name, age, note, sex, birthday) VALUES ('韩鹏飞', '21', '大牛', '男', '1995-09-16') ";
			int len = stmt.executeUpdate(sql);
			System.out.println("影响数据行数" + len);
//			stmt.executeQuery("SELECT * FROM user");
		} catch (Exception e) {
			System.out.println("数据库连接异常");
		} finally {
			// 第四步、关闭数据库
			try {
				conn.close();
			} catch (SQLException e) {
				System.out.println("数据库关闭异常");
			}
		}
	}

}