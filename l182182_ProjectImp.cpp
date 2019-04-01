#include "Project.h"

Project::Project(char* name, int budget, int duration)
{
	int s = strlen(name) + 1;
	this->name = new char[s];
	strcpy_s(this->name, s, name);

	this->budget = budget;
	this->duration = duration;
}

Project::Project(const Project& dummy)
{
	int s = strlen(dummy.name) + 1;
	this->name = new char[s];
	strcpy_s(this->name, s, dummy.name);

	this->budget = dummy.budget;
	this->duration = dummy.duration;
}

const Project& Project::operator = (const Project& dummy)
{
	if (this != &dummy)
	{
		int s = strlen(dummy.name) + 1;
		if (this->name != nullptr)
			delete[]this->name;
		this->name = new char[s];
		strcpy_s(this->name, s, dummy.name);

		this->budget = dummy.budget;
		this->duration = dummy.duration;
	}

	return *this;
}

ostream& operator << (ostream& out, const Project& dummy)
{
	out << dummy.name << ", Budget = " << dummy.budget << ", Duration = " << dummy.duration;
	return out;
}

void Project::setBudget(const int bud)
{
	this->budget = bud;
}

Project::~Project()
{
	if (this->name != nullptr)
		delete[]this->name;
}
