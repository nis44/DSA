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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        int n = lists.size();

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;



        for(auto head : lists) if(head != nullptr) pq.push({head -> val, head});

        while(!pq.empty()) {
            ListNode* mini = pq.top().second;
            pq.pop();

            if(mini -> next != nullptr) pq.push({mini -> next -> val, mini -> next});

            temp -> next = mini;
            temp = temp -> next;



        }

        return dummy -> next;




    }
};