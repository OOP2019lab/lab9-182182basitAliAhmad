#include "Address.h"

Address::Address(char* house_Number, char* Street_Name, char* City, char* Country)
{
	int s = strlen(house_Number) + 1;
	this->house_Number = new char[s];
	strcpy_s(this->house_Number, s, house_Number);

	s = strlen(Street_Name) + 1;
	this->street_Name = new char[s];
	strcpy_s(this->street_Name, s, Street_Name);

	s = strlen(City) + 1;
	this->city = new char[s];
	strcpy_s(this->city, s, City);

	s = strlen(Country) + 1;
	this->county = new char[s];
	strcpy_s(this->county, s, Country);
}

Address::Address(const Address& dummy)
{
	int s = strlen(dummy.house_Number) + 1;
	this->house_Number = new char[s];
	strcpy_s(this->house_Number, s, dummy.house_Number);

	s = strlen(dummy.street_Name) + 1;
	this->street_Name = new char[s];
	strcpy_s(this->street_Name, s, dummy.street_Name);

	s = strlen(dummy.city) + 1;
	this->city = new char[s];
	strcpy_s(this->city, s, dummy.city);

	s = strlen(dummy.county) + 1;
	this->county = new char[s];
	strcpy_s(this->county, s, dummy.county);
}

ostream& operator << (ostream& out, const Address& dummy)
{
	out << "House # " << dummy.house_Number << ", " << dummy.street_Name << ", " << dummy.city << ", " << dummy.county;

	return out;
}

const Address& Address::operator = (const Address& dummy)
{
	if (this != &dummy)
	{

		int s = strlen(dummy.house_Number) + 1;
		if (this->house_Number != nullptr)
			delete[]this->house_Number;
		this->house_Number = new char[s];
		strcpy_s(this->house_Number, s, dummy.house_Number);

		s = strlen(dummy.street_Name) + 1;
		if (this->street_Name != nullptr)
			delete[]this->street_Name;
		this->street_Name = new char[s];
		strcpy_s(this->street_Name, s, dummy.street_Name);

		s = strlen(dummy.city) + 1;
		if (this->city != nullptr)
			delete[]this->city;
		this->city = new char[s];
		strcpy_s(this->city, s, dummy.city);

		s = strlen(dummy.county) + 1;
		if (this->county != nullptr)
			delete[]this->county;
		this->county = new char[s];
		strcpy_s(this->county, s, dummy.county);
	}
	return *this;
}

Address::~Address()
{
	if (this->house_Number != nullptr)
		delete[]this->house_Number;

	if (this->street_Name != nullptr)
		delete[]this->street_Name;

	if (this->city != nullptr)
		delete[]this->city;

	if (this->county != nullptr)
		delete[]this->county;
}