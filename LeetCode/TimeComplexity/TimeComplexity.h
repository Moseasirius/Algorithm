//
// Created by mozhenhai on 2021/8/8.
//

#ifndef TIMECOMPLEXITY_TIMECOMPLEXITY_H
#define TIMECOMPLEXITY_TIMECOMPLEXITY_H
#include <iostream>
#include <ctime>
#include <cmath>
#include <cassert>
using namespace std;
void timeComplexityBasic() {
    // 数据规模每次增大10倍进行测试
    // 有兴趣的同学也可以试验一下数据规模每次增大2倍哦:)
    for (int x = 1; x <= 9; x++) {

        int n = pow(10, x);

        clock_t startTime = clock();

        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += i;
        clock_t endTime = clock();

        cout << "sum = " << sum << endl;
        cout << "10^" << x << " : "
             << double(endTime - startTime) / CLOCKS_PER_SEC
             << " s" << endl << endl;
    }
}
    int sum1( int n ){

        assert( n >= 0 );
        int ret = 0;
        for( int i = 0 ; i <= n ; i ++ )
            ret += i;
        return ret;
    }

    int sum2( int n ){

        assert( n >= 0 );
        if( n == 0 )
            return 0;

        return n + sum2(n-1);
    }
    void timeComplexityBasic2(){

        cout << sum1(10000) << endl;
        cout << sum2(10000) << endl;

    }




#endif //TIMECOMPLEXITY_TIMECOMPLEXITY_H
