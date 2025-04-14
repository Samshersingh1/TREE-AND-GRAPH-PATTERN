/* this is a  cycle  detection using dfs method  
  the solution which we have done in undirected will fail in this because path can change here..for some time 
 NOTE::  we need to take care of paths as well like this node is in the same path or not..
.*/    

class Solution {
    public: 
      bool dfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&path){
               vis[node]=1;
               path[node]=1;
            for(auto &it:adj[node]){
                if(vis[it]!=1) {
                   
                   if(dfs(it,vis,adj,path)) {
                        return true;
                    }
                }  
                
                else if(path[it]==1){
                     return true;
                } 
            } 
             path[node]=0;  //backtrack
            return false;
      } 
       
      
      bool isCyclic(int n, vector<vector<int>> &edges) {
           vector<vector<int>>adj(n); 
      
          for(auto &it:edges){
             adj[it[0]].push_back(it[1]); 
          }    
          vector<int>vis(n,0); 
          vector<int>path(n,0);
          for(int i=0;i<n;i++){
              if(vis[i]!=1){
                if(dfs(i,vis,adj,path)) return true;
              }
          } 
          return false;
          
      }
  };  