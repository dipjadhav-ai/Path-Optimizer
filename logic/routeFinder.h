#ifndef ROUTEFINDER_H
#define ROUTEFINDER_H

#include "graph.h"

class routeFinder{

public:

    graph maps;
    int distance;

    routeFinder();

    vector<int> finder(int start,int end);

    void routeDisplay(vector<int> route,int roadcost);
};

#endif