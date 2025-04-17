/* this is a briliyant Question to  Solve we can solve it using two ways 
 1. BFS(Normal bfs method for this :: ) 
 2. min PQ (MODIFY DIJARKESTRA ALGO WILL BE USE )  { 
        the key idea will continue if my current stop for a particuler city will be greater than >k ...
    } 

 
 */ 

 //the minheap soltution will be 

 class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int, int>>> adj(n);
            for (auto &it : flights) {
                adj[it[0]].push_back({it[1], it[2]});
            }
    
            priority_queue< pair<int, pair<int, int>>,
                            vector<pair<int, pair<int, int>>>,
                            greater<>> q;
    
            q.push({0, {src, 0}}); // {cost, {node, stops}}
    
            while (!q.empty()) {
                int dist = q.top().first;
                int node = q.top().second.first;
                int stop = q.top().second.second;
                q.pop();
    
                if (node == dst) return dist;
                if (stop > k) continue;
    
                for (auto &it : adj[node]) {
                    int neighbor = it.first;
                    int cost = it.second;
                    q.push({dist + cost, {neighbor, stop + 1}});
                }
            }
    
            return -1;
        }
    };
     

    //time complexity will be O(O((E * (k + 1)) * log(E * (k + 1)))) 

    // the second approach will be BFS..
    class Solution {
        public:
            int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
                    
                    vector<vector<pair<int,int>>>adj(n);  
                    for(auto &it:flights){
                      adj[it[0]].push_back({it[1],it[2]});    //okish.... 
                    }  
                        vector<int>ans(n,1e9);
                  //  priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
                    queue<pair<int,pair<int,int>>>q;
                    q.push({0,{src,0}});  
                    while(!q.empty()){
                           int dist=q.front().first;
                           int node=q.front().second.first;
                           int stop=q.front().second.second;  
                        //   if(node==dst) return dist; 
                           q.pop(); 
                          
                           for(auto & it:adj[node]){
                                int cost=it.second;
                                int neighbor=it.first;  // this is neighbor.. 
                               
                                if(ans[neighbor]>cost+dist) {
                                   ans[neighbor]=cost+dist ; 
                                   if(stop+1<=k) {
                                   q.push({ans[neighbor],{neighbor,stop+1}});   
                                   } 
                                }
                               
                           }  
                           
                    }  
        
          return (ans[dst]==1e9)?-1:ans[dst];
            }
        };     
        //tc O(N*E)