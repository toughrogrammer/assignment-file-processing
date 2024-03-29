#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "Packable.h"
#include "fixfld.h"
#include "length.h"
#include "delim.h"

#include <vector>
#include <string>

using namespace std;


class Student : public Packable
{
public:
	Student(int id, 
		string name, 
		string address, 
		string firstEnrollmentDate,
		int completedCreditHours);
	~Student();

	// getter
	int GetID() {
		return _id;
	}

	string GetName() {
		return _name;
	}
	void SetName(string name) {
		_name = name;
	}

	string GetAddress() {
		return _address;
	}
	void SetAddress(string address) {
		_address = address;
	}

	string GetFirstEnrollmentDate() {
		return _dateOfFirstEnrollment;
	}

	int GetCompletedCreditHours() {
		return _completedCreditHours;
	}
	void IncreaseCreditHours(int i) {
		_completedCreditHours += i;
	}

	Student& operator=(const Student&);
	static void ReadFromFile(string path, vector<Student>& ret);
	static Student CreateFromData(string str);
	static Student CreateFromInput();
	string Export();

	static int InitBuffer (DelimFieldBuffer &);
	static int InitBuffer (LengthFieldBuffer &);
	static int InitBuffer (FixedFieldBuffer &);
	virtual bool Pack(IOBuffer& buffer);
	virtual bool Unpack(IOBuffer& buffer);


private:
	int _id;
	string _name;
	string _address;
	string _dateOfFirstEnrollment;
	int _completedCreditHours;
};

#endif