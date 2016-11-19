
public class School {
    // 学校类
    private String sid;
    private String sname;
    private static int depNum = 0;

    private Department department;

    public School(String sname) {
        this.sname = sname;
    }

    public School(String sname, String sid) {
        this(sname);
        this.sid = sid;
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
