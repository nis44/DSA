/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp -> next;
        }

        k = k % len;

        if(k == 0) return head;

        int part = len-k-1;

        ListNode* p1, *p2;
        temp = head;

        while(part--) {
            temp = temp -> next;
        }

        p1 = temp;
        p2 = temp -> next;

        p1 -> next = nullptr;

        ListNode* end = p2;
        while(end -> next) {
            end = end -> next;
        }

        end -> next = head;

        return p2;

    }
};