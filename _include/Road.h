#ifndef _ROAD_CLASS
#define _ROAD_CLASS

#include <iostream>
#include <string>
#include "Intersection.h"


template <class V>
class Road {
	std::string name;
	V src;
	V dst;
	double Congestion;
	
public:
	Road(): name("no name"), src(0),dst(0),Congestion(0) {}
	Road(std::string& n, const V& s, const V& d): name(n), src(s), dst(d), Congestion(0) {}
	Road(std::string& n, const V& s, const V& d, const double& c): name(n), src(s), dst(d), Congestion(c) {}

	void setSrcDst(const V& s, const V& d) {
		src = s; dst = d;
	}
	void setNameSrcDstCongestion(std::string& n, const V& s, const V& d, const V& c) {
		name = n, src = s; dst = d; Congestion = c;
	}

	void setName(std::string& n){
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

	std::string& getName() const {
		return name;
	}

};

#endif