/*
 * eligibilities.h
 *
 *  Created on: 17-Apr-2020
 *      Author: Saddam Sayyed
 */

#ifndef ELIGIBILITIES_H_
#define ELIGIBILITIES_H_
#include <cstring>
#include <iostream>
using namespace std;
class eligibilities {
private :
	string course_name ;
	string degree;
	double min_percentage;
public:
	eligibilities();
	virtual ~eligibilities();
	void display();
	const string& getCourseName() const;
	void setCourseName(const string& courseName);
	const string& getDegree() const;
	void setDegree(const string& degree);
	double getMinPercentage() const;
	void setMinPercentage(double minPercentage);
};

#endif /* ELIGIBILITIES_H_ */
