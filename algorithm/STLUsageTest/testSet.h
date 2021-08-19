//
// Created by mozhenhai on 2021/8/6.
//

#ifndef STLUSAGETEST_TESTSET_H
#define STLUSAGETEST_TESTSET_H

#include <set>
#include <iostream>

using namespace std;
bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
    bool operator() (const int& lhs, const int& rhs) const
    {return lhs<rhs;}
};
namespace TestSet {
    void testSet() {
        //set::set()函数 功能：构造set
        set<int> first;//empty set of ints
        int myInts[]{1, 2, 3, 4, 5};
        set<int> second(myInts, myInts + 5);
        //pointers used as iterator
        const set<int> &third(second);//a copy of second
        set<int> fourth(second.begin(), second.end());
        //iterator ctor
        set<int, classcomp> fifth;
        //class as compare
        bool (*fn_pt)(int, int) =fncomp;
        set<int, bool (*)(int, int)> sixth(fn_pt);//function pointer as compare
        cout << "------------------------------------------" << endl;
    }

    void testOperator() {
        //set::operator=()函数 功能：赋值set
        //set::size()函数 功能：集合中元素的数目
        //set::begin()函数  功能：返回指向第一个元素的迭代器
        //set::end()函数 功能：返回指向最后一个元素的迭代器
        int myInts[] = {1998, 11, 1, 2, 3};
        set<int> first(myInts, myInts + 5);//set with 5 ints
        set<int> second;//empty set
        second = first;//now second contains the 5 ints
        first = set<int>();//and first is empty
        set<int> mySet;
        mySet = second;

        cout << "Size of first:" << int(first.size()) << endl;
        cout << "Size of second:" << int(second.size()) << endl;
        set<int>::iterator it;
        cout << "mySet contains";
        for (it = mySet.begin(); it != mySet.end(); it++) {
            cout << " " << *it;
        }
        cout << "------------------------------------------" << endl;
    }

