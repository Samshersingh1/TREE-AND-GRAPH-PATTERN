/* ✅ Why Dijkstra Uses a Priority Queue
Dijkstra’s algorithm uses a priority queue (min-heap) to always pick the node with the smallest distance so far.

That means:
You process the most promising (cheapest) path first

When you reach a node via the shortest path, you never need to revisit it

It works even when weights vary

 
🧠 Intuition:
In a weighted graph, "getting somewhere first" doesn’t mean "getting there cheapest."
You must always choose the cheapest path so far, not the earliest — and that’s what Dijkstra (with a priority queue) does.*/ 

class Solution {
    public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //  int n=adj.size();
             vector<int>ans(V,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
               vector<vector<pair<int,int>>>adj(V); 
            
             for(auto &it:edges){
                 adj[it[0]].push_back({it[1],it[2]}); 
             } 
              
            int cnt=0;
            ans[src]=0;  
            q.push({0,src}); 
            while(q.size()>0){ 
                 int d=q.top().first, node=q.top().second;   
                    q.pop(); 
                  // cnt++;
                  for(auto &c:adj[node]) { 
                   if(ans[c.second]>d+c.first) {
                    ans[c.second]= d+c.first; 
                       q.push({c.second,c.first+d});  
                    }  
                } 
            }   
            
           
            return ans;
      }
  }; 

  //time complexity will be O(E+VlogV) beacause we are using PQ..