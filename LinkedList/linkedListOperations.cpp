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

// Insert Node at Beginning
Node* insertAtBegin(Node* head, int data){
    Node *newNode = new Node(data);
    Node *temp = head;
    if(head==NULL){
        head=newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Insert Node at End
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

// Insert at Given Position
Node* insertAtPos(Node* head, int data, int pos){
    Node *newNode = new Node(data);
    Node *temp = head;
    if(head==NULL){
        head=newNode;
    }
    else{
        if(pos==0){
            return insertAtBegin(head, data);
        }
        else{
            while(pos-1 > 0){
                temp = temp->next;
                pos--;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

// Delete from front
Node* deleteFromBegin(Node *head){
    if(head==NULL){
        return NULL;
    }
    else{
            Node *temp = head->next;
            delete(head);
            return temp;   
    }
}

// Delete from End
Node* deleteFromEnd(Node *head){
    if(head==NULL){
        return NULL;
    }
    else{
        if(head->next==NULL){
            delete(head);
            return NULL;
        }
        else{
            Node *temp = head;
            Node *curr = head;
            while(temp->next){
                curr=temp;
                temp = temp->next;
            }
            delete(temp);
            curr->next=NULL;
            return head;
        }
    }
}

// Delete from Given Position
// Node* deleteFromPos(Node *head, int pos){
    
// }

// Reverse the LinkedList Iteratively
Node* reverseIterative(Node *head){
    Node *temp = head;
    Node *prev = NULL;
    
    while(temp!=NULL){
        Node *nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
    return prev;
}

// Reverse the LinkedList Recursively
Node *reverseRecursively(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    
        Node *newHead = reverseIterative(head->next);
        head->next->next=head;
        head->next = NULL;
        return newHead;
    
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

int main(){
    int n, dt, opt, pos;
    //cin>>n;
    Node* head = NULL;
    while(true){
        cout<<"\n1. Insert at Begin\n2. Insert At End\n3. Insert At Given Position\n4. Delete from begin\n5. Delete from End\n6. Delete from given position\n7. Print Linked List\n8. Reverse Iteratively\n9. Reverse Recursively\n100. Exit\n";
        cin>>opt;
        if(opt==1){
            cout<<"\nEnter data to be inserted - ";
            cin>>dt;
            head = insertAtBegin(head, dt);
        }
        else if(opt==2){
            cout<<"\nEnter data to be inserted - ";
            cin>>dt;
            head = insertAtEnd(head, dt);
        }
        else if(opt==3){
            cout<<"\nEnter data to be inserted - ";
            cin>>dt;
            cout<<"\nEnter the position where the node is to be inserted (Positioning starts from index 0) - ";
            cin>>pos;
            head = insertAtPos(head, dt, pos);
        }
        else if(opt==4){
            head = deleteFromBegin(head);
        }
        else if(opt==5){
            head = deleteFromEnd(head);
        }
        else if(opt==6){
            cout<<"\nEnter the position from where the Node is to be deleted - ";
            cin>>pos;
            //head = deleteFromPos(head, pos);
        }
        else if(opt==7){
            printList(head);
        }
        else if(opt==8){
            Node* temphead = reverseIterative(head);
            //cout<<newHead;
            printList(temphead);
        }
        else if(opt==9){
            head = reverseRecursively(head);
            printList(head);
        }
        else if(opt==100){
            break;
        }   
    }
    return 0;
}