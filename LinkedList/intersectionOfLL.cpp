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

int getCount(Node* head){
    Node* temp = head;
    int cnt=0;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

Node* travel(Node* hd, int k){
    Node *tmp = hd;
    while(k--){
        tmp = tmp->next;
    }
    return tmp;
}

int getIntersection(Node* head1, Node* head2){
    int cnt1 = getCount(head1);
    int cnt2 = getCount(head2);
    if(cnt1>cnt2){
        Node* temp = travel(head1, abs(cnt1-cnt2));
        while(temp!=NULL && head2!=NULL){
            if(temp==head2){
                return temp->data;
            }
            temp = temp->next;
            head2 = head2->next;
        }
    }
    else{
        Node* temp = travel(head2, abs(cnt1-cnt2));
        while(temp!=NULL && head1!=NULL){
            if(temp==head1){
                return temp->data;
            }
            temp = temp->next;
            head1 = head1->next;
        }
    }
    
    return -1;
}

int main(){
    int t,i,cnt=0,ans,dt,n;
    Node* head1 = NULL, *head2=NULL;
    // cout<<"Enter Number of Nodes - ";
    // cin>>n;
    // while(n--){
    //     cin>>dt;
    //     head1 = insertAtEnd(head1, dt);
    // }
    // cout<<"Enter Number of Nodes - ";
    // cin>>n;
    // while(n--){
    //     cin>>dt;
    //     head2 = insertAtEnd(head2, dt);
    // }
    head1 = insertAtEnd(head1, 10);
    head1 = insertAtEnd(head1, 20);
    head1 = insertAtEnd(head1, 30);
    head1 = insertAtEnd(head1, 40);
    head1 = insertAtEnd(head1, 50);

    head2 = insertAtEnd(head2, 80);
    head2 = insertAtEnd(head2, 90);
    head2->next->next = head1->next;
    
    ans = getIntersection(head1, head2);
    cout<<"Two LinkedList Intersect at - "<<ans;

    //printList(head);
    return 0;
}