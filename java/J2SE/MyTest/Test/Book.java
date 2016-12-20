class MyBook {
    private String bname;
    private int bid;
    private double price;
    private static int count = 0;

    public MyBook() {
        count++;
        this.bid = count;
    };

    public MyBook (String bname) {
        this();
        this.bname = bname;
    }

    public MyBook (String bname, double price) {
        this();
        this.bname = bname;
        this.price = price;
    }

    public void setBname(String bname) {
        this.bname = bname;
    }

    public String getBname() {
        return this.bname;
    }
    
    public void setBid(int bid) {
        this.bid = bid;
    }

    public int getBid() {
        return this.bid;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getPrice() {
        return this.price;
    }

    public String getInfo() {
        return "书名: " + this.bname +
            "\t编号: " + this.bid +
            "\t价格: " + this.price +
            "\t总册数: " + this.count;
    }
}

public class Book {
    public static void main(String[] args) {
        MyBook MyBook1 = new MyBook("JAVA 开发", 79.8);
        MyBook MyBook2 = new MyBook();
        MyBook MyBook3 = new MyBook("网络安全与技术");
        MyBook MyBook4 = new MyBook("漏洞挖掘与利用", 99);

        System.out.println(MyBook1.getInfo());
        System.out.println(MyBook2.getInfo());
        System.out.println(MyBook3.getInfo());
        System.out.println(MyBook4.getInfo());
    }
}
