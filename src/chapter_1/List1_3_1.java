package chapter_1;

import java.util.Random;

public class List1_3_1 {

	private static final int N = 10;
	private static int[] sort = new int[N];

	private static void quickSort(int bottom, int top, int[] data) {
		int lower, upper;

		if(bottom >= top) {
			return;
		}
		// 先頭の値を適当な値とする
		int div = data[bottom];

		for(lower = bottom, upper = top; lower < upper;) {
			while(lower <= upper && data[lower] <= div)
				lower++;
			while (lower <= upper && data[upper] > div)
				upper--;
			if(lower < upper) {
				System.out.println("lower:" + lower + " upper:" + upper);

				int temp = data[lower];
				data[lower] = data[upper];
				data[upper]=temp;
			}
		}

		// 最初に選択した値を中央に移動
		int temp= data[bottom];
		data[bottom]=data[upper];
		data[upper]=temp;

		// 配列表示はじめ
		String s ="\n";

		for(int j=0; j<N; ++j) {
			if(j==bottom) {
				s += "B" + sort[j] + " ";
			}else if(j==upper) {
				s += "U" + sort[j] + " ";
			}else {
				s += sort[j] + " ";
			}
		}
		System.out.println(s);
		// 配列表示　おわり

		quickSort(bottom, upper-1, data);
		quickSort(upper+1, top, data);
	}

	public static void main(String args[]) {

		Random random = new Random();
		System.out.println("Sort prepare");

		String s = "";

		for(int i=0; i<N; ++i) {
			sort[i] = random.nextInt(100);
			s += sort[i] + " ";
		}

		System.out.println(s);

		System.out.println("\nSort Start");
		quickSort(0, N-1, sort);
		System.out.println("Sort End\n");

		s ="";

		for(int i=0; i<N; ++i) {
			s += sort[i] + " ";
		}

		System.out.println(s);

	}
}
