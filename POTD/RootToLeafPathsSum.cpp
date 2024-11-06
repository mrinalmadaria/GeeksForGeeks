void solve(Node *root,int csum,int &ans){
         if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            csum=(csum*10)+root->data;
           // cout<<csum<<" ";
            ans+=csum;
            return;
        }
       
        //cout<<csum<<" ";
        solve(root->left,(csum*10)+root->data,ans);
        solve(root->right,(csum*10)+root->data,ans);
        
    }
    int treePathsSum(Node *root) {
        // code here.
        int ans=0;
        int csum=0;
        solve(root,csum,ans);
        return ans;
    }