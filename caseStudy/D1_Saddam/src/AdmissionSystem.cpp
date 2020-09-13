/*
 * AdmissionSystem.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author: Saddam Sayyed
 */

#include "AdmissionSystem.h"
#include <algorithm>
using namespace std;
AdmissionSystem * AdmissionSystem::ptr = NULL;

/*=======================display functions==================================*/

void AdmissionSystem::display_students_Info() {
	for (unsigned int i = 0; i < ptr->students_Info.size(); i++) {
		ptr->students_Info[i].display();
	}
}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::display_center_info() {
	for (unsigned int i = 0; i < ptr->center_info.size(); i++) {
		ptr->center_info[i].display();
	}

}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::display_course_info() {
	for (unsigned int i = 0; i < ptr->course_info.size(); i++) {
		ptr->course_info[i].display();
	}
}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::display_course_and_eligibility() {
	for (unsigned int i = 0; i < ptr->course_info.size(); i++) {
		cout << "\t\n-----------------------------------------\n";
		cout << "\tcourse id : " << ptr->course_info[i].getId() << "\n";
		cout << "\tname : " << ptr->course_info[i].getName() << "\n";
		cout << "\tFees : " << ptr->course_info[i].getFees() << "\n";
		cout << "\tccat_section : " << ptr->course_info[i].getCcatSection()
				<< "\n";
		cout << "\t\nEligibilities :\n";
		for (unsigned int j = 0; j < ptr->course_info[i].eligibility.size();
				j++)
			ptr->course_info[i].eligibility[j].display();
		cout << "\t\n-----------------------------------------\n";
	}
}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::display_capacities_info() {
	for (unsigned int i = 0; i < ptr->capacities_info.size(); i++) {
		capacities_info[i].display();
	}
}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::display_degrees() {
	for (unsigned int i = 0; i < degrees.size(); i++)
		cout << degrees[i] << "\n";
}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::display_eligibilities_info() {
	for (unsigned int i = 0; i < eligibilities_info.size(); i++)
		eligibilities_info[i].display();
}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::display_preferences_info() {
	for (unsigned int i = 0; i < ptr->preferences_info.size(); i++) {
		preferences_info[i].display();
	}
}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::display_centers_with_course(string courseName) {
	for (unsigned int i = 0; i < center_info.size(); i++)
		for (unsigned int j = 0; j < center_info[i].courses.size(); j++)
			if (courseName == center_info[i].courses[j].getName()) {
				cout << "CENTER ID : " << center_info[i].getId();
				cout << "\t\tCENTER NAME : " << center_info[i].getName();
				center_info[i].courses[j].display();
			}
}
/*==============================load functions=========================*/

void AdmissionSystem::load_students_file() {
	fstream fin;
	vector<string> row;
	fin.open("04_students_1st_install_paid.csv", ios::in);
	string word, line;
	AdmissionSystem *p1 = AdmissionSystem::get_instance();
	if (fin.is_open()) {
		while (getline(fin, line)) {
			row.clear();
			stringstream s(line);
			while (getline(s, word, ','))
				row.push_back(word);
			int i = 0;
			students temp;
			temp.setFormNo(stoi(row[i++]));
			temp.setName(row[i++]);
			temp.setRankA(stoi(row[i++]));
			temp.setRankB(stoi(row[i++]));
			temp.setRankC(stoi(row[i++]));
			temp.setDegree(row[i++]);
			temp.setPercentage(stod(row[i++]));
			temp.setAllocatedPreference(stoi(row[i++]));
			temp.setAllocatedCourseName(row[i++]);
			temp.setAllocatedCenterId(row[i++]);
			temp.setPayment(stoi(row[i++]));
			temp.setReportedToCenter(stoi(row[i++]));
			temp.setPrn(row[i]);
			p1->students_Info.push_back(temp);
		}
	} else {
		cout << "file could not open \n ";
		return;
	}

}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::load_preferences_file() {
	fstream fin;
	vector<string> row;
	fin.open("01_preferences.csv", ios::in);
	string temp, word, line;
	AdmissionSystem *p1 = AdmissionSystem::get_instance();
	if (fin.is_open()) {
		while (getline(fin, line)) {
			row.clear();
			stringstream s(line);
			while (getline(s, word, ','))
				row.push_back(word);
			int i = 0;
			preferences temp;
			temp.setFormNo(stoi(row[i++]));
			temp.setPreferenceNo(stoi(row[i++]));
			temp.setCourceName(row[i++]);
			temp.setCenterId(row[i++]);
			p1->preferences_info.push_back(temp);
			for (unsigned int i = 0; i < p1->students_Info.size(); i++) {
				if (p1->students_Info[i].getFormNo() == temp.getFormNo())
					p1->students_Info[i].filled_preferences.push_back(temp);
			}
		}
	} else {
		cout << "file could not open \n ";
		return;
	}

}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::load_eligibilities_file() {
	fstream fin;
	vector<string> row;
	fin.open("eligibilities.csv", ios::in);
	string word, line;
	AdmissionSystem *p1 = AdmissionSystem::get_instance();
	if (fin.is_open()) {
		while (getline(fin, line)) {
			row.clear();
			stringstream s(line);
			while (getline(s, word, ','))
				row.push_back(word);
			int i = 0;
			eligibilities temp;
			temp.setCourseName(row[i++]);
			temp.setDegree(row[i++]);
			temp.setMinPercentage(stod(row[i++]));
			p1->eligibilities_info.push_back(temp);
			for (unsigned int i = 0; i < p1->center_info.size(); i++) {
				if (p1->course_info[i].getName() == temp.getCourseName())
					p1->course_info[i].eligibility.push_back(temp);
			}

		}
	} else {
		cout << "file could not open \n ";
		return;
	}

}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::load_course_file() {
	fstream fin;
	vector<string> row;
	fin.open("courses.csv", ios::in);
	string temp, word, line;
	AdmissionSystem *p1 = AdmissionSystem::get_instance();
	if (fin.is_open()) {

		while (getline(fin, line)) {
			row.clear();
			stringstream s(line);
			while (getline(s, word, ','))
				row.push_back(word);
			int i = 0;
			course temp;
			temp.setId(row[i++]);
			temp.setName(row[i++]);
			temp.setFees(row[i++]);
			temp.setCcatSection(row[i++]);
			p1->course_info.push_back(temp);
			for (unsigned int i = 0; i < p1->center_info.size(); i++) {
				if (p1->center_info[i].capacity[i].getCapacity() != 0)
					p1->center_info[i].courses.push_back(temp);
			}
		}

	} else {
		cout << "file could not open \n ";
		return;
	}

}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::load_center_file() {
	fstream fin;
	vector<string> row;
	fin.open("centers.csv", ios::in);
	string temp, word, line;
	AdmissionSystem *p1 = AdmissionSystem::get_instance();
	if (fin.is_open()) {
		while (getline(fin, line)) {
			row.clear();
			stringstream s(line);
			while (getline(s, word, ','))
				row.push_back(word);
			int i = 0;
			center temp;
			temp.setId(row[i++]);
			temp.setName(row[i++]);
			temp.setAddress(row[i++]);
			temp.setCoordinator(row[i++]);
			temp.setPassword(row[i++]);
			p1->center_info.push_back(temp);
		}
	} else {
		cout << "file could not open \n ";
		return;
	}

}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::load_capacities_file() {
	fstream fin;
	vector<string> row;
	fin.open("03_capacities.csv", ios::in);
	string temp, word, line;
	AdmissionSystem *p1 = AdmissionSystem::get_instance();
	if (fin.is_open()) {
		while (getline(fin, line)) {
			row.clear();
			stringstream s(line);
			while (getline(s, word, ','))
				row.push_back(word);
			int i = 0;
			capacities temp;
			temp.setId(row[i++]);
			temp.setName(row[i++]);
			temp.setCapacity(stoi(row[i++]));
			temp.setFilledSeats(stoi(row[i++]));
			p1->capacities_info.push_back(temp);
			for (unsigned int i = 0; i < p1->center_info.size(); i++) {
				if (p1->center_info[i].getId() == temp.getId())
					p1->center_info[i].capacity.push_back(temp);
			}
		}
	} else {
		cout << "file could not open \n ";
		return;
	}
}

/*---------------------------------------------------------------------------*/

void AdmissionSystem::load_degrees() {
	fstream fin;
	vector<string> row;
	fin.open("degrees.txt", ios::in);
	string word;
	AdmissionSystem *p1 = AdmissionSystem::get_instance();
	if (fin.is_open()) {
		while (getline(fin, word))
			p1->degrees.push_back(word);
	} else {
		cout << "file could not open \n ";
		return;
	}
}

/*---------------------------------------------------------------------------*/
void AdmissionSystem::update_payment(students *p) {
	if (p->getPayment() == 0) {
		for (unsigned int i = 0; i < ptr->center_info.size(); i++) {
			if (p->getAllocatedCourseName() == ptr->course_info[i].getName()) {
				cout << " Fees to Pay : " << ptr->course_info[i].getFees()
						<< "1st Installment : 11800";
				int flag = 0;
				cout << "1. Pay 1st installment\n0. cancel payment\n";
				cin >> flag;
				if (flag) {
					p->setPayment(11800);
					cout << "\n Payment Sucessful \n";
					//updating in csv....
				} else
					cout << "Payment Cancelled\n";

			} else {
				cout << "You Have Not Been Allocated yet";
				break;
			}

		}
	} else {
		int flag = 0;
		for (unsigned int i = 0; i < course_info.size(); i++) {
			if (p->getAllocatedCourseName() == course_info[i].getName()) {
				cout << "Allocated Course :" << p->getAllocatedCourseName();
				cout << "Total fees : " << course_info[i].getFees();
				cout << "\nFirst installment paid : 11800\n";
				cout << "\n2nd Installment : "
						<< stod(course_info[i].getFees()) - 11800 << endl;
				cout << "\n1.Pay 2nd Installment\n0.Cancel\n";
				cin >> flag;
				if (flag) {
					p->setPayment(stod(course_info[i].getFees()) - 11800);
					cout << "Payment Successful\n";
				} else {
					cout << "Payment Cancelled\n";
					break;
				}
			}
		}

	}

}
void AdmissionSystem::student_log_in() {

	int username, flag = 0;
	preferences ptemp;
	unsigned int i;
	string passcode;
	cout << "\nPlease enter Username : ";
	cin >> username;
	cout << "\nPassword : ";
	cin >> passcode;
	for (i = 0; i < ptr->students_Info.size(); i++) {
		if (ptr->students_Info[i].getFormNo() == username
				&& ptr->students_Info[i].getName() == passcode) {
			flag = 1;
			students *p = &ptr->students_Info[i];
			cout << "Welcome " << ptr->students_Info[i].getName();
			int choice;

			do {
				cout
						<< "\n**********************(Student Menu)***************************\n";

				cout
						<< "\n Please enter choice\n1.List Courses As Per Eligibility\n"
								"2.List Centers\n3.Give preferences\n4.See Allocated Centers\n5.Update Payment Details\n0.exit";
				cout
						<< "\n***************************************************************\n";
				cin >> choice;
				if (choice == 0)
					return;
				switch (choice) {
				case 1: //list course(as per eligibility)
					p->display_eligible_courses();
					break;
				case 2:	//list centers;
					ptr->display_center_info();
					break;
				case 3:	//Give preferences(eligibles(for course) Allowed to give preference Then append preferences in Preferences.csv).
					p->display_eligible_courses();
					cout << "\nABOVE ARE THE COURSES YOU CAN APPLY FOR\n"
							"please Enter your preferences(MAXIMUM 10))";
					cout << "Form Number : " << p->getFormNo();
					ptemp.setFormNo(p->getFormNo());
					ptemp.accept();
					p->filled_preferences.push_back(ptemp);
					p->display();
					cout << "Preferences Updated\n";
					//updating in csv....
					break;
				case 4:
					cout << "Allocated Center : " << p->getAllocatedCenterId();
					cout << "\nAllocated course : "
							<< p->getAllocatedCourseName() << endl;
					break;
				case 5:	//Update payment details
					update_payment(p);
					break;
				}
			} while (choice);

		}
	}
	if (!flag)
		cout << "\nNo such Student Found\n";

}

int AdmissionSystem::menu(int choice) {
	cout
			<< "\n*************************************(MAIN MENU)**************************************************\n";
	cout << "\nChoose option\n";
	cout << "1.Admin\n2.Center Coordinator\n3.Student\n4.0.Exit\n";
	cin >> choice;
	cout
			<< "\n**************************************************************************************************\n";
	return choice;
}
void AdmissionSystem::register_student() {
	students temp;
	string s;
	int flag = 0;
	double d;
	cout << "\nEnter ";
	temp.setFormNo(202);
	cout << "\nEnter Name : ";
	cin >> s;
	temp.setName(s);
	cout
			<< "\nFollowing are the applicable degrees after 10th,12th/Diploma , enter your degree number : ";
	for (unsigned int i = 3; i < degrees.size(); i++) {
		cout << i - 2 << "." << degrees[i] << endl;
	}
	cin >> flag;
	temp.setDegree(degrees[flag + 2]);
	cout << "\nEnter Percentage : ";
	cin >> d;
	temp.setPercentage(d);
	temp.filled_preferences.clear();
	students_Info.push_back(temp);
	cout << "\nRegistered Successfully\n";
	temp.display();
}
int AdmissionSystem::student_menu() {
	int choice;
	do {
		cout
				<< "\n**********************(Student Menu)***************************\n";
		cout << "\nChoose option\n";
		cout << "1.register\n2.Log IN\n0.Exit";
		cin >> choice;
		cout
				<< "\n***************************************************************\n";

		switch (choice) {
		case 1: //register
			register_student();
			break;
		case 2: //log in
			student_log_in();
			break;

		}
	} while (choice);
	return choice;
}

void AdmissionSystem::update_student_ranks() {
	int n;
	do {
		cout << "Enter Form number / 0 to exit : ";
		cin >> n;
		for (unsigned int i = 0; i < students_Info.size(); i++) {
			if (n == students_Info[i].getFormNo()) {
				cout << "Set Rank A : ";
				cin >> n;
				students_Info[i].setRankA(n);
				cout << "Set Rank B : ";
				cin >> n;
				students_Info[i].setRankB(n);
				cout << "Set Rank C : ";
				cin >> n;
				students_Info[i].setRankC(n);
				cout << "Ranks Updated\n";
				break;
			}

		}
	} while (n);
}
bool compareStudentA(students &s1, students &s2) {
	return (s1.getRankA() < s2.getRankA());
}
bool compareStudentB(students &s1, students &s2) {
	return (s1.getRankB() < s2.getRankB());
}
bool compareStudentC(students &s1, students &s2) {
	return (s1.getRankC() < s2.getRankC());
}
int AdmissionSystem::find_capacity(string centerId, string courseName) {
	int available;
	for (unsigned int i = 0; i < center_info.size(); i++)
		for (unsigned int j = 0; j < center_info[i].capacity.size(); j++) {
			if (center_info[i].capacity[j].getId() == centerId
					&& center_info[i].capacity[j].getName() == courseName) {
				available = center_info[i].capacity[j].getCapacity()
						- center_info[i].capacity[j].getFilledSeats();
			}
		}
	return available;
}
string AdmissionSystem::getCcatSection(students &s) {
	string rank;
	if (s.getRankC() != -1)
		rank = s.getRankC();
	else if (s.getRankB() != -1)
		rank = s.getRankB();
	else if (s.getRankA() != -1)
		rank = s.getRankA();
	return rank;
}
void AdmissionSystem::increment_AllocatedSeat(string center,
		string courseName) {
	for (unsigned int i = 0; i < center_info.size(); i++) {
		for (unsigned int j = 0; j < center_info[i].capacity.size(); j++) {
			if (center == center_info[i].getId()
					&& courseName == center_info[i].capacity[j].getName())
				center_info[i].capacity[j].setFilledSeats(
						center_info[i].capacity[j].getFilledSeats() + 1);
		}
	}
}
void AdmissionSystem::allocate_seat(unsigned int i, unsigned int j) {
	students *s = &students_Info[i];
	if (students_Info[i].getAllocatedPreference() == 0) {
		s->setAllocatedCenterId(s->filled_preferences[j].getCenterId());
		s->setAllocatedCourseName(s->filled_preferences[j].getCourceName());
		s->setAllocatedPreference(s->filled_preferences[j].getPreferenceNo());
		increment_AllocatedSeat(s->filled_preferences[j].getCenterId(),
				s->filled_preferences[j].getCourceName());
		//s->display();
		allocated_studentsR1.push_back(students_Info[i]);
	}
}

void AdmissionSystem::round1_allocation() {
	unsigned int i, j;
	int available;
	for (i = 0; i < 10; i++) {
		sort(students_Info.begin(), students_Info.end(), compareStudentA);
		for (j = 0; j < students_Info.size(); j++) {
			students *s = &students_Info[j];
			if (s->filled_preferences.size() > i && s->getPayment() != -1
					&& s->getAllocatedPreference() == 0) {
				available = find_capacity(
						s->filled_preferences[i].getCenterId(),
						s->filled_preferences[i].getCourceName());
				if (available > 0
						&& s->filled_preferences[i].getCourceName() == "PG-DGI"
						&& s->getRankA() != -1)
					allocate_seat(j, i);
			}
		}
		sort(students_Info.begin(), students_Info.end(), compareStudentB);

		for (j = 0; j < students_Info.size(); j++) {
			students *s = &students_Info[j];
			if (s->filled_preferences.size() > i && s->getPayment() != -1
					&& s->getAllocatedPreference() == 0) {
				available = find_capacity(
						s->filled_preferences[i].getCenterId(),
						s->filled_preferences[i].getCourceName());
				if ((available > 0)
						&& (s->filled_preferences[i].getCourceName() != "PG-DGI")
						&& (s->filled_preferences[i].getCourceName()
								!= "PG-DESD") && (s->getRankB() != -1))
					allocate_seat(j, i);
			}
		}
		sort(students_Info.begin(), students_Info.end(), compareStudentC);
		for (j = 0; j < students_Info.size(); j++) {
			students *s = &students_Info[j];
			if (s->filled_preferences.size() > i && s->getPayment() != -1
					&& s->getAllocatedPreference() == 0) {

				available = find_capacity(
						s->filled_preferences[i].getCenterId(),
						s->filled_preferences[i].getCourceName());
				if ((available > 0)
						&& (s->filled_preferences[i].getCourceName()
								== "PG-DESD") && (s->getRankC() != -1))
					allocate_seat(j, i);
			}
		}

	}

	ptr->display_allocated_students();
}

void AdmissionSystem::clear_capacities() {
	for (unsigned int i = 0; i < center_info.size(); i++) {
		center *c = &center_info[i];
		for (unsigned int j = 0; j < c->capacity.size(); j++) {
			c->capacity[j].setFilledSeats(0);
		}

	}
}
void AdmissionSystem::round2_allocation() {
	for (unsigned int i = 0; i < students_Info.size(); i++) {
		if (students_Info[i].getAllocatedPreference() != 0
				&& students_Info[i].getPayment() == 0)
			students_Info[i].setPayment(-1);
		students_Info[i].setAllocatedCenterId("NA");
		students_Info[i].setAllocatedCourseName("NA");
		students_Info[i].setAllocatedPreference(0);
	}
	clear_capacities();
	round1_allocation();

}
bool compareFormNo(students &s1, students &s2) {
	return (s1.getFormNo() < s2.getFormNo());
}
void AdmissionSystem::write_students() {
	unsigned i;
	ofstream fout("udatedStudents.csv", ios::out | ios::trunc);
	sort(students_Info.begin(), students_Info.end(), compareFormNo);
	for (i = 0; i < students_Info.size(); i++) {
		students *d = &students_Info[i];
		fout << d->getFormNo() << ",";
		fout << d->getName() << ",";
		fout << d->getRankA() << ",";
		fout << d->getRankB() << ",";
		fout << d->getRankC() << ",";
		fout << d->getDegree() << ",";
		fout << d->getPercentage() << ",";
		fout << d->getAllocatedPreference() << ",";
		fout << d->getAllocatedCourseName() << ",";
		fout << d->getAllocatedCenterId() << ",";
		fout << d->getPayment() << ",";
		fout << d->getReportedToCenter() << ",";
		fout << d->getPrn() << "\n";
	}
}
void AdmissionSystem::write_preferences() {
	unsigned i, j;
	ofstream fout("udatedPreferences.csv", ios::out | ios::trunc);
	for (i = 0; i < students_Info.size(); i++)
		for (j = 0; j < preferences_info.size(); j++) {
			preferences *d = &students_Info[i].filled_preferences[j];
			fout << d->getFormNo() << ",";
			fout << d->getPreferenceNo() << ",";
			fout << d->getCourceName() << ",";
			fout << d->getCenterId() << "\n";
		}
}
void AdmissionSystem::write_capacities() {
	unsigned i, j;
	ofstream fout("udatedCapacities.csv", ios::out | ios::trunc);
	// check
	//sort(capacities_info.begin(),capacities_info.end(),compareFormNo);
	for (i = 0; i < center_info.size(); i++)
		for (j = 0; j < center_info[i].capacity.size(); j++) {
			capacities *d = &center_info[i].capacity[i];
			fout << d->getId() << ",";
			fout << d->getName() << ",";
			fout << d->getCapacity() << ",";
			fout << d->getFilledSeats() << "\n";
		}
}
void AdmissionSystem::display_allocated_students() {
	int count = 0;
	for (unsigned int i = 0; i < students_Info.size(); i++) {
		if (students_Info[i].getAllocatedCenterId() != "NA") {
			students_Info[i].display();
			count++;
		}
	}
	if (count == 0)
		cout << "Allocation Pending....";
	else
		cout << "No Of Students Allocated : " << count;

}

void AdmissionSystem::deallocate_seat(string center, string courseName,
		int formNo) {
	for (unsigned int i = 0; i < center_info.size(); i++)
		for (unsigned int j = 0; j < center_info[i].capacity.size(); j++)
			if (center == center_info[i].getId()
					&& courseName == center_info[i].capacity[j].getName())
				center_info[i].capacity[j].setFilledSeats(
						center_info[i].capacity[j].getFilledSeats() - 1);

}

void AdmissionSystem::display_paid_students() {
	int flag = 0;
	for (unsigned int i = 0; i < students_Info.size(); i++)
		if (students_Info[i].getPayment() > 1) {
			students_Info[i].display();
			flag++;
		}
	if (flag != 0)
		cout << "Total " << flag << " Students have paid fees..";
	else
		cout << "\nNo Students have paid fees yet";

}
void AdmissionSystem::display_reported_students() {
	int flag = 0;
	for (unsigned int i = 0; i < students_Info.size(); i++)
		if (students_Info[i].getReportedToCenter() == 1) {
			students_Info[i].display();
			flag = 1;
		}
	if (!flag)
		cout << "\nNo Students have Reported to Centers yet";
}
void AdmissionSystem::generate_prn() {
	int flag = 0;
	for (unsigned int i = 0; i < students_Info.size(); i++)
		if (students_Info[i].getReportedToCenter() == 1) {
			students *s = &students_Info[i];
			string prn = "";
			cout << "the reported students are :";
			cout << "Name : " << s->getName() << "\n";
			cout << "FormNo : " << s->getFormNo() << "\n";
			cout << "Allocated Center: " << s->getAllocatedCenterId() << "\n";
			cout << "Allocated Course : " << s->getAllocatedCourseName()
					<< "\n";
			prn.append(s->getAllocatedCenterId());
			prn.append("_");
			prn.append(s->getAllocatedCourseName());
			prn.append("_");
			prn.append(to_string(s->getFormNo()));
			s->setPrn(prn);
			cout << s->getPrn();
			flag = 1;
		}
	if (!flag)
		cout << "\nNo Students have Reported to Centers yet";
}

int AdmissionSystem::admin_menu() {
	int choice;
	do {
		cout
				<< "\n**********************(Admin Menu)***************************\n";

		cout << "\nChoose option\n";
		cout
				<< "0.Exit\n1. List courses & eligibilities\n2. List centers & capacities\n"
						"3. List students\n4. Update student ranks\n5. Allocate centers (Round 1)\n6. Allocate centers (Round 2)\n"
						"7. List allocated students\n8. List paid students\n9. List reported (at center) students\n"
						"10. Generate PRN\n11. List admitted students (with PRN) for given center";
		cin >> choice;
		cout
				<< "\n*************************************************************\n";

		switch (choice) {
		case 0: //Sign in (username & password: admin)
			break;
		case 1: //List courses & eligibilities
			ptr->display_course_and_eligibility();
			break;
		case 2: //List centers & capacities
			ptr->display_center_info();
			break;
		case 3: //List students
			ptr->display_students_Info();
			break;
		case 4: //Update student ranks
			ptr->update_student_ranks();

			break;
		case 5: //Allocate centers (Round 1students_Info[i])
			round1_allocation();
			break;
		case 6: //Allocate centers (Round 2)
			round2_allocation();
			break;
		case 7: //List allocated students
			display_allocated_students();
			break;
		case 8: //List paid students
			display_paid_students();
			break;
		case 9: //List reported (at center) students
			display_reported_students();
			break;
		case 10: // Generate PRN
			generate_prn();
			break;
		case 11: //list Admitted students
			display_all_admitted_students();
			break;
		}
	} while (choice);
	return choice;
}
int AdmissionSystem::display_allocated_to_center(string id) {
	int flag = 0;
	for (unsigned int i = 0; i < students_Info.size(); i++)
		if (students_Info[i].getAllocatedCenterId() == id) {
			students_Info[i].display();
			flag = 1;
		}
	if (!flag)
		cout << "\nNo Students have been Allocated to Center yet";
	return flag;
}
void AdmissionSystem::update_reported_status(string id) {
	int formNo = -1;
	if (!ptr->display_allocated_to_center(id))
		return;

	while (formNo) {
		cout
				<< "Enter Form No of student Reported from above\n or press 0 to go back\n";
		cin >> formNo;

		for (unsigned int i = 0; i < students_Info.size(); i++) {
			if (students_Info[i].getAllocatedCenterId() == id) {
				if (formNo == 0)
					break;
				cout << students_Info[i].getFormNo() << "\n";
				if (students_Info[i].getFormNo() == formNo
						&& students_Info[i].getPayment() > 11800) {
					cout << "Matched\n";
					students_Info[i].setReportedToCenter(1);
					students_Info[i].display();
				}

			}
		}
	}
}
void AdmissionSystem::display_admitted_students(string id) {
	int flag = 0;
	for (unsigned int i = 0; i < students_Info.size(); i++)
		if (students_Info[i].getAllocatedCenterId() == id) {
			if (students_Info[i].getPayment() == 80000
					&& students_Info[i].getAllocatedCourseName() == "PG-DGI") {
				students_Info[i].display();
				flag = 1;
			} else if (students_Info[i].getPayment() == 115000
					&& students_Info[i].getAllocatedCourseName() == "PG-DBDA") {
				students_Info[i].display();
				flag = 1;
			} else if (students_Info[i].getPayment() == 94000) {
				students_Info[i].display();
				flag = 1;
			}
		}
	if (!flag)
		cout << "\nNo Students have been Admitted to Center yet";
}

void AdmissionSystem::display_all_admitted_students() {
	int flag = 0, count = 0;
	for (unsigned int i = 0; i < students_Info.size(); i++) {
		if (students_Info[i].getPayment() == 80000
				&& students_Info[i].getAllocatedCourseName() == "PG-DGI") {
			students_Info[i].display();
			count++;
			flag = 1;
		} else if (students_Info[i].getPayment() == 115000
				&& students_Info[i].getAllocatedCourseName() == "PG-DBDA") {
			students_Info[i].display();
			count++;
			flag = 1;
		} else if (students_Info[i].getPayment() == 94000) {
			students_Info[i].display();
			count++;
			flag = 1;
		}
	}
	if (!flag)
		cout << "\nNo Students have been Admitted to Center yet";
	else
		cout << "Total students Admitted : " << count << endl;
}

void AdmissionSystem::coordinator_menu() {
	int choice = 0;
	string username, password;
	cout << "Username : ";
	cin >> username;
	cout << "password : ";
	cin >> password;
	center *c;
	for (unsigned int i = 0; i < center_info.size(); i++)
		if (password == center_info[i].getId()) {
			cout << "Welcome " << center_info[i].getCoordinator();
			c = &center_info[i];
			choice = 1;
			break;
		}
	if (!choice) {
		cout << "\nWrong Credentials\n";
		return;
	}

	while (choice) {
		cout
				<< "\n*******************(Coordinator-Menu)******************************\n";
		cout << "\nChoose option\n";
		cout
				<< "1.List courses \n2.List students (allocated to that center)\n3.Update reported status"
						"\n4.List admitted students (with PRN)\n0.Exit";
		cout
				<< "\n*******************************************************************\n";
		cin >> choice;
		switch (choice) {
		case 1: //List courses (of that center)
			c->display();
			break;
		case 2: //List students (allocated to that center)
			display_allocated_to_center(c->getId());
			break;
		case 3: //Update reported status
			update_reported_status(c->getId());
			break;
		case 4: //List admitted students (with PRN)
			display_admitted_students(c->getId());
			break;
		}
	}
}
void AdmissionSystem::load_files() {
	ptr->load_center_file();
	ptr->load_capacities_file();
	ptr->load_students_file();
	ptr->load_preferences_file();
	ptr->load_course_file();
	ptr->load_eligibilities_file();
	ptr->load_degrees();
}
void AdmissionSystem::write_files() {
	ptr->write_students();
	ptr->write_capacities();
	ptr->write_preferences();
}

