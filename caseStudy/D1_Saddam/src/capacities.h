/*
 * capacities.h
 *
 *  Created on: 16-Apr-2020
 *      Author: Saddam Sayyed
 */

#ifndef CAPACITIES_H_
#define CAPACITIES_H_
#include <cstring>
#include <iostream>
using namespace std;
class capacities {
private:
	string id;
	string name;
	int capacity;
	int filled_seats;
public:
	capacities();
	virtual ~capacities();
	void load();
	void display();
	int getCapacity() const;
	void setCapacity(int capacity);
	int getFilledSeats() const;
	void setFilledSeats(int filledSeats);
	const string& getId() const;
	void setId(const string& id);
	const string& getName() const;
	void setName(const string& name);
};

#endif /* CAPACITIES_H_ */
