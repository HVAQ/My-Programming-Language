public class ShuZuZhuanHuan {
    public static void main(String args[]) {
        int data[][] = new int[][] {
            {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
        };
        // 转换
        ZhuanHuan(data);
        // 输出
        ShuChu(data);
    }

    public static void ZhuanHuan(int arr[][]) {
        for (int hang = 0; hang < arr.length; hang++)
            for (int lie = hang; lie < arr[hang].length; lie++)
                if (hang != lie) {
                    int temp = arr[hang][lie];
                    arr[hang][lie] = arr[lie][hang];
                    arr[lie][hang] = temp;
                }
    }

    public static void ShuChu(int arr[][]) {
        for (int hang = 0; hang < arr.length; hang++) {
            for (int lie = 0; lie < arr[hang].length; lie++)
                System.out.print(arr[hang][lie] + "、");
            System.out.println();
        }
    }
}
