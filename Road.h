#ifndef _ROAD_CLASS
#define _ROAD_CLASS

#include <iostream>
#include <string>
#include "Intersection.h"
using namespace std;

template <class V>
class Road {
	string name;
	Intersection<V> *src;
	Intersection<V> *dst;
	double Congestion;
	

public:
	Road(): name("no name"), src(nullptr),dst(nullptr),Congestion(0) {}
	Road(string& n, const Intersection<V>& s, const Intersection<V>& d): name(n), src(s), dst(d), Congestion(0) {}
	Road(string& n, const Intersection<V>& s, const Intersection<V>& d, const double& c): name(n), src(s), dst(d), Congestion(c) {}

	void setSrcDst(const V& s, const V& d) {
		src = s; dst = d;
	}
	void setNameSrcDstCongestion(string& n, const V& s, const V& d, const V& c) {
		name = n, src = s; dst = d; Congestion = c;
	}

	void setName(string& n){
		name = n;
	}

	void setCongestion(const V& c) {
		Congestion = c;
	}

	V getSrc() const {
		return src;
	}

	V getDst() const {
		return dst;
	}
	
	V getCongestion() const {
		return Congestion;
	}

	string& getName() const {
		return name;
	}

};

#endif