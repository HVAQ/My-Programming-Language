package com.sims.dao.impl;

/**
 * 数据层学校类实现
 * Created by whoami on 2016/12/30.
 */
public class SchoolDaoImpl extends DaoImpl {
    private String childTable = "departments";

    @Override
    public String getChildTable() {
        return this.childTable;
    }

}