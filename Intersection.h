#ifndef INTERSECTION_CLASS_
#define INTERSECTION_CLASS_

#include <iostream>
#include <vector>

template<class V>
class Intersection {
    V value;
	double service_time;
    Intersection<V> *next; //remove
    vector<Intersection<V>> adj_intersections; //left, right, straight, back //add
public:
    Intersection(): value(0), service_time(0), next(nullptr){};
	Intersection(V& val): value(val), service_time(0), next(nullptr) {};
	Intersection(V& val, double T): value(val), service_time(T), next(nullptr){};
    Intersection(V& val, double T, Intersection<V> *nextIntersection): value(val), service_time(T), next(nextIntersection){};
    
    Intersection<V>* getNextIntersection() const;
    void setNextIntersection(Intersection<V>*);
    V getIntersectionValue() const;
    void setIntersectionValue(V);
	double getIntersectionservice_time() const;
	void setIntersectionservice_time(double);
};

template<class V>
Intersection<V>* Intersection<V>::getNextIntersection() const{
    return next;
}

template<class V>
void Intersection<V>::setNextIntersection(Intersection<V>* nextIntersection){
    next = nextIntersection;
}

template<class V>
V Intersection<V>::getIntersectionValue() const{
    return value;
}

template<class V>
void Intersection<V>::setIntersectionValue(V val){
    value = val;
}

template<class V>
double Intersection<V>::getIntersectionservice_time() const {
	return service_time;
}

template<class V>
void Intersection<V>::setIntersectionservice_time(double val) {
	service_time = val;
}

#endif
