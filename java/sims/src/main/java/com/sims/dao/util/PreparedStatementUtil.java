package com.sims.dao.util;

import com.sims.dao.domain.AInfo;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

/**
 * 通过java泛型实现PreparedStatemnet对象的自动装载
 * @author whoami
 * 2017.01.02
 * @version 1.2
 */
public class PreparedStatementUtil {
	/**
	 * PreparedStatement对象啊自动装载
	 * 
	 * @param conn
	 *            数据库连接
	 * @param sql
	 *            要执行的语句
	 * @param filedsName
	 *            要执行语句中的通配符对应的属性名
	 * @param member
	 *            包装了通配符所代表的属性
	 * @return 当执行传入的sql语句失败，或sql语句自动装载失败时，返回false
	 */
	public static PreparedStatement getPreparedStatement(Connection conn, String sql, String[] filedsName, AInfo member) {
		try {
			PreparedStatement ps = conn.prepareStatement(sql);
			if (filedsName != null) {
				for (int index = 0; index < filedsName.length; index++) {
					if (filedsName[index] == null || filedsName[index].trim().length() == 0
							|| !setPreparedStatement(ps, index + 1, filedsName[index], member)) {
						return null;
					}
				}
			}
			return ps;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}

	/**
	 * 通过反射机制，实现PreparedStatement对象的自动装载操作
	 * @param ps 已经实例化的PreparedStatement对象
	 * @param num 对应的装载次序标号
	 * @param filedName 要进设置的属性关键字
	 * @param member 要实现装载的对象
	 * @return 当设置的关键字在相应类中未设置相应的getter方法、相应的getter方法的返回值类型无PreparedStatement对应的方法时返回false<br />
	 * <li>否则进行相应类型属性值得的自动装载，并返回true</li>
	 */
	private static boolean setPreparedStatement(PreparedStatement ps, int num, String filedName, AInfo member) {
		if (filedName == null || filedName.trim().length() == 0) {
			return false;
		}
		// 自动构造相应属性的getter方法
		String getMethodOfKeyword = "get" + filedName.replace(filedName.substring(0, 1), filedName.substring(0, 1).toUpperCase());
		try {
			Method getMethod = member.getClass().getMethod(getMethodOfKeyword);		// 通过反射获取相应属性对应的getter方法
			Class returnType = getMethod.getReturnType();		// 获取getter方法的返回值类型
			// 自动构造相应返回值类型对应的的PreParedStatement的setter方法字符串
			String setMethodName = "set" + returnType.getSimpleName().replace(returnType.getName().substring(0, 1),
					returnType.getName().substring(0, 1).toUpperCase());
			// 获取PreparedStatement的相应setter方法
			Method setMethod = ps.getClass().getMethod(setMethodName, int.class, returnType);
			setMethod.invoke(ps, num, getMethod.invoke(member));
			return true;
		} catch (NoSuchMethodException | IllegalAccessException | InvocationTargetException e) {
			e.printStackTrace();
		}
		return false;
	}
}
