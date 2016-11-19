import Students;

public class Course {
    // 课程类
    private String cid;
    private String cname;
    private int grades;

    public Course(String cname, int grades) {
        this.cname = cname;
        this.grades = grades;
        Students.courseNum++;
    }

    public Course(String cname, int grades, String cid) {
        this(cname, grades);
        this.cid = cid;
    }

    public void setCid(String cid) {
        this.cid = cid;
    }

    public String getCid() {
        return this.cid;
    }

    public void setCname(String cname) {
        this.cname = cname;
    }

    public String getCname() {
        return this.cname;
    }

    public void setGrades(int grades) {
        this.grades = grades;
    }

    public int getGrades() {
        return this.grades;
    }
}
