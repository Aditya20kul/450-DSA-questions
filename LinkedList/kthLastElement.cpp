#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            this->data=val;
            this->next=NULL;
        }
}; 

int kthLastElement(Node *head, int k){
    //Complete this function to return kth last element
    Node *first=head, *second=head;
    k = k-1;
    while(k>0){
        second = second->next;
        k--;
    }
    while(second->next){
        first = first->next;
        second = second->next;
    }
    return first->data;
}

void printList(Node *head){
    if(head==NULL){
        cout<<"\n!!! Linked List Empty !!!\n";
        return;
    }
    else{
        cout<<"\n *** Printing LinkedList - ";
        Node *temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

Node* insertAtEnd(Node* head, int data){
    Node *newNode = new Node(data);
    Node *temp = head;
    if(head==NULL){
        head=newNode;
    }
    else{
        while(temp->next){
            temp = temp->next;
        }
        temp->next=newNode;
    }
    return head;
}

int main(){
    int t,i,cnt=0,ans,n,dt;
    Node* head = NULL;
    cout<<"Enter Number of Nodes - ";
    cin>>n;
    while(n--){
        cin>>dt;
        head = insertAtEnd(head, dt);
    }
    cout<<"\n Enter value of K - ";
    int k;
    cin>>k;
    cout<<" Kth element from last is "<<kthLastElement(head,k);
    return 0;
}