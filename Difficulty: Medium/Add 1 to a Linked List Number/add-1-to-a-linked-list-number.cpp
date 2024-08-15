//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++




class Solution {
  public:
    Node* reverse(Node* h1){
        Node* prv = nullptr;
        Node* curr = h1;
        Node* nxt = nullptr;
        while (curr != nullptr){
            nxt = curr -> next;
            curr -> next = prv;
            prv = curr;
            curr = nxt;
        }
        
        return prv;
    }
    Node* addOne(Node* head) {
       Node* revLink = reverse(head);
       
       Node* trv = revLink;
       Node* prv = nullptr;
       int carry = 0;
       while (trv != nullptr){
           if (trv->data + 1 > 9){
               carry = 1;
               trv->data = 0;
           }
           else{
               trv -> data += 1;
               carry = 0;
               break;
           }
           prv = trv;
           trv = trv->next;
       }
       if (carry){
           Node* node = new Node(carry);
           prv -> next = node;
           node -> next = nullptr;
       }
       
       return reverse(revLink);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends