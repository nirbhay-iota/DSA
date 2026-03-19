class Solution {
public:
    void deleteNode(ListNode* node) {
        
        // node ko hi next node bnado then next node ko delete krdo
        node->val=node->next->val;
        node->next=node->next->next;

    }
};
