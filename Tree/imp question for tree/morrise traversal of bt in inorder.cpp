//Self notes:
//In-order Morris Traversal:
//🌳 1st case: if left is null, print current node and go right
//🌳 2nd case: before going left, make right most node on left subtree connected to current node, then go left
//🌳 3rd case: if thread is already pointed to current node, then remove the thread ...


//for recusive  as well as itreative the tc=o(n) and sc o(n).. 
//but  for morrise traversal it will be  tc=o(n) and sc o(1).. 
// morris traversal works in  threds tree 

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
        vector<int> inorderTraversal(TreeNode* root) {
             vector<int>ans;
             TreeNode*curr=root;
             while(curr) {
                if(curr->left==NULL){  //1st edge case is here when left substree is null
                    ans.push_back(curr->val); //this will be the root..
                    curr=curr->right; //go to the right 
                } 
                else{
                    TreeNode*pre=curr->left; //if left is not null we have to go to the right most guy..
                    while(pre->right && pre->right!=curr) {  //we have to take care this is not pointing to curr..(therds tree) 
                      pre=pre->right;
                    }  
                    if(pre->right==NULL){
                        pre->right=curr; 
                        curr=curr->left;   //move to the left 
                    }  
    
                    else{
                        pre->right=NULL;  //if threds mil raha hai then remove it and go to right 
                        ans.push_back(curr->val);   // this will be root..
                        curr=curr->right;    //move to the right 
                    }  
    
                } 
    
             }   
    
             return ans;
        }
    }; 