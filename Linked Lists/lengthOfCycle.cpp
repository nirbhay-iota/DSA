
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
