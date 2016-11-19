import School;

public class Department {
    // 系部类
    private String pname;
    private String pid;
    private static int majorNum = 0;

    private Major major;

    public Department(String pname) {
        this.pname = pname;
    }

    public Department(String pname, String pid) {
        this(pname);
        this.pid = pid;
        School.depNum++;
    }

    public void setPname(String pname) {
        this.pname = pname;
    }

    public String getPname() {
        return this.pname;
    }

    public void setPid(String pid) {
        this.pid = pid;
    }

    public String getPid() {
        return this.pid;
    }
}
