✅ Correct BFS Approach (Intuition First)
Start by pushing all 0s into a queue.

Set distance of all 1s to ∞ (or INT_MAX).

While the queue is not empty:

Pop a cell.

For all 4 directions:

If the neighbor cell can get a shorter distance via current cell, update it and push it to the queue.

This way, the shortest distance will propagate outward from all the 0s. 


class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
              int m=mat.size();
              int n=mat[0].size();
            queue<pair<int,int>>q;
                 for(int i=0;i<m;i++){
                 for(int j=0;j<n;j++){
                     if(mat[i][j]==0) q.push({i,j});  // we are inserting position that has 0 as value we will cheack adj of 0..
                     else mat[i][j]=INT_MAX;
                 } 
                }  
               int dx[4]={0,-1,0,1};
               int dy[4]={1,0,-1,0};
             
              while(q.size()>0){
                      
                   int x=q.front().first;
                   int y=q.front().second; 
                    q.pop();
                   for(int i=0;i<4;i++){
                     int nx=x+dx[i];
                     int ny=y+dy[i]; 
                    if(nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny] > mat[x][y]+1 )  {   
                          mat[nx][ny]=mat[x][y]+1;
                          q.push({nx,ny});
                    }   
    
                   }  
                   
              } 
              return mat;
        }
    };   