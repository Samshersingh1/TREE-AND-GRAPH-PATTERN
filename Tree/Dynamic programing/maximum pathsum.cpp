/* this is briliyant patten Based question  
 base case 
 hypothesis kaise bhi karke left and right ka answer de dega baki ka socho */




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public: 
                int solve(TreeNode* root,int &ans){
                    if(root==NULL) return 0;
                   int a= max(0,solve(root->left,ans)); 
                   int b=max(0,solve(root->right,ans));  //hypothesis is here
                   int temp=root->val+max(a,b);   //indextions...
                    ans=max(ans,a+b+root->val); 
                    return temp;
                }  
    
        int maxPathSum(TreeNode* root) {
             if(root->left==NULL && root->right==NULL) return root->val; 
             int ans=INT_MIN;
             int c=solve(root,ans);
             return ans;
        }
    }; 