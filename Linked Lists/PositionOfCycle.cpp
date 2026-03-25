/*
  🧠 The trick (this is the magic part ✨)

  Once slow == fast:

  Move one pointer back to head
  Keep the other at meeting point
  Move both 1 step at a time
  Where they meet again = start of cycle
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
