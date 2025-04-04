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
          void  makeparent(TreeNode*root,TreeNode*target, unordered_map<TreeNode*,TreeNode*>&parent_pointer) {
               
               queue<TreeNode*>q;
               q.push(root);
             while(!q.empty()){
                 TreeNode*current=q.front();
                   q.pop();
                   if(current->left){
                      parent_pointer[current->left]=current;
                      q.push(current->left);
                   }  
    
                    if(current->right){
                    parent_pointer[current->right]=current;
                      q.push(current->right);
                   } 
            } 
          }    
    
    
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            /* Step 1: we have to stroe the parent pointer to go back
                Step 2: we will go redaily in there direction (parent,lft,right) by using 
                 visted aray and increse dis by 1 at the same time when my distance is k all the element which are in the queue 
                 will be our answer...*/  
    
                 unordered_map<TreeNode*,TreeNode*>parent_pointer;
                 makeparent(root,target,parent_pointer); 
                 unordered_map<TreeNode*,bool>vis;
                  queue<TreeNode*>q;
                  q.push(target); 
                  vis[target]=true;
                  int dis=0; 
                    while(!q.empty() && dis < k) { 
                      int s=q.size();
                      for(int i=0;i<s;i++) {
                          TreeNode*temp=q.front();  
                            q.pop();
                           // vis[temp]++;
                        if(temp->left!=NULL  && !vis[temp->left]) {  //elemtn is exist and we have to touch yet 
                             q.push(temp->left); 
                             vis[temp->left]=true;
                        }   
                         if(temp->right!=NULL && !vis[temp->right]) {  //element is exist and we have to touch yet 
                             q.push(temp->right);
                             vis[temp->right]=true;
                         }  
    
                          if( parent_pointer[temp]  && !vis[parent_pointer[temp]]) {
                             q.push(parent_pointer[temp]);
                             vis[parent_pointer[temp]]=true;
                        }   
                      }      
                      
                      dis++;  
                  }  
                  vector<int>ans;
                  while (!q.empty()) {
                ans.push_back(q.front()->val);
                q.pop();
            } 
                 return ans;
        }
    };     