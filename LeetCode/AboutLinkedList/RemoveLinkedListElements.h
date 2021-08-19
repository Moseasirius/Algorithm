//
// Created by mozhenhai on 2021/8/15.
//

#ifndef ABOUTLINKEDLIST_REMOVELINKEDLISTELEMENTS_H
#define ABOUTLINKEDLIST_REMOVELINKEDLISTELEMENTS_H

#include "TestYourLinkedList.h"


//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/description/
// 不使用虚拟头结点
// 时间复杂度: O(n)
// 空间复杂度: O(1)

namespace removeElements1 {
    class Solution {
    public:
        ListNode *removeElements(ListNode *head, int val) {

            // 需要对头结点进行特殊处理
            while (head != NULL && head->val == val) {
                ListNode *node = head;
                head = head->next;
                delete node;
            }

            if (head == NULL)
                return head;

            ListNode *cur = head;
            while (cur->next != NULL) {
                if (cur->next->val == val) {
                    ListNode *delNode = cur->next;
                    cur->next = delNode->next;
                    delete delNode;
                } else
                    cur = cur->next;
            }

            return head;
        }
    };
}

// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/description/
// 使用虚拟头结点
// 时间复杂度: O(n)
// 空间复杂度: O(1)

namespace removeElements2 {

    class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val) {

            // 创建虚拟头结点
            ListNode* dummyHead = new ListNode(0);
            dummyHead->next = head;

            ListNode* cur = dummyHead;
            while(cur->next != NULL){
                if(cur->next->val == val){
                    ListNode* delNode = cur->next;
                    cur->next = delNode->next;
                    delete delNode;
                }
                else
                    cur = cur->next;
            }

            ListNode* retNode = dummyHead->next;
            delete dummyHead;

            return retNode;
        }
    };

}

#endif //ABOUTLINKEDLIST_REMOVELINKEDLISTELEMENTS_H
