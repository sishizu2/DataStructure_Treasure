package chapter_1;

import java.util.Random;

public class List1_3 {

	// データの件数
	private static final int N = 10;
	private static final int[] sort = new int[N];

	private static void quickSort(int bottom, int top, int[] data) {

		int lower, upper;

		if(bottom >= top) {
			return;
		}

		// 先頭の値を適当な値とする
		int div = data[bottom];

		for(lower = bottom, upper = top; lower < upper;) {

			while(lower <= upper && data[lower] <= div) {
				lower++;
			}
			while(lower <= upper && data[upper] > div) {
				upper--;
			}
			if(lower < upper) {
				int temp = data[lower];
				data[lower] = data[upper];
				data[upper] = temp;

				quickSort(bottom, upper - 1, data);
				quickSort(upper + 1, top, data);
			}
		}


	}

	public static void main(String args[]) {
		Random random = new Random();

		System.out.println("sort prepare\n");
		String s = "";
		for(int i = 0; i < N; ++i) {
			sort[i] = random.nextInt(100);
			s += sort[i] + " ";
		}
		System.out.println(s);

		System.out.println("\nsort start");
		quickSort(0, N-1, sort);	// bottom = 0, top = N-1
		System.out.println("sort end\n");

		s = "";
		for(int i = 0; i < N; ++i) {
			s += sort[i] + " ";
		}
		System.out.println(s);
	}
}
