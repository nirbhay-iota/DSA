// using 3 pointer

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode=NULL;
        ListNode* currNode=head;
        ListNode* nextNode=head;

        while(currNode != NULL){
            nextNode=currNode->next;
            currNode->next=prevNode;
            prevNode=currNode;
            currNode=nextNode;
        }
        return prevNode;
    }
};

//using stack

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        stack<ListNode*> st;
        ListNode* temp=head;
        while(temp != NULL){
            st.push(temp);
            temp= temp->next;
        }
        head=st.top();
        st.pop();
        temp=head;
        while(!st.empty()){
            temp->next = st.top();
            temp= temp->next;
            st.pop();
            
        }
        temp->next=NULL;
        return head;
    }
};
