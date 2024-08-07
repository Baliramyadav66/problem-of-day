//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int>& v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root) {
    vector<int> v;
    queue<Node*> q;

    q.push(root);

    Node* next_row = NULL;

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();

        if (n == next_row) {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left) {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right) {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node* createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends

class Solution {
  public:
   
    Node *createTree(vector<int> parent) {
       
       
       unordered_map<int,vector<int>>mpp;
       
       int data=-1;
       
       for(int i=0;i<parent.size();i++){
           
           mpp[parent[i]].push_back(i);
           
           if(parent[i]==-1){
               
               data=i;
           }
       }
       
       
           Node *root=new Node(data);
       
       queue<Node*>q;
       
       q.push(root);
       
       while(!q.empty()){
           
           
         
          Node* temp=q.front();
          q.pop();
        
            if (mpp.find(temp->data) != mpp.end()) {
              
            int size=mpp[temp->data].size();
            
            if(size>0){
                
                temp->left=new Node(mpp[temp->data][0]);
                    q.push(temp->left);
            }
            if(size>1){
                 temp->right=new Node(mpp[temp->data][1]);
                     q.push(temp->right);
            }
            
        
       }
       }
       
       return root;
       
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        Solution ob;

        Node* res = ob.createTree(a);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends