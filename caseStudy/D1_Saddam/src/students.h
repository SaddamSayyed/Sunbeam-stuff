/*
 * students.h
 *
 *  Created on: 15-Apr-2020
 *      Author: Saddam Sayyed
 */

#ifndef STUDENTS_H_
#define STUDENTS_H_
#include <cstring>
#include <iostream>
#include <vector>
#include "preferences.h"
using namespace std;
class students {
private:
	int form_no;
	string name;
	int rank_a;
	int rank_b;
	int rank_c;
	string degree;
	double percentage;
	int Allocated_preference;
	string Allocated_course_name;
	string Allocated_center_id;
	double Payment;
	int Reported_to_center;
	string Prn;

public:
	vector<preferences> filled_preferences;
	students();
	void display();
	void load();
	virtual ~students();
	int getAllocatedPreference() const;
	void setAllocatedPreference(int allocatedPreference);
	const string& getDegree() const;
	void setDegree(const string& degree);
	int getFormNo() const;
	void setFormNo(int formNo);
	const string& getName() const;
	void setName(const string& name);
	double getPercentage() const;
	void setPercentage(double percentage);
	int getRankA() const;
	void setRankA(int rankA);
	int getRankB() const;
	void setRankB(int rankB);
	int getRankC() const;
	void setRankC(int rankC);
	const string& getAllocatedCourseName() const;
	void setAllocatedCourseName(const string& AllocatedCourseName);
	const string& getAllocatedCenterId() const;
	void setAllocatedCenterId(const string& AllocatedCenterId);
	const string& getPrn() const;
	void setPrn(const string& Prn);
	double getPayment() const;
	void setPayment(double payment);
	int getReportedToCenter() const;
	void setReportedToCenter(int reportedToCenter);
	void display_eligible_courses();
};

#endif /* STUDENTS_H_ */
