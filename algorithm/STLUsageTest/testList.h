//
// Created by mozhenhai on 2021/8/6.
//

#ifndef STLUSAGETEST_TESTLIST_H
#define STLUSAGETEST_TESTLIST_H
#include <list>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

namespace TestList{
    void testList(){
        //list::list()函数 功能：构造list
        //constructors used in the same order as described above:
        list<int>::iterator it;
        list<int>first;//empty list of ints
        list<int>second(5,20);//five ints with value 20;
        list<int>third(second.begin(),second.end());
        cout<<"the contents of third are:";
        for(it=third.begin();it!=third.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        //iterating through second
        list<int>fourth(third);
        cout<<"the contents of fourth are:";
        for(it=fourth.begin();it!=fourth.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        //a copy of third
        //the iterator constructor can also be used to construct from arrays
        int myInts[]={1998,11,3,520};
        list<int>fifth( myInts, myInts+sizeof( myInts)/sizeof(int));

        cout<<"the contents of fifth are:";
        for(it=fifth.begin();it!=fifth.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testOperator(){
        //list::operator=()函数 功能：赋值list
        list<int>first(3);//list of 3 zero-initialized ints
        list<int>second(11);//list of 11 zero-initialized ints
        second=first;
        first=list<int>();
        cout<<"size of first :"<<int(first.size())<<endl;
        cout<<"size of second :"<<int(second.size())<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testAssign(){
        //list::assign()函数 功能：给list赋值
        list<int>first;
        list<int>second;
        first. assign(5,20);//5 ints with value 20
        second.assign(first.begin(),first.end());//a copy of first
        list<int>::iterator it;
        cout<<"first contains:";
        for(it=first.begin();it!=first.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        int myInts[]={1998,11,3};
        first.assign( myInts, myInts+3);//assigning from array
        cout<<"size of first:"<<(int)first.size()<<endl;
        cout<<"size of second:"<<(int)second.size()<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testBeginEnd(){
        //list::begin()函数 功能：返回指向第一个元素的迭代器
        //list::end()函数 功能：返回末尾的迭代器
        //list::rbegin()函数 功能：返回指向list尾部的逆向迭代器
        //list::rend()函数 功能：返回指向第一个元素的逆向迭代器
        int myInts[]={1998,11,3,5,20};
        list<int>myList( myInts, myInts+5);
        list<int>::iterator it;
        cout<<"myList contains:";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        list<int>::reverse_iterator rit;
        cout<<"myList contains:";
        for(rit=myList.rbegin();rit!=myList.rend();rit++){
            cout<<" "<<*rit;
        }
        cout<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testBack(){
        //list::back()函数 功能：返回最后一个元素
        list<int>myList;
        list<int>::iterator it;
        myList.push_back(11);
        while(myList.back()!=1){
            myList.push_back(myList.back()-1);
        }
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testFront(){
        //list::front()函数 功能：返回第一个元素
        list<int>myList;
        myList.push_back(1998);
        myList.push_back(11);
        myList.push_back(3);
        //now front equals 1998,and back 3
        myList.front()-=myList.back();
        cout<<"myList.front()is now:  "<<myList.front()<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testPopPush(){
        //list::push_back()函数 功能：在list的末尾添加一个元素
        list<int>myList1;
        int myInts1=10;
        cout<<"please enter some integers(enter 0 to end):\n";
        do{

            myList1.push_back(myInts1);
            myInts1--;
        } while(myInts1);
        cout<<"myList1 stores:  "<<(int)myList1.size()<<endl;

        //list::pop_back()函数 功能： 删除最后一个元素
        list<int>myList2;
        int sum(0);
        myList2.push_back(1998);
        myList2.push_back(11);
        myList2.push_back(3);
        while(!myList2.empty()){
            sum+=myList2.back();
            myList2.pop_back();
        }
        cout<<"the elements of myList2 summed "<<sum<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testInsert(){
        cout<<"insert--------------------------"<<endl;
        //list::insert()函数 功能：插入一个元素到list中(插入下标的前面）
        list<int>myList;
        list<int>::iterator it;
        //set some initial values
        for(int i=1;i<11;i++){
            myList.push_back(i);//1 2 3 4 5 6 7 8 9 10
        }
        cout<<"myList1 contains:";
        for(int & it1 : myList){
            cout<<" "<<it1;
        }
        cout<<endl;

        it=myList.begin();
        ++it;//it points now to number 2
        myList.insert(it,1314);//1 1314 2 3 4 5 6 7 8 9 10
        cout<<"myList2 contains:";
        for(int & it2 : myList){
            cout<<" "<<it2;
        }
        cout<<endl;

        myList.insert(it,3,5);//1 1314 5 5 5 2 3 4 5 6 7 8 9 10
        //注意 此时 it 还是指向2 
        cout<<"myList3 contains:";
        for(int & it3 : myList){
            cout<<" "<<it3;
        }
        cout<<endl;

        vector<int>myVector(5,100);
        myList.insert(it,myVector.begin(),myVector.end());
        cout<<"myList4 contains:";
        for(int & it4 : myList){
            cout<<" "<<it4;
        }
        cout<<endl;
        //注意 此时 it 还是指向2
        myList.erase(it);//删掉了2  
        cout<<"myList5 contains:";
        for(int & it5 : myList){
            cout<<" "<<it5;
        }
        cout<<endl;
        //如果此时还删掉it，则没有效果 
        ++it; //删掉了3

        myList.erase(it);
        cout<<"myList6 contains:";
        for(int & it6 : myList){
            cout<<" "<<it6;
        }
        cout<<endl;

        myList.erase(--it,++it);//注意此时it的位置不变--++，如果两次++++ 
        cout<<"myList7 contains:";
        for(int & it7 : myList){
            cout<<" "<<it7;
        }
        cout<<endl;
        cout<<"insert--------------------------"<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testErase(){
        //list:erase()函数 功能：删除一个元素或者一组连续元素
        list<int>myList;
        list<int>::iterator it,it1,it2;
        //set some values:
        for(int i=1;i<10;i++)myList.push_back(i);
        //1 2 3 4 5 6 7 8 9
        cout<<"myList contains: ";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;

        it1=it2=myList.begin();
        advance(it2,6);
        ++it1;
        it1=myList.erase(it1);//1 3 4 5 6 7 8 9
        cout<<"myList contains: ";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        it2=myList.erase(it2);//1 3 4 5 6 8 9
        cout<<"myList contains: ";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        ++it1;
        --it2;
        myList.erase(it1,it2);//1 3 6 8 9
        cout<<"myList contains: ";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testClear(){
        //list::clear()函数 功能：删除所有元素
        list<int>myList;
        list<int>::iterator it;
        myList.push_back(1998);
        myList.push_back(11);
        myList.push_back(3);
        cout<<"myList contains:  ";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        myList.clear();
        cout<<"myList contains:  ";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        myList.push_back(1);
        myList.push_back(2);
        myList.push_back(3);
        cout<<"myList contains:  ";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testEmpty(){
        //list::empty()函数 功能：如果list是空的则返回true
        list<int>myList;
        int sum=0;
        for(int i=1;i<11;i++){
            myList.push_back(i);
        }
        while(!myList.empty()){
            sum+=myList.back();
            myList.pop_back();
        }
        cout<<"total: "<<sum<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testSize(){
        //list::size()函数 功能：返回list中元素的个数
        list<int>myInts;
        cout<<"0.size"<<(int) myInts.size()<<endl;
        for(int i=0;i<10;i++){
            myInts.push_back(i);
        }
        cout<<"1.size"<<(int) myInts.size()<<endl;
        myInts.insert( myInts.begin(),11,3);
        cout<<"2.size"<<(int) myInts.size()<<endl;
        myInts.pop_back();
        cout<<"3.size"<<(int) myInts.size()<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testResize(){
        //list::resize()函数 功能：改变list的大小
        list<int>myList;
        list<int>::iterator it;
        //set some initial content
        for(int i=1;i<11;i++) {
            myList.push_back(i);
        }
        myList.resize(5);
        cout<<"myList1 contains: ";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        myList.resize(8,3);
        cout<<"myList2 contains: ";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        myList.resize(11);
        cout<<"myList3 contains: ";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testSwap(){
        //list::swap()函数 功能：交换两个list
        list<int>first(3,11);
        //three ints with a value of 100
        list<int>second(5,20);
        //five ints with a value of 20

        list<int>::iterator it;
        cout<<"first contains: ";
        for(it=first.begin();it!=first.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        cout<<"second contains: ";
        for(it=second.begin();it!=second.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;

        first.swap(second);

        cout<<"first contains: ";
        for(it=first.begin();it!=first.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        cout<<"second contains: ";
        for(it=second.begin();it!=second.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        cout<<"--------------------------------"<<endl;
    }
    void testGetAllocator(){
        //list::get_allocator()函数 功能：返回list的适配器
        list<int>myList;
        int *p;
        //allocate an array of 5 elements using myList's allocator
        p=myList.get_allocator().allocate(5);
        //assign some values to array
        for(int i=0;i<5;i++)p[i]=i;
        cout<<"size of myList"<<myList.size()<<endl;//0
        cout<<"the allocated array contains: ";
        for(int i=0;i<5;i++){
            cout<<"  "<<p[i];
        }
        cout<<endl;
        myList.get_allocator().deallocate(p,5);
        cout<<endl;
        cout<<"--------------------------------"<<endl;
    }
    bool compare_noCase(string first,string second){

        unsigned  int i=0;
        while((i<first.length())&&(i<second.length())){
            if(tolower(first[i])<tolower(second[i]))//转换为小写
                return true;
            ++i;
        }
        if(first.length()<second.length())return true;
        else return false;
    }
    //先按长度由小到大，在按开头字符a-z
    int tolower(int c)
    {
        if ((c >= 'A') && (c <= 'Z'))
            return c + ('a' - 'A');
        return c;
    }

    void testSort(){
        list<string>myList;
        list<string>::iterator it;
        myList.emplace_back("one");
        myList.emplace_back("two");
        myList.emplace_back("Three");
        myList.emplace_back("four");

        myList.sort();
        cout<<"myList contains:";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;

        myList.sort(compare_noCase);


        cout<<"myList contains:";
        for(it=myList.begin();it!=myList.end();it++){
            cout<<" "<<*it;
        }
        cout<<endl;
        string str = "THIS IS A STRING";
        for (char & i : str)
            i = char(tolower(int(i)));//把大写全部转为小写
        cout<<str<<endl;

    }
}

#endif //STLUSAGETEST_TESTLIST_H
