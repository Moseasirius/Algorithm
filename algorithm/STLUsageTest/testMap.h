//
// Created by mozhenhai on 2021/8/6.
//

#ifndef STLUSAGETEST_TESTMAP_H
#define STLUSAGETEST_TESTMAP_H

#include <map>
#include <iostream>

using namespace std;
namespace TestMap {
    void testOperator() {
        //map::operator=()函数 赋值map
        map<char, int> first;
        map<char, int> second;
        first['x'] = 8;
        first['y'] = 18;
        first['z'] = 28;
        second = first;//second now contains 3 ints
        first = map<char, int>();//and first is now empty
        cout << "size of first: " << int(first.size()) << endl;
        cout << "size of second: " << int(second.size()) << endl;
        cout << "------------------------------------------" << endl;
    }

    void testBeginEnd() {
        //map::begin()函数 功能：返回指向map头部的迭代器
        //map::end()函数 功能：返回指向map末尾的迭代器
        //map::rbegin()函数 功能：返回一个指向map尾部的逆向迭代器
        //map::rend()函数 功能：返回一个指向map头部的逆向迭代器
        map<char, int> myMap;
        map<char, int>::iterator it;
        myMap['a'] = 100;
        myMap['b'] = 200;
        myMap['c'] = 300;
        //show content;
        for (it = myMap.begin(); it != myMap.end(); it++) {
            cout << (*it).first << ":" << (*it).second << endl;
        }
        map<char, int>::reverse_iterator rit;
        for (rit = myMap.rbegin(); rit != myMap.rend(); rit++) {
            cout << (*rit).first << ": " << (*rit).second << endl;

        }
        cout << "------------------------------------------" << endl;
    }

    void testInert() {
        //map::insert()函数 功能：插入元素
        map<char, int> myMap;
        map<char, int>::iterator it;
        pair<map<char, int>::iterator, bool> ret;
        //first insert function version(single parameter):
        myMap.insert(pair<char, int>('a', 10));
        myMap.insert(pair<char, int>('z', 20));
        ret = myMap.insert(pair<char, int>('z', 60));
        if (!ret.second) {
            cout << "element  'z' already existed" << endl;
            cout << "with a value of " << ret.first->second << endl;
        }
        //second insert function version(with hint position):
        it = myMap.begin();
        myMap.insert(it, pair<char, int>('b', 11));//max efficiency inserting
        myMap.insert(it, pair<char, int>('c', 12));//no max efficiency inserting
        //third insert function version(range insertion)
        map<char, int> anotherMap;
        anotherMap.insert(myMap.begin(), myMap.find('c'));
        //show contents:
        cout << "myMap contains:" << endl;
        for (it = myMap.begin(); it != myMap.end(); it++) {
            cout << (*it).first << ":" << (*it).second << endl;
        }
        cout << "anotherMap contains:" << endl;
        for (it = anotherMap.begin(); it != anotherMap.end(); it++) {
            cout << (*it).first << ":" << (*it).second << endl;
        }
        cout << "------------------------------------------" << endl;
    }

    void testErase() {
        //map::erase()函数 功能：删除一个元素
        map<char, int> myMap;
        map<char, int>::iterator it;
        // insert some values
        myMap['a'] = 1;
        myMap['b'] = 2;
        myMap['c'] = 3;
        myMap['d'] = 4;
        myMap['e'] = 5;
        myMap['f'] = 6;
        myMap['g'] = 7;
        it = myMap.find('b');
        myMap.erase(it);//erasing by iterator
        myMap.erase('c');//erasing by key
        it = myMap.find('e');
        myMap.erase(it, myMap.end());//erasing by range
        //show content
        for (it = myMap.begin(); it != myMap.end(); it++) {
            cout << (*it).first << ":" << (*it).second << endl;
        }
        cout << "------------------------------------------" << endl;
    }

    void testClear() {
        //map::clear() 函数 功能：删除所有元素
        map<char, int> myMap;
        map<char, int>::iterator it;
        myMap['m'] = 1998;
        myMap['z'] = 11;
        myMap['h'] = 3;
        cout << " myMap contains:\n";
        for (it = myMap.begin(); it != myMap.end(); it++) {
            cout << (*it).first << "->" << (*it).second << endl;
        }
        myMap.clear();
        myMap['a'] = 1999;
        myMap['b'] = 9;
        myMap['c'] = 15;
        cout << " myMap contains:\n";
        for (it = myMap.begin(); it != myMap.end(); it++)
            cout << (*it).first << "->" << (*it).second << endl;
        cout << "------------------------------------------" << endl;
    }

    void testFind() {
        //map::find()函数 功能：查找一个元素，如果找到返回改元素的迭代器
        map<char, int> myMap;
        map<char, int>::iterator it;
        // insert some values
        myMap['a'] = 1;
        myMap['b'] = 2;
        myMap['c'] = 3;
        myMap['d'] = 4;
        myMap['e'] = 5;
        myMap['f'] = 6;
        myMap['g'] = 7;
        it = myMap.find('b');
        myMap.erase(it);
        myMap.erase(myMap.find('d'));
        while (!myMap.empty()) {
            cout << (*myMap.begin()).first << ":" << (*myMap.begin()).second << endl;
            cout << myMap.begin()->first << ":" << myMap.begin()->second << endl;
            myMap.erase(myMap.begin());
        }
        cout << "------------------------------------------" << endl;
    }

    void testCount() {
        //map::count()函数 功能：返回指定元素出现的次数
        map<char, int> myMap1;

        myMap1['a'] = 1;
        myMap1['b'] = 2;
        myMap1['c'] = 3;
        for (char c = 'a'; c < 'h'; c++) {
            cout << c;
            if (myMap1.count(c) > 0)
                cout << "  is an elements of  myMap1" << endl;
            else
                cout << "  is not an elements of  myMap1" << endl;
        }
        //multimap::count()函数 与map::count()有区别
        map<char, int> myMap;
        myMap['a'] = 1;
        myMap['a'] = 2;
        myMap['a'] = 3;
        cout << "map count 'a'" << myMap.count('a') << endl;//只输出1

        multimap<char, int> myMultimap;
        myMultimap.insert(pair<char, int>('a', 1));
        myMultimap.insert(pair<char, int>('a', 2));
        myMultimap.insert(pair<char, int>('a', 3));
        cout << "multimap count 'a'" << myMultimap.count('a') << endl;//输出3


        multimap<char, int> myMultimap1;
        multimap<char, int>::iterator it;

        myMultimap1.insert(pair<char, int>('x', 1));
        myMultimap1.insert(pair<char, int>('y', 2));
        myMultimap1.insert(pair<char, int>('y', 3));
        myMultimap1.insert(pair<char, int>('y', 4));
        myMultimap1.insert(pair<char, int>('z', 5));
        myMultimap1.insert(pair<char, int>('z', 6));
        myMultimap1.insert(pair<char, int>('y', 1));
        myMultimap1.insert(pair<char, int>('z', 1));
        for (char c = 'x'; c <= 'z'; c++) {
            cout << "there are " << (int) myMultimap1.count(c);
            cout << " elements with key  " << c << "  :";
            for (it = myMultimap1.equal_range(c).first; it != myMultimap1.equal_range(c).second; ++it)
                cout << " " << (*it).second;
            cout << endl;
        }
        cout << "------------------------------------------" << endl;
    }

    void testSizeAndSwap() {
        //map::swap()函数 功能：交换两个map
        //map::size()函数 功能：返回map中元素的个数
        map<char, int> foo;
        map<char, int> bar;
        map<char, int>::iterator it;
        foo['x'] = 1;
        foo['y'] = 2;
        foo['z'] = 3;
        bar['a'] = 4;
        bar['b'] = 5;
        cout << "before swap foo contains:" << endl;
        for (it = foo.begin(); it != foo.end(); it++) {
            cout << (*it).first << "->" << (*it).second << endl;
        }
        cout << "size of foo: " << foo.size() << endl;
        cout << "before swap bar contains:" << endl;
        for (it = bar.begin(); it != bar.end(); it++) {
            cout << (*it).first << "->" << (*it).second << endl;
        }
        cout << "size of bar: " << bar.size() << endl;
        foo.swap(bar);
        cout << "after swap foo contains:" << endl;
        for (it = foo.begin(); it != foo.end(); it++) {
            cout << (*it).first << "->" << (*it).second << endl;
        }
        cout << "size of foo: " << foo.size() << endl;
        cout << "after swap bar contains:" << endl;
        for (it = bar.begin(); it != bar.end(); it++) {
            cout << (*it).first << "->" << (*it).second << endl;
        }
        cout << "size of bar: " << bar.size() << endl;
        cout << "------------------------------------------" << endl;
    }

