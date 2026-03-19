class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp->next != NULL){
            cnt++;
            temp= temp->next;
        }
        cnt++;
        int index=(cnt/2) ;
        temp=head;
        int cnt2=0;
        while(cnt2<index){
            temp=temp-> next;
            cnt2++;
        }
        return temp;
    }
};


//More optimized Approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // fast aur head 2 pointers use krenge
        //fast 2 steps move krega and slow 1 step
        // jab fast last me hoga toh slow middle pe hoga

        ListNode* fast =head;
        ListNode* slow =head;
        while(fast!=NULL && fast->next != NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
