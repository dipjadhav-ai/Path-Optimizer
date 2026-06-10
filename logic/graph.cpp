#include "graph.h"
#include <fstream>

graph::graph(){

    fstream file("roads.txt", ios::in);

    if(!file.is_open()){
        cerr << "Unable to open file";
        return;
    }

    string city1;
    string city2;
    string roadcost;

    while(file >> city1 >> city2 >> roadcost){
        addCity(
            city1,
            city2,
            roadcost
        );
    }

    file.close();
}

void graph::addCity(
    string city1,
    string city2,
    string roadcost
){

    if(Ids[city1] == 0){
        Ids[city1] = finalId;
        Cities[finalId] = city1;
        finalId++;
    }

    if(Ids[city2] == 0){
        Ids[city2] = finalId;
        Cities[finalId] = city2;
        finalId++;
    }

    int c1 = Ids[city1];
    int c2 = Ids[city2];
    int cost = stoi(roadcost);

    adj[c1].push_back({cost,c2});
    adj[c2].push_back({cost,c1});
}