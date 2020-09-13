/*
 * preferences.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: Saddam Sayyed
 */

#include "preferences.h"
#include "AdmissionSystem.h"

preferences::preferences() {
	form_no = 0;
	preference_no = 0;
	cource_name = "NA";
	center_id = "NA";
}

const string& preferences::getCenterId() const {
	return center_id;
}

void preferences::setCenterId(const string& centerId) {
	center_id = centerId;
}

const string& preferences::getCourceName() const {
	return cource_name;
}

void preferences::setCourceName(const string& courceName) {
	cource_name = courceName;
}

int preferences::getFormNo() const {
	return form_no;
}

void preferences::setFormNo(int formNo) {
	form_no = formNo;
}

int preferences::getPreferenceNo() const {
	return preference_no;
}

void preferences::setPreferenceNo(int preferenceNo) {
	preference_no = preferenceNo;
}

preferences::~preferences() {
	// TODO Auto-generated destructor stub
}
void preferences::display() {

	cout << "\t\n-----------------------------------------\n";
	//cout<<"\tForm No :  "<<form_no<<"\n";
	cout << "\tPreference no : " << preference_no << "\n";
	cout << "\tCource Name : " << cource_name << "\n";
	cout << "\tCenter Id : " << center_id << "\n";
	cout << "\t\n-----------------------------------------\n";
}
void preferences::accept() {
	//cout<<"\tForm No :  "<<form_no<<"\n";
	cout << "\tPreference no : ";
	cin >> preference_no;
	cout << "\tCource Name : ";
	cin >> cource_name;
	cout << "\tCenter Id : ";
	cin >> center_id;
}
