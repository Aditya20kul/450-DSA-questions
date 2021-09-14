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

Node* segregate(Node* head){
    Node *evenst=NULL, *evenend=NULL, *oddst=NULL, *oddend=NULL;
    for(Node *curr=head; curr!=NULL; curr=curr->next){
        int val = curr->data;
        if(val%2==0){
            if(evenst==NULL){
                evenst = curr;
                evenend = curr;
            }
            else{
                evenend->next = curr;
                evenend = evenend->next;
            }
        }
        else{
            if(oddst==NULL){
                oddst = curr;
                oddend = curr;
            }
            else{
                oddend->next = curr;
                oddend = oddend->next;
            }
        }
    }
    if(evenst==NULL){
        return oddst;
    }
    evenend->next = oddst;
    oddend->next = NULL;
    return evenst;
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


int main(){
    int t,i,cnt=0,dt,n;
    Node* head1 = NULL;
    cout<<"Enter Number of Nodes in LL - ";
    cin>>n;
    while(n--){
        cin>>dt;
        head1 = insertAtEnd(head1, dt);
    }
    Node *ans = segregate(head1);
    printList(ans);
    return 0;
}