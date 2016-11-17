// Source : https://leetcode.com/problems/partition-list/
// Author : Dylan
// Date   : 2016-11-16

/*************************************************************************************** 
 *
 * Given a linked list and a value x, partition it such that all nodes less than x come 
 * before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two 
 * partitions.
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 ***************************************************************************************/
/**
 * Definition for singly-linked list.
 */
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *greaterFront, *greaterBack, *lessFront, *lessBack;
        greaterFront = lessFront = head;
        greaterBack = lessBack = NULL;
        while (lessFront != NULL) {
            if (greaterFront->val < x) {
                greaterBack = greaterFront;
                greaterFront = greaterFront->next;
                lessBack = lessFront;
                lessFront = lessFront->next;
            } else {
                if (lessFront->val < x) {
                    lessBack->next = lessFront->next;
                    if (greaterBack == NULL) {
                        lessFront->next = head;
                        greaterBack = lessFront;
                        head = lessFront;
                    } else {
                        greaterBack->next = lessFront;
                        greaterBack = greaterBack->next;
                        greaterBack->next = greaterFront;
                    }
                    lessFront = lessBack->next;
                } else {
                    lessBack = lessFront;
                    lessFront = lessFront->next;
                }
            }
        }
        return head;
    }

};

class TestList {
public:
    ListNode* createList(){
        ListNode *head = NULL;
        ListNode *tmp;
        ListNode *p;
        int val;
        while(cin>>val){
            tmp = new ListNode(val);
            if (head == NULL) {
                head = tmp;
                p = tmp;
            }
            p->next = tmp;
            p = p->next;
        }
        return head;
    }

    void printList(ListNode *head) {
        while (head != NULL) {
            cout<<head->val<<' ';
            head = head->next;
        }
    }
};

int main()
{
    Solution test;
    TestList list;
    ListNode *head;
    int val;

    head = list.createList();
    cout<<'\n';

    val = 9;

    head = test.partition(head, val);

    list.printList(head);
    cout<<'\n';

    return 0;
}
