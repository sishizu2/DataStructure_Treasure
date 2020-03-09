package chapter_5;

public class List5_6 {
	// 開き直り数を列挙するプログラム
	private static long[] power = new long[10];
	private static int usingNumber[] =
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	List5_6(){

		for(int i = 0; i <= 9; i++) {
			int k = 1;
			for(int j = 0; j < i; j++) {
				k *= i;	// a*=b a = a*b
			}

			// 0の0乗は0なので、1から9まで計算
			power[i] = (i != 0) ? k : 0;

		}
	}

	// numberの中に、0から9の1桁の整数が何文字あるか数える関数
	private int numOfDigit(long number, long digit) {

		int ret = 0;

		// 0桁ならば0を返す
		if(number == 0) {
			return 0;
		}

		// 1の位がdigitであるかチェック
		if(number % 10 == digit) {
			ret = 1;
		}

		ret += numOfDigit(number / 10, digit);

		return ret;
	}

	// 数字群をもとに計算した結果の数字の個数が、元の数字群と同じだけ使われているかチェック 0は考慮せず
	private void checkNumber() {

		long result;
		result = 0;

		// 数字群を元に、計算結果を作成
		for(int i = 1; i <= 9; i++)
			result += power[i] * usingNumber[i];

		// 計算結果の中の数字の個数が、数字群と同じかどうか確認
		for(int i = 1; i <= 9; i++) {

			if(numOfDigit(result, i) != usingNumber[i]) {
				// 1つでも違えば、それは解ではない
				return;
			}
		}

		// 計算結果は解である
		System.out.println(result);
		return;
	}

	public void makeNumbers(int start, int kosuu) {
		int i;

		// 10桁を超えた数字に開き直り数は存在せず
		if(kosuu > 10) {
			return;
		}

		// startから9までの数を新たに生成する
		for(i = start; i <= 9; i++) {
			// 新しい数を末尾に追加
			usingNumber[i]++;

			// それが開き直り数になるかチェック
			checkNumber();

			// 追加した数の後ろに、もう一桁追加した場合を調べる
			makeNumbers(i, kosuu + 1);

			// 先ほど追加した数を消す
			usingNumber[i]--;

		}
	}

	public static void main(String[] args) {

		List5_6 sol = new List5_6();

		sol.makeNumbers(1, 1);

	}

}
