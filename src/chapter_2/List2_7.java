package chapter_2;

import java.io.BufferedReader;
import java.util.Random;

public class List2_7 {

	private static int organizationSearch(int x, int[] a) {

		int n = 0;

		// 配列の範囲内で目的の値を探す
		while(n < a.length && a[n] != x)
			n++;

		if(n < a.length) {
			if(n > 0) {
				// 一つ前と入れ替える
				int t = a[n-1];
				a[n-1] = a[n];
				a[n] = t;

				String s = "";

				for(int i=0; i<a.length; ++i) {
					s += a[i] + " ";
				}
				System.out.println(s);

				return n - 1;
			}
			return n;
		}
		return -1;
	}

	public static void main(String args[]) {

		int[] array = new int[20];
		Random random = new Random();

		String s = "";

		for(int i=0; i<array.length; ++i) {
			array[i] = random.nextInt(20);
			s += array[i] + " ";
		}

		System.out.println(s);

		while(true) {

			System.out.println("What are you looking for?");

			int x = intReader();
			if(x == -1) {
				break;
			}

			int r = organizationSearch(x, array);

			if(r == -1) {
				System.out.println("Not found");
			}else {
				System.out.println(r + "th");
			}

		}
 	}

	private static int intReader() {

		try {
			BufferedReader read = new BufferedReader(new java.io.InputStreamReader(System.in));
			String str = read.readLine();
			return Integer.parseInt(str);
		}catch(java.io.IOException e) {
			return 0;
		}
	}

}
