//⁠Dijkstra's algorithm solves the single-source shortest path problem for a graph with non-negative edge weights. 
//the single-source shortest path problem for a graph with non-negative edge weights.
//It finds the path with the lowest total cost, distance, or time from a single starting point (node) 
//to all other reachable nodes (or a specific destination node).
const int N=1e5+5;
vector<pair<int,int>>adj[N];//the graph representation
vector<int>cost(N,-1);//the vector that U will use to find the shortest or lowest total cost from ur start node and i node.
void dijkstra(int start)//pass the root node
{
    priority_queue<pair<int,int>,deque<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});
    while(pq.size())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int node=p.second,nodecost=p.first;
        if(cost[node]!=-1)
        {
            continue;
        }
        cost[node]=nodecost;
        for(auto [node2,cost2]:adj[node])
        {
            if(cost[node2]==-1)
            {
                pq.push({nodecost+cost2,node2});
            }
        }
    }
}
