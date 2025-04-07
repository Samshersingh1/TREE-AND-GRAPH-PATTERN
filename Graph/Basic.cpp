/* in this we will understand how to make a graph using*/ 

// Approach 1: USING  MATRIX

//Approach 2: USING ADJANCENCY LIST.. 

//Note: 
/* 
 in every question we hace to convert the graph into adjancency graph then we will   use bfs ot dfs as per question ..alignas
 what we are given a matrix then we have to make adjancey matrix such that adj[0] ={1,2,4,5} all the {1,2,3,4,5} are 
 connected to 0 parasoi kitne connect hai wo batat hai ..alignas
   

     int n=isConnected.size();
        vector<int>adj[n];  //first we will convert 2-D matrix convert to adj list... in every question then apply dfs or bfs as your choice..
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  if(isConnected[i][j]==1 && i!=j){
                     adj[i].push_back(j);
                     adj[j].push_back(i);
                  }
              } 
        
*/