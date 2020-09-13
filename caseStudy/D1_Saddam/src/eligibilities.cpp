/*
 * eligibilities.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: Saddam Sayyed
 */

#include "eligibilities.h"

#include "AdmissionSystem.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

eligibilities::eligibilities() {
	course_name = "NA";
	degree = "NA";
	min_percentage = 0.0;
}

eligibilities::~eligibilities() {
	// TODO Auto-generated destructor stub
}

const string& eligibilities::getCourseName() const {
	return course_name;
}

const string& eligibilities::getDegree() const {
	return degree;
}

void eligibilities::setDegree(const string& degree) {
	this->degree = degree;
}

double eligibilities::getMinPercentage() const {
	return min_percentage;
}

void eligibilities::setMinPercentage(double minPercentage) {
	min_percentage = minPercentage;
}

void eligibilities::setCourseName(const string& courseName) {
	course_name = courseName;
}

void eligibilities::display() {
	cout << "\t\n-----------------------------------------\n";
	//cout<<"\tcourse Name : "<<course_name<<"\n";
	cout << "\tDegree : " << degree << "\n";
	cout << "\tPercentage : " << min_percentage << "\n";
	cout << "\t\n-----------------------------------------\n";
}

