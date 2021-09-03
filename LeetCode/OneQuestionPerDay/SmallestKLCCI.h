//
// Created by mozhenhai on 2021/9/3.
//

#ifndef ONEQUESTIONPERDAY_SMALLESTKLCCI_H
#define ONEQUESTIONPERDAY_SMALLESTKLCCI_H
#include <vector>
#include <ctime>
#include <iostream>
#include <queue>
using namespace std;
namespace smallestKLCCI{
    class Solution {
    private:
        void quickSort3(vector<int>& array,int l,int r){
            if(l>r)
                return;

            int v = array[l];
            int lt = l;
            int gt = r+1;
            int i = l+1;
            while(i<gt){
                if(array[i]<v){
                    swap(array[i],array[lt+1]);
                    lt++;
                    i++;
                }else if(array[i]>v){
                    swap(array[i],array[gt-1]);
                    gt--;
                }else //array[i]==v
                {
                    i++;
                }
            }
            swap(array[l],array[lt]);

            quickSort3(array,l,lt-1);
            quickSort3(array,gt,r);
        }
        void quickSort(vector<int>& arr,int n){

            quickSort3(arr,0,n-1);
        }
    public:
        vector<int> smallestK(vector<int>& arr, int k) {

            quickSort(arr,arr.size());
            // sort(arr.begin(),arr.end());
            vector<int> ret;
            for(int i=0;i<k;i++){

                ret.push_back(arr[i]);
            }
            return ret;

        }
    };

}
namespace smallestKLCCI1
{
    class Solution {


    public:
        vector<int> smallestK(vector<int>& arr, int k) {
            priority_queue<int> pq;
            for(int i=0;i<k;i++){
                pq.push(arr[i]);
            }
            for(int i=k;i<arr.size();i++){
                if(arr[i]<pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
            vector<int> ret;
            for(int i=0;i<k;i++){
                ret.push_back(pq.top());
                pq.pop();
            }
            return ret;

        }
    };
}

void testSmallestKLCCI(){

    int arr [] = {1,3,5,7,2,4,6,8};
    vector<int> array(arr,arr+sizeof(arr)/sizeof (int ));
    int k =4;
    vector<int> ret = smallestKLCCI1::Solution().smallestK(array,k);
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<" ";
    }
//    cout<<endl<<"Done";
//    priority_queue<int>mypq1;
//
//    mypq1.push(1999);
//    mypq1.push(2000);
//    mypq1.push(1998);
//    mypq1.push(2020);
//    cout<<"size of mypq1 :"<<mypq1.size()<<endl;
//    cout<<"popping out elements:";
//    while(!mypq1.empty()){
//        cout<<" "<<mypq1.top();
//        mypq1.pop();
//    }
//    cout<<endl;
//    cout<<"size of mypq1 :"<<mypq1.size()<<endl;

}
#endif //ONEQUESTIONPERDAY_SMALLESTKLCCI_H
