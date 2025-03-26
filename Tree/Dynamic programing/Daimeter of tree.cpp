class Solution {
    public: 
            int helper(TreeNode*root,int &ans){
                if(root==NULL) return 0; 
                int a=helper(root->left,ans);
                int b=helper(root->right,ans); 
                 int temp=1+max(a,b);    //passing to senoirs..
                  ans=max(ans,a+b);    //checking if he can be answer or not..
                return temp;
    
            } 
        int diameterOfBinaryTree(TreeNode* root) {
              if(root==NULL) return 0;
               int ans=0; 
               int c=helper(root,ans); 
               return ans;
        }
    };     

    //TRY THIS QUESTION PLEASE https://leetcode.com/problems/longest-univalue-path/description/