package com.sims.dao;

import com.sims.dao.domain.AInfo;

import java.util.Set;

/**
 * 数据层接口类
 *
 * @author whoami 提供数据库的增、删、改、查规范 2016.12.27 Version 1.0
 */
public interface IDao {
	/**
	 * 批量增加操作
	 * <li>在执行批量增加之前，先执行数据校验工作</li>
	 * <li>即，对数据编号进行检索，如果集合中数据编号在数据库中存在，不执行任何数据增加行为，直接返回</li>
	 * 
	 * @param members
	 *            要增加的成员
	 * @return 当调用该方法，却未执行增加操作是返回false<br>
	 *         <li>当执行了增加操作，执行事务次数与集合成员数不同时，进行数据库回滚操作，返回false</li>
	 *         <li>否则返回true，表明集合中的数据全部增加成功</li>
	 */
	boolean doInsert(Set<AInfo> members);

	/**
	 * 批量删除操作
	 * <li>在执行批量删除之前，先执行数据校验工作</li>
	 * <li>即，利用keyword，进行检索，查找要删除对象的编号，之后，根据编号进行删除</li>
	 * <li>即，调用doDeleteByNo()方法</li>
	 * <li>在调用此方法前，必须将所有要删除的对象封装为AInfo对象</li>
	 * 
	 * @param keyword
	 *            要删除对象的属性关键字<br>
	 *            <li>即，如要根据属性s1、s2进行删除，则keyword应为String[] keyword = new
	 *            String[]{"s1", "s2"}</li>
	 * @param member
	 *            要真正删除的属性描述<br>
	 *            <li>即，如上，要删除的关键字为属性s1、s2，则member应设置为member.setS1(...),
	 *            member.setS2(...)</li>
	 *            <li>程序根据keyword[1]、keyword[2]分别调用member.getS1()和member.getS2()进行关键字的抽出，并调用检索功能，查找匹配成员编号</li>
	 * @return 当数据校验或根据编号进行删除返回false时，返回false，否则返回true
	 *         <note>关键字抽出与校验功能不在此方法中实现</note>
	 */
	boolean doDelete(String[] keyword, AInfo member);

	/**
	 * 整列更新操作
	 * 
	 * @param columnName
	 *            要更新的列名称
	 * @param member
	 *            要更新的新数据
	 * @return 当要更新的列不存在、member中对应于数据列的属性为空，或要更新的列为编号列时，返回false
	 */
	boolean doUpdate(String columnName, AInfo member);

	/**
	 * 条件更新操作
	 * @param columnName 要更新的列名称
	 * @param member 要更新的新数据
	 * @param keyword 条件限制语句的关键字
	 * @param condition 更新限制条件，即更新语句的WHERE部分
	 * @return 当要更新的列不存在、member中与列对应属性为空<br>
	 *         <li>或要更新的列为编号列，更新条件关键字中无编号限制时，返回false</li>
	 *         <note>当更新列为编号列时，最稳妥、高效的办法为忽略keyword，抽取、且只抽取condition中的编号作为限制条件</note>
	 */
	boolean doUpdate(String columnName, AInfo member, String[] keyword, AInfo condition);

	/**
	 * 单表多列查询操作
	 * @param columnName 要查询的列名称数组
	 * @return 当要查询的列不存在时，返回null，否则，根据要查询的列进行包装返回
	 */
	AInfo doSelect(String[] columnName);

	/**
	 * &#x5355;&#x8868;&#x591a;&#x5217;&#x9650;&#x5236;&#x67e5;&#x8be2;&#x64cd;&#x4f5c;
	 *
	 * @param columnName
	 *            &#x8981;&#x67e5;&#x8be2;&#x7684;&#x5217;&#x540d;&#x79f0;&#x6570;&#x7ec4;
	 * @param keyword
	 *            &#x9650;&#x5236;&#x6761;&#x4ef6;&#x5173;&#x952e;&#x5b57;
	 * @param condition
	 *            &#x5305;&#x88c5;&#x6709;&#x9650;&#x5236;&#x6761;&#x4ef6;&#x5173;&#x952e;&#x5b57;&#x7684;&#x76f8;&#x5173;&#x5c5e;&#x6027;
	 * @return &#x8981;&#x67e5;&#x8be2;&#x7684;&#x5217;&#x4e0d;&#x5b58;&#x5728;&#x3001;&#x9650;&#x5236;&#x6761;&#x4ef6;&#x5173;&#x952e;&#x5b57;&#x4e0d;&#x5b58;&#x5728;&#xff0c;&#x9650;&#x5236;&#x6761;&#x4ef6;&#x5173;&#x952e;&#x5b57;&#x5bf9;&#x5e94;&#x7684;&#x5c5e;&#x6027;&#x4e3a;&#x7a7a;&#x65f6;&#xff0c;&#x8fd4;&#x56de;false&#xff0c;&#x5426;&#x5219;&#xff0c;&#x6839;&#x636e;&#x8981;&#x67e5;&#x8be2;&#x7684;&#x5217;&#x540d;&#x79f0;&#x8fdb;&#x884c;&#x5305;&#x88c5;&#x8fd4;&#x56de;
	 */
	AInfo doSelect(String[] columnName, String[] keyword, AInfo condition);

	/**
	 * 成员数统计
	 * 
	 * @return 返回表结果全部成员数
	 */
	Integer getMemberNum();

	/**
	 * 条件限制成员数统计
	 * @param keyword 条件限制关键字
	 * @param member 包装有条件限制关键字
	 * @return 当限制条件关键字在表中不存在、当限制条件关键字对应属性为空时，返回0，否则返回对应条件成员数
	 */
	Integer getMemberNum(String[] keyword, AInfo member);
}
