#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Edge
{
    int src,dst;
}Edge;

class Graph
{
public:
    vector< vector<int> > adjList;
    vector<int> indegree;
    
    Graph(vector< Edge > G, int N )
    {
        adjList.resize(N);
        vector<int> empty(N, 0);
        indegree = empty;
        for (auto edge : G)
        {
            adjList[edge.src].push_back(edge.dst);
            ++indegree[edge.dst];
        }
    }
    
    bool topologicalSort(vector<int>& L)
    {
        vector<int> S;
        
        // find out node having indegree zero
        for (int i=0; i<indegree.size(); ++i)
        {
            if (!indegree[i])
            {
                S.push_back(i);
            }
        }
        
        while (!S.empty())
        {
            int node = S.back();
            S.pop_back();
            L.push_back(node);
            
            for (int nxt: adjList[node])
            {
                indegree[nxt]--;
                if (!indegree[nxt])
                {
                    S.push_back(nxt);
                }
            }
        }
        
        for (int i=0; i<indegree.size(); ++i)
        {
            if (indegree[i]) { return false; }
        }
        return true;
        
    }
    
    
};
int main()
{
    vector< Edge > edges({{0,1},{1,2},{1,4},{2,3},{2,4}});
    Graph G(edges,5);
    vector<int> L;
    if (G.topologicalSort(L))
    {
        for (int ele:L)
        {
            cout << "  " << ele;
        }
        
    }
    else
    {
        cout << "Cycle detected";
        return -1;
    }
    return 0;
}
