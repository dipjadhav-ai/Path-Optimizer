#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class graph{
    
    public:

    unordered_map<int,vector<pair<int,int>>>adj;
    unordered_map<string,int>Ids;
    unordered_map<int,string>Cities;
    int finalId=1;

    public:

    graph(){
        fstream file("roads.txt",ios::in);
        if(!file.is_open()){
            cout<<"Unable to open file";
            return;
        }
        string city1,city2,roadcost;
        while(file>>city1>>city2>>roadcost){
            addCity(city1,city2,roadcost);
        }
    };
    void addCity(string city1,string city2, string roadcost){
        if(Ids[city1]==0){
            Ids[city1]=finalId;
            Cities[finalId]=city1;
            finalId++;
        }
        if(Ids[city2]==0){
            Ids[city2]=finalId;
            Cities[finalId]=city2;
            finalId++;
        }
        int c1=Ids[city1],c2=Ids[city2], price=stoi(roadcost);
        adj[c1].push_back({price,c2});
        adj[c2].push_back({price,c1});
    }
};

class routeFinder{
    public:
    int start,end;
    graph maps;
    int distance=0;
    routeFinder(string s1,string s2){
        start = maps.Ids[s1];
        end = maps.Ids[s2];
        vector<int>order=finder(start,end);
        cout<<"Best route among the all routes possible is:"<<"\n";
        if(distance!=INT_MAX) cout<<routeDisplay(order,distance)<<"\n"<<"Total Cost:"<<distance;
        else cout<<routeDisplay(order,distance)<<"\n";
    }
    string routeDisplay(vector<int>route,int roadcost){
        if(roadcost==INT_MAX){
            return "No path exist as of now!!!!";
        }
        string ans="";
        unordered_map<int,string>Cities = maps.Cities;
        for(int i:route){
            ans+=Cities[i]+"->";
        }
        return ans;
    }
    vector<int> finder(int node1,int node2){
        unordered_map<int,vector<pair<int,int>>>adj = maps.adj;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>mincost(maps.finalId,INT_MAX);
        vector<int>parent(maps.finalId,-1);
        vector<int>ans; 
        mincost[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            pair<int,int>work=pq.top();
            pq.pop();
            int node = work.second;
            int cost = work.first;
            if(cost > mincost[node]) continue;
            if(cost > mincost[node2]) break;
            for (auto neg:adj[node]){
                int nextNode = neg.second;
                int nextCost = neg.first;
                if(mincost[nextNode] > cost+nextCost){
                    mincost[nextNode]=cost+nextCost;
                    parent[nextNode]=node;
                    pq.push({cost+nextCost,nextNode});
                }
            }
        }
        distance=mincost[node2];
        int node=node2;
        while(node!=-1){
            ans.push_back(node);
            node=parent[node];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class input{
    public:
    string city1,city2;
    public:
    input(){
        cout<<"Entre the city from to"<<"\n";
        cin>>city1>>city2;
    }
};

int main(){
    input user1;
    routeFinder route(user1.city1,user1.city2);
    return 0;
}