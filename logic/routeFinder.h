#ifndef ROUTEFINDER_H
#define ROUTEFINDER_H

#include "graph.h"

struct RouteResult{

    int distance;

    vector<string> path;
};

class routeFinder{

public:

    graph maps;

    RouteResult getRoute(
        string source,
        string destination
    );
};

#endif