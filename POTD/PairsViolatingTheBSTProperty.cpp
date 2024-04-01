//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
    int ans = 0;
    void inorder(Node *node, vector<int> &vec){
        if(!node) return;
        inorder(node -> left, vec);
        vec.push_back(node -> data);
        inorder(node -> right, vec);
    }
    int merge(vector<int> &arr, int s, int m, int e){
        vector<int> t1, t2;
        for(int i = s; i <=m; i++) t1.push_back(arr[i]);
        for(int i=m+1;i<=e;i++) t2.push_back(arr[i]);
      
        int N = t1.size(), M = t2.size();
        for(int i = 0, j = 0, k = s; k <= e; k++) {
            if(i == N) { arr[k] = t2[j++]; continue; }
            if(j == M) { arr[k] = t1[i++]; continue; }
            if(t1[i]<=t2[j]) arr[k]=t1[i++];
            else {
                ans += (t1.size()-i);
                arr[k]= t2[j++];
            }
        }
    }
     void mergeSort(vector<int>& arr, int s, int e) {
        if( s >= e) return;
        int m = (s + e)/2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        merge(arr, s, m, e);
    }
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector<int> arr;
        inorder(root, arr);
        mergeSort(arr, 0, arr.size()-1);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends