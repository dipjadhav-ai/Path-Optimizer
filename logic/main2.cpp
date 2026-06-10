#include "routeFinder.h"

int main(){

    routeFinder route;

    string source,destination;

    cout<<"Enter source city : ";
    cin>>source;

    cout<<"Enter destination city : ";
    cin>>destination;

    int start=route.maps.Ids[source];
    int end=route.maps.Ids[destination];

    vector<int> path=route.finder(start,end);

    route.routeDisplay(path,route.distance);

    return 0;
}