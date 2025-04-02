//here is given preorder traversal of the given binary tree and inorder traversal of the given binary tree we have to 
// construct a binary tree with the help of this.............we have to build unique binary tree.. for pre and post  we can not conrtuc unique

//Note :: for given postorder and preorder only we can not construct unique binarty binary tree  

// for the given preorder it's first element will always be root and for this we will check the index of the root in the 
//inorder traversal  and it's left will be the left subtree of the bs and right will be right subtree of the bs..

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
    
                 TreeNode* build(vector<int>& preorder,int prestart,int preend, vector<int>& inorder,int instart,int inend,unordered_map<int,int>&mpp) {
                     if(prestart>preend || instart>inend) return NULL;   // if any of this become empty then null
                      TreeNode*root=new TreeNode(preorder[prestart]); 
                      int p=mpp[root->val];    // finding the ind where root is present in inorder
                     int j=p-instart;   // find element till left 
                     root->left=build(preorder,prestart+1,prestart+j,inorder,instart,p-1,mpp);  //this is main steps here we are building the left and right subtree...using recursion here..
                     root->right=build(preorder,prestart+j+1,preend,inorder,p+1,inend,mpp);     //keep take care of index where we partite 
                    return root;
        }   
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
              unordered_map<int,int>mpp;   //storing the inorder in map because we have to check for this 
            for(int i=0;i<inorder.size();i++){
                 mpp[inorder[i]]=i;
            } 
            TreeNode*root= build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);  // calling the function that will give me root
            return root;
        }   
    }; 