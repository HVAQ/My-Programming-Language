public class getDate {
	public static void main(String args[]) {
		String str = "知通团队JAVA20120909";
		char ch[] = str.toCharArray();
		String year = new String(ch, 8, 4);
		String month = new String(ch, 12, 2);
		String day = new String(ch, 14, 2);
		System.out.println(year + "年" + month + "月" + day + "日");
	}
}
