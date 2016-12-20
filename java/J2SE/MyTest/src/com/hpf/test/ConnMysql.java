package com.hpf.test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class ConnMysql {
	public static void main(String[] args) {
		Connection con = null;		// 定义连接对象
		try {
			Class.forName("com.mysql.jdbc.Driver").newInstance();	// 加载数据库驱动
			// 创建连接
			con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/hpf", "root", "950916Pf,.");
			
			Statement stmt = con.createStatement();		// 创建声明
			
			// 新建数据表
//			String createTable = "CREATE TABLE userinfo (id INT AUTO_INCREMENT PRIMARY KEY, "
//					+ "username VARCHAR(30) NOT NULL,"
//					+ "age INT NOT NULL,"
//					+ "password VARCHAR(30) NOT NULL,"
//					+ "email VARCHAR(30) NOT NULL);";
//			stmt.executeUpdate(createTable);
			
			// 更新数据
//			String updateInfo = "INSERT INTO userinfo (username, password, age, email) "
//					+ "VALUES ('武亚卿', 'ILoveYou', 21, '1821938745@qq.com')";
//			stmt.executeUpdate(updateInfo);
			
			// 删除数据
//			String deleteInfo = "DELETE FROM userinfo WHERE username = '武亚卿'";
//			stmt.executeUpdate(deleteInfo);
			
			// 更改数据
//			String changeInfo = "UPDATE userinfo SET email = '1666970690@qq.com' WHERE id = 1";
//			stmt.executeUpdate(changeInfo); 
			
			// 数据库查询
			String selectSql = "SELECT * FROM userinfo "; // WHERE username = '武亚卿'";
			ResultSet selectRes = stmt.executeQuery(selectSql);
			System.out.println("-------------------------------------------------------------------------------------------------------");
			while (selectRes.next()) {
				int id = selectRes.getInt(1);
				String username = selectRes.getString("username");
				String password = selectRes.getString("password");
				int age = selectRes.getInt(1);
				String email = selectRes.getString("email");
				System.out.println ("|  id = " + id + "  |  "
						+ "username = " + username + "  |  "
						+ " password = " + password + "  |  "
						+ " age = " + age + "    | "
						+ " email = " + email + " |");
				System.out.println("-------------------------------------------------------------------------------------------------------");
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				con.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
}
