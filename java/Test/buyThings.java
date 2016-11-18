class Things {
    private String tname;
    private double price;
    private int tnum;
    private static double allPrice = 0;

    private Things(double price, int tnum) {
        // 超市买东西不会出现商品没名字的情况
        this.price = price;
        this.tnum = tnum;
        allPrice += price * tnum;
    }

    public Things(String tname, double price) {
        this(price, 1);
        this.tname = tname;
    }
    
    public Things(String tname, double price, int tnum) {
        this(price, tnum);
        this.tname = tname;
    }

    public void setTname(String tname) {
        this.tname = tname;
    }

    public String getTname() {
        return tname;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getPrice() {
        return this.price;
    }

    public void setTnum(int tnum) {
        this.tnum = tnum;
    }

    public int getTnum() {
        return this.tnum;
    }

    public String getInfo() {
        return "商品名称: " + this.tname +
            "  单价: " + this.price +
            "  数量: " + this.tnum + 
            "  总价: " + allPrice;
    }
}

public class buyThings {
    public static void main(String[] args) {
        Things t1 = new Things("练习本", 2.5, 2);
        Things t2 = new Things("钢笔", 15);
        Things t3 = new Things("圆珠笔", 3, 2);
        Things t4 = new Things("笔芯", 0.5, 6);
        Things t5 = new Things("橡皮", 1);
        System.out.println(t1.getInfo());
        System.out.println(t2.getInfo());
        System.out.println(t3.getInfo());
        System.out.println(t4.getInfo());
        System.out.println(t5.getInfo());
    }
}
