/*
 * center.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: Saddam Sayyed
 */

#include "center.h"
#include <fstream>
#include "AdmissionSystem.h"
center::center() {
	id = "NA";
	name = "NA";
	address = "NA";
	coordinator = "NA";
	password = "NA";
}

const string& center::getAddress() const {
	return address;
}

void center::setAddress(const string& address) {
	this->address = address;
}

const string& center::getCoordinator() const {
	return coordinator;
}

void center::setCoordinator(const string& coordinator) {
	this->coordinator = coordinator;
}

const string& center::getName() const {
	return name;
}

void center::setName(const string& name) {
	this->name = name;
}

const string& center::getPassword() const {
	return password;
}

void center::setPassword(const string& password) {
	this->password = password;
}

center::~center() {
	// TODO Auto-generated destructor stub
}

const string& center::getId() const {
	return id;
}

void center::setId(const string& id) {
	this->id = id;
}

void center::display() {
	cout << "\n=============================================================\n";
	cout << "center id : " << id << "\n";
	cout << "name : " << name << "\n";
	cout << "address : " << address << "\n";
	cout << "coordinator : " << coordinator << "\n";
	cout << "password : " << password << "\n";
	cout << "\nCourses : \n";
	for (unsigned int i = 0; i < courses.size(); i++)
		courses[i].display();
	cout << "\nCapacities : \n";
	for (unsigned int i = 0; i < capacity.size(); i++)
		capacity[i].display();
	cout << "\n=============================================================\n";
}
