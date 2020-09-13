/*
 * students.cpp
 *
 *  Created on: 15-Apr-2020
 *      Author: Saddam Sayyed
 */

#include "students.h"
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include "AdmissionSystem.h"
using namespace std;
students::students() {
	form_no = 0;
	name = "not loadd";
	rank_a = -1;
	rank_b = -1;
	rank_c = -1;
	degree = "NA";
	percentage = 0.0;
	Allocated_preference = 0;
	Allocated_course_name = "NA";
	Allocated_center_id = "NA";
	Payment = 0;
	Reported_to_center = 0;
	Prn = "not Generated";
}

int students::getAllocatedPreference() const {
	return Allocated_preference;
}

void students::setAllocatedPreference(int allocatedPreference) {
	Allocated_preference = allocatedPreference;
}

const string& students::getDegree() const {
	return degree;
}

void students::setDegree(const string& degree) {
	this->degree = degree;
}

int students::getFormNo() const {
	return form_no;
}

void students::setFormNo(int formNo) {
	form_no = formNo;
}

const string& students::getName() const {
	return name;
}

void students::setName(const string& name) {
	this->name = name;
}

double students::getPercentage() const {
	return percentage;
}

void students::setPercentage(double percentage) {
	this->percentage = percentage;
}

int students::getRankA() const {
	return rank_a;
}

void students::setRankA(int rankA) {
	rank_a = rankA;
}

int students::getRankB() const {
	return rank_b;
}

void students::setRankB(int rankB) {
	rank_b = rankB;
}

int students::getRankC() const {
	return rank_c;
}

void students::setRankC(int rankC) {
	rank_c = rankC;
}

const string& students::getAllocatedCourseName() const {
	return Allocated_course_name;
}

void students::setAllocatedCourseName(const string& AllocatedCourseName) {
	this->Allocated_course_name = AllocatedCourseName;
}
const string& students::getAllocatedCenterId() const {
	return Allocated_center_id;
}

void students::setAllocatedCenterId(const string& AllocatedCenterId) {
	this->Allocated_center_id = AllocatedCenterId;
}
const string& students::getPrn() const {
	return Prn;
}

double students::getPayment() const {
	return Payment;
}

int students::getReportedToCenter() const {
	return Reported_to_center;
}

void students::setReportedToCenter(int reportedToCenter) {
	Reported_to_center = reportedToCenter;
}

void students::setPayment(double payment) {
	Payment = payment;
}

void students::setPrn(const string& Prn) {
	this->Prn = Prn;
}
students::~students() {
	// TODO Auto-generated destructor stub
}
void students::display() {
	cout << "\n=============================================================\n";
	cout << "form_no : " << form_no << "\n";
	cout << "name : " << name << "\n";
	cout << "rank_a : " << rank_a << "\n";
	cout << "rank_b : " << rank_b << "\n";
	cout << "rank_c : " << rank_c << "\n";
	cout << "degree : " << degree << "\n";
	cout << "percentage : " << percentage << "\n";
	cout << "Allocated_preference : " << Allocated_preference << "\n";
	cout << "Allocated_course_name : " << Allocated_course_name << "\n";
	cout << "Allocated_center_id : " << Allocated_center_id << "\n";
	cout << "Payment : " << Payment << "\n";
	cout << "Reported_to_center : " << Reported_to_center << "\n";
	cout << "Prn : " << Prn << "\n";
	cout << "\nPreferences :\n";
	for (unsigned int i = 0; i < filled_preferences.size(); i++)
		filled_preferences[i].display();
	cout << "\n=============================================================\n";
}

void students::display_eligible_courses() {
	AdmissionSystem *ptr = AdmissionSystem::get_instance();
	string section = "A";
	if (this->rank_b != -1)
		section = "B";
	if (this->rank_c != -1)
		section = "C";
	cout << "\nSection of Student : " << section;
	if (section == "A" && this->percentage >= 50) {
		for (unsigned int i = 0; i < ptr->course_info.size(); i++) {
			if (ptr->course_info[i].getName() == "PG-DGI") {
				ptr->course_info[i].display();
				cout << "Centers Conducting This Course :\n";
				ptr->display_centers_with_course(ptr->course_info[i].getName());

			}
		}
	}
	if (section == "B" && this->percentage >= 55) {
		for (unsigned int i = 0; i < ptr->course_info.size(); i++) {
			if (ptr->course_info[i].getName() != "PG-DESD") {
				ptr->course_info[i].display();
				cout << "Centers Conducting This Course :\n";
				ptr->display_centers_with_course(ptr->course_info[i].getName());
			}
		}

	}
	if (section == "C" && this->percentage >= 55) {
		for (unsigned int i = 0; i < ptr->course_info.size(); i++) {
			ptr->course_info[i].display();
			cout << "Centers Conducting This Course :\n";
			ptr->display_centers_with_course(ptr->course_info[i].getName());

		}
	}

	this->display();
}
