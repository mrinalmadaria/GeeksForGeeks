#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    Node* rev(Node* head){
        Node* curr=head;
        Node* pre=NULL;
        Node* nxt=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nxt;
        }
        return pre;
    }
    
    Node* trimZero(Node* head){
        while(head->next && head->data==0){
            head=head->next;
        }
        return head;
    }
    
    int size(Node* head){
        int size=0;
        while(head){
            ++size;
            head=head->next;
        }
        return size;
    }
    
    bool compare(Node* head1, Node* head2){
        while(head1 && head1->data==head2->data){
            head1=head1->next;
            head2=head2->next;
        }
        if(head1 && head1->data<head2->data){
            return false;
        }
        return true;
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        head1=trimZero(head1);
        head2=trimZero(head2);
        int n1=size(head1);
        int n2=size(head2);
        if(n1<n2){
            swap(head1,head2);
        }else if(n1==n2){
            if(!compare(head1, head2)){
                swap(head1,head2);
            }
        }
        head1=rev(head1);
        head2=rev(head2);
        Node* dummy=new Node(-1);
        Node* curr=dummy;
        int rem=0, val1, val2;
        while(head1 && head2){
            val1=head1->data;
            val2=head2->data+rem;
            if(val2>val1){
                val1+=10;
                rem=1;
            }else{
                rem=0;
            }
            curr->next=new Node(val1-val2);
            curr=curr->next;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1){
            val1=head1->data;
            val2=rem;
            if(val2>val1){
                val1+=10;
                rem=1;
            }else{
                rem=0;
            }
            curr->next=new Node(val1-val2);
            curr=curr->next;
            head1=head1->next;
        }
        Node* ans=rev(dummy->next);
        ans=trimZero(ans);
        return ans;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}