#ifndef GRAPH_H
#define GRAPH_H

#include<bits/stdc++.h>
using namespace std;

class graph{
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    unordered_map<string,int> Ids;
    unordered_map<int,string> Cities;
    int finalId=1;

    graph();

    void addCity(string city1,string city2,string roadcost);
};

#endif