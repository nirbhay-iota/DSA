class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* temp=head;
        while(temp-> next != NULL){
            cnt++;
            temp=temp-> next;
        }
        cnt++;
        // handle edge case for removing the head
        if(cnt==n) return head->next;
        temp=head;
        int cnt2=0;
        while(cnt2<(cnt-n-1)){
            temp=temp->next;
            cnt2++;
        }
        temp->next= temp->next->next;
        return head;
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        // phle fast ko n steps aage krdo
        for(int i=0;i<n;i++){
            fast=fast->next;
        }

        // handle removing head edge case
        if(fast==NULL) return head->next;

        // warna dono ko aage badhao  ....jab fast last pe hoga tab slow n wali position ke peeche hoga
        // toh bas uska slow->next->next krdo
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
