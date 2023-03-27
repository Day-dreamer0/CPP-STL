/*
IP-> 4
3
1 3 5 7 2 4 6 8 0 9 10 11

OP-> 0 1 2 3 4 5 6 7 8 9 10 11 
*/

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
        priority_queue<ListNode*,vector<ListNode*>,std::function<bool(ListNode*, ListNode*)> > mpq([]( ListNode* a, ListNode* b) {
            // if(a!=nullptr and b!=nullptr)
                return a->val > b->val;
            // else if(a==nullptr)
            // return false;
            // else
            // return true;
      });
        int k=lists.size();
        for(int i=0;i<k;i++)
        {
            if(lists[i]!=nullptr)
            mpq.push(lists[i]);
        }
        
        ListNode* res=nullptr; 
        ListNode* curr,*prev;
        while(!mpq.empty())
        {
            ListNode* temp=mpq.top();
            mpq.pop();
            if(temp!=nullptr)
            {
                curr=new ListNode(temp->val);
                //curr->val = temp->val;
                //curr->next = temp->next;
            }
            if(res==nullptr)
            {
                res=curr;
                prev=curr;
            }
            else
            {
                prev->next=curr;
                prev=curr;
            }  
            if(temp!=nullptr and temp->next!=nullptr)
                mpq.push(temp->next);
        }
        return res;
    }
};