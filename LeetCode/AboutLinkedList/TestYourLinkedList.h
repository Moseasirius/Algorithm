//
// Created by mozhenhai on 2021/8/15.
//

#ifndef ABOUTLINKEDLIST_TESTYOURLINKEDLIST_H
#define ABOUTLINKEDLIST_TESTYOURLINKEDLIST_H

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

namespace TestListHelper {
/**
 * Definition for singly-linked list.
 */


/// LinkedList 测试辅助函数
    // 根据n个元素的数组arr创建一个链表, 并返回链表的头
    ListNode *createLinkedList(int arr[], int n) {

        if(n==0)
            return nullptr;

        ListNode* head = new ListNode(arr[0]);
        ListNode* curNode = head;

        for(int i=1;i<n;i++){

            curNode->next = new ListNode(arr[i]);
            curNode = curNode->next;
        }
        return head;
    }
    // 打印以head为头结点的链表信息内容
    void printLinkedList(ListNode* head){

        ListNode* curNode = head;

        while(curNode!= nullptr){

            cout<<curNode->val<<"->";
            curNode = curNode->next;
        }
        cout<<"nullptr"<<endl;
    }
    // 释放以head为头结点的链表空间
    void deleteLinkedList(ListNode* head){

        ListNode* curNode = head;

        while(curNode!= nullptr){
            ListNode *delNode = curNode;
            curNode = curNode->next;
            delete delNode;
        }
    }
}





#endif //ABOUTLINKEDLIST_TESTYOURLINKEDLIST_H
