/* disjoint set union this is tell us if there is given a dynamic graph then finding the (components , parents node and all the these stuff) in constant tie 
  i can asked you answer at any time and you have to tell me  that  like  query wala example*/  

  //rank :: benith for a particuler node 
  // parents ::  just above node for a particuler node 

  /* 
    */

  /*   
      input n=7 
      these are query and i have ot tell at each query okk... 
       (1,2)
       (2,3)
       (4,5)
       (6,7)                                      6
       (5,6)                                 - -  - - - - - -
       (3,7)     GRAPH FORMATION ::  1 - 2 - 3   4 - 5 - 6 - 7   
                   QUERY ::           1   2       3   4   5   

    step 1:: find ultimate parents for a particular node (u,v) 
    step 2:: find rank for the (u,v)
    step 3:: Smaller one rank will add on  larger one .. 
                   
               */

        // code 

        #include<bits/stdc++.h>
using namespace std; 

 class DisjointSet{ 
           vector<int>parent,rank;
   public:  //here make public so that we can access it from out side class also... 

           DisjointSet (int n){    //this is constructer for put intial values 
                parent.resize(n+1);
                rank.resize(n+1,0);
              for(int i=0;i<=n;i++){
                parent[i]=i;
               }  
             }    
    
             int findParents(int node){    //path compression technique here is used..
                if(node==parent[node]) {
                    return node;
                } 
                 return parent[node]=findParents(parent[node]); 
             }   

            void unionByrank(int u,int v){
                 int ult_u=findParents(u);
                 int ult_v=findParents(v);
                 if(ult_u==ult_v) return ;
                 if(rank[ult_u]<rank[ult_v]) {
                     parent[ult_u]=ult_v;
                 }  
                else if(rank[ult_u]>rank[ult_v]) {
                    parent[ult_v]=ult_u;
                }  
                else{
                    //when rank is equal 
                    parent[ult_u]=ult_v;
                    rank[ult_v]++;
                } 
            } 

 };  


int main(){
    //karna hai badd main 
    DisjointSet ds(7); 
    ds.unionByrank(1,2);
    ds.unionByrank(2,3);
    ds.unionByrank(4,5);
    ds.unionByrank(6,7);
    ds.unionByrank(5,6); 
     if(ds.findParents(3)==ds.findParents(7)) {
        cout<<"same"<<endl;
     } 
     else{
        cout<<"Not -same"<<endl;
     } 
    ds.unionByrank(3,7);  
  //  return 0;

    if(ds.findParents(3)==ds.findParents(7)) {
        cout<<"same"<<endl;
     } 
     else{
        cout<<"Not -same"<<endl;
     } 

}  

 /* 
 Operation	Time Complexity	Space Complexity
findParent()	O(α(n))	O(n)   here alphe will be near about (4,5)..
unionByRank()	O(α(n))	O(n)
  */
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  */