package com.sims.dao.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 * 取得数据库操作连接
 * 
 * @author whoami
 *         <li>可改进</li>
 *         <li>可通过外部传入参数，取得数据库连接，实现多数据库连接实现</li> 2016.12.28 Version 1.0
 */
public class Conn {

	public static Connection getConn() {
		Connection conn = null;
		try {
			Class.forName(Config.getConfig().getDBConfig("DRIVER"));
			try {
				conn = DriverManager.getConnection(Config.getConfig().getDBConfig("URL"),
                        Config.getConfig().getDBConfig("NAME"), Config.getConfig().getDBConfig("PWD"));
			} catch (SQLException e) {
				e.printStackTrace();
			}
			return conn;
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		return null;
	}

	// public static ResultSet getResultSet(Connection conn, String sql, String
	// args[], ConnService cs[]) {
	// PrintStream output = Log.getLog();
	// ResultSet rs = null;
	// try {
	// rs = getPreparedStatement(conn, sql, args, cs).executeQuery();
	// return rs;
	// } catch (SQLException e1) {
	// e1.printStackTrace(output);
	// output.close();
	// } catch (ClassSetErrorException e2) {
	// e2.printStackTrace(output);
	// output.close();
	// }
	// return rs;
	// }
	//
	// public static int getResultInt(Connection conn, String sql, String
	// args[], ConnService cs[]) {
	// PrintStream output = Log.getLog();
	// int ri = 0;
	// try {
	// ri = getPreparedStatement(conn, sql, args, cs).executeUpdate();
	// return ri;
	// } catch (SQLException e1) {
	// e1.printStackTrace(output);
	// output.close();
	// } catch (ClassSetErrorException e2) {
	// e2.printStackTrace(output);
	// output.close();
	// }
	// return ri;
	// }
	//
	// /**
	// * 数据库执行公共方法
	// *
	// * @param conn
	// * 获取数据库连接
	// * @param sql
	// * 要执行的sql语句
	// * @param args
	// * 包含的数据包类型说明以及包含的数据包个数
	// * @param cs
	// * 包含的实际数据
	// * @return 当两个数据包长度不同时，说明设置错误，此时返回空，否则执行语句，并返回相应的结果
	// * @throws ClassSetErrorException
	// * args[]元素不属于cs类包含类型时，抛出此异常
	// */
	// private static PreparedStatement getPreparedStatement(Connection conn,
	// String sql, String args[], ConnService cs[])
	// throws ClassSetErrorException {
	// if (args.length != cs.length) {
	// return null;
	// }
	// PrintStream output = Log.getLog();
	// PreparedStatement ps = null;
	// try {
	// ps = conn.prepareStatement(sql);
	// for (int index = 0; index < args.length; index++) {
	// switch (args[index]) {
	// case "Date":
	// ps.setDate((index + 1), (Date) cs[index].getDate());
	// break;
	// case "String":
	// ps.setString((index + 1), cs[index].getStr());
	// break;
	// case "Integer":
	// ps.setInt((index + 1), cs[index].getInteger());
	// break;
	// default:
	// throw new
	// ClassSetErrorException("com.sims.dao.getPreparedStatement(line.120)");
	// }
	// }
	// } catch (SQLException e) {
	// e.printStackTrace(output);
	// }
	// return ps;
	// }
}
