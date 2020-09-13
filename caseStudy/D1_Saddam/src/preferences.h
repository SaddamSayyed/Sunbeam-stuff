/*
 * preferences.h
 *
 *  Created on: 16-Apr-2020
 *      Author: Saddam Sayyed
 */

#ifndef PREFERENCES_H_
#define PREFERENCES_H_
#include <cstring>
#include <iostream>
using namespace std;
class preferences {
private:
	int form_no;
	int preference_no;
	string cource_name;
	string center_id;
public:
	preferences();
	void display();
	void accept();
	void load();
	virtual ~preferences();
	const string& getCenterId() const;
	void setCenterId(const string& centerId);
	const string& getCourceName() const;
	void setCourceName(const string& courceName);
	int getFormNo() const;
	void setFormNo(int formNo);
	int getPreferenceNo() const;
	void setPreferenceNo(int preferenceNo);
};

#endif /* PREFERENCES_H_ */
