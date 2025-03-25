   // just do bfs  but when you put ans into main vector check for order odd or even first will left then right







class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
              queue<TreeNode*>q;  
              
             
              vector<vector<int>>v; 
              if(root==NULL) return v; 
              int x=0;
             q.push(root); 
              while(q.size()>0){
                  int s=q.size();
                    vector<int>ans; 
                    for(int i=0;i<s;i++){
                        TreeNode*temp=q.front();
                             q.pop(); 
                            if(temp->left!=NULL) q.push(temp->left);  
                            if(temp->right!=NULL) q.push(temp->right);   
                           ans.push_back(temp->val);
                    }     
    
                     if(x%2!=0){ 
                          reverse(ans.begin(),ans.end()) ;  
                          v.push_back(ans); 
                          x++;
                    } 
                    else{
                         v.push_back(ans);
                         x++;
                    }
                    
              }  
              return v;
        }
    };  