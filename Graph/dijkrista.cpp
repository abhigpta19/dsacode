#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,S});
        vector<int> visited(V,0);
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            visited[node]=1;
            
            for(auto x: adj[node])
            {
                if(!visited[x[0]] && dist[x[0]]>d+x[1])
                {
                    dist[x[0]]=d+x[1];
                    pq.push({dist[x[0]],x[0]});
                }
            }
        
            
        }
        return dist;
    }
};
