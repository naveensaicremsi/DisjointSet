#include<bits/stdc++.h>
using namespace std;

class DisjointSet{

    private:

    vector<int>size;
    vector<int>parent;

    public:

    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0; i<=n; i++)
        {
            parent[i] =i;
        }
    }

    int findUltimateParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findUltimateParent(parent[node]);
    }
    
    void UnionBySize(int u,int v)
    {
        int up_u=findUltimateParent(u);
        int up_v=findUltimateParent(v);
        if(up_u==up_v)
        {
            return;
        }
        if(size[up_u]<size[up_v])
        {
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else 
        {
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }

};

int main()
{
    DisjointSet d1(7);
   d1.UnionBySize(1,2);
   d1.UnionBySize(2,3);
   d1.UnionBySize(4,5);
   d1.UnionBySize(6,7);
   d1.UnionBySize(5,6);
   
   // check weather 3 and 7 belongs to same component or not

   if(d1.findUltimateParent(3)==d1.findUltimateParent(7))
   {
    cout<<"Same\n";
   }
   else
   {
    cout<<"Not same\n";
   }
   d1.UnionBySize(3,7);
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