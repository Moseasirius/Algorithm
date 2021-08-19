//
// Created by mozhenhai on 2021/8/15.
//

#ifndef ABOUTLINKEDLIST_TEST_H
#define ABOUTLINKEDLIST_TEST_H

#include "TestYourLinkedList.h"

#include "ReverseLinkedList.h"
#include "RemoveLinkedListElements.h"
#include "SwapNodesInPairs.h"
#include "Remove-Nth-Node-From-End-of-List.h"
#include "Delete-Node-in-a-Linked-List.h"



void  testReverseList(){
    int arr [] = {1,2,3,4,5};
    int n = sizeof (arr)/sizeof (int);

    ListNode* head1 = TestListHelper::createLinkedList(arr,n);

    TestListHelper::printLinkedList(head1);

    ListNode* head2 = reverseList1::Solution().reverseList(head1);

    TestListHelper::printLinkedList(head2);

    TestListHelper::deleteLinkedList(head2);
}
void testRemoveElements1(){
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    ListNode* head = TestListHelper::createLinkedList(arr, n);
    TestListHelper::printLinkedList(head);

    removeElements1::Solution().removeElements(head, 6);
    TestListHelper::printLinkedList(head);

    TestListHelper::deleteLinkedList(head);
}
void testRemoveElements2(){
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    ListNode* head = TestListHelper::createLinkedList(arr, n);
    TestListHelper::printLinkedList(head);

    removeElements2::Solution().removeElements(head, 6);
    TestListHelper::printLinkedList(head);

    TestListHelper::deleteLinkedList(head);

}



#endif //ABOUTLINKEDLIST_TEST_H
