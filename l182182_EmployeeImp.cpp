#include "Employee.h"

Employee::Employee(char *name, const Address& address)
{
	int s = strlen(name) + 1;
	this->emp_name = new char[s];
	strcpy_s(this->emp_name, s, name);

	this->address = &address;
	for (int i = 0; i < 2; i++)
		this->projects[i] = nullptr;
}

Employee::Employee(const Employee& dummy)
{
	this->address = dummy.address;
	
	int s = strlen(dummy.emp_name) + 1;
	this->emp_name = new char[s];
	strcpy_s(this->emp_name, s, dummy.emp_name);
	for (int i = 0; i < 3; i++)
		this->projects[i] = dummy.projects[i];
}

ostream& operator << (ostream& out, const Employee& dummy)
{
	out << "Employee Name: " << dummy.emp_name << endl;
	out << "Address: " << *dummy.address << ". His projects are follow: ";

	for (int i = 0; i < 2; i++)
	{
		if (dummy.projects[i] != nullptr)
			out << endl << *dummy.projects[i];
	}

	return out;
}

const Employee& Employee::operator = (const Employee& dummy)
{
	if (this != &dummy)
	{
	this->address = dummy.address;

	int s = strlen(dummy.emp_name) + 1;
	if (this->emp_name != nullptr)
		delete[]emp_name;
	this->emp_name = new char[s];
	strcpy_s(this->emp_name, s, dummy.emp_name);
	for (int i = 0; i < 3; i++)
		this->projects[i] = dummy.projects[i];
	}
	return *this;
}

void Employee::addProject(Project const* ptr)
{
	for (int i = 0; i < 2; i++)
	{
		if (this->projects[i] == nullptr)
		{
			this->projects[i] = ptr;
			break;
		}
	}
}

void Employee::removeProject(Project const* ptr)
{
	for (int i = 0; i < 2; i++)
	{
		if (projects[i] == ptr)
			projects[i] = nullptr;
	}
}

Employee::~Employee()
{
	delete this->address;
	if (this->emp_name != nullptr)
		delete[]this->emp_name;
}