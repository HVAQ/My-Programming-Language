public class delAllEmpty {
    public static void main(String[] args) {
        String str = " 安徽理工大学 知通团队 java 组 20120909 ";
        delEmpty(str);
    }

    public static void delEmpty(String str) {
        char ch[] = str.toCharArray();
        for (int index = 0; index < ch.length; index++) {
            if (ch[index] != ' ') {
                System.out.print(ch[index]);
            }
        }
        System.out.println();
    }
}