    void testGetAllocator() {
        //map::get_allocator()函数 功能：返回map的配置器
        int pSize;
        map<char, int> myMap;
        pair<const char, int> *p;
        //allocate an array of 5 elements using map's allocate
        p = myMap.get_allocator().allocate(5);
        pSize = (int) sizeof(map<char, int>::value_type) * 5;
        cout << "the allocated array has a size of" << pSize << "bytes" << endl;
        myMap.get_allocator().deallocate(p, 5);
        cout << "------------------------------------------" << endl;
    }

    void testKeyComp() {
        //may::key_comp()函数 功能：返回比较元素key的函数
        map<char, int> myMap;
        map<char, int>::iterator it;
        char highest;


        myMap['a'] = 1;
        myMap['b'] = 3;
        myMap['c'] = 4;
        myMap['d'] = 5;
        myMap['e'] = 2;
        cout << " myMap contains:" << endl;
        highest = myMap.rbegin()->first;//key value of last element
        it = myMap.begin();
        do {
            cout << (*it).first << "->" << (*it).second << endl;
        } while (myMap.key_comp()((*it++).first, highest));
        cout << endl;
        cout << "------------------------------------------" << endl;
    }

    void testValueComp() {
        //map::value_comp()函数 功能：返回比较元素value的函数
        map<char, int> myMap;
        map<char, int>::iterator it;
        pair<char, int> highest;
        myMap['x'] = 2000;
        myMap['y'] = 2001;
        myMap['z'] = 2002;
        cout << " myMap contains:" << endl;
        highest = *myMap.rbegin();//last element
        it = myMap.begin();
        do {
            cout << (*it).first << "->" << (*it).second << endl;

        } while (myMap.value_comp()(*it++, highest));
        cout << "------------------------------------------" << endl;
    }

    void testBound() {
        //map::lower_bound()函数 功能：返回键值大于等于(>=)给定元素的第一个位置
        //map::upper_bound()函数 功能：返回键值大于(>)给定元素的第一个位置
        map<char, int> myMap;
        map<char, int>::iterator it, itLow, itUp;
        myMap['a'] = 20;
        myMap['b'] = 40;
        myMap['c'] = 60;
        myMap['d'] = 80;
        myMap['e'] = 100;
        myMap['f'] = 120;
        myMap['g'] = 140;
        itLow = myMap.lower_bound('b');//itLow points to b
        itUp = myMap.upper_bound('d');//itUp points to e (not d!)
        myMap.erase(itLow, itUp);//erases [itLow,itUp)
        //print content:
        for (it = myMap.begin(); it != myMap.end(); it++) {
            cout << (*it).first << "->" << (*it).second << endl;
        }
        cout << "------------------------------------------" << endl;
    }

    void testMaxSize() {
        //map::max_size()函数 功能：返回可以容纳的最大元素个数
        map<int, int> myMap;
        if (myMap.max_size() > 1000) {
            for (int i = 0; i < 10; i++) myMap[i] = 1;
            cout << "the map contains 10 elements \n";
        } else cout << "the map could not hold 1000 elements\n";
        cout << " myMap contains: ";
        map<int, int>::iterator it;
        for (it = myMap.begin(); it != myMap.end(); it++) {
            cout << (*it).first << "   " << (*it).second << endl;
        }
        cout << "------------------------------------------" << endl;
    }

    void testEqualRange() {
        //map::equal_range()函数 功能：返回map中与给定值相等的上下限的两个迭代器
        //左闭右开
        map<char, int> myMap;
        pair<map<char, int>::iterator, map<char, int>::iterator> ret;
        myMap['a'] = 1;
        myMap['b'] = 2;
        myMap['e'] = 4;
        myMap['c'] = 3;
        ret = myMap.equal_range('b');
        cout << "lower bound points to : ";
        cout << ret.first->first << " ->" << ret.first->second << endl;
        cout << "upper bound points to : ";
        cout << ret.second->first << " ->" << ret.second->second << endl;
        cout << "------------------------------------------" << endl;
    }


}
#endif //STLUSAGETEST_TESTMAP_H
