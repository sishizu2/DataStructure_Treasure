package chapter_1;

import java.util.Random;

public class List1_6 {
	// data amount
	private static final int N = 10;
	private static int[] sort = new int[N];

	/**
	 *
	 */
	private static void combSort() {
		boolean flag;
		int gap = N;

		do {
			// 収縮率は1.3
			gap =(gap *10)/13;

			if(gap==0) {
				gap=1;
			}
			flag = true;
			for(int i = 0; i < N-gap; i++) {
				// 先頭から順に見ていく
				if(sort[i] > sort[i+gap]) {
					// 距離がGAP分離れた要素を比較、並びがおかしければ並べ替え
					flag = false;
					int temp = sort[i];
					sort[i] = sort[i+gap];
					sort[i+gap] = temp;

					String s ="\n";

					for(int j=0; j<N; ++j) {
						s += sort[j] + " ";
					}
					System.out.println(s);
				}
			}
			// 一度も並べ替えずにGAP＝＝１で見終われば終了
		}while((gap>1) || !flag);
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
		combSort();
		System.out.println("Sort End\n");

		s ="";

		for(int i=0; i<N; ++i) {
			s += sort[i] + " ";
		}

		System.out.println(s);
	}

}
