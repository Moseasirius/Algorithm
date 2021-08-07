//
// Created by mozhenhai on 2021/8/6.
//

#ifndef STLUSAGETEST_TESTSTRING_H
#define STLUSAGETEST_TESTSTRING_H
#include<iostream>
#include<string>
#include <cstring>
#include <fstream>

using namespace std;
namespace TestString{

    void testString(){
        //string::string() 功能：构造函数，用于字符串初始化
        string s1;
        string s2("mozhenhai string");
        cout<<s2;
        const string& s3(s2);
        string s4(s2,8);
        string s5(10,'m');
        string s6a(10,42);
        string s6b(s2.c_str(),s2.c_str()+4);
        cout<<s1<<endl;
        cout<<s2<<endl;
        cout<<s3<<endl;
        cout<<s4<<endl;
        cout<<s5<<endl;
        cout<<s6a<<endl;
        cout<<s6b<<endl;
        //string::operator+=()函数 功能：连接两个字符串
        string first("Tom");
        string second("may");
        first+=" is a boy ";
        second+=" is a girl";
        cout<<first<<endl;
        cout<<first<<endl;
        first+=second;
        cout<<first<<endl;
        //string::operator=()函数 功能：字符串赋值
        string str1="Test string " ;
        string str2("code");
        string str3("mo");

        str1+=str2;
        cout<<str1<<endl;
        str1+=str3;
        cout<<str1<<endl;
        //string::operator[]()函数 功能：获取特定的字符
        string str4("test string");
        for(char i : str4){
            cout<<i<<" ";
        }
        //string::operator[]() 功能：获取特定的字符
        string str5("mozhenhai");
        for(char i : str5){
            cout<<i<<" ";
        }
        cout<<"------------------------------------------"<<endl;
    }
    void testAssign(){
        //string::assign()函数 功能：为字符串赋新值
        string str;
        string base="mozhenhai is writing#code";
        //used in the same order as described above
        str.assign(base);
        cout<<str<<endl;
        str.assign(base,9,12);
        cout<<str<<endl;
        str.assign("program is the tool",7);
        cout<<str<<endl;
        str.assign("I like coding");
        cout<<str<<endl;
        str.assign(3,'?');
        cout<<str<<endl;

        str.assign(base.begin()+2,base.end()-4);
        cout<<str<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    void testAppend(){
        //string::append()函数 功能：在字符串的末尾添加文本
        string str;
        string str2="mozhenhai";
        string str3="you#are#a#bad#boy";
        //used in the same order as described above
        str.append(str2);
        cout<<str<<endl;
        str.append(str3,3,6);//第四个个字符后面六个字符包括第四个
        cout<<str<<endl;
        str.append("boy",2);
        cout<<str<<endl;
        str.append("good:");
        cout<<str<<endl;
        str.append(6,'!');
        cout<<str<<endl;
        str.append(str3.begin()+4,str3.end());
        cout<<str<<endl;
        cout<<str<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    void testBeginEnd(){
        //string::begin()函数 功能：返回一个迭代器；指向第一个字符
        //string::end()函数  功能：返回一个迭代器；指向字符串的末尾。(最后一个字符的下一个位置)

        string str1("program");
        string::iterator it;
        for(it=str1.begin();it<str1.end();it++){
            cout<<" "<<*it;
        }
        //string::rbegin()函数 功能：返回一个逆向迭代器，指向最后一个字符
        //string::rend()函数 功能：返回一个逆向迭代器，指向第一个元素的前一个位置
        string str("mozhenhai is coding");
        string::reverse_iterator rit;
        for(rit=str.rbegin();rit!=str.rend();rit++){
            cout<<*rit;
        }
        cout<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    void testPopPush(){
        //string::push_back() 功能：Append character to string
        string str;

        str.push_back('m');

        cout<<str;
        cout<<"------------------------------------------"<<endl;
    }
    void testInsert(){
        //string::insert()函数 功能：插入字符
        string str1="you are a lovely boy";
        string str2="not ";
        string str3("is intelligent girl");

        string::iterator it;

//	used in the same order as described above
        str1.insert(8,str2);
        cout<<str1<<endl;
        str1.insert(14,str3,3,11);
        cout<<str1<<endl;
        str1.insert(14,"code is interesting ",5);
        cout<<str1<<endl;
        str1.insert(14,"code is interesting ");
        cout<<str1<<endl;
        str1.insert(14,2,',');
        cout<<str1<<endl;
        str1.insert(str1.begin()+3,'#');
        cout<<str1<<endl;
        str1.insert(str1.end(),4,'!');
        cout<<str1<<endl;
        it=str1.insert(str1.begin()+3,'$');
        cout<<str1<<endl;
        str1.insert(it+2,str3.begin(),str3.begin()+2);
        cout<<str1<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    void testErase(){
        //string::erase()函数 功能：删除字符
        string str("you are a lovely boy");
       
        //erase used in the same order as described above:
        str.erase(14);//删除下标为14（第十五个字符）及以后的字符
        cout<<str<<endl;
        str.erase(5,2);//删除下标为5及后面一个字符。就是连同下标为5的两个字符
        cout<<str<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    void testClear(){
        //string::clear()函数 功能：Clear string
        string str("Tom");
        cout<<str<<endl;
        str.clear();
        cout<<"after str.clear:"<<str<<endl;
        cout<<"------------------------------------------"<<endl;

    }
    void testEmpty(){
        //string::empty()函数 功能：如果字符串为空，返回真
        string str1 = "";
        string str2 = "mo zhen hai";
        cout<<"str1: "<<str1.empty()<<endl;
        cout<<"str2: "<<str2.empty()<<endl;
        cout<<"------------------------------------------"<<endl;


    }
    void testCStr(){
        //string::c_str()函数 功能：将字符串以C字符数组的形式返回

        char *cStr;

        string str("mo zhen hai is coding program is interesting");

        cStr=new char [str.size()+1];

        strcpy(cStr,str.c_str());

        delete[] cStr;
        cout<<"------------------------------------------"<<endl;
    }
    void testCopy(){
        //string::copy()函数 功能：将内容复制为一个字符数组

        string str("program code code");

        char buffer[20];
        str.copy(buffer,6,5);//6,5:5为字符的下标，6为字符串长度

        cout<<"buffer contains: "<<buffer<<endl;
        cout<<"------------------------------------------"<<endl;


    }
    void testLength(){
        //string::length()函数 功能：返回字符串的长度
        string str0("I like program");
        cout<<"The length of str is :"<<str0.length()<<"characters"<<endl;
        //string::size()函数 功能：返回字符串中字符的数量
        //string::length()函数 功能：返回字符串的长度
        string str("program code");
        cout<<"The size of str is : "<<str.size()<<endl;
        cout<<"The length of str is : "<<str.length()<<endl;
        //string::substr()函数 功能：返回某个子字符串
        string str1("you are program boy");
        string str2=str1.substr(3,4);//3,4 3是下标位置 ，4是长度
        cout<<str2<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    void testCapacity(){
        //string::capacity()函数 功能：返回重新分配空间前的字符容量
        string str("program is");
        cout<<"size "<<str.size()<<endl;
        cout<<"length: "<<str.length()<<endl;
        cout<<"capacity "<<str.capacity()<<endl;
        cout<<"max_size "<<str.max_size()<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    void testMaxSize(){
        //string::max_size()函数 功能：返回字符的最大可能个数
        string str("mozhenhai");
        cout<<"size: "<<str.size()<<endl;
        cout<<"length: "<<str.length()<<endl;
        cout<<"capacity: "<<str.capacity()<<endl;
        cout<<"max_size: "<<str.max_size()<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    void testSwap(){
        //string::swap()函数 功能：交换两个字符串的内容
        string buyer("money");
        string seller("goods");

        cout<<"before swap buyer:"<<buyer<<endl;
        cout<<"before swap seller:"<<seller<<endl;

        seller.swap(buyer);

        cout<<"after swap buyer:"<<buyer<<endl;
        cout<<"after swap seller:"<<seller<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    void testFind() {
        //string::find()函数 功能：在字符串中查找字符
        string str("The boy is writing code");
        string str1("by");
        string str2("is");
        cout << string::npos << endl;
        cout << str.find(str1) << endl; //返回子字符串在字符串中的起始位置下标
        cout<<"------------------------------------------"<<endl;

    }
    void testSubstr(){
        //string::substr()函数 功能：返回某个子字符串
        string str="i am coding,what are you doing";
        string str1,str2;
        size_t pos;
        str1=str.substr(5,6);//"coding"
        pos=str.find("you");//get from "you" to the end
        str2=str.substr(pos);
        cout<<str1<<endl;
        cout<<str2<<endl;
        cout<<"------------------------------------------"<<endl;
    }
    void testAt(){
        //string::at()函数 功能：按给定索引值返回字符
        string str("mozhenhai");
        cout<<"index2: "<<str.at(2)<<endl;
        for(char i : str){
            cout<<i<<" ";
        }
        cout<<endl;
        cout << "------------------------------------------" << endl;
    }
    void testCompare(){
        //string::compare()函数 功能：比较两个字符串,相等返回0，不相等返回-1

        string str1("code");
        string str2("program code");
        string str3("code");
        cout<<str1.compare(str3)<<endl;

        cout<<str2.compare(7,10,"code")<<endl;
        //7,10表示第八个字符到第十一个字符
        cout<<str2.size()<<endl;

        cout<<str2.compare(str2.size()-4,4,"code")<<endl;
        cout<<str2.compare(7,4,"code")<<endl;

        //7,4表示第八个字符后面四个字符包括第八个
        //简单概括就是如果后面数字前面大按照下标截取
        //如果后面数字比前面小或等按照下标加长度
        cout<<str1.compare(2,2,str2,9,10)<<endl;//str1:de str2:de
        cout<<str1.compare(2,2,str2,9,12)<<endl;//str1:de str2:de
        //第二种截取字符串的方法
        //表明超出字符串长度的下标和字符串最大下标效果一样
    }
}
#endif //STLUSAGETEST_TESTSTRING_H
