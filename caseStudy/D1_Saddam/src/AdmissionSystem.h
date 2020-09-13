/*
 * AdmissionSystem.h
 *
 *  Created on: 16-Apr-2020
 *      Author: Saddam Sayyed
 */

#ifndef ADMISSIONSYSTEM_H_
#define ADMISSIONSYSTEM_H_
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include "students.h"
#include "center.h"
#include "capacities.h"
#include "eligibilities.h"
#include "preferences.h"


class AdmissionSystem
{
private:
	AdmissionSystem() { }
	static AdmissionSystem *ptr;
public:
	static AdmissionSystem* get_instance()
	{
		if(ptr == NULL)
			ptr = new AdmissionSystem;
		return ptr;
	}
	static void shutdown()
	{
		delete ptr;
	}
	vector<students> students_Info;
	vector<center> center_info;
	vector<course> course_info;
	vector<capacities> capacities_info;
	vector<eligibilities> eligibilities_info;
	vector<preferences> preferences_info;
	vector<string> degrees;
	vector<students> allocated_studentsR1;
	vector<students> allocated_studentsR2;
	void display_students_Info();
	void display_center_info();
	void display_course_info();
	void display_capacities_info();
	void display_degrees();
	void display_preferences_info();
	void display_eligibilities_info();
	void display_centers_with_course(string courseName);
	void display_paid_students();
	void display_reported_students();
	void display_admitted_students(string id);
	int display_allocated_to_center(string id);
	void display_course_and_eligibility();
	void update_student_ranks();
	void round1_allocation();
	void round2_allocation();
	int find_capacity(string centerId,string courseName);
	string getCcatSection(students &);
	void increment_AllocatedSeat(string center,string courseName);
	void allocate_seat(unsigned int i,unsigned int j);
	void deallocate_seat(string center,string courseName,int formNo);
	void display_allocated_students();
	void display_all_admitted_students();
	void update_reported_status(string);
	void generate_prn();
	void load_files();
	void write_files();
	void clear_capacities();
	void write_students();
	void write_preferences();
	void write_capacities();
	void load_degrees();
	void load_students_file();
	void load_preferences_file();
	void load_eligibilities_file();
	void load_course_file();
	void load_center_file();
	void load_capacities_file();
	int menu(int);
	void student_log_in();
	void register_student();
	int admin_menu();
	void coordinator_menu();
	int student_menu();
	void update_payment(students *p);
};



#endif /* ADMISSIONSYSTEM_H_ */
