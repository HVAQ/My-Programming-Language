
class School {
    // 学校类
    private String name;
    private int id;

    private School next;         // 为学校管理系统做扩充
    private Department root;
    private int memberNum;

    public School() {}

    public School(String name) {
        this.name = name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return this.id;
    }
    
    public void setNext(School next) {
        this.next = next;
    }

    public School getNext() {
        return this.next;
    }

    public void setRoot(Department root) {
        this.root = root;
    }

    public Department getRoot() {
        return this.root;
    }

    public void setMemberNum(int memberNum) {
        this.memberNum = memberNum;
    }

    public int getMmberNum() {
        return this.memberNum;
    }

    public boolean add(Department member) {
        if (member == null) {
            return false;
        }
        if (this.root == null) {
            // 当前对象的 root 节点为空时
            // 将成员设置为当前对象的 root 节点
            this.setRoot(member);
        } else {
            Department temp = new Department();
            temp = this.root;
            // 当前对象的 root 节点不为空时
            // 继续查找当前节点的下一个节点是否为空
            while (temp.getNext() != null) {
                temp = temp.getNext();
            }
            temp.setNext(member);
        }
        this.memberNum++;
        return true;
    }

    public boolean del(Department member) {
        if (member == null) {
            return false;
        }
        // 利用计数来实现要删除节点的查找
        int count = this.find(member);
        if (count >= this.memberNum) {
            return false;
        } else if (count == 0) {
            this.root = this.root.getNext();
        } else {
            Department temp = new Department();
            temp = this.root;       // temp 用来记录要删除节点的上一个节点
            for (int index = 1; index < count; index++) {
                temp = temp.getNext();
            }
            temp.setNext(temp.getNext().getNext());
        }
        this.memberNum--;
        return true;
    }

    public boolean change(Department member, Department the_new) {
        if (member == null) {
            return false;
        }
        // 利用计数来实现要改变节点的查找
        int count = this.find(member);
        if (count >= this.memberNum) {
            return false;
        } else {
            Department temp = new Department();
            temp = this.root;
            for (int index = 0; index < count; index++) {
                temp = temp.getNext();
            }
            temp.setName(the_new.getName());
            temp.setId(the_new.getId());
        }
        return true;
    }

    public int find(Department member) {
        // 通过名称获取索引
        // 如果 member 在链表中存在
        // 返回 member 再链表中的索引
        Department temp = new Department();
        temp = this.root;
        int count = 0;
        while (count < this.memberNum) {
            if (!temp.isSame(member)) {
                temp = temp.getNext();
                count++;
            } else {
                break;
            }
        }
        return count;
    }

    public boolean isSame(School member) {
        if (this.name.equals(member.getName()) && (this.id == member.getId() || member.getId() == 0)) {
            return true;
        }
        return false;
    }
}

class Department {
    private String name;
    private int id;

    private Aclass root;
    private Department next;
    private int memberNum;

    public Department() {}

    public Department(String name) {
        this.name = name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return this.id;
    }

    public void setRoot(Aclass root) {
        this.root = root;
    }

    public Aclass getRoot() {
        return this.root;
    }

    public void setNext(Department next) {
        this.next = next;
    }

    public Department getNext() {
        return this.next;
    }

    public void setMemberNum(int memberNum) {
        this.memberNum = memberNum;
    }

    public int getMmberNum() {
        return this.memberNum;
    }

    public boolean isSame(Department member) {
        if (this.name.equals(member.getName()) && (this.id == member.getId() || member.getId() == 0)) {
            return true;
        }
        return false;
    }
}

class Aclass {
    private String name;
    private int id;

    private int memberNum;

    public Aclass() {};

    public Aclass(String name) {
        this.name = name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId() {
        return this.id;
    }
}

public class MfcDemo {
    public static void main(String[] args) {
    }
}
