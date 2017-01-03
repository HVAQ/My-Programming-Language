package com.sims.dao;

import com.sims.dao.impl.ClassesDaoImpl;
import com.sims.dao.impl.DepartmentsDaoImpl;
import com.sims.dao.impl.SchoolDaoImpl;
import com.sims.dao.impl.SpecialitiesDaoImpl;

/**
 * Created by whoami on 2016/12/30.
 */
public class DaoFactory {
    public static SchoolDaoImpl getSchool() {
        return new SchoolDaoImpl();
    }
    public static DepartmentsDaoImpl getDepartments() {
        return new DepartmentsDaoImpl();
    }
    public static SpecialitiesDaoImpl getSpecialities() {
        return new SpecialitiesDaoImpl();
    }
    public static ClassesDaoImpl getClasses() {
        return new ClassesDaoImpl();
    }
}
