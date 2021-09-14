//
// Created by mozhenhai on 2021/9/5.
//

#ifndef ONEQUESTIONPERDAY_IMPLEMENTRAND10USINGRAND7_H
#define ONEQUESTIONPERDAY_IMPLEMENTRAND10USINGRAND7_H

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

namespace rand10UsingRand7{
    class Solution {
    public:
        int rand10() {
            while(true){
                int sum = (rand7()-1)*7+rand7();
                if(sum<=40) return sum%10 +1;
            }

        }
    };

}

#endif //ONEQUESTIONPERDAY_IMPLEMENTRAND10USINGRAND7_H
