#include "routeFinder.h"

routeFinder::routeFinder(){
    distance=0;
}

vector<int> routeFinder::finder(int node1,int node2){

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> mincost(maps.finalId,INT_MAX);
    vector<int> parent(maps.finalId,-1);

    vector<int> ans;

    mincost[node1]=0;

    pq.push({0,node1});

    while(!pq.empty()){

        auto work=pq.top();
        pq.pop();

        int cost=work.first;
        int node=work.second;

        if(cost>mincost[node])
            continue;

        for(auto nxt:maps.adj[node]){

            int nextCost=nxt.first;
            int nextNode=nxt.second;

            if(mincost[nextNode] > cost+nextCost){

                mincost[nextNode]=cost+nextCost;
                parent[nextNode]=node;

                pq.push({cost+nextCost,nextNode});
            }
        }
    }

    distance=mincost[node2];

    if(distance==INT_MAX)
        return {};

    int node=node2;

    while(node!=-1){

        ans.push_back(node);
        node=parent[node];
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

void routeFinder::routeDisplay(vector<int> route,int roadcost){

    if(roadcost==INT_MAX){

        cout<<"No route exists\n";
        return;
    }

    cout<<"\nShortest Route:\n";

    for(int city:route){

        cout<<maps.Cities[city]<<" -> ";
    }

    cout<<"\nDistance = "<<roadcost<<"\n";
}