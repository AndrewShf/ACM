/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* left, ListNode* right) {
        if (right == NULL) return left;
        left->next = NULL;
        ListNode* newhead = left;
        while(right) {
            ListNode* tmp = right;
            right = right->next;
            tmp->next = left;
            left = tmp;
        }
        return left;
    }
    void reorderList(ListNode* head) {
        if (head==NULL || head->next==NULL || head->next->next==NULL)
            return;
        ListNode* p = head;
        int len = 0;
        while(p) {
            len++;
            p = p->next;
        }
        p = head;
        ListNode *left = head;
        ListNode *right;
        int i = 0;
        while(i != len/2) {
            left = left->next;
            ++i;
        }
        right = left->next;
        left->next = NULL;
        left = right;
        right = right->next;
        ListNode* newhead = reverseList(left, right);
        left = head;
        while(newhead) {
            ListNode* tmp = newhead->next;
            newhead->next = left->next;
            left->next = newhead;
            newhead = tmp;
            left = left->next->next;
        }
        return;
    }
};
