#ifndef _ROAD_CLASS
#define _ROAD_CLASS

#include <iostream>
#include <string>

template <class V>
class Road {
	std::string name;
	V src;
	V dst;
	float Congestion;
	float length_segment;	//miles
	int no_of_cars; 
	float avg_speed;		//mph
	int no_of_lanes;		//mph
	int speed_limit;
	Road<V> *next;

public:

	Road(): name("no name"), src(0),dst(0),Congestion(0.0), length_segment(0.0), no_of_cars(0), avg_speed(0.0), no_of_lanes(0), speed_limit(0)  {}
	
	Road(std::string& n, const V& s, const V& d, const int& nc, const float& ls, const float& v, const int& n_l, const int& limit, const float& cng) {
		name = n;
		src = s;
		dst = d;
		no_of_cars = nc;
		length_segment = ls;
		avg_speed = v;
		no_of_lanes = n_l;
		speed_limit = limit;
		Congestion = cng;

	}

	void setRoadParameters(std::string& nme, const V& s, const V& d, const float& c, const float& l, const int& n, const float& v, const int& n_l, const int& limit, const float& cng) {
		name = nme, src = s; dst = d;
		length_segment = l; no_of_cars = n; avg_speed = v, no_of_lanes = n_l; speed_limit = limit; Congestion = cng;
	}

	void setName(std::string& n) { name = n; }
	float getCongestion() const { return Congestion; }
	void setCongestion(const float& c) { Congestion = c; }
	void setSrcDst(const V& s, const V& d) { src = s; dst = d; }
	V getSrc() const { return src; }
	V getDst() const { return dst; }
	std::string getName() const { return name;}
	float getLength() const { return length_segment; }
	void setLength(const float& ls) { length_segment = ls; }
	Road<V>* getNextRoad() const{return next;}
	void setNextRoad(Road<V>* nextRoad) { next = nextRoad; }
	void setNumCars(const int& nc) { no_of_cars = nc; }
	int getNumCars() const { return no_of_cars; }
	float getAvgSpeed() const { return avg_speed; }
	void setAvgSpeed(const float& v) { avg_speed = v; }
	void setSpeedLimit(const int& limit) {speed_limit = limit;}
	int getSpeedLimit() const {return speed_limit;}
};

#endif