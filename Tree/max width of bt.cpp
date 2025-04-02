//in this we have to find the maximum lenth level  wise when node is not null ..

/* APPROACH WILL BE JUST DO INDEX OVER ALL THE NODE IF NODE IS NULL DO THAT INDEXING 
   THE INDEXING WILL BE FOR A CURRENT NODE i the left value will be (2*i+1 (for 0-based indexing)) and for right (2*i+2) will
   be there and for overflow please consider do for each level substarct the min of each level*/ 


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
        int widthOfBinaryTree(TreeNode* root) {
            if(root==NULL) return 0;
            int ans=0;
            queue<pair<TreeNode*,long long>>q; 
            q.push({root,0}); 
            while(q.size()>0){
                int s=q.size();
                int mini=q.front().second;   //mini of previous
                int first,last;
                for(int i=0;i<s;i++){
                    long long idx=q.front().second-mini;   //to overcome overflow 
                    TreeNode*temp=q.front().first;
                    if(i==0) first=idx;
                    if(i==s-1)  last=idx;  
                    q.pop();
                    if(temp->left) {
                        q.push({temp->left,2*idx+1}); 
                    }
                     if(temp->right) {
                        q.push({temp->right,2*idx+2}); 
                    } 
                } 
                ans=max(ans,last-first+1);
            } 
            return ans;
        }
    }; 