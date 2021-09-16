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

// Print the Linked List
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

Node *pairWiseSwap(Node* head){
    
}

int main(){
    int t,i,cnt=0,ans,dt,n;
    Node* head = NULL;
    cout<<"Enter Number of Nodes - ";
    cin>>n;
    while(n--){
        cin>>dt;
        head = insertAtEnd(head, dt);
    }
    Node *temp = pairWiseSwap(head);
    printList(temp);
    printList(head);
    return 0;
}