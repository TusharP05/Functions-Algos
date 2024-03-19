#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> parent, rank, size;

    public:
    //initializing the constructor
    disjointSet(int n){ 
      rank.resize(n+1, 0);
      parent.resize(n+1);
      size.resize(n+1);
      for(int i=0; i<=n; i++){
        parent[i]=i;
        size[i]=1;
      }
    }
    //The Find Ultimate Parent Function

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]= findParent(parent[node]);
    }
    
    //The Union by Rank Function

    void unionByRank(int u, int v){
        int ult_u= findParent(u);
        int ult_v= findParent(v);
        if(ult_u==ult_v) return;
        else if(rank[ult_u]>rank[ult_v]){
          parent[ult_v]=ult_u;
        }
        else if(rank[ult_u]<rank[ult_v]){
          parent[ult_u]=ult_v;
        }
        else{
            parent[ult_u]=ult_v;
            rank[ult_v]++;
        }

    }

    // The Union by Size Function

     void unionBySize(int u, int v){
        int ult_u= findParent(u);
        int ult_v= findParent(v);
        if(ult_u==ult_v) return;
        else if(size[ult_u]>size[ult_v]){
          parent[ult_v]= parent[ult_u];
          size[ult_u]+= size[ult_v];
        }
      
        else{
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }

    }





};