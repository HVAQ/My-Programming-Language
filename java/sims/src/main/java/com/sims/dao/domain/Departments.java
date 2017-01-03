package com.sims.dao.domain;

/**
 * Created by whoami on 2016/12/30.
 */
public class Departments extends AInfo {
    public Departments() {

    }
    public Departments(String no, String name) {
        this(no, name, "");
    }
    public Departments(String no, String name, String note) {
        super(no, name, School.getSchool().getName(), note);
    }
}
