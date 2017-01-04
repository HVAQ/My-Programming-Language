package com.hpf.test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class TestConn {
	static final String DBDRIVER = "com.mysql.jdbc.Driver";
	static final String URL = "jdbc:mysql://127.0.0.1:3306/test";
	static final String NAME = "root";
	static final String PWD = "950916Pf,.";
	
	public static void main(String[] args) {
		System.out.println(getConn());
	}
	public static Connection getConn() {
		Connection conn = null;
		try {
			Class.forName(DBDRIVER);
			conn = DriverManager.getConnection(URL, NAME, PWD);
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		return conn;
	}
}
