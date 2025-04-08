 /*✅ Correct BFS Approach (Intuition First)
Start by pushing all 0s into a queue.

Set distance of all 1s to ∞ (or INT_MAX).

While the queue is not empty:

Pop a cell.

For all 4 directions:

If the neighbor cell can get a shorter distance via current cell, update it and push it to the queue.

This way, the shortest distance will propagate outward from all the 0s. */


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


    /* ❓Why Pushing 0s into the Queue Makes More Sense (Correct Approach)
Think BFS Like a Wave 🌊
BFS expands outward level by level, like ripples from a stone thrown into water.

So if you:

Start BFS from all 0s, and

Expand outward to reach each 1,

Then you're naturally computing the shortest distance from any cell to the nearest 0, because BFS always finds the shortest path first in an unweighted graph/grid.

🟩 Analogy:
Imagine the 0s as fire sources, and you want to know how long it takes for the fire to reach every cell.
So you light all 0s at time 0 and simulate the spread.

❌ Why Pushing 1s Instead is Wrong
If you push 1s into the queue and try to search for the nearest 0, you:

Start many BFS searches from far away,

Don't know which direction is optimal,

Risk overwriting distances incorrectly,

Need extra conditions to prevent visiting nodes in the wrong order.

BFS is only guaranteed to work for shortest path if:

You expand from the source, and

You never revisit nodes unless a better path is found (which gets messy when you're the one walking towards 0s).

🧠 Key Intuition:
From 0s (Correct)	From 1s (Buggy & Messy)
You know where you’re going	You're guessing direction
Natural BFS spread	Prone to mistakes
Distances increase gradually	Need extra conditions
BFS guarantees correctness	Not intuitive
🔁 TL;DR:
✅ Push 0s, propagate distance outward — BFS finds shortest path.
❌ Pushing 1s and trying to walk toward 0s goes against the nature of BFS, and makes everything harder.

*/