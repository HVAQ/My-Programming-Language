public class delAllZero {
    public static void main(String[] args) {
        String str = "知通团队JAVA组20120909";
        print(delZero(str));
    }

    public static char [] delZero(String str) {
        char ch[] = str.toCharArray();
        char ch_now[] = new char[ch.length];
        for (int index = 0, count = 0; index < ch.length; index++) {
            if (ch[index] != '0') {
                ch_now[count] = ch[index];
                count++;
            }
        }
        return ch_now;
    }

    public static void print(char ch[]) {
        for (int index = 0; index < ch.length; index++) {
            System.out.print(ch[index]);
        }
        System.out.println();
    }
}
