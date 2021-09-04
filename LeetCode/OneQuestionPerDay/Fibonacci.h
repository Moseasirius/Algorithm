//
// Created by mozhenhai on 2021/9/4.
//

#ifndef ONEQUESTIONPERDAY_FIBONACCI_H
#define ONEQUESTIONPERDAY_FIBONACCI_H
namespace fibonacci1{
    class Solution {
    private:
        vector<int> memo;

        int _fib(int n){
            if(n==0) return 0;
            if(n==1) return 1;
            if(memo[n]==-1)
                memo[n]=_fib(n-1)%(1000000007)+_fib(n-2)%(1000000007);

            return memo[n]%(1000000007);
        }
    public:
        int fib(int n) {
            memo = vector<int>(n+1,-1);
            return _fib(n);
        }
    };
}
namespace fibonacci2{
    class Solution {
    public:
        int fib(int n) {
            int zero = 0;
            int one =1;
            int sum =0;
            if(n==0) return 0;
            if(n==1) return 1;

            for(int i=2;i<=n;i++){
                sum = one%(1000000007)+zero%(1000000007);
                zero = one;
                one = sum;
            }
            return sum%(1000000007);
        }
    };
}
#endif //ONEQUESTIONPERDAY_FIBONACCI_H
