/*
 * center.h
 *
 *  Created on: 16-Apr-2020
 *      Author: Saddam Sayyed
 */

#ifndef CENTER_H_
#define CENTER_H_
#include "course.h"
#include "capacities.h"
#include <cstring>
#include <iostream>
using namespace std;

class center {
private:
	string id;
	string name;
	string address;
	string coordinator;
	string password;
public:
	vector<course> courses;
	vector<capacities> capacity;
	center();
	virtual ~center();
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getCoordinator() const;
	void setCoordinator(const string& coordinator);
	const course*& getCourses() const;
	const string& getName() const;
	void setName(const string& name);
	const string& getPassword() const;
	void setPassword(const string& password);
	void load();
	void display();
	const string& getId() const;
	void setId(const string& id);
};

#endif /* CENTER_H_ */
