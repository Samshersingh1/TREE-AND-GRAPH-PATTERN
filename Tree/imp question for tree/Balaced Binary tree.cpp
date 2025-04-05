/* the difination is if the height diffrence between left substree and right substree is not moore than 1 in all the node s
 then tree is said to be balanceed*/ 



 //approach bottom up o(n*2);

 class Solution {
    public:  
              int helper(TreeNode*root){
                 if(root==NULL)  return 0;
                 return 1+max(helper(root->left),helper(root->right));
              }
         
        bool isBalanced(TreeNode* root) {
             if(root==NULL) return true;  
              int  a=helper(root->left);  //it will give us left subtree count...
            int  b=helper(root->right);   //it will gives us right subtree count...
            return (abs(a-b)<=1 && isBalanced(root->left) && isBalanced(root->right));  //if all are true our answer will be true...
            
        } 
    };           

    //approach 2 top down o(n)..

    class Solution {
        public:
            int checkHeight(TreeNode* root) {
                if (root == NULL) return 0;
        
                int leftHeight = checkHeight(root->left);
                if (leftHeight == -1) return -1;  // If left subtree is unbalanced, return -1.
        
                int rightHeight = checkHeight(root->right);
                if (rightHeight == -1) return -1; // If right subtree is unbalanced, return -1.
        
                if (abs(leftHeight - rightHeight) > 1) return -1;  // If unbalanced, return -1.
        
                return max(leftHeight, rightHeight) + 1;  // Otherwise, return height of current subtree.
            }
        
            bool isBalanced(TreeNode* root) {
                return checkHeight(root) != -1; // If checkHeight returns -1, the tree is unbalanced.
            }
        };
        