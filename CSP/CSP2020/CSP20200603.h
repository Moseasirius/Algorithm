//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2020_CSP20200603_H
#define CSP2020_CSP20200603_H

namespace CSP20200603{
    typedef struct Markdown{
        int type;//标记类型，
        //0 空行，1 项目列表第一行
        // 2 项目列表第二行 3 段落
        string s;
    }Markdown;

    vector<Markdown>vec;

//判断是否为空行
    bool isSpace(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')return false;
        }
        return true;
    }
//去掉首尾空格
    string  standard(string s){
        int pos1=0,pos2=s.size()-1;
        for(int i=0;i<pos2;i++){
            if(s[i]!=' '){
                pos1=i;
                break;
            }
        }
        for(int i=s.size();i>0;i--){
            if(s[i]!=' '){
                pos2=i;
                break;
            }
        }
        string temp=s.substr(pos1,pos2-pos1+1);
//	string substr (size_t pos = 0, size_t len = npos) const;
//	_Off：所需的子字符串的起始位置。
//	字符串中第一个字符的索引为 0,默认值为0。
//  _Count：复制的字符数目。
//  返回值：一个子字符串，从其指定的位置开始。
        return temp;
    }
    void testCSP20200603(){
        ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
        //提高输入输出速度
        Markdown temp;
        int w ,flag=0;
        cin>>w;
        string str;


//while(getline(cin,line))语句
//注意这里默认回车符停止读入,按Ctrl+Z或键入EOF回车即可退出循环。
//在这个语句中，首先getline从标准输入设备上读入字符，
//然后返回给输入流cin，注意了，是cin，
//所以while判断语句的真实判断对象是cin，也
//就是判断当前是否存在有效的输入流。

        while(getline(cin,str)){
            if(isSpace(str)){//处理空行
                if(flag!=0){//上一行不是空行，就添加一行空行
                    temp.s="";
                    temp.type=0;
                    vec.push_back(temp);
                    flag=0;
                }
                continue;
            }
            if(str.size()>=2 && str[0]=='*' && str[1]==' '){
                //处理项目列表第一行
                if(flag==3){//上一行是段落，就插入一行空行隔开
                    temp.s="";temp.type=0;
                    vec.push_back(temp);
                }
                //然后在把项目列表放入vec
                temp.type=1;
                temp.s=standard(str.substr(2,str.size()));
                vec.push_back(temp);
                flag=1;
            } else if(str.size()>=2 && str[0]==' ' && str[1]==' ' && (flag==1 || flag==2)){//处理项目其余行
                if(vec[vec.size()-1].s==""){
                    //处理特殊情况，即项目列表第一行为空
                    vec[vec.size()-1].s=standard(str);
                }else{
                    vec[vec.size()-1].s=vec[vec.size()-1].s+" "+standard(str);
                }
                flag=2;
            }else{//处理段落
                if(flag==1 || flag==2){
                    temp.s="";temp.type=0;
                    vec.push_back(temp);
                    temp.s=standard(str);
                    temp.type=3;
                    vec.push_back(temp);
                }else if(flag==3){
                    vec[vec.size()-1].s=vec[vec.size()-1].s+" "+standard(str);
                }else{
                    temp.s=standard(str);
                    temp.type=3;
                    vec.push_back(temp);
                }
                flag=3;
            }
        }
        long long res = 0;//结果，记录行数
        if(vec[vec.size()-1].type==0)res=-1;//若最后一行是空行，就去掉，即令res从-1开始
        for(int i=0;i<vec.size();i++){
            int type=vec[i].type;
            string s=vec[i].s;
            if(type==0){//空行结果+1
                res++;
                //cout<<endl;
            }else if(type==1 || type==2){//项目列表
                if(s.size()==0){//处理特殊情况，即项目列表为空，行数+1
                    res++;
                    continue;
                }
                int t=0;
                while(t<s.size()){
                    while(1){//保证每行开头不是空格
                        if(t>=s.size())break;
                        if(s[t]!=' ')break;
                        t++;
                    }
                    //cout<<s.substr(t,w-3)<<endl;
                    t+=(w-3);
                    res++;
                }
            }else{
                int t=0;
                while(t<s.size()){
                    while(1){//保证每行开头不是空格
                        if(t>=s.size())break;
                        if(s[t]!=' ')break;
                        t++;
                    }
                    //cout<<s.substr(t,w)<<endl;
                    t+=w;
                    res++;
                }
            }
        }cout<<res<<endl;
}
#endif //CSP2020_CSP20200603_H
