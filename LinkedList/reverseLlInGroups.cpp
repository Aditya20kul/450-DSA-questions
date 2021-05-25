#include<bits/stdc++.h>
using namespace std;
using ll = long long;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* reverseKGroup(ListNode* head, int k) {
    int flag=0;
        int len=0;
        ListNode* tempp = head;
        while(tempp){
            len++;
            tempp = tempp->next;
        }
        int cnt=0;
        ListNode *ans = NULL;
        ListNode *res=ans;
        while(head){
            int t = k;
            
            if(cnt<(len - len%k)){
                stack<ListNode*>st;
                while(head && t>0){
                st.push(head);
                head = head->next;
                cnt++;
                t--;
            }

            while(!st.empty()){
                ListNode* temp = st.top();
                if(ans==NULL){
                    ans = temp;
                    res = temp;
                }
                else{
                    ans->next = temp;
                    ans = ans->next;
                }
                st.pop();
            }
        }
        else{
            flag=1;
            ans -> next = head;
            break;
        }
    }
    if(flag==0){
        ans -> next = NULL;
    }
        return res;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int len, k;
  cin>>len;
  ListNode *head=NULL;
  ListNode *ans = head;
    while(len--){
        int ele;
        cin>>ele;
        ListNode* newNode = new ListNode(ele);
        if(ans==NULL){
            ans = newNode;
            head = newNode;
        }
        else{
            ans -> next = newNode;
            ans = ans->next;
        }
    }
    cin>>k;
    ListNode *res = reverseKGroup(head, k);
    ans = res;
    while(ans){
        cout<<ans->val<<" ";
        ans = ans->next;
    }

  return 0;
}