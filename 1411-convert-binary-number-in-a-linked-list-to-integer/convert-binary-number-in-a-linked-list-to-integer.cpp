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

int ans = 0;
int mul = 0;

    int solve(ListNode* temp) {
        if(!temp) return 0;
            solve(temp -> next);
        

        ans += (temp -> val) * pow(2, mul++);
        return ans;

    }    

    int getDecimalValue(ListNode* head) {
        
        ListNode* temp = head;

        return solve(temp);

    }
};