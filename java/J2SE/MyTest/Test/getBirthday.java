public class getBirthday {
    public static void main(String[] args) {
        String str = "141121199509160171";
        birthday(str);
    }
    
    public static void birthday(String str) {
        char ch[] = str.toCharArray();
        if (ch.length == 18) {
            String year = new String(ch, 6, 4);
            String month = new String(ch, 10, 2);
            String day = new String(ch, 12, 2);
            System.out.println(year + "年" + month + "月" + day + "日");
        }
    }
}
