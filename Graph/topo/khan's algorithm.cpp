
/*  
by the use KHAN'S ALGORITHM WE CAN FIND WHETHER IT IS POOSBILE TO FIND TO-PO ORDER  for a particuler graph..abort
Algorithm:
Step1: Compute the Indegree of all the vertices of the Graph and Initialize the variable count with zero(It maintains the Visited node count)
 
Step 2: All the nodes with the in-degree must have zero pick them and put them in a Queue
 
Step 3: Pick the node from the Queue mark it visited then, increment the count value and Decrement the Indegree value for all the nodes that are
 edges from the given node
 
Step 4: Keep Doing step 3 until the Queue is Empty
 
Step 5: Now compare the count value with the no of nodes of the graph,in-degree, and if they are not equal, then the Topological sort is not 
possible for the Graph.   

Application of Kahn’s algorithm 
Here are some key applications of Kahn's algorithm:

Task Scheduling: Determining the order in which tasks or jobs should be executed to meet dependencies or constraints
 
Course Scheduling: Scheduling courses in academic institutions while considering prerequisites
 
Workflow Management: Designing and executing workflows in data processing or automation systems
 
Network Routing: Finding the optimal path or order for data or signal transmission in networks
 
Optimization Problems: Solving optimization problems that involve ordering or sequencing constraints
  
Resource Allocation: Managing resource allocation in scenarios with interdependent tasks or processes  

time complexity will ve O(V+E)............   

*/ 

//here is code 
vector<vector<int>>adj(n); 
vector<int>indegree(n,0);  //this is for indegree...
for(auto &it:edges){
   adj[it.first].push_back(it.second); 
   indegree[it.second]++;
}   
     //adj is a adjancency list is there....  
queue<int>q;
for(int i=0;i<n;i++){
   if(indegree[i]==0) q.push(i);
} 
  vector<int>topo;
 while(!q.empty()){  
   int node=q.front(); //main node  
       topo.push_back(node);
         q.pop();
    for(auto & it:adj[node]){
          indegree[it]--;
         if(indegree[it]==0) q.push(it);
   }   

 }  
 int p=topo.size(); 
 return (p==n)?0:1;
}  
  
// by the use of this we can also detect cycle in directed graph 