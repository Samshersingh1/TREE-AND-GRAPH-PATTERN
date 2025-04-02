 //accenstor is the just  (from  upper or from current root to root) ya khud hi 
 
 
  //brute force of this will be just check path for (p,q) and store the path in araay space o(n) will be used 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==NULL || root==p || root==q) return root; 
    
            TreeNode*left=lowestCommonAncestor( root->left,p,q);   //will go to up to null
            TreeNode*right=lowestCommonAncestor( root->right,p,q);  //will go up to null
    
            if(left==NULL){
                 return right;
            }
           else if(right==NULL){
             return  left;
           }
           else{
              return root;
           }
            
        }
    }; 