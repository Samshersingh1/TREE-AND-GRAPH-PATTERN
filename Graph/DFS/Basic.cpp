class Solution {
    public: 
           void dfs(int id,vector<int>&ans,vector<int>&vis,vector<vector<int>>& adj){
           //  if(id>=adj.size()) return;  no base case  required..
               vis[id]=1;
               ans.push_back(id);
               for(auto &it:adj[id]){    //this is taken care for the base ...
                   if(vis[it]!=1){
                       dfs(it,ans,vis,adj); 
                   }
               } 
               
           } 
      vector<int> dfs(vector<vector<int>>& adj) {
          vector<int>ans;  //for storing answer
          int n=adj.size();
          vector<int>vis(n,0); //for tracing visted node  
          for(int i=0;i<n;i++){
              if(vis[i]!=1){
                  dfs(i,ans,vis,adj); 
              } 
          } 
          return ans;
          
      }
  };