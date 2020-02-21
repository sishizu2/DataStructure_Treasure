package chapter_2;

import java.io.BufferedReader;
import java.util.Arrays;
import java.util.Random;

public class List2_4 {

	// left -- mid ---- right

	private static int binarySearch(int x, int[] a) {

		int left = 0, right = a.length - 1, mid;

		while(left < right) {
			mid = (left + right)/2;

			if(a[mid] < x) {
				// midより左側←にはXは存在しない
				left = mid + 1;
			}else {
				// midより右側→にはXは存在しない
				right = mid;
			}
		}

		if(a[left] == x) {
			return left;
		}

		// サーチ範囲がなくなっても一致なし
		return -1;
	}

	public static void main(String args[]) {

		int[] array = new int[20];
		Random random = new Random();

		for(int i = 0; i < array.length; ++i) {
			array[i] = random.nextInt(10);
		}

		String s = "";

		Arrays.sort(array);
		for(int i = 0; i < array.length; ++i) {
			s += array[i] + " ";
		}
		System.out.println(s);

		System.out.println("\nWhat are you looking for:");
		int x = intReader();

		int r = binarySearch(x, array);

		if(r == -1) {
			System.out.println(x + " is not found");
		}else {
			System.out.println(x + " is " + r + "th");
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
