import Department;

public class Students {
    // 学生类
    private String sid;                 // 学号
    private String sname;               // 姓名
    private static int courseNum = 0;   // 课程数

    private Major major;
    
    public Students(String sid, String sname) {
        this.sid = sid;
        this.sname = sname;
        Department.majorNum++;
    }

    public void setSid(String sid) {
        this.sid = sid;
    }

    public String getSid() {
        return this.sid;
    }

    public void setSname(String sname) {
        this.sname = sname;
    }

    public String getSname() {
        return this.sname;
    }
}
