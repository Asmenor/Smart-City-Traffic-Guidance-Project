#ifndef _ROADMAP_INTERFACE_
#define _ROADMAP_INTERFACE_

#include <vector>
#include "Road.h"

template<class V>
class RoadMapInterface{
    virtual createRoadMap(std::vector<Road>&) = 0;
    virtual calculateSP(const V&) const = 0;
    virtual printAdjacencyList() const = 0;
    virtual printAdjacencyMatrix() const = 0;
    virtual printRoadMap() const = 0;
    virtual updateRoad(string&,int,int,int) = 0;
    virtual updateIntersection(V,double) = 0; //add update vector of adj intersections

}


#endif