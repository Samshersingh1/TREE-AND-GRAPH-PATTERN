// int this problem we have given 'O' and 'X' we hve to vconvert 'o' to 'x' but 'o' region should be surronded by all the x if the
//there is any boundary then all the 'o' will not convert to 'x' that form region by this 'o'..



Approach 1:  our answer will effect by boundry o so first call DFS/BFS t oall the boundary O and all the o whcih we will get
by traversing that will not convert to x and all of remaing will convert 


class Solution {
    public:  
             int dx[4]={1,0,-1,0};
             int dy[4]={0,1,0,-1};
            void dfs(int i,int j,vector<vector<char>>& board, vector<vector<int>>&vis) { 
                 int m=board.size();
            int n=board[0].size();
                 for(int d=0;d<4;d++){
                    int nx=i+dx[d];
                    int ny=j+dy[d];
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]!=1 && board[nx][ny]=='O'){
                        vis[nx][ny]=1;
                        dfs(nx,ny,board,vis);
                   }   
                 } 
            } 
        void solve(vector<vector<char>>& board) { 
            int m=board.size();
            int n=board[0].size();
             vector<vector<int>>vis(m+1,vector<int>(n+1,0)); 
             
             for(int i=0;i<n;i++){
                if(board[0][i]=='O'){ 
                    if(vis[0][i]!=1){
                    vis[0][i]=1;
                    dfs(0,i,board,vis);
                    }
                } 
             } 
              for(int i=0;i<m;i++){
                if(board[i][0]=='O'){
                      if(vis[i][0]!=1){
                        vis[i][0]=1;
                    dfs(i,0,board,vis);
                    }
                } 
             } 
              for(int i=0;i<n;i++){
                if(board[m-1][i]=='O'){
                    if(vis[m-1][i]!=1){
                    vis[m-1][i]=1;
                    dfs(m-1,i,board,vis);
                    }
                } 
             } 
              for(int i=0;i<m;i++){
                if(board[i][n-1]=='O'){
                      if(vis[i][n-1]!=1){
                         vis[i][n-1]=1;  
                        dfs(i,n-1,board,vis);
                    }  
                } 
             }  
    
             for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                  if(vis[i][j]!=1){
                      board[i][j]='X';
                  } 
                  else{
                       board[i][j]='O';
                  }
                }  
             }  
       //answer no need to print anything....
        }      
    };   