//in this we  are given a binary tree we have t oconvert it into linkedlist that will be pre-order traversal in..
// binary tree.. we have to do it in place  


//approach 1. 
 /* Your approach to flattening the binary tree is almost perfect, and it's based on reverse post-order traversal 
 (right → left → root), which is correct.*/

 class Solution {
    public: 
       
            TreeNode*prev=NULL;
        void flatten(TreeNode* root) {
             
             if(root==NULL) return ;
             flatten(root->right);
            flatten (root->left);
             root->right=prev;
             root->left=NULL;
             prev=root;
        }
    };  
 
    //tc :o(n) and sc: o(max(height))...
 
    //APPROACH 2..  


    class Solution {
        public:
            void flatten(TreeNode* root) {
                TreeNode*prev=NULL;  
                TreeNode*curr=root;
            while(curr){
                 if(curr->left){
                    prev=curr->left;
                    while(prev->right){
                        prev=prev->right;  // right most finding 
                    } 
                    prev->right=curr->right;  //atach right most ot curr right 
                    curr->right=curr->left; // make  curr right to left ot make preorder ...
                     curr->left=NULL;
                 } 
                 curr=curr->right;  
            } 
        
            } 
        };

  //tc :o(n) and sc: o(1)...