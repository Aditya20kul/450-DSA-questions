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

Node* merge(Node *head1, Node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node *temp;
    if(head1->data < head2->data){
        temp = head1;
        temp->next = merge(head1->next, head2);
    }
    else{
        temp = head2;
        temp->next = merge(head1, head2->next);
    }
    return temp;
}

Node* getMid(Node *head){
    //Complete this function to return data middle node
    Node *fast=head, *slow=head;
    while(fast && fast->next){
        if(fast->next->next!=NULL){
            slow = slow->next;
        }
        fast = fast->next->next;
    }
    return slow;   
}


Node* mergeSort(Node* head){
    // Base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    // Compute Middle Element
    Node *mid = getMid(head);
    Node *a = head;
    Node *b = mid->next;
    mid->next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);
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
    int t,i,cnt=0,ans,dt,n;
    Node* head = NULL;
    cout<<"Enter Number of Nodes - ";
    cin>>n;
    while(n--){
        cin>>dt;
        head = insertAtEnd(head, dt);
    }
    cout<<"Unsorted List - ";
    printList(head);
    Node* temp = mergeSort(head);
    cout<<"\nSorted List - ";
    printList(temp);
    return 0;
}