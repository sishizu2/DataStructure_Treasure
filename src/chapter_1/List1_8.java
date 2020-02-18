package chapter_1;

import java.util.Random;

public class List1_8 {

	private static final int N = 10;
	private static int[] sort = new int[N];

	private static void binaryInsertSort() {
		// 最初から最後まで全てソート済になるまで繰り返す
		for(int sorted=1; sorted<N; ++sorted) {
			// ソート済領域の直後の値を取り出す
			int insert=sort[sorted];
			// 挿入場所を見つける
			int i, left, right;
			left=0;
			right=sorted;
			while(left<right) {
				int mid=(left+right)/2;
				if(sort[mid]<insert) {
					left=mid+1;
				}else {
					right=mid;
				}
			}
			i=left;
			// ソート済領域直後の値を挿入
			while(i<=sorted) {
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
		binaryInsertSort();
		System.out.println("Sort End\n");

		s ="";

		for(int i=0; i<N; ++i) {
			s += sort[i] + " ";
		}

		System.out.println(s);
	}

}
