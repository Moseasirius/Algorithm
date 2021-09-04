//
// Created by mozhenhai on 2021/9/4.
//

#ifndef CSP2019_CSP20190302_H
#define CSP2019_CSP20190302_H

void  testCSP20190302(){
    int n;
    vector<int>num;
    vector<char>op;
    string str;
    cin>>n;
    while(n--){
        cin>>str;
        for(int i=0;i<str.size();i++){
            if(i%2==0){
                num.push_back(str[i]-'0');//存操作数
            }
            else{
                op.push_back(str[i]);//存操作符
            }
        }
        for(int i=0;i<op.size();i++){
            if(op[i]=='x'){
                num[i]=num[i]*num[i+1];
                num.erase(num.begin()+i+1);//删除第i+2个元素，即下标为i+1
                op.erase(op.begin()+i);// 除第i+1个元素，即下标为i
                i=-1;//这里有三个操作符，假如第二个，即下标为1的是乘号，
                //做完一次之后，该下标的元素删除，应该从0下标开始遍历。
                //所以要减一
            }
            if(op[i]=='/'){
                num[i]=num[i]/num[i+1];
                num.erase(num.begin()+i+1);
                op.erase(op.begin()+i);
                i=-1;
            }
        }
        while(op.size()>0){
            if(op[0]=='+'){
                num[0]=num[0]+num[1];
                num.erase(num.begin()+1);
                op.erase(op.begin());
            }
            if(op[0]=='-'){
                num[0]=num[0]-num[1];
                num.erase(num.begin()+1);
                op.erase(op.begin());
            }
        }
        if(num[0]==24)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        num.clear();op.clear();
    }
}
#endif //CSP2019_CSP20190302_H
