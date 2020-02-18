package chapter_1;

import java.util.Random;

public class List1_7 {

	private static final int N = 10;
	private static int[] sort = new int[N];

	private static void insertSort() {
		// 最初から最後までソート済になるまで繰り返す
		for(int sorted=0; sorted<N-1; ++sorted) {
			// ソート済領域の直後の値を取り出す
			int insert=sort[sorted+1];
			// 挿入場所を見つける　リニアサーチ
			int i;
			for(i=0; i<= sorted; ++i) {
				if(sort[i] > insert) {
					break;
				}
			}

			// ソート済領域直後の値を挿入
			while(i<=sorted+1) {
				int temp=sort[i];
				sort[i]=insert;
				insert=temp;
				++i;
			}

			String s ="\n";

			for(int j=0; j<N; ++j) {

				if(j==i) {
					s+= "*" + sort[j] + " ";
				}else {
					s += sort[j] + " ";
				}
			}
			System.out.println(s);

		}
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
		insertSort();
		System.out.println("Sort End\n");

		s ="";

		for(int i=0; i<N; ++i) {
			s += sort[i] + " ";
		}

		System.out.println(s);
	}

}
