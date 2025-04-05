// this is i importent and most asked querstion in interviews..

//You need to maintain a valid range (min, max) for each node:

//For the left child, max = root->val

//For the right child, min = root->val 



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
           bool find(TreeNode*root,long long int a,long long int b){
            if(root==NULL) return true;
            if(root->val>=b || root->val <=a) return false;
            return find(root->left,a,root->val)&&find(root->right,root->val,b);
           }
        bool isValidBST(TreeNode* root) {
          long long  int a=LLONG_MIN,b=LLONG_MAX; //due to constraints...
           return find(root,a,b) ;
    
        }
    }; 

    //tc o(n) and space will be height of the tree skew ke case me o(n)..