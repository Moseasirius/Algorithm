//
// Created by mozhenhai on 2021/8/15.
//

#ifndef ABOUTLINKEDLIST_REVERSELINKEDLIST_H
#define ABOUTLINKEDLIST_REVERSELINKEDLIST_H

#include "TestYourLinkedList.h"

//struct ListNode{
//    int val;
//    ListNode *next;
//    ListNode(int x): val(x),next(nullptr){}
//};

// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/description/
// 时间复杂度: O(n)
// 空间复杂度: O(1)
namespace reverseList1{
    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {

            ListNode* pre = nullptr;
            ListNode* cur = head;
           ;
            while(cur!= nullptr){
                ListNode* next = cur->next;

                cur->next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }
    };
}

// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/description/
//
// 递归的方式反转链表
// 时间复杂度: O(n)
// 空间复杂度: O(1)

namespace reverseList2{
    class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            // 递归终止条件
            if(head== nullptr||head->next== nullptr)
                return head;
            ListNode* rHead = reverseList(head->next);

            // head->next此刻指向head后面的链表的尾节点
            // head->next->next = head把head节点放在了尾部
            head->next->next = head;
            head->next = NULL;

            return rHead;
        }
    };
}


#endif //ABOUTLINKEDLIST_REVERSELINKEDLIST_H
