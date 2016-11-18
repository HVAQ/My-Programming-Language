public class ChenFaKouJue {
    public static void main (String args[]) {
        for (int big = 1; big <= 9; big++) {
            for (int small = 1; small <= big; small++) {
                int sum = big * small;
                System.out.print(small + " * " + big + " = " + sum);
                int index = (sum < 10) ? 5 : 4;
                for (int count = 0; count < index; count++)
                    System.out.print(" ");
            }
            System.out.println();
        }
    }
}
