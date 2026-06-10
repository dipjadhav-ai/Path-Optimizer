#include "routeFinder.h"

RouteResult routeFinder::getRoute(
    string source,
    string destination
){

    RouteResult result;

    result.distance=INT_MAX;

    if(
        maps.Ids.find(source)==maps.Ids.end() ||
        maps.Ids.find(destination)==maps.Ids.end()
    ){
        return result;
    }

    int start=maps.Ids[source];
    int end=maps.Ids[destination];

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> mincost(
        maps.finalId,
        INT_MAX
    );

    vector<int> parent(
        maps.finalId,
        -1
    );

    mincost[start]=0;

    pq.push({0,start});

    while(!pq.empty()){

        auto work=pq.top();
        pq.pop();

        int cost=work.first;
        int node=work.second;

        if(cost>mincost[node])
            continue;

        for(auto nxt:maps.adj[node]){

            int edgeCost=nxt.first;
            int nextNode=nxt.second;

            if(
                mincost[nextNode] >
                cost+edgeCost
            ){

                mincost[nextNode]=
                    cost+edgeCost;

                parent[nextNode]=node;

                pq.push({
                    cost+edgeCost,
                    nextNode
                });
            }
        }
    }

    if(mincost[end]==INT_MAX)
        return result;

    result.distance=mincost[end];

    vector<int> nodes;

    int node=end;

    while(node!=-1){

        nodes.push_back(node);

        node=parent[node];
    }

    reverse(
        nodes.begin(),
        nodes.end()
    );

    for(int city:nodes){

        result.path.push_back(
            maps.Cities[city]
        );
    }

    return result;
}