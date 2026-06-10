#include "routeFinder.h"

int main(){

    routeFinder rf;

    string source;
    string destination;

    cin>>source>>destination;

    RouteResult result=
        rf.getRoute(
            source,
            destination
        );

    if(result.distance==INT_MAX){

        cout<<"No route found\n";

        return 0;
    }

    cout<<"Distance : "
        <<result.distance
        <<"\n";

    for(auto city:result.path){

        cout<<city<<" -> ";
    }

    cout<<"\n";

    return 0;
}