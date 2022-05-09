/*
Currently this class in not in use. It has been kept for potential future use.
*/

#ifndef INTERSECTION_CLASS_
#define INTERSECTION_CLASS_

#include <iostream>
#include <vector>

template<class V>
class Intersection {
    V value;
	double congestion;
    Intersection<V> *next;
public:
    Intersection(): value(0), congestion(0.0), next(nullptr){};
	Intersection(V& val): value(val), congestion(0.0), next(nullptr) {};
	Intersection(V& val, double C): value(val), congestion(C), next(nullptr){};
    Intersection(V& val, double C, Intersection<V> *nextIntersection): value(val), congestion(C), next(nextIntersection){};
    
    Intersection<V>* getNextIntersection() const;
    void setNextIntersection(Intersection<V>*);
    V getIntersectionValue() const;
    void setIntersectionValue(V);
	double getIntersectionCongestion() const;
	void setIntersectionCongestion(double);
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
double Intersection<V>::getIntersectionCongestion() const {
	return congestion;
}

template<class V>
void Intersection<V>::setIntersectionCongestion(double val) {
	congestion = val;
}

#endif
