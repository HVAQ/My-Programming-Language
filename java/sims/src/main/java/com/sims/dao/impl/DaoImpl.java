package com.sims.dao.impl;

import com.sims.dao.IDao;
import com.sims.dao.domain.AInfo;
import com.sims.dao.util.Config;
import com.sims.dao.util.Conn;
import com.sims.dao.util.PreparedStatementUtil;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Iterator;
import java.util.Set;

/**
 * 数据层公共服务类
 * 
 * @author whoami 依赖于数据表设置与拆箱，简化数据库操作流程，是数据自动化的核心代码层
 * 待改进<br>
 * <li>可利用反射机制，获取当前对象的子链表，实现要操作数据表的参数不传入</li>
 */
public abstract class DaoImpl implements IDao {
	/**
	 * 增加操作
	 * 
	 * @param members
	 *            包装有要增加的成员信息
	 * @return 当传入表不存在或传入参数为空,或传入参数编号在数据库中存在时，返回空
	 */
	public boolean doInsert(Set<AInfo> members) {
		if (!this.hasTable()) {
			return false;
		}
		Iterator<AInfo> member = members.iterator();
		Connection conn = Conn.getConn();
		try {
			int memberNum = 0; // 传入数据集合的成员数
			int updateNum = 0; // 数据插入动作的执行语句数
			while (member.hasNext()) {
				memberNum++;
				AInfo info = member.next();
				// 此操作只处理了数据存储上的逻辑关系，数据数值上的逻辑关系应该留给业务层处理
				if (info.getNo() == null || info.getName() == null || info.getSuperior() == null) {
					return false;
				}
				if ("students".equals(this.getChildTable()) && (info.getBirthday() == null  || info.getYear() == null)) {
					return false;
				}
				String checkSql = " SELECT no FROM " + this.getChildTable() + " WHERE no = ? "; // 此语句用来执行数据校验操作
				PreparedStatement ps = PreparedStatementUtil.getPreparedStatement(conn, checkSql, new String[]{"no"}, info);
				if (ps == null) {
					return false;
				}
				if (ps.executeQuery().next()) { // 检查数据是否在数据库中存在
					return false;
				}
				ps.clearBatch();
				// 当编号在库中不存在时，执行数据插入操作
				/* ------------------- 插入语句自动构建 -------------------------- */
				StringBuilder sql = new StringBuilder();
				StringBuilder keyword = new StringBuilder();
				sql.append(" INSERT INTO ").append(this.getChildTable()).append(" ( ");
				String []allFileds = Config.getConfig().getDBConfig(getChildTable() + "FIELD").split(",");
				for (String filed: allFileds) {
					sql.append(filed).append(", ");
					keyword.append(filed).append(",");
				}
				sql.replace(sql.length() - 2, sql.length() - 1, ")");
				keyword.replace(keyword.length() - 1, keyword.length(), "");
				sql.append(" VALUES ( ");
				for (String filed : allFileds) {
					sql.append("?, ");
				}
				sql.replace(sql.length() -2, sql.length() - 1, ")");
				/* ----------------- 插入语句自动构建完成 ------------------------ */
				ps = PreparedStatementUtil.getPreparedStatement(conn, sql.toString(), keyword.toString().split(","), info);
				if (ps == null || ps.executeUpdate() != 1) {
					// 缺少数据库回滚功能
					return false;
				}
				ps.clearBatch();
				updateNum++;
			}
			// 如果要添加的数据为空或执行操作数为0，说明操作失败
			return !(memberNum == 0 || updateNum == 0) && memberNum == updateNum; // 防止数据包在程序执行过程中丢失
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			try {
				assert conn != null;
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		return false;
	}
	/**
	 * 数据删除操作
	 * @param keyword 要删除的依赖关键字属性
	 * @param member 封装有要删除属性关键字对应的属性值
	 * @return 当关键字keyword为空或包含空字符串、或member中与keyword对应属性为空时，返回false<br />
	 * <li>否则进行删除语句自动构造，并进行删除</li>
	 * <li>当删除成功是，返回true</li>
	 */
	public boolean doDelete(String[] keyword, AInfo member) {
		if (!this.hasFields(keyword)) {
			return false;
		}
		Connection conn = null;
		try {
			conn = Conn.getConn();
			StringBuilder sql = new StringBuilder();
			sql.append(" DELETE FROM ").append(getChildTable()).append(" WHERE ");
			// 判断关键字中是否有唯一表示符
			boolean hasFiled = false;
			for (String key: keyword) {
				if ("no".equals(key)) {
					hasFiled = true;
				}
			}
			if (hasFiled) {
				// 如果有唯一标示符，依照标示符删除，以提高性能
				sql.append(" no = ? ");
				PreparedStatement ps = PreparedStatementUtil.getPreparedStatement(conn, sql.toString(), new String[]{"no"}, member);
				if (ps != null && ps.executeUpdate() != 0) {
					return true;
				}
			} else {
				String[] fields = Config.getConfig().getDBConfig(getChildTable() + "FIELD").split(",");
				for (String key : keyword) {
					sql.append(key).append(" = ").append("? , ");
				}
				sql.replace(sql.length() - 2, sql.length() - 1, "");
				PreparedStatement ps = PreparedStatementUtil.getPreparedStatement(conn, sql.toString(), keyword, member);
				if (ps != null && ps.executeUpdate() != 0) {
					return true;
				}
			}
			return false;
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			if (conn != null) {
				try {
					conn.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return false;
	}

    /**
     * 数据更新操作
     * @param columnName
     *            要更新的列名称
     * @param member
     *            要更新的新数据
     * @return 当要更新的列不存在，与要更新的列相对应的包装数据属性为空时，返回false
     */
	public boolean doUpdate(String columnName, AInfo member) {
		if ("no".equals(columnName) || this.hasFields(new String[]{columnName})) {
			return false;
		}
		Connection conn = null;
		try {
			conn = Conn.getConn();
			String sql = " UPDATE " + this.getChildTable() + " SET " + columnName + " = ? ";
			PreparedStatement ps = PreparedStatementUtil.getPreparedStatement(conn, sql, new String[]{columnName}, member);
			if (ps != null) {
				ps.executeUpdate();
				return true;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			try {
				if (conn != null) {
					conn.close();
				}
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		return false;
	}

    /**
     * 限制条件并列，数据更新操作
     * @param columnName 要更新的列名称
     * @param member 要更新的新数据
     * @param keyword 条件限制语句的关键字
     * @param condition 更新限制条件，即更新语句的WHERE部分
     * @return 当要更新的列名称不存在、限制条件列名称不存在、
     */
	public boolean doUpdate(String columnName, AInfo member, String[] keyword, AInfo condition) {
        if ("no".equals(columnName) || !this.hasFields(new String[]{columnName}) ||
                condition == null || member == null || !this.hasFields(keyword)) {
            return false;
        }
        boolean hasNo = false;
        for (String key : keyword) {
            if ("no".equals(key)) {
                hasNo = true;
            }
        }
        Connection conn = null;
        try {
            conn = Conn.getConn();
            StringBuilder sql = new StringBuilder();
            sql.append(" UPDATE ").append(this.getChildTable()).append(" SET ").append(columnName).append(" = ? WHERE ");
            PreparedStatement ps = null;
            if (hasNo) {
                sql.append(" no = ").append(condition.getNo());
                PreparedStatementUtil.getPreparedStatement(conn, sql.toString(), new String[]{columnName}, member);
            } else {
                for (String key : keyword) {
                    Method method = null;
                    method = condition.getClass().getDeclaredMethod("get" + key.replace(key.substring(0, 1), key.substring(0, 1).toUpperCase()));
                    sql.append(key).append(" = ").append(method.invoke(condition.getClass())).append(" AND ");
                    sql.replace((sql.length() - 4), sql.length(), "");
                }
            }
            ps = PreparedStatementUtil.getPreparedStatement(conn, sql.toString(), new String[]{columnName}, member);
            return !(ps == null || ps.executeUpdate() != 1);
        } catch (SQLException | IllegalAccessException | InvocationTargetException | NoSuchMethodException e) {
            e.printStackTrace();
        } finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
        return false;
	}

	@Override
	public AInfo doSelect(String[] columnName) {
		if (!this.hasTable() || !this.hasFields(columnName)) {
			return null;
		}
		Connection conn = Conn.getConn();
		ResultSet rs = null;
		AInfo info = new AInfo();
		try {
			StringBuilder sql = new StringBuilder();
			sql.append(" SELECT  ");
			for (String column: columnName) {
				sql.append(column).append(", ");
			}
			sql.replace(sql.length() - 2, sql.length() - 1, "");
			sql.append(" FROM ").append(this.getChildTable()).append(" ");
			PreparedStatement ps = PreparedStatementUtil.getPreparedStatement(conn, sql.toString(), null, null);
			if (ps == null) {
			    return null;
            }
			rs = ps.executeQuery();
			for (int index = 0; index < columnName.length; index++) {
				String methodName = "get" + columnName[index].getClass().getName();
				Method method = rs.getClass().getDeclaredMethod(methodName, int.class);
				Object obj = method.invoke(rs.getClass(), index);
				String setMethodName = "set" + columnName[index].getClass().getName();
				Method setMethod = info.getClass().getDeclaredMethod(setMethodName, columnName.getClass());
				setMethod.invoke(info.getClass(), obj);
			}
			return info;
		} catch (SQLException | NoSuchMethodException | IllegalAccessException | InvocationTargetException e) {
			e.printStackTrace();
		} finally {
			if (conn != null) {
				try {
					conn.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return null;
	}
	public AInfo doSelect(String[] columnName, String[] keyword, AInfo condition) {
		if (!this.hasTable() || !this.hasFields(columnName) || !this.hasFields(keyword)) {
			return null;
		}
		Connection conn = Conn.getConn();
		ResultSet rs = null;
		AInfo info = new AInfo();
		try {
			StringBuilder sql = new StringBuilder();
			sql.append(" SELECT  ");
			for (String column: columnName) {
				sql.append(column).append(", ");
			}
			sql.replace(sql.length() - 2, sql.length() - 1, "");
			sql.append(" FROM ").append(this.getChildTable()).append(" WHERE ");
			for (String key: keyword) {
				sql.append(key).append(" = ? AND ");
			}
			sql.replace(sql.length() - 4, sql.length(), " ");
			PreparedStatement ps = PreparedStatementUtil.getPreparedStatement(conn, sql.toString(), keyword, condition);
			if (ps == null) {
				return null;
			}
			rs = ps.executeQuery();
			for (int index = 0; index < columnName.length; index++) {
				String methodName = "get" + columnName[index].getClass().getName();
				Method method = rs.getClass().getDeclaredMethod(methodName, int.class);
				Object obj = method.invoke(rs.getClass(), index);
				String setMethodName = "set" + columnName[index].getClass().getName();
				Method setMethod = info.getClass().getDeclaredMethod(setMethodName, columnName.getClass());
				setMethod.invoke(info.getClass(), obj);
			}
			return info;
		} catch (SQLException | NoSuchMethodException | IllegalAccessException | InvocationTargetException e) {
			e.printStackTrace();
		} finally {
			try {
				assert conn != null;
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		return null;
	}

	public Integer getMemberNum(String[] keyword, AInfo member) {
		if (!this.hasTable() || !this.hasFields(keyword)) {
			return -1;
		}
		Connection conn = null;
		try {
			conn = Conn.getConn();
			StringBuilder sql = new StringBuilder();
			sql.append(" SELECT cound(*) FROM ").append(this.getChildTable()).append(" ");
			if (keyword.length != 0) {
				sql.append(" WHERE ");
				for (String key: keyword) {
					sql.append(key).append(" =  ? AND ");
				}
				sql.replace(sql.length() - 4, sql.length(), "");
			}
			PreparedStatement ps = PreparedStatementUtil.getPreparedStatement(conn, sql.toString(), keyword, member);
			if (ps == null) {
				return -1;
			}
			return ps.getUpdateCount();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			if (conn != null) {
				try {
					conn.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return -1;
	}

	public Integer getMemberNum(){
		if (!this.hasTable()) {
			return -1;
		}
		Connection conn = null;
		try {
			conn = Conn.getConn();
			String sql = " SELECT count(*) FROM " + this.getChildTable() + " ";
			PreparedStatement ps = PreparedStatementUtil.getPreparedStatement(conn, sql, null, null);
			if (ps == null) {
				return -1;	// 表示执行失败
			}
			return ps.getUpdateCount();
		} catch (SQLException e) {
			e.printStackTrace();
		} finally {
			if (conn != null) {
				try {
					conn.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
		}
		return -1;
	}

	abstract String getChildTable();

	/**
	 * 数据表校验
	 * @return 当表名为空、表名为空字符串或表不存在时返回false
	 */
	private boolean hasTable() {
		return !(this.getChildTable() == null || this.getChildTable().trim().length() == 0 ||
				Config.getConfig().getDBConfig("table" + this.getChildTable()) == null);
	}

	/**
	 * 校验在表中是否存在于关键字相匹配的表字段
	 * @param keyword 要进行校验的关键字
	 * @return 当表在数据库中不存在、关键字为空或为空字符串，以及关键字在表中无匹配表字段时返回false
	 */
	@org.jetbrains.annotations.Contract("null -> false")
    private boolean hasFields(String[] keyword) {
		if (keyword == null || !this.hasTable()) {
			return false;
		}
		String files = (Config.getConfig().getDBConfig(this.getChildTable() + "FIELD"));
		String []allFileds = null;
		if (files == null) {
			return false;
		} else {
			allFileds = files.split(",");
		}
		boolean hasFiled = false;
		for (String filed: allFileds) {
			for (String key : keyword) {
				if (key == null || key.trim().length() == 0) {
					return false;
				}
				if (filed.equals(key)) {
					hasFiled = true;
				}
			}
		}
		if (!hasFiled) {
			return false;
		}
		return true;
	}
}
