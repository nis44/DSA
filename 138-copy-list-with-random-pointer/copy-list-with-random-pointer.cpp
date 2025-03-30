/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* temp = head;
        while(temp) {
            Node* nex = temp -> next;
            Node* copy = new Node(temp->val);
            temp -> next = copy;
            copy -> next = nex;
            temp = nex;
        }

        temp = head;
        while(temp) {
            Node* rndm = temp -> random;
            if(rndm == NULL)  temp -> next -> random = nullptr;

            else {
                Node* dumrndm = rndm -> next;

                temp -> next -> random = dumrndm; 
            } 

            temp  = temp -> next -> next;
        }

        temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while(temp) {
            Node* nex = temp -> next -> next;
            res -> next = temp -> next;
            temp -> next = nex;
            temp = nex;
            res = res -> next;
        }

        return dummy -> next;

    }
};