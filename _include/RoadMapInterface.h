#ifndef _ROADMAP_INTERFACE_
#define _ROADMAP_INTERFACE_

#include <vector>
#include "Road.h"

template<class V>
class RoadMapInterface{
    virtual void calculateDijkstrasSP(const V&) = 0;
    virtual void printAdjList() const = 0;
    virtual void printAdjMatrix(bool) const = 0;
    //virtual void printRoadMap() const = 0;
    //virtual void updateRoad(string&,int,int,int) = 0;
    //virtual void updateIntersection(V,double) = 0; //add update vector of adj intersections

};


#endif