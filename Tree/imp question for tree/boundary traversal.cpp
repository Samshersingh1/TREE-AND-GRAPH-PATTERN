#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
                 int val;
                 TreeNode *left;
                   TreeNode *right;
                 TreeNode() : val(0), left(nullptr), right(nullptr) {}
                    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
                TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };     
     void  rightBoundarytraversal(TreeNode*root,stack<int>&st) {
             if(root==NULL) return ;
             if(root->right!=NULL){
                 st.push(root->val);
                 rightBoundarytraversal(root->right,st);
             } 
             else if(root->left!=NULL){
                st.push(root->val);
                rightBoundarytraversal(root->left,st);
             }
     }
 
 void  leafNodetraversal(TreeNode*root,vector<int>&ans) {
       if(root==NULL) return;
       leafNodetraversal(root->left,ans);
       if(root->left==NULL && root->right==NULL){
           ans.push_back(root->val);  //collenting root node ...
       } 
       leafNodetraversal(root->right,ans);
 } 

 void leftBoundarytraversal(TreeNode*root,vector<int>&ans){
          if(root==NULL) return;
          if(root->left!=NULL){
              ans.push_back(root->val);
              leftBoundarytraversal(root->left,ans);
          } 
          else if(root->right!=NULL){
            ans.push_back(root->val);
            leftBoundarytraversal(root->right,ans);
          }
 }  
  vector<int> Boundarytraversal(TreeNode*root){    //implement this ...
        vector<int>ans;
        if(root==NULL) return ans;  
        if(root->left!=NULL || root->right!=NULL){
            ans.push_back(root->val);
        } 
        
         leftBoundarytraversal(root->left,ans);   //for left boundary..

         leafNodetraversal(root,ans); 
            stack<int>st;
         rightBoundarytraversal(root->right,st); 
         while(st.size()>0){
             ans.push_back(st.top());
             st.pop();
         } 
         return ans;
  }  

     int main(){
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->right = new TreeNode(5);
        root->right->right = new TreeNode(4); 

        vector<int>ans=Boundarytraversal(root);  
        for(auto &it:ans){
             cout<<it<<" ";
        }
     }   


     