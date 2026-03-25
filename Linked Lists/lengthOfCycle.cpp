// using map
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        unordered_map<Node *,int> mp;
        int count=0;
        Node *temp=head;
        while(temp!=NULL){
            if(mp.find(temp) != mp.end()){
                int length= count-mp[temp];
                return length;
            }
            
            mp[temp]=count;
            temp=temp->next;
            count++;
        }
        return 0;
    }
};
 
// using slow fast 
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node * slow=head;
        Node * fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                int count=1;
                slow=slow->next;
                while(slow!=fast){
                    count++;
                    slow=slow->next;
                }
                return count;
            }
        }
        return 0;
    }
};
