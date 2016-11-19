import Department;

public class Major {
    // 专业类
    private String mname;
    private String mid;
    private static int studentsNum = 0;

    private Students student;

    public Major(String mname) {
        this.mname = mname;
    }

    public Major(String mname, String mid) {
        this(mname);
        this.mid = mid;
        Department.majorNum++;
    }

    public void setMname(String mname) {
        this.mname = mname;
    }

    public String getMname() {
        return mname;
    }

    public void setMid(String mid) {
        this.mid = mid;
    }

    public void getMid() {
        return this.mid;
    }
}
