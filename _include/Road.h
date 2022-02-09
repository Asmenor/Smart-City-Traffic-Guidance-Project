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
	float length_segment; //miles
	int no_of_cars;
	float avg_speed; //mph
	int no_of_lanes;

public:
	Road(): name("no name"), src(0),dst(0),Congestion(0.0), length_segment(0.0), no_of_cars(0), avg_speed(0.0), no_of_lanes(0)  {}
	Road(std::string& n, const V& s, const V& d): name(n), src(s), dst(d), Congestion(0), length_segment(0.0), no_of_cars(0), avg_speed(0.0), no_of_lanes(0) {}
	Road(std::string& n, const V& s, const V& d, const float& c): name(n), src(s), dst(d), Congestion(c), length_segment(0.0), no_of_cars(0), avg_speed(0.0), no_of_lanes(0) {}

	void setRoadParameters(std::string& nme, const V& s, const V& d, const float& c, const float& l, const int& n, const float& v, const int& n_l) {
		name = nme, src = s; dst = d; Congestion = c;
		length_segment = l; no_of_cars = n; avg_speed = v, no_of_lanes = n_l;
	}

	void setName(std::string& n) { name = n; }
	void setCongestion(const float& c) { Congestion = c; }
	float getCongestion() const { return Congestion; }
	void setSrcDst(const V& s, const V& d) { src = s; dst = d; }
	V getSrc() const { return src; }
	V getDst() const { return dst; }
	std::string getName() const { return name;}
	float getLength() const { return length_segment; }
	void setLength(const float& l) { length_segment = l; }

};

#endif