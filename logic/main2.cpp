#include "routeFinder.h"

int main(int argc,char* argv[]){

    if(argc!=3){
        cout<<"Invalid Arguments";
        return 1;
    }

    string source=argv[1];
    string destination=argv[2];

    routeFinder rf;

    RouteResult result=
        rf.getRoute(source,destination);

    if(result.distance==INT_MAX){

        cout<<"{\"error\":\"No Route Found\"}";
        return 0;
    }

    cout<<"{";
    cout<<"\"distance\":"<<result.distance<<",";

    cout<<"\"path\":[";

    for(int i=0;i<result.path.size();i++){

        cout<<"\""<<result.path[i]<<"\"";

        if(i!=result.path.size()-1)
            cout<<",";
    }

    cout<<"]}";

    return 0;
}