    void testBeginEnd() {
        //set::rbegin()函数 功能：返回指向集合中最后一个元素的反向迭代器
        //set::rend()函数  功能：返回指向集合中第一个元素的反向迭代器
        int myInts[] = {1998, 11, 1};
        set<int> mySet(myInts, myInts + 3);
        set<int>::iterator it;
        cout << "mySet contains:";
        for (it = mySet.begin(); it != mySet.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        set<int>::reverse_iterator rit;
        cout << "mySet contains:";
        for (rit = mySet.rbegin(); rit != mySet.rend(); rit++) {
            cout << " " << *rit;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testInsert() {
        //set::insert()函数 功能： 在集合中插入元素
        set<int> mySet;
        set<int>::iterator it;
        pair<set<int>::iterator, bool> ret;
        //set some initial values
        for (int i = 1; i < 6; i++) {
            mySet.insert(i * 10);
            //set:10  20 30 40 50
        }
        ret = mySet.insert(20);//no new elements inserted
        if (!ret.second)it = ret.first;//it now points to elements 20
        mySet.insert(it, 25);//max efficiency inserting
        mySet.insert(it, 24);//max efficiency inserting
        mySet.insert(it, 26);//no max efficiency inserting

        int myInts[] = {1949, 10, 1};
        //10 already in set,not inserted
        mySet.insert(myInts, myInts + 3);
        cout << "mySet contains:";
        for (it = mySet.begin(); it != mySet.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testEraseFind() {
        //set::erase()函数 功能：删除集合中的元素
        //set::find()函数 功能：返回一个指向被查找元素的迭代器
        set<int> mySet;
        set<int>::iterator it;
        //insert some values
        for (int i = 1; i < 11; i++) {
            mySet.insert(i * 10);
        }
        it = mySet.begin();
        it++;//it points now to 2o
        mySet.erase(it);
        mySet.erase(40);//找得到就删除，如果没有就删除，比如41
        it = mySet.find(60);

        mySet.erase(it, mySet.end());
        cout << "mySet contains:";
        for (it = mySet.begin(); it != mySet.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testClear() {
        //set::clear()函数 功能：清除所有元素
        set<int> mySet;
        set<int>::iterator it;
        mySet.insert(1998);
        mySet.insert(11);
        mySet.insert(3);
        cout << "mySet contains:";
        for (it = mySet.begin(); it != mySet.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        mySet.clear();
        cout << "mySet contains:";
        for (it = mySet.begin(); it != mySet.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        mySet.insert(1999);
        mySet.insert(2000);
        cout << "mySet contains:";
        for (it = mySet.begin(); it != mySet.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testEmpty() {
        //set::empty()函数 功能：如果集合为空，返回true
        set<int> mySet;
        mySet.insert(1998);
        mySet.insert(11);
        mySet.insert(3);
        mySet.insert(1999);
        cout << "mySet contains: ";
        while (!mySet.empty()) {
            cout << " " << *mySet.begin();
            mySet.erase(mySet.begin());
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testCount() {
        //set::count()函数 功能：返回某个值元素的个数
        set<int> mySet1;
        //set some initial values
        for (int i = 1; i < 5; i++) {
            mySet1.insert(i * 3);//set:3 6 9 12
        }
        for (int i = 0; i < 10; i++) {
            cout << i;
            if (mySet1.count(i) > 0)
                cout << "is an elements of mySet" << endl;
            else
                cout << "is not an elements of mySet" << endl;

        }
        mySet1.insert(9);
        mySet1.insert(9);
        mySet1.insert(9);
        cout << mySet1.count(9) << endl;//只输出一个
        //multiset::count()函数 与set::count()有区别
        int myInts[] = {1, 2, 3, 3, 3, 3, 3, 4, 5, 6};
        multiset<int> mySet(myInts, myInts + sizeof(myInts));
        cout << "3 appears ";
        cout << (int) mySet.count(3);
        cout << " times in mySet" << endl;
        //与set的区别，其他函数大都相同
        cout << "------------------------------------------" << endl;
    }

    void testSize() {
        //set::size()函数 功能：集合中元素的数目
        set<int> mySet;
        mySet.insert(1998);
        mySet.insert(11);
        mySet.insert(3);
        cout << "mySet contains: ";
        while (!mySet.empty()) {
            cout << " " << *mySet.begin();
            mySet.erase(mySet.begin());
        }
        cout << endl;
        cout << "size " << (int) mySet.size() << endl;
        for (int i = 1; i < 11; i++)mySet.insert(i);
        cout << "size " << (int) mySet.size() << endl;
        mySet.insert(1998);
        mySet.insert(98);//插入自动排序
        cout << "size " << (int) mySet.size() << endl;
        mySet.erase(6);
        cout << "size " << (int) mySet.size() << endl;
        cout << "mySet contains: ";
        set<int>::iterator it;
        for (it = mySet.begin(); it != mySet.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testSwap() {
        //set::swap()函数 功能：交换两个集合变量
        int myInts[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        set<int> first(myInts, myInts + 3);
        set<int> second(myInts + 3, myInts + 6);
        set<int>::iterator it;

        cout << "before swap first contains:";
        for (it = first.begin(); it != first.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "before swap second contains:";
        for (it = second.begin(); it != second.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;

        first.swap(second);

        cout << "first contains:";
        for (it = first.begin(); it != first.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "second contains:";
        for (it = second.begin(); it != second.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testGetAllocator() {
        //set::get_allocator()函数 功能:返回集合分配器
        set<int> mySet;
        int *p;

        //allocate an array of 5 elements using mySet's allocator
        p = mySet.get_allocator().allocate(6);
        //assign some values to array
        for (int i = 0; i < 6; i++) {
            p[i] = (i + 1) * 10;
        }
        cout << "The allocated array contains:";
        for (int i = 0; i < 6; i++) {
            cout << " " << p[i];
        }
        cout << endl;
        mySet.get_allocator().deallocate(p, 6);
        cout << "------------------------------------------" << endl;
    }

    void testKeyComp() {
        //set::key_comp()函数 功能：返回一个用于元素间比较的函数
        set<int> mySet;

        set<int>::iterator it;
        int highest;

        for (int i = 0; i <= 5; i++) {
            mySet.insert(i);
        }
        cout << "mySet contains:";
        highest = *mySet.rbegin();
        //set::rbegin()返回指向集合中最后一个元素的反向迭代器

        it = mySet.begin();
        do {
            cout << " " << *it;
        } while (mySet.key_comp()(*it++, highest));
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testValueComp() {
        //set::value_comp()函数 功能：返回一个用于
        set<int> mySet;

        set<int>::iterator it;
        int highest;

        for (int i = 0; i <= 5; i++) {
            mySet.insert(i);
        }
        cout << "mySet contains:";
        highest = *mySet.rbegin();
        //set::rbegin()返回指向集合中最后一个元素的反向迭代器

        it = mySet.begin();
        do {
            cout << " " << *it;
        } while (mySet.value_comp()(*it++, highest));
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testBound() {
        //set::lower_bound()函数 返回指向大于等于某值的第一个元素的迭代器
        //set::upper_bound()函数 返回指向大于等于某值的迭代器
        set<int> mySet;
        set<int>::iterator it, itLow, itUp;
        for (int i = 1; i < 10; i++) {
            mySet.insert(i * 10);//10 20 30 40 50 60 70 80 90
        }
        itLow = mySet.lower_bound(30);
        itUp = mySet.upper_bound(60);
        cout << "itLow:" << *itLow << endl;
        cout << "itUp:" << *itUp << endl;
        mySet.erase(itLow, itUp);//不删除itUp指向的元素
        //10 20 70 80 90
        cout << "mySet contains:";
        for (it = mySet.begin(); it != mySet.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testMaxSize() {
        //set::max_size()函数 返回集合能容纳的元素的最大限值
        set<int> mySet;
        if (mySet.max_size() > 1000) {
            for (int i = 0; i < 1000; i++) {
                mySet.insert(i);
            }
            cout << "the set contains 1000 elements" << endl;
        } else {
            cout << "the set could not contains 1000 elements" << endl;
        }
        cout << mySet.max_size();
        cout << "------------------------------------------" << endl;
    }

    void testEqualRange() {
        //set::equal_range()函数 功能：返回集合中与给定值相等的上下限的两个迭代器
        set<int> mySet;
        pair<set<int>::iterator, set<int>::iterator> ret;
        for (int i = 1; i < 6; i++) {
            mySet.insert(i * 10);//set:10 20 30 40 50
        }
        ret = mySet.equal_range(30);
        cout << "lower bound points to:" << *ret.first << endl;
        cout << "upper bound points to:" << *ret.second << endl;
        cout << "------------------------------------------" << endl;
    }

}
#endif //STLUSAGETEST_TESTSET_H
