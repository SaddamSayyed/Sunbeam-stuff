/*
 * course.h
 *
 *  Created on: 16-Apr-2020
 *      Author: Saddam Sayyed
 */

#ifndef COURSE_H_
#define COURSE_H_
#include <cstring>
#include <iostream>
#include "eligibilities.h"
#include <vector>
using namespace std;
class course {
private:
	string id;
	string name;
	string fees;
	string ccat_section;
public:
	vector<eligibilities> eligibility;
	course();
	virtual ~course();
	const string& getCcatSection() const;
	void setCcatSection(const string& ccatSection);
	const string& getFees() const;
	void setFees(const string& fees);
	const string& getName() const;
	void setName(const string& name);
	const string& getId() const;
	void setId(const string& id);
	void load();
	void display();
};

#endif /* COURSE_H_ */
