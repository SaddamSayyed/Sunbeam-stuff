/*
 * course.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: Saddam Sayyed
 */

#include "course.h"
#include <fstream>
#include "AdmissionSystem.h"
course::course()
{
	id="NA";
	name = "NA";
	fees = "NA";
	ccat_section = "NA";
	//eligibilities[10] = "NA";

}

course::~course() {
}

const string& course::getCcatSection() const {
	return ccat_section;
}

void course::setCcatSection(const string& ccatSection) {
	ccat_section = ccatSection;
}

const string& course::getFees() const {
	return fees;
}

void course::setFees(const string& fees) {
	this->fees = fees;
}

const string& course::getName() const {
	return name;
}

const string& course::getId() const {
	return id;
}

void course::setId(const string& id) {
	this->id = id;
}

void course::setName(const string& name) {
	this->name = name;
}
void course::display()
{
	cout<<"\t\n-----------------------------------------\n";
	cout<<"\tcourse id : "<<id<<"\n";
	cout<<"\tname : "<<name<<"\n";
	cout<<"\tFees : "<<fees<<"\n";
	cout<<"\tccat_section : "<<ccat_section<<"\n";
	/*cout<<"\t\nEligibilities :\n";
	for(unsigned int i=0; i<eligibility.size();i++)
		eligibility[i].display();*/
	cout<<"\t\n-----------------------------------------\n";
}
