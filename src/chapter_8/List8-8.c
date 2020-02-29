#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 解析したい関数
double func(double x){
    return x * x * x * x
            - 10.0 * x * x * x * x
            + 25.0 * x * x * x
            + 40.0 * x * x
            + 200.0 * x - 500.0;
}

// 2分探索法　バイナリリサーチ
double BinarySearch(void){

    double left, mid, right, epsilon;

    // 「答えに非常に近い」と言える範囲を定義
    epsilon = 0.00001;

    // 「leftとrightの間に確実に解がある」という範囲を指定
    left = 1.0;
    right = 3.0;

    // 範囲をひたすら絞り込む   fabs関数でdouble型の絶対値を計算
    while(fabs(right - left) > epsilon && fabs(func(left)) > epsilon){

        mid = (left + right) / 2.0;

        // func(left)とfunc(mid)が同符号ならば
        if(func(left) * func(mid) >= 0.0){
            left = mid;
        }else{
            right = mid;
        }

    }
    return left;
}

int main(void){
    double d;
    d = BinarySearch();
    printf("Answer is %lf, the value is %lf \n", d, func(d));
    
    return EXIT_SUCCESS;
}