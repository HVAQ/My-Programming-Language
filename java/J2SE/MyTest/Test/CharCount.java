public class CharCount {
	public static void main(String args[]) {
		String str = "want you to know one thing";
		int nCount = 0;
		int oCount = 0;
		char ch[] = str.toCharArray();

		for (int index = 0; index < ch.length; index++) {
			if (ch[index] == 'n') {
				nCount++;
			} else if (ch[index] == 'o') {
				oCount++;
			}
		}
		System.out.println(str + "中有n" + nCount + "个，" + "o" + oCount + "个。");
	}
}
