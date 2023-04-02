/*
Disjoint Set Data structure is used to find the ultimate parent of a node and also to create the graph dynamically.
The main beauty of the Disjoint Set is it tells for a given 2 nodes , weather they belongs to same component or not in constant time O(4alpha).
We use path Compression Technique.
Time Complexity of Disjoint Set DataStucture is O(4 alpha ) which is constant.
There are two types of Unions in Disjoint Set Data Structure Union By Rank and By size.
This is using Union By Rank.
*/
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>parent;
    vector<int>rank;
    public :
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0; i<=n; i++)
        {
            parent[i]=i;
        }
    }
    int findUltimateParent(int n)
    {
        if(parent[n]==n)
        {
            return n;
        }
        return parent[n]=findUltimateParent(parent[n]);
    }
    void UnionByRank(int u,int v)
    {
        int up_u=findUltimateParent(u);
        int up_v=findUltimateParent(v);
        if(up_u==up_v)
        {
            return;
        }
        if(rank[up_u]<rank[up_v])
        {
            parent[up_u]=up_v;
        }
        else if(rank[up_u]==rank[up_v])
        {
            parent[up_u]=up_v;
            rank[up_v]++;
        }
        else
        {
            parent[up_v]=up_u;
        }
    }
};
int main()
{
   DisjointSet d1(7);
   d1.UnionByRank(1,2);
   d1.UnionByRank(2,3);
   d1.UnionByRank(4,5);
   d1.UnionByRank(6,7);
   d1.UnionByRank(5,6);
   
   // check weather 3 and 7 belongs to same component or not

   if(d1.findUltimateParent(3)==d1.findUltimateParent(7))
   {
    cout<<"Same\n";
   }
   else
   {
    cout<<"Not same\n";
   }
   d1.UnionByRank(3,7);
   if(d1.findUltimateParent(3)==d1.findUltimateParent(7))
   {
    cout<<"Same\n";
   }
   else
   {
    cout<<"Not same\n";
   }
   return 0;
}