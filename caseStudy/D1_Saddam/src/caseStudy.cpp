//============================================================================
// Name        : caseStudy.cpp
// Author      : Saddam Sayyed
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <cstring>
#include "AdmissionSystem.h"
#include "capacities.h"
#include "preferences.h"

using namespace std;
int main() {

	AdmissionSystem *p = NULL;
	p = AdmissionSystem::get_instance();
	p->load_files();
	int choice;
	string username, password;
	while ((choice = p->menu(choice)) != 0) {
		switch (choice) {
		case 0: //exit
			break;
		case 1: //Admin
			cout << "Username : ";
			cin >> username;
			cout << "password : ";
			cin >> password;
			if (password == "admin" && username == "admin")
				p->admin_menu();
			else
				cout << "\nWrong Credentials\n";
			break;
		case 2:	//center coordinator

			p->coordinator_menu();
			break;
		case 3:	//Student
			p->student_menu();
			break;
		}
	}
	p->write_files();
	AdmissionSystem::shutdown();
	return 0;
}
