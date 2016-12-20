public class ChangeStr {
	public static void main(String args[]) {
		String str = "知通团队JAVA20120909";
		String str_one = str.replaceAll("JAVA", "J2EE");
		System.out.println(str_one);
	}
}
