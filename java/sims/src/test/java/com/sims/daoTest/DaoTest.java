package com.sims.daoTest;

import com.sims.dao.DaoFactory;
import com.sims.dao.domain.*;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by whoami on 2017/1/3.
 */
public class DaoTest {
    public static void main(String args[]) {
        AInfo dep = new Departments("01", "矿业工程系");
        Set<AInfo> info = new HashSet<AInfo>();
        info.add(dep);
        System.out.println(DaoFactory.getSchool().doInsert(info));
        AInfo spe = new Specialities("011", "煤矿开采技术", "001");
        info.clear();
        info.add(spe);
        System.out.println(DaoFactory.getDepartments().doInsert(info));
        AInfo cla = new Classes("0111", "1班", "011");
        info.clear();
        info.add(cla);
        System.out.println(DaoFactory.getSpecialities().doInsert(info));
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        String birthday = "1995-09-16";
        try {
            AInfo stu = new Students("140421041", "韩鹏飞", "0111" ,
                    sdf.parse("2014-09-12"),3, 1 ,sdf.parse(birthday));
            info.clear();
            info.add(stu);
            System.out.println(DaoFactory.getClasses().doInsert(info));
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }
}
