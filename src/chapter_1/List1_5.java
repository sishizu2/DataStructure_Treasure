package chapter_1;

import java.util.Random;

public class List1_5 {

	// データの件数
	private static final int N = 10;
	private static final int[] sort = new int[N];

	private static void mergeSort(int n, int[] x, int offset) {

		if(n <= 1) {
			return;
		}

		int m = n/2;

		// ブロックを前半と後半に分ける
		mergeSort(m, x, offset);
		mergeSort(n - m, x, offset + m);

		int[] buffer = new int[m];

		// 併合（マージ）作業
		for(int i = 0; i < m; ++i) {
			buffer[i] = x[offset + i];
		}

		int j = m;
		int i = 0;
		int k = 0;

		while(i < m && j < n) {

			if(buffer[i] <= x[offset + j]) {
				x[offset + k++] = buffer[i++];
			}else {
				x[offset + k++] = x[offset + j++];
			}
		}

		while(i < m) {
			x[offset + k++] = buffer[i++];
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

		mergeSort(N, sort, 0);

		System.out.println("sort end\n");

		s = "";
		for(int i = 0; i < N; ++i) {
			s += sort[i] + " ";
		}
		System.out.println(s);
	}

}
