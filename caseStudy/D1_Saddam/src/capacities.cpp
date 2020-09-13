/*
 * capacities.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: Saddam Sayyed
 */

#include "capacities.h"
#include <fstream>
#include "AdmissionSystem.h"
capacities::capacities() {
	id = "NA";
	name = "NA";
	capacity = 0;
	filled_seats = 0;
}
capacities::~capacities() {
}

int capacities::getCapacity() const {
	return capacity;
}

void capacities::setCapacity(int capacity) {
	this->capacity = capacity;
}

int capacities::getFilledSeats() const {
	return filled_seats;
}

void capacities::setFilledSeats(int filledSeats) {
	filled_seats = filledSeats;
}

const string& capacities::getId() const {
	return id;
}

void capacities::setId(const string& id) {
	this->id = id;
}

const string& capacities::getName() const {
	return name;
}

void capacities::setName(const string& name) {
	this->name = name;
}

void capacities::display() {
	cout << "\t\n-----------------------------------------\n";
	//cout<<"\tCenter id : "<<id<<"\n";
	cout << "\tCourse name : " << name << "\n";
	cout << "\tCapacity : " << capacity << "\n";
	cout << "\tFilled Seats : " << filled_seats << "\n";
	cout << "\t\n-----------------------------------------\n";
}
