#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"COVID.h"
#include<fstream>
#include<string>
#include<ctime>
#include<conio.h>
#include<chrono>
#include<thread>
#include<iomanip>
using namespace std;
//return total number of citizens
int Filling::getCitizenCount()
{
	ifstream in;
	in.open("numberOfCitizens.txt");
	int count;
	in >> count;
	in.close();
	return count;
}
//updates total number of citizens
void Filling::setCitizenCount(int count)
{
	ofstream out;
	out.open("numberOfCitizens.txt");
	out << count;
	out.close();
}
//return total number of Registered citizens
int Filling::getRegisteredCitizenCount()
{
	ifstream in;
	in.open("numberOfRegisteredCitizens.txt");
	int count;
	in >> count;
	in.close();
	return count;
}
//return total number of citizens who took the booster dose
int Filling::getBoosterCitizenCount()
{
	ifstream in;
	in.open("numberOfBoosterCitizens.txt");
	int count;
	in >> count;
	in.close();
	return count;
}
//updates total number of citizens who took the booster dose
void Filling::setBoosterCitizenCount()
{
	ifstream in;
	in.open("numberOfBoosterCitizens.txt");
	int count;
	in >> count;
	in.close();
	ofstream out;
	out.open("numberOfBoosterCitizens.txt");
	out << ++count;
	out.close();
}
//returns number of cities where vaccination centers are available
int Filling::totalVaccinationCities()
{
	ifstream in;
	in.open("totalVaccineHoldingCities.txt");
	int count;
	in >> count;
	in.close();
	return count;
}
//updates total number of Registered citizens
void Filling::setRegisteredCitizenCount()
{
	int count;
	count = getRegisteredCitizenCount();
	ofstream out;
	out.open("numberOfRegisteredCitizens.txt");
	out << ++count;
	out.close();
}
//inputs citizen data from file to Variables (& calls Citizen::getDataToObject)
void Citizen::getCitizenData(int i)
{
	UsefulFunctions u;
	ifstream in;
	int ID, age;
	string citizenData[10];
	int dob[3];
	in.open("citizenData.txt");
	u.reachLine(in, 1 + (i * 15));
	in >> ID;
	in >> age;
	for (int i = 0;i < 10;i++)
	{
		in >> citizenData[i];
	}
	in >> dob[0];
	in >> dob[1];
	in >> dob[2];
	in.close();
	getDataToObject(ID, age, citizenData, dob);
}
void Citizen::setToTemporaryFile()
{
	ofstream out;
	out.open("temporary.txt", ios::app);
	out << ID << endl;
	out << age << endl;
	out << firstName << endl;
	out << lastName << endl;
	out << email << endl;
	out << password << endl;
	out << cnic << endl;
	out << contactNumber << endl;
	out << bloodType << endl;
	out << city << endl;
	out << state << endl;
	out << address << endl;
	out << dob.day << endl;
	out << dob.month << endl;
	out << dob.year << endl;
	out.close();
}
//sets data to object from variables (came from Citizen::getCitizenData)
void Citizen::getDataToObject(int ID, int age, string citizenData[10], int dob[3])
{
	this->ID = ID;
	this->age = age;
	firstName = citizenData[0];
	lastName = citizenData[1];
	email = citizenData[2];
	password = citizenData[3];
	cnic = citizenData[4];
	contactNumber = citizenData[5];
	bloodType = citizenData[6];
	city = citizenData[7];
	state = citizenData[8];
	address = citizenData[9];
	this->dob.day = dob[0];
	this->dob.month = dob[1];
	this->dob.year = dob[2];
}
//sets Citizen data from variables to file
void Filling::setCitizenData(string data[10], int ID, int ageDob[4], bool b)
{
	ofstream out;
	if (b == false)
	{
		out.open("citizenData.txt", ios::app);
	}
	else if (b == true)
	{
		out.open("temporary.txt", ios::app);
	}
	out << ID << endl;
	out << ageDob[3] << endl;
	for (int i = 0;i < 10;i++)
	{
		out << data[i] << endl;
	}
	out << ageDob[0] << endl;
	out << ageDob[1] << endl;
	out << ageDob[2] << endl;
	out.close();
}
//sets registration data of a newly registered citizen
void Filling::setRegisteredCitizenData(int i)
{
	UsefulFunctions u;
	ifstream in;
	in.open("citizenData.txt");
	u.reachLine(in, 1 + (i * 15));
	int ID;
	in >> ID;
	in.close();
	ofstream out;
	out.open("RegisteredCitizen.txt", ios::app);
	out << ID << endl;
	out << 0 << endl;
	out << "Nil" << endl;
	out << 0 << endl;
	out << "Nil" << endl;
	int date[3];
	u.currentDate(date);
	out << date[2] << endl;
	out << date[1] << endl;
	out << date[0] << endl;
	out.close();
}
//asks user to add information in the object (& calls Filling::setCitizenData)
void Citizen::signUp(int ID, bool a)
{
	UsefulFunctions integer;
	Filling file;
	string data[10];
	string checkMail;
	int ageDob[4] = { 0 };
	this->ID = ID;
	cout << "\t:First Name   : ";
	static bool b = false;
	if (b == true)
		cin.ignore();
	if (b == false)
		b = true;
	getline(cin, data[0]);
	this->firstName = data[0];
	cout << "\t:Last Name    : ";
	getline(cin, data[1]);
	this->lastName = data[1];
	while (1)
	{
		cout << "\t:Email        : ";
		getline(cin, data[2]);
		for (int i = 0;i < file.getCitizenCount();i++)
		{
			ifstream in;
			in.open("citizenData.txt");
			integer.reachLine(in, 5 + (i * 15));
			in >> checkMail;
			if (checkMail == data[2])
			{
				cout << "\tEmail Already Taken!" << endl;
				break;
			}
		}
		if (checkMail != data[2])
		{
			break;
		}
	}
	this->email = data[2];
	cout << "\t:Password     : ";
	getline(cin, data[3]);
	this->password = data[3];
	cout << "\t:CNIC         : ";
	getline(cin, data[4]);
	this->cnic = data[4];
	cout << "\t:Contact No.  : ";
	getline(cin, data[5]);
	this->contactNumber = data[5];
	cout << "\t:Blood Group  : ";
	getline(cin, data[6]);
	this->bloodType = data[6];
	cout << "\t:City         : ";
	getline(cin, data[7]);
	this->city = data[7];
	cout << "\t:State        : ";
	getline(cin, data[8]);
	this->state = data[8];
	cout << "\t:Address      : ";
	getline(cin, data[9]);
	this->address = data[9];
	cout << "\t:DOB :: Day   : ";
	ageDob[0] = integer.integerInput();
	this->dob.day = ageDob[0];
	cout << "\t:DOB :: Month : ";
	ageDob[1] = integer.integerInput();
	this->dob.month = ageDob[1];
	cout << "\t:DOB :: Year  : ";
	ageDob[2] = integer.integerInput();
	this->dob.year = ageDob[2];
	ageDob[3] = integer.calculateAge(ageDob);
	file.setCitizenData(data, ID, ageDob, a);
}
//Parametrized Constructor of UsefulFunctions
UsefulFunctions::UsefulFunctions(int n)
{
	int ID;
	ifstream in;
	in.open("randID.txt");
	in >> ID;
	in.close();
	this->ID = ID;
}
//Default Constructor of UsefulFunctions
UsefulFunctions::UsefulFunctions()
{
	//nothing to be initialized
}
//Initiallization of Static variable ID if not been assigned from file
int UsefulFunctions::ID = 11111;
//return random (+1) ID
int UsefulFunctions::RandomID()
{
	ofstream out;
	out.open("randID.txt");
	out << ID + 1;
	out.close();
	return ID++;
}
//reaches at the start of the required Line of a file (input/output Stream)
void UsefulFunctions::reachLine(ifstream& in, int n)
{
	for (int i = 0; i < n - 1; ++i) {
		in.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
//Checks the login validity of a citizen
int Filling::loginValidation(int n, string email, string password)
{
	UsefulFunctions u;
	ifstream in;
	string mail;
	string pass;
	for (int i = 0;i < n;i++)
	{
		in.open("citizenData.txt");
		u.reachLine(in, 5 + (i * 15));
		in >> mail;
		in.close();
		in.open("citizenData.txt");
		u.reachLine(in, 6 + (i * 15));
		in >> pass;
		in.close();
		if (mail == email && pass == password)
		{
			return i + 1;
		}
	}
	return 0;
}
//inputs integer to eliminate crashing & errors
int UsefulFunctions::integerInput()
{
	int i;
	string str;
	cin >> i;
	while (cin.fail())
	{
		cin.clear();
		getline(cin,str);
		cout << "\tError::001 expected an integer: ";
		cin >> i;
	}
	return i;
}
//finds the current date according to the system
void UsefulFunctions::currentDate(int date[3])
{
	time_t t = time(0);
	tm* l = localtime(&t);
	date[0] = 1900 + l->tm_year;
	date[1] = 1 + l->tm_mon;
	date[2] = l->tm_mday;
}
//calculates and returns age from Date of Birth
int UsefulFunctions::calculateAge(int ageDob[4])
{
	int date[3];
	currentDate(date);
	int age = 0;
	for (int i = ageDob[2];i < date[0];i++)
	{
		age++;
	}
	if (date[1] < ageDob[1])
	{
		age--;
	}
	else if (date[1] == ageDob[1])
	{
		if (date[2] < ageDob[0])
		{
			age--;
		}
	}
	return age;
}
//Checks if the Citizen is Registered ((i) is the position of the citizen in the file)
bool RegisteredCitizens::checkRegisteredBool(int i) {
	UsefulFunctions u;
	int ID;
	ifstream in;
	in.open("citizenData.txt");
	u.reachLine(in, 1 + (i * 15));
	in >> ID;
	in.close();
	int t;
	ifstream in1;
	in1.open("numberOfRegisteredCitizens.txt");
	in1 >> t;
	in1.close();
	int regID;
	ifstream in2;
	in2.open("RegisteredCitizen.txt");
	for (int x = 0;x < t;x++)
	{
		ifstream in2;
		in2.open("RegisteredCitizen.txt");
		u.reachLine(in2, 1 + (8 * x));
		in2 >> regID;
		in2.close();
		if (regID == ID)
		{
			return true;
		}
	}
	return false;
}
//returns saved age of the citizen ((i) is the position of the citizen in the file)
int Filling::getAge(int i)
{
	UsefulFunctions u;
	ifstream in;
	in.open("citizenData.txt");
	u.reachLine(in, 2 + (i * 15));
	int age;
	in >> age;
	return age;
}
//Outputs the Vacination history of the Citizen ((i) is the position of the citizen in the file)
void Filling::history(int i)
{
	UsefulFunctions u;
	int ID;
	ifstream in;
	in.open("citizenData.txt");
	u.reachLine(in, 1 + (i * 15));
	in >> ID;
	in.close();
	int t;
	ifstream in1;
	in1.open("numberOfRegisteredCitizens.txt");
	in1 >> t;
	in1.close();
	int regID;
	for (int x = 0;x < t;x++)
	{
		ifstream in2;
		in2.open("RegisteredCitizen.txt");
		u.reachLine(in2, 1 + (8 * x));
		in2 >> regID;
		if (regID == ID)
		{
			int doseNo;
			string vaccineName;
			in2 >> doseNo;
			in2 >> vaccineName;
			if (doseNo == 1)
			{
				cout << "\tDose No. 1: " << vaccineName << endl;
			}
			else
			{
				cout << "\tDose No. 1: Not Yet Taken" << endl;
			}
			in2 >> doseNo;
			in2 >> vaccineName;
			if (doseNo == 2)
			{
				cout << "\tDose No. 2: " << vaccineName << endl;
			}
			else
			{
				cout << "\tDose No. 2: Not Yet Taken" << endl;
			}
			int date[3] = { 0 };
			in2 >> date[0];
			in2 >> date[1];
			in2 >> date[2];
			cout << "\tNext Dose is Sheduled on " << date[2] << "/" << date[1] << "/" << date[0] << endl;
			break;
		}
		in2.close();
	}
}
//Checks the login validity of Super Admin
bool Filling::SuperAdminValidation()
{
	UsefulFunctions u;
	ifstream in;
	in.open("SuperAdminLogin.txt");
	string superAdmin;
	string superPassword;
	string IDcheck;
	string PASScheck;
	in >> superAdmin;
	in >> superPassword;
	cout << "\tSuper Admin Login" << endl;
	cout << "\t-------------------------" << endl;
	cout << "\t: USERNAME: ";
	cin >> IDcheck;
	cout << "\t: PASSWORD: ";
	cin >> PASScheck;
	if (IDcheck == superAdmin && PASScheck == superPassword)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//gives list of all the signed up citizens
int Filling::listProfiles()
{
	UsefulFunctions u;
	int ctCount;
	ctCount = getCitizenCount();
	int ID = 0;
	string firstName;
	string lastName;
	string cnic;
	cout << "\tProfiles List" << endl;
	cout << "\t-------------------------" << endl;
	cout << "\t ID / Name / Cnic" << endl;
	for (int i = 0;i < ctCount;i++)
	{
		ifstream in;
		in.open("citizenData.txt");
		u.reachLine(in, 1 + (i * 15));
		in >> ID;
		in.close();
		ifstream in1;
		in1.open("citizenData.txt");
		u.reachLine(in1, 3 + (i * 15));
		in1 >> firstName;
		in1 >> lastName;
		in1.close();
		ifstream in2;
		in2.open("citizenData.txt");
		u.reachLine(in2, 7 + (i * 15));
		in2 >> cnic;
		in2.close();
		cout << "\t" << ID << "   " << firstName << " " << lastName << "   " << cnic << endl;
	}
	return ctCount;
}
//deletes the profile of a citizen
void Filling::DeleteProfile()
{
	UsefulFunctions u;
	int ID = 0;
	int n = 0;
	char s;
	int ctCount;
	while (1)
	{
		while (1)
		{
			system("cls");
			cout << "\tDelete a Profile" << endl;
			ctCount = listProfiles();
			cout << "\t-------------------------" << endl;
			cout << "\tID: ";
			int IDtoDelete;
			IDtoDelete = u.integerInput();
			ifstream in3;
			in3.open("citizenData.txt");
			for (int i = 0;i < ctCount;i++)
			{
				u.reachLine(in3, 1 + (i * 15));
				in3 >> ID;
				in3.close();
				if (ID == IDtoDelete)
				{
					n = i;
					break;
				}
			}
			if (ID == IDtoDelete)
			{
				break;
			}
			system("cls");
			cout << "\tError::002 No such ID Available!" << endl;
		}
		Citizen citizen;
		ofstream out;
		out.open("temporary.txt");
		out.close();
		for (int i = 0;i < ctCount;i++)
		{
			if (i != n)
			{
				citizen.getCitizenData(i);
				citizen.setToTemporaryFile();
			}
		}
		remove("citizenData.txt");
		if (rename("temporary.txt", "citizenData.txt"));
		while (1)
		{
			system("cls");
			Filling file;
			file.setCitizenCount(--ctCount);
			cout << "\t     (Profile Removed)" << endl;
			cout << "\t--------------------------" << endl;
			cout << "\t   Remove Another Profile " << endl;
			cout << "\t--------------------------" << endl;
			cout << "\t--------------------------" << endl;
			cout << "\t:          EXIT          : " << endl;
			cout << "\t--------------------------" << endl;
			s = _getch();
			if (s == 'r' || s == 'R')
			{
				break;
			}
			else if (s == 'e' || s == 'E')
			{
				break;
			}
			else
			{
				system("cls");
				cout << "\t       Invalid Input! " << endl;
			}
		}
		if (s == 'e' || s == 'E')
		{
			break;
		}
	}
}
//displays profile of a citizen
void Citizen::displayProfile()
{
	Filling file;
	UsefulFunctions u;
	int ID = 0;
	int n = 0;
	char s;
	int ctCount;
	while (1)
	{
		while (1)
		{
			system("cls");
			cout << "\tDisplay Profile" << endl;
			ctCount = file.listProfiles();
			cout << "\t-------------------------" << endl;
			cout << "\tID: ";
			int IDtoDisplay;
			IDtoDisplay = u.integerInput();
			ifstream in3;
			in3.open("citizenData.txt");
			int integer;
			string str;
			for (int i = 0;i < ctCount;i++)
			{
				u.reachLine(in3, 1 + (i * 15));
				in3 >> ID;
				if (ID == IDtoDisplay)
				{
					system("cls");
					cout << "\tID: ";
					cout << IDtoDisplay << endl;
					cout << "\t-------------------------" << endl;
					cout << "\tAge: ";
					in3 >> integer;
					cout << integer << endl;
					cout << "\tName: ";
					in3 >> str;
					cout << str << " ";
					in3 >> str;
					cout << str << endl;
					cout << "\tEmail: ";
					in3 >> str;
					cout << str << endl;
					in3 >> str;
					cout << "\tCnic ";
					in3 >> str;
					cout << str << endl;
					cout << "\tContact No. : ";
					in3 >> str;
					cout << str << endl;
					cout << "\tBlood Group: ";
					in3 >> str;
					cout << str << endl;
					cout << "\tCity ";
					in3 >> str;
					cout << str << endl;
					cout << "\tState: ";
					in3 >> str;
					cout << str << endl;
					cout << "\tAddress: ";
					in3 >> str;
					cout << str << endl;
					cout << "\tDOB: ";
					in3 >> integer;
					cout << integer << "/";
					in3 >> integer;
					cout << integer << "/";
					in3 >> integer;
					cout << integer << endl;
					in3.close();
					break;
				}
				in3.close();
			}
			if (ID == IDtoDisplay)
			{
				break;
			}
			system("cls");
			cout << "\tError::002 No such ID Available!" << endl;
		}
		while (1)
		{
			cout << "\t-----------------------------" << endl;
			cout << "\t:  Display Another Profile  :" << endl;
			cout << "\t-----------------------------" << endl;
			cout << "\t-----------------------------" << endl;
			cout << "\t:            EXIT           : " << endl;
			cout << "\t-----------------------------" << endl;
			s = _getch();
			if (s == 'd' || s == 'D')
			{
				break;
			}
			else if (s == 'e' || s == 'E')
			{
				break;
			}
			else
			{
				system("cls");
				cout << "\t       Invalid Input! " << endl;
			}
		}
		if (s == 'e' || s == 'E')
		{
			break;
		}
	}
}
//updates profile of a citizen
void Filling::UpdateProfile()
{
	UsefulFunctions u;
	int ID = 0;
	int n = 0;
	char s;
	int ctCount;
	while (1)
	{
		while (1)
		{
			system("cls");
			cout << "\tDelete a Profile" << endl;
			ctCount = listProfiles();
			cout << "\t-------------------------" << endl;
			cout << "\tID: ";
			int IDtoUpdate;
			IDtoUpdate = u.integerInput();
			ifstream in3;
			in3.open("citizenData.txt");
			for (int i = 0;i < ctCount;i++)
			{
				u.reachLine(in3, 1 + (i * 15));
				in3 >> ID;
				in3.close();
				if (ID == IDtoUpdate)
				{
					n = i;
					break;
				}
			}
			if (ID == IDtoUpdate)
			{
				break;
			}
			system("cls");
			cout << "\tError::002 No such ID Available!" << endl;
		}
		Citizen citizen;
		ofstream out;
		out.open("temporary.txt");
		out.close();
		for (int i = 0;i < ctCount;i++)
		{
			if (i != n)
			{
				citizen.getCitizenData(i);
				citizen.setToTemporaryFile();
			}
			else
			{
				system("cls");
				cout << "\tUpdate Profile (";
				cout << "ID : " << ID << ")" << endl;
				cout << "\t-------------------------" << endl;
				citizen.signUp(ID, true);
			}
		}
		remove("citizenData.txt");
		if (rename("temporary.txt", "citizenData.txt"));
		while (1)
		{
			cout << "\t     (Profile Updated)" << endl;
			cout << "\t--------------------------" << endl;
			cout << "\t: Update Another Profile :" << endl;
			cout << "\t--------------------------" << endl;
			cout << "\t--------------------------" << endl;
			cout << "\t:          EXIT          : " << endl;
			cout << "\t--------------------------" << endl;
			s = _getch();
			if (s == 'u' || s == 'U')
			{
				break;
			}
			else if (s == 'e' || s == 'E')
			{
				break;
			}
			else
			{
				system("cls");
				cout << "\t       Invalid Input! " << endl;
			}
		}
		if (s == 'e' || s == 'E')
		{
			break;
		}
	}
}
//Checks the login validity of Admin
bool Filling::AdminValidation()
{
	ifstream in;
	in.open("AdminLogin.txt");
	string Admin;
	string Password;
	string IDcheck;
	string PASScheck;
	cout << "\tAdmin Login" << endl;
	cout << "\t-------------------------" << endl;
	cout << "\t: USERNAME: ";
	cin >> IDcheck;
	cout << "\t: PASSWORD: ";
	cin >> PASScheck;
	int totalAdmins;
	in >> totalAdmins;
	for (int i = 0;i < totalAdmins;i++)
	{
		in >> Admin;
		in >> Password;
		if (IDcheck == Admin && PASScheck == Password)
		{
			in.close();
			return true;
		}
	}
	in.close();
	return false;
}
//Checks the login validity of Gov Officials
bool Filling::GovOffValidation()
{
	ifstream in;
	in.open("GovLogin.txt");
	string GOV;
	string Password;
	string IDcheck;
	string PASScheck;
	cout << "\tGov. Login" << endl;
	cout << "\t-------------------------" << endl;
	cout << "\t: USERNAME: ";
	cin >> IDcheck;
	cout << "\t: PASSWORD: ";
	cin >> PASScheck;
	int totalOfficials;
	in >> totalOfficials;
	for (int i = 0;i < totalOfficials;i++)
	{
		in >> GOV;
		in >> Password;
		if (IDcheck == GOV && PASScheck == Password)
		{
			in.close();
			return true;
		}
	}
	in.close();
	return false;
}
//updates the amount used by Gov on Vaccines
void Filling::updateBudgetUsed(double newPrice)
{
	ifstream in;
	in.open("Gov.Budget.txt");
	double oldPrice;
	in >> oldPrice;
	in.close();
	ofstream out;
	out.open("Gov.Budget.txt");
	out << oldPrice + newPrice;
	out.close();
}
//updates number of cities working for vaccination
void Filling::updateVaccineCitiesCount()
{
	ifstream in;
	in.open("totalVaccineHoldingCities.txt");
	int oldCount;
	in >> oldCount;
	in.close();
	ofstream out;
	out.open("totalVaccineHoldingCities.txt");
	out << ++oldCount;
	out.close();
}
//updates vaccines data hold by a particular city (Doses Bought)
void Filling::updateVaccinesData(string city, Vaccine& vaccine)
{
	UsefulFunctions u;
	ifstream in;
	in.open("totalVaccineHoldingCities.txt");
	int totalCities;
	in >> totalCities;
	in.close();
	string checkCity;
	string vaccineName;
	int dose;
	ofstream out;
	out.open("temporary.txt");
	bool b = false;
	for (int i = 0;i < totalCities;i++)
	{
		ifstream in;
		in.open("VaccinesInHold.txt");
		u.reachLine(in, 1 + (i * 5));
		in >> checkCity;
		if (city == checkCity)
		{
			out << checkCity;
			if (vaccine.name == "Sinopharm")
			{
				in >> vaccineName;
				in >> dose;
				out << vaccine.name << endl;
				out << vaccine.doses + dose << endl;
				in >> vaccineName;
				in >> dose;
				out << vaccineName << endl;
				out << dose << endl;
			}
			else
			{
				in >> vaccineName;
				in >> dose;
				out << vaccineName << endl;
				out << dose << endl;
				in >> vaccineName;
				in >> dose;
				out << vaccineName << endl;
				out << vaccine.doses + dose << endl;
			}
			b = true;
		}
		else
		{
			out << checkCity << endl;
			in >> vaccineName;
			in >> dose;
			out << vaccineName << endl;
			out << dose << endl;
			in >> vaccineName;
			in >> dose;
			out << vaccineName << endl;
			out << dose << endl;
		}
		in.close();
	}
	if (b == false)
	{
		updateVaccineCitiesCount();
		out << city << endl;
		if (vaccine.name == "Sinopharm")
		{
			out << vaccine.name << endl;
			out << vaccine.doses << endl;
			out << "Pfizer" << endl;
			out << 0 << endl;
		}
		else
		{
			out << "Sinopharm" << endl;
			out << 0 << endl;
			out << vaccine.name << endl;
			out << vaccine.doses << endl;
		}
	}
	out.close();
	remove("VaccinesInHold.txt");
	if (rename("temporary.txt", "VaccinesInHold.txt"));
}
//Procure Vaccines from Suppliers
void Admin::ProcureVaccines()
{
	UsefulFunctions u;
	Filling file;
	int totalTypes;
	ifstream in;
	in.open("VaccinesInfo.txt");
	in >> totalTypes;
	Vaccine* vaccine = new Vaccine[totalTypes];
	while (1)
	{
		system("cls");
		for (int i = 0;i < totalTypes;i++)
		{
			in >> vaccine[i].name;
			in >> vaccine[i].manufacturer;
			in >> vaccine[i].supplierID;
			in >> vaccine[i].doses;
			in >> vaccine[i].price;
			cout << "\tBUY VACCCINES" << endl;
			cout << "\t-------------------------" << endl;
			cout << "\tVaccine Name: ";
			cout << vaccine[i].name << endl;
			cout << "\tCompany: ";
			cout << vaccine[i].manufacturer << endl;
			cout << "\tSupplier ID: ";
			cout << vaccine[i].supplierID << endl;
			cout << "\tDoses Per Batch: ";
			cout << vaccine[i].doses << endl;
			cout << "\tPrice: ";
			cout << vaccine[i].price << " " << endl;
			cout << endl;
		}
		in.close();
		string supplierID;
		string vaccineName;
		int totalBatches;
		cout << "\tSupplier ID: ";
		supplierID = u.integerInput();
		cout << "\tVaccineName: ";
		cin >> vaccineName;
		cout << "\tNo. of Batches: ";
		totalBatches = u.integerInput();
		bool b = false;
		string city;
		for (int i = 0;i < totalTypes;i++)
		{
			if (supplierID == vaccine[i].supplierID && vaccineName == vaccine[i].name)
			{
				vaccine[i].doses *= totalBatches;
				cout << "\tCity to Buy For: ";
				cin >> city;
				file.updateVaccinesData(city, vaccine[i]);
				file.updateBudgetUsed(vaccine[i].price * totalBatches);
				b = true;
			}
		}
		if (b == true)
		{
			break;
		}
		else if (b == false)
		{
			cout << "\tError::003 Doesn't Match any Data" << endl;
		}
	}
}
//Hires a doctor from citizens
void Doctor::hireDoctor()
{
	Filling file;
	UsefulFunctions u;
	char s;
	while (1)
	{
		while (1)
		{
			cout << "\tHire a Doctor" << endl;
			int ctCount;
			int ID = -1;
			int doc;
			ctCount = file.listProfiles();
			cout << "\t-------------------------" << endl;
			cout << "\tID: ";
			doc = u.integerInput();
			for (int i = 0;i < ctCount;i++)
			{
				ifstream in;
				in.open("citizenData.txt");
				u.reachLine(in, 1 + (i * 15));
				in >> ID;
				in.close();
				if (ID == doc)
				{
					ofstream out;
					out.open("Doctors.txt", ios::app);
					out << doc << endl;
					out.close();
					break;
				}
			}
			if (ID == doc)
			{
				break;
			}
			else
			{
				system("cls");
				cout << "\tError::004 No Such ID Found!" << endl;
			}
		}
		while (1)
		{
			cout << "\t--------------------------" << endl;
			cout << "\t:   Hire Another Doctor  :" << endl;
			cout << "\t--------------------------" << endl;
			cout << "\t--------------------------" << endl;
			cout << "\t:          EXIT          : " << endl;
			cout << "\t--------------------------" << endl;
			s = _getch();
			if (s == 'e' || s == 'E')
			{
				system("cls");
				break;
			}
			else if (s == 'd' || s == 'D')
			{
				break;
			}
			else
			{
				system("cls");
				cout << "\t       Invalid Input! " << endl;
			}
		}
		if (s == 'e' || s == 'E')
		{
			break;
		}
	}
}
//Hires an FDo from Citizens
void FDO::hireFDO()
{
	Filling file;
	UsefulFunctions u;
	char s;
	while (1)
	{
		while (1)
		{
			cout << "\tHire a FDO" << endl;
			int ctCount;
			int ID = 0;
			int fdo;
			ctCount = file.listProfiles();
			cout << "\t-------------------------" << endl;
			cout << "\tID: ";
			fdo = u.integerInput();
			for (int i = 0;i < ctCount;i++)
			{
				ifstream in;
				in.open("citizenData.txt");
				u.reachLine(in, 1 + (i * 15));
				in >> ID;
				in.close();
				if (ID == fdo)
				{
					ofstream out;
					out.open("FDO.txt", ios::app);
					out << fdo << endl;
					out.close();
					break;
				}
			}
			if (ID == fdo)
			{
				break;
			}
			else
			{
				system("cls");
				cout << "\tError::004 No Such ID Found!" << endl;
			}
		}
		while (1)
		{
			cout << "\t--------------------------" << endl;
			cout << "\t:     Hire Another FDO   :" << endl;
			cout << "\t--------------------------" << endl;
			cout << "\t--------------------------" << endl;
			cout << "\t:          EXIT          : " << endl;
			cout << "\t--------------------------" << endl;
			s = _getch();
			if (s == 'e' || s == 'E')
			{
				system("cls");
				break;
			}
			else if (s == 'f' || s == 'F')
			{
				break;
			}
			else
			{
				system("cls");
				cout << "\t       Invalid Input! " << endl;
			}
		}
		if (s == 'e' || s == 'E')
		{
			break;
		}
	}
}
//sets age from variable to instance variable (setter)
void Citizen::setAge(int age)
{
	this->age = age;
}
//updates age of all the citizen according to DOB & Current Date
void Filling::updateAgeDaily()
{
	UsefulFunctions u;
	Filling file;
	int ctCount;
	ctCount = file.getCitizenCount();
	Citizen citizen;
	int age[4];
	ofstream out;
	out.open("temporary.txt");
	out.close();
	for (int i = 0;i < ctCount;i++)
	{
		citizen.getCitizenData(i);
		age[0] = citizen.dob.day;
		age[1] = citizen.dob.month;
		age[2] = citizen.dob.year;
		age[3] = u.calculateAge(age);
		citizen.setAge(age[3]);
		citizen.setToTemporaryFile();
	}
	remove("citizenData.txt");
	if (rename("temporary.txt", "citizenData.txt"));
}
//returns ID (getter)
int Citizen::getID()
{
	return ID;
}
//returns city (getter)
string Citizen::getCity()
{
	return city;
}
//returns First Name (getter)
string Citizen::getFirstName()
{
	return firstName;
}
//returns Last Name (getter)
string Citizen::getLastName()
{
	return lastName;
}
//returns CNIC (getter)
string Citizen::getCnic()
{
	return cnic;
}
//updates vaccines data hold by a particular city (Doses Used)
void UsefulFunctions::updateLiveVaccines(string city, string vacS, int s, string vacP, int p, char c)
{
	string s1;
	string s2;
	int v1;
	int v2;
	string checkCity;
	int vacCount;
	ifstream in5;
	in5.open("totalVaccineHoldingCities.txt");
	in5 >> vacCount;
	in5.close();
	ofstream out;
	out.open("temporary.txt");
	ifstream in6;
	in6.open("VaccinesInHold.txt");
	if (c == 's' || c == 'S')
	{
		s--;
	}
	else if (c == 'p' || c == 'P')
	{
		p--;
	}
	for (int n = 0;n < vacCount;n++)
	{
		in6 >> checkCity;
		in6 >> s1;
		in6 >> v1;
		in6 >> s2;
		in6 >> v2;
		out << checkCity << endl;
		if (checkCity == city)
		{
			out << vacS << endl;
			out << s << endl;
			out << vacP << endl;
			out << p << endl;
		}
		else
		{
			out << s1 << endl;
			out << v1 << endl;
			out << s2 << endl;
			out << v2 << endl;
		}
	}
	in6.close();
	out.close();
	remove("VaccinesInHold.txt");
	if (rename("temporary.txt", "VaccinesInHold.txt"));
}
//Updates reigtration data during vaccination drive (Live)
void UsefulFunctions::updateLiveReg(int regID, int n, char c)
{
	Filling file;
	int regCount;
	regCount = file.getRegisteredCitizenCount();
	ofstream out;
	out.open("temporary.txt");
	int ID;
	int integer;
	string str;
	int date[3];
	for (int i = 0;i < regCount;i++)
	{
		ifstream in;
		in.open("RegisteredCitizen.txt");
		reachLine(in, 1 + (i * 8));
		in >> ID;
		if (ID == regID)
		{
			out << ID << endl;
			if (n == 1)
			{
				if (c == 's' || c == 'S')
				{
					out << n << endl;
					out << "Sinopharm" << endl;
				}
				else if (c == 'p' || c == 'P')
				{
					out << n << endl;
					out << "Pfizer" << endl;
				}
				out << 0 << endl;
				out << "Nil" << endl;
				currentDate(date);
				date[1] += 3;
				if (date[1] > 12)
				{
					date[1] = date[1] % 12;
					date[0]++;
				}
				out << date[2] << endl;
				out << date[1] << endl;
				out << date[0] << endl;
				cout << "\tNext Dose is Scheduled on " << date[2] << "/" << date[1] << "/" << date[0] << endl;
			}
			else if (n == 2)
			{
				out << ID << endl;
				in >> integer;
				in >> str;
				out << integer << endl;
				out << str << endl;
				if (c == 's' || c == 'S')
				{
					out << n << endl;
					out << "Sinopharm" << endl;
				}
				else if (c == 'p' || c == 'P')
				{
					out << n << endl;
					out << "Pfizer" << endl;
				}
				out << 0 << endl;
				out << 0 << endl;
				out << 0 << endl;
			}
		}
		else
		{
			out << ID << endl;
			in >> integer;
			in >> str;
			out << integer << endl;
			out << str << endl;
			in >> integer;
			in >> str;
			out << integer << endl;
			out << str << endl;
			in >> integer;
			out << integer << endl;
			in >> integer;
			out << integer << endl;
			in >> integer;
			out << integer << endl;
		}
		in.close();
	}
	out.close();
	remove("RegisteredCitizen.txt");
	if (rename("temporary.txt", "RegisteredCitizen.txt"));
}
//Updates booster dose citizen data during vaccination drive (Live)
void UsefulFunctions::updateLiveBooster(int boosterID)
{
	ofstream out;
	out.open("BoosterDoseCitizens.txt", ios::app);
	out << boosterID << endl;
	out.close();
}
//Runs the Vaccination Drive (Live)
void UsefulFunctions::startVaccinationDrive()
{
	system("cls");
	UsefulFunctions u;
	Filling file;
	Citizen citizen;
	Citizen fdo;
	Citizen doc;
	int regCount;
	regCount = file.getRegisteredCitizenCount();
	int ctCount;
	ctCount = file.getCitizenCount();
	int boosterCount;
	boosterCount = file.getBoosterCitizenCount();
	int vacCount;
	ifstream in5;
	in5.open("totalVaccineHoldingCities.txt");
	in5 >> vacCount;
	in5.close();
	int regID;
	string city;
	int s = 0;
	int p = 0;
	string checkCity;
	string vacS;
	string vacP;
	string reg1;
	int regT1;
	int boosterID = 0;
	int boosterCheck;
	string reg2;
	int regT2;
	int day;
	int month;
	int year;
	int date[3];
	currentDate(date);
	for (int i = 0;i < regCount;i++)
	{
		bool d = false;
		bool f = false;
		ifstream in;
		in.open("RegisteredCitizen.txt");
		u.reachLine(in, 1 + (i * 8));
		in >> regID;
		in >> regT1;
		in >> reg1;
		in >> regT2;
		in >> reg2;
		in >> day;
		in >> month;
		in >> year;
		in.close();
		ifstream inb;
		boosterCheck = regID;
		inb.open("BoosterDoseCitizens.txt");
		for (int b = 0;b < boosterCount; b++)
		{
			inb >> boosterID;
			if (boosterCheck == boosterID)
			{
				break;
			}
		}
		inb.close();
		if (((regT1 == 0 || regT2 == 0) || boosterCheck != boosterID) && day == date[2] && month == date[1] && year == date[0])
		{
			for (int j = 0;j < ctCount;j++)
			{
				citizen.getCitizenData(j);
				if (citizen.getID() == regID)
				{
					break;
				}
			}
			city = citizen.getCity();
			for (int m = 0;m < vacCount;m++)
			{
				ifstream in4;
				in4.open("VaccinesInHold.txt");
				u.reachLine(in4, 1 + (i * 5));
				in4 >> checkCity;
				if (checkCity == city)
				{
					in4 >> vacS;
					in4 >> s;
					in4 >> vacP;
					in4 >> p;
					in4.close();
					break;
				}
				in4.close();
			}
			ifstream in2;
			in2.open("Doctors.txt");
			while (!in2.eof())
			{
				in2 >> ID;
				for (int k = 0;k < ctCount;k++)
				{
					doc.getCitizenData(k);
					if (doc.getID() == ID)
					{
						if (doc.getCity() == city)
						{
							d = true;
							break;
						}
					}
				}
			}
			in2.close();
			ifstream in3;
			in3.open("FDO.txt");
			while (!in3.eof())
			{
				in3 >> ID;
				for (int l = 0;l < ctCount;l++)
				{
					fdo.getCitizenData(l);
					if (fdo.getID() == ID)
					{
						if (fdo.getCity() == city)
						{
							f = true;
							break;
						}
					}
				}
			}
			in3.close();
			this_thread::sleep_for(chrono::milliseconds(1500));
			cout << "\t---------------------------" << endl;
			cout << "\t" << citizen.getID() << "   " << citizen.getFirstName() << " " << citizen.getLastName() << "   " << citizen.getCnic() << endl;
			cout << endl;
			if (d == true && f == true)
			{
				this_thread::sleep_for(chrono::milliseconds(1500));
				cout << "\t FDO" << endl;
				cout << "\t----------" << endl;
				cout << "\t" << fdo.getFirstName() << " " << fdo.getLastName() << endl;
				cout << "\t" << city << endl;
				cout << "\t" << fdo.getCnic() << endl;
				cout << endl;
				this_thread::sleep_for(chrono::milliseconds(1500));
				cout << "\t Doctor" << endl;
				cout << "\t----------" << endl;
				cout << "\t" << doc.getFirstName() << " " << doc.getLastName() << endl;
				cout << "\t" << city << endl;
				cout << "\t" << doc.getCnic() << endl;
				cout << endl;
				if (s > 0 && p > 0)
				{
					if ((rand() % 2) + 1 == 1)
					{
						this_thread::sleep_for(chrono::milliseconds(1500));
						cout << "\tCitizen Selected Sinopharm->" << endl;
						updateLiveVaccines(city, vacS, s, vacP, p, 's');
						this_thread::sleep_for(chrono::milliseconds(1500));
						if (regT1 == 0)
						{
							cout << "\tFirst Dose Injected->" << endl;
							updateLiveReg(regID, 1, 's');
						}
						else if (regT2 == 0)
						{
							cout << "\tNow You Are Fully Vaccinated->" << endl;
							updateLiveReg(regID, 2, 's');
						}
						else if (boosterCheck != boosterID)
						{
							cout << "\tBooster Dose Injected->" << endl;
							file.setBoosterCitizenCount();
							updateLiveBooster(regID);
						}
					}
					else if ((rand() % 2) + 1 == 2)
					{
						this_thread::sleep_for(chrono::milliseconds(1500));
						cout << "\tCitizen Selected Pfizer->" << endl;
						updateLiveVaccines(city, vacS, s, vacP, p, 'p');
						this_thread::sleep_for(chrono::milliseconds(1500));
						if (regT1 == 0)
						{
							cout << "\tFirst Dose Injected->" << endl;
							updateLiveReg(regID, 1, 'p');
						}
						else if (regT2 == 0)
						{
							cout << "\tNow You Are Fully Vaccinated->" << endl;
							updateLiveReg(regID, 2, 'p');
						}
						else if (boosterCheck != boosterID)
						{
							cout << "\tBooster Dose Injected->" << endl;
							file.setBoosterCitizenCount();
							updateLiveBooster(regID);
						}
					}
				}
				else if (s > 0)
				{
					this_thread::sleep_for(chrono::milliseconds(1500));
					cout << "\tCitizen Selected Sinopharm->" << endl;
					updateLiveVaccines(city, vacS, s, vacP, p, 's');
					this_thread::sleep_for(chrono::milliseconds(1500));
					if (regT1 == 0)
					{
						cout << "\tFirst Dose Injected->" << endl;
						updateLiveReg(regID, 1, 's');
					}
					else if (regT2 == 0)
					{
						cout << "\tNow You Are Fully Vaccinated->" << endl;
						updateLiveReg(regID, 2, 's');
					}
					else if (boosterCheck != boosterID)
					{
						cout << "\tBooster Dose Injected->" << endl;
						file.setBoosterCitizenCount();
						updateLiveBooster(regID);
					}
				}
				else if (p > 0)
				{
					this_thread::sleep_for(chrono::milliseconds(1500));
					cout << "\tCitizen Selected Pfizer->" << endl;
					updateLiveVaccines(city, vacS, s, vacP, p, 'p');
					this_thread::sleep_for(chrono::milliseconds(1500));
					if (regT1 == 0)
					{
						cout << "\tFirst Dose Injected->" << endl;
						updateLiveReg(regID, 1, 'p');
					}
					else if (regT2 == 0)
					{
						cout << "\tNow You Are Fully Vaccinated->" << endl;
						updateLiveReg(regID, 2, 'p');
					}
					else if (boosterCheck != boosterID)
					{
						cout << "\tBooster Dose Injected->" << endl;
						file.setBoosterCitizenCount();
						updateLiveBooster(regID);
					}
				}

			}
			if (d == false)
			{
				this_thread::sleep_for(chrono::milliseconds(1500));
				cout << "\tCurrently no Active Doctor in the City!" << endl;
			}
			if (f == false)
			{
				this_thread::sleep_for(chrono::milliseconds(1500));
				cout << "\tCurrently no FDO int the City!" << endl;
			}
			if (d == false || f == false)
			{
				this_thread::sleep_for(chrono::milliseconds(1500));
				cout << "\tSorry You Can't be Vaccinated!" << endl;
			}
			cout << endl << endl;
		}
	}
	cout << "\t Vaccination Drive has Ended!" << endl;
}
//Analyze fully vaccinated citizens
void GovOff::fullyVaccinated()
{
	UsefulFunctions u;
	Filling file;
	Citizen citizen;
	int ctCount;
	ctCount = file.getCitizenCount();
	int regCount;
	regCount = file.getRegisteredCitizenCount();
	int regID;
	int checkFull = 0;
	int IDcheck;
	int regCheck = 0;
	int integer;
	string str;
	char s;
	while(1)
	{
		while (1)
		{
			cout << "\tFully Vaccinated Citizens" << endl;
			cout << "\t-----------------------------------" << endl;
			cout << "\tID / Name / Cnic" << endl << endl;
			for (int i = 0;i < regCount;i++)
			{
				ifstream in;
				in.open("RegisteredCitizen.txt");
				u.reachLine(in, 1 + (i * 8));
				in >> regID;
				in.close();
				ifstream in2;
				in2.open("RegisteredCitizen.txt");
				u.reachLine(in2, 6 + (i * 8));
				in2 >> checkFull;
				in2.close();
				if (checkFull == 0)
				{
					for (int j = 0;j < ctCount;j++)
					{
						citizen.getCitizenData(j);
						if (citizen.getID() == regID)
						{
							cout << "\t" << citizen.getID() << "   " << citizen.getFirstName() << " " << citizen.getLastName() << "   " << citizen.getCnic() << endl;
							break;
						}
					}
				}
			}
			cout << endl;
			cout << "\t-------------------------" << endl;
			cout << "\tID: ";
			IDcheck = u.integerInput();
			for (int k = 0;k < regCount;k++)
			{
				ifstream in3;
				in3.open("RegisteredCitizen.txt");
				u.reachLine(in3, 1 + (k * 8));
				in3 >> regCheck;
				in3.close();
				ifstream in5;
				in5.open("RegisteredCitizen.txt");
				u.reachLine(in5, 6 + (k * 8));
				in5 >> checkFull;
				in5.close();
				if (IDcheck == regCheck && checkFull == 0)
				{
					break;
				}
			}
			if (IDcheck == regCheck && checkFull == 0)
			{
				break;
			}
			system("cls");
			cout << "\tError::002 No such ID Available!" << endl;
		}
		for (int l=0;l < ctCount;l++)
		{
			ifstream in4;
			in4.open("citizenData.txt");
			u.reachLine(in4, 1 + (l * 15));
			in4 >> regCheck;
			if (regCheck == IDcheck)
			{
				system("cls");
				cout << "\t             ID: " << IDcheck << endl;
				cout << "\t-----------------------------------" << endl;
				cout << "\tAge: ";
				in4 >> integer;
				cout << integer << endl;
				cout << "\tName: ";
				in4 >> str;
				cout << str << " ";
				in4 >> str;
				cout << str << endl;
				cout << "\tEmail: ";
				in4 >> str;
				cout << str << endl;
				in4 >> str;
				cout << "\tCnic ";
				in4 >> str;
				cout << str << endl;
				cout << "\tContact No. : ";
				in4 >> str;
				cout << str << endl;
				cout << "\tBlood Group: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tCity ";
				in4 >> str;
				cout << str << endl;
				cout << "\tState: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tAddress: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tDOB: ";
				in4 >> integer;
				cout << integer << "/";
				in4 >> integer;
				cout << integer << "/";
				in4 >> integer;
				cout << integer << endl;
				in4.close();
			}
			else
			{
				in4.close();
			}
		}
		cout << "\t-----------------------------" << endl;
		cout << "\t:  Display Another Profile  :" << endl;
		cout << "\t-----------------------------" << endl;
		cout << "\t-----------------------------" << endl;
		cout << "\t:            EXIT           : " << endl;
		cout << "\t-----------------------------" << endl;
		s = _getch();
		if (s == 'd' || s == 'D')
		{
			system("cls");
			continue;
		}
		else if (s == 'e' || s == 'E')
		{
			system("cls");
			break;
		}
		else
		{
			system("cls");
			cout << "\t       Invalid Input! " << endl;
		}
	}
}
//Analyze partialy vaccinated citizens
void GovOff::PartiallyVaccinated()
{
	UsefulFunctions u;
	Filling file;
	Citizen citizen;
	int ctCount;
	ctCount = file.getCitizenCount();
	int regCount;
	regCount = file.getRegisteredCitizenCount();
	int regID;
	int checkFull = 0;
	int IDcheck;
	int regCheck = 0;
	int integer;
	string str;
	char s;
	while (1)
	{
		while (1)
		{
			cout << "\tPartially Vaccinated Citizens" << endl;
			cout << "\t-----------------------------------" << endl;
			cout << "\tID / Name / Cnic" << endl << endl;
			for (int i = 0;i < regCount;i++)
			{
				ifstream in;
				in.open("RegisteredCitizen.txt");
				u.reachLine(in, 1 + (i * 8));
				in >> regID;
				in.close();
				ifstream in2;
				in2.open("RegisteredCitizen.txt");
				u.reachLine(in2, 6 + (i * 8));
				in2 >> checkFull;
				in2.close();
				if (checkFull != 0)
				{
					for (int j = 0;j < ctCount;j++)
					{
						citizen.getCitizenData(j);
						if (citizen.getID() == regID)
						{
							cout << "\t" << citizen.getID() << "   " << citizen.getFirstName() << " " << citizen.getLastName() << "   " << citizen.getCnic() << endl;
							break;
						}
					}
				}
			}
			cout << endl;
			cout << "\t-------------------------" << endl;
			cout << "\tID: ";
			IDcheck = u.integerInput();
			for (int k = 0;k < regCount;k++)
			{
				ifstream in3;
				in3.open("RegisteredCitizen.txt");
				u.reachLine(in3, 1 + (k * 8));
				in3 >> regCheck;
				in3.close();
				ifstream in5;
				in5.open("RegisteredCitizen.txt");
				u.reachLine(in5, 6 + (k * 8));
				in5 >> checkFull;
				in5.close();
				if (IDcheck == regCheck && checkFull != 0)
				{
					break;
				}
			}
			if (IDcheck == regCheck && checkFull != 0)
			{
				break;
			}
			system("cls");
			cout << "\tError::002 No such ID Available!" << endl;
		}
		for (int l = 0;l < ctCount;l++)
		{
			ifstream in4;
			in4.open("citizenData.txt");
			u.reachLine(in4, 1 + (l * 15));
			in4 >> regCheck;
			if (regCheck == IDcheck)
			{
				system("cls");
				cout << "\t             ID: " << IDcheck << endl;
				cout << "\t-----------------------------------" << endl;
				cout << "\tAge: ";
				in4 >> integer;
				cout << integer << endl;
				cout << "\tName: ";
				in4 >> str;
				cout << str << " ";
				in4 >> str;
				cout << str << endl;
				cout << "\tEmail: ";
				in4 >> str;
				cout << str << endl;
				in4 >> str;
				cout << "\tCnic ";
				in4 >> str;
				cout << str << endl;
				cout << "\tContact No. : ";
				in4 >> str;
				cout << str << endl;
				cout << "\tBlood Group: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tCity ";
				in4 >> str;
				cout << str << endl;
				cout << "\tState: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tAddress: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tDOB: ";
				in4 >> integer;
				cout << integer << "/";
				in4 >> integer;
				cout << integer << "/";
				in4 >> integer;
				cout << integer << endl;
				in4.close();
			}
			else
			{
				in4.close();
			}
		}
		cout << "\t-----------------------------" << endl;
		cout << "\t:  Display Another Profile  :" << endl;
		cout << "\t-----------------------------" << endl;
		cout << "\t-----------------------------" << endl;
		cout << "\t:            EXIT           : " << endl;
		cout << "\t-----------------------------" << endl;
		s = _getch();
		if (s == 'd' || s == 'D')
		{
			system("cls");
			continue;
		}
		else if (s == 'e' || s == 'E')
		{
			system("cls");
			break;
		}
		else
		{
			system("cls");
			cout << "\t       Invalid Input! " << endl;
		}
	}
}
//Analyze citizens based on specific vaccine
void GovOff::SpecificVaccine()
{
	UsefulFunctions u;
	Filling file;
	Citizen citizen;
	int ctCount;
	ctCount = file.getCitizenCount();
	int regCount;
	regCount = file.getRegisteredCitizenCount();
	int regID;
	int check1st = 0;
	int check2nd = 0;
	int IDcheck;
	int regCheck = 0;
	int integer;
	string str;
	string vac1;
	string vac2;
	char s;
	while (1)
	{
		while (1)
		{
			cout << "\t             Sinopharm" << endl;
			cout << "\t-----------------------------------" << endl;
			cout << "\tID / Name / Cnic / Doses" << endl << endl;
			for (int i = 0;i < regCount;i++)
			{
				ifstream in;
				in.open("RegisteredCitizen.txt");
				u.reachLine(in, 1 + (i * 8));
				in >> regID;
				in.close();
				ifstream in2;
				in2.open("RegisteredCitizen.txt");
				u.reachLine(in2, 3 + (i * 8));
				in2 >> vac1;
				in2.close();
				ifstream in7;
				in7.open("RegisteredCitizen.txt");
				u.reachLine(in7, 5 + (i * 8));
				in7>> vac2;
				in7.close();
				if (vac1 == "Sinopharm" || vac2 == "Sinopharm")
				{
					for (int j = 0;j < ctCount;j++)
					{
						citizen.getCitizenData(j);
						if (citizen.getID() == regID)
						{
							cout << "\t" << citizen.getID() << "   " << citizen.getFirstName() << " " << citizen.getLastName() << "   " << citizen.getCnic() << "   ";
							if (vac1 == "Sinopharm" && vac2 == "Sinopharm")
							{
								cout << "1st & 2nd : Dose" << endl;
							}
							else if (vac1 == "Sinopharm")
							{
								cout << "1st : Dose" << endl;
							}
							else if (vac2 == "Sinopharm")
							{
								cout << "2st : Dose" << endl;
							}
							break;
						}
					}
				}
			}
			cout << endl << endl;
			cout << "\t               Pfizer" << endl;
			cout << "\t-----------------------------------" << endl;
			cout << "\tID / Name / Cnic / Doses" << endl << endl;
			for (int i = 0;i < regCount;i++)
			{
				ifstream in;
				in.open("RegisteredCitizen.txt");
				u.reachLine(in, 1 + (i * 8));
				in >> regID;
				in.close();
				ifstream in2;
				in2.open("RegisteredCitizen.txt");
				u.reachLine(in2, 3 + (i * 8));
				in2 >> vac1;
				in2.close();
				ifstream in8;
				in8.open("RegisteredCitizen.txt");
				u.reachLine(in8, 5 + (i * 8));
				in8 >> vac2;
				in8.close();
				if (vac1 == "Pfizer" || vac2 == "Pfizer")
				{
					for (int j = 0;j < ctCount;j++)
					{
						citizen.getCitizenData(j);
						if (citizen.getID() == regID)
						{
							cout << "\t" << citizen.getID() << "   " << citizen.getFirstName() << " " << citizen.getLastName() << "   " << citizen.getCnic() << "   ";
							if (vac1 == "Pfizer" && vac2 == "Pfizer")
							{
								cout << "1st & 2nd : Dose" << endl;
							}
							else if (vac1 == "Pfizer")
							{
								cout << "1st : Dose" << endl;
							}
							else if (vac2 == "Pfizer")
							{
								cout << "2st : Dose" << endl;
							}
							break;
						}
					}
				}
			}
			cout << endl << endl;
			cout << "\t-------------------------" << endl;
			cout << "\tID: ";
			IDcheck = u.integerInput();
			for (int k = 0;k < regCount;k++)
			{
				ifstream in3;
				in3.open("RegisteredCitizen.txt");
				u.reachLine(in3, 1 + (k * 8));
				in3 >> regCheck;
				in3.close();
				ifstream in5;
				in5.open("RegisteredCitizen.txt");
				u.reachLine(in5, 2 + (k * 8));
				in5 >> check1st;
				in5.close();
				ifstream in6;
				in6.open("RegisteredCitizen.txt");
				u.reachLine(in6, 4 + (k * 8));
				in6 >> check2nd;
				in6.close();
				if (IDcheck == regCheck && (check1st == 1 || check2nd == 2))
				{
					break;
				}
			}
			if (IDcheck == regCheck && (check1st == 1 || check2nd == 2))
			{
				break;
			}
			system("cls");
			cout << "\tError::002 No such ID Available!" << endl;
		}
		for (int l = 0;l < ctCount;l++)
		{
			ifstream in4;
			in4.open("citizenData.txt");
			u.reachLine(in4, 1 + (l * 15));
			in4 >> regCheck;
			if (regCheck == IDcheck)
			{
				system("cls");
				cout << "\t             ID: " << IDcheck << endl;
				cout << "\t-----------------------------------" << endl;
				cout << "\tAge: ";
				in4 >> integer;
				cout << integer << endl;
				cout << "\tName: ";
				in4 >> str;
				cout << str << " ";
				in4 >> str;
				cout << str << endl;
				cout << "\tEmail: ";
				in4 >> str;
				cout << str << endl;
				in4 >> str;
				cout << "\tCnic ";
				in4 >> str;
				cout << str << endl;
				cout << "\tContact No. : ";
				in4 >> str;
				cout << str << endl;
				cout << "\tBlood Group: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tCity ";
				in4 >> str;
				cout << str << endl;
				cout << "\tState: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tAddress: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tDOB: ";
				in4 >> integer;
				cout << integer << "/";
				in4 >> integer;
				cout << integer << "/";
				in4 >> integer;
				cout << integer << endl;
				in4.close();
			}
			else
			{
				in4.close();
			}
		}
		cout << "\t-----------------------------" << endl;
		cout << "\t:  Display Another Profile  :" << endl;
		cout << "\t-----------------------------" << endl;
		cout << "\t-----------------------------" << endl;
		cout << "\t:            EXIT           : " << endl;
		cout << "\t-----------------------------" << endl;
		s = _getch();
		if (s == 'd' || s == 'D')
		{
			system("cls");
			continue;
		}
		else if (s == 'e' || s == 'E')
		{
			system("cls");
			break;
		}
		else
		{
			system("cls");
			cout << "\t       Invalid Input! " << endl;
		}
	}
}
//Analyze booster dose citizens
void GovOff::BoosterDose()
{
	UsefulFunctions u;
	Filling file;
	Citizen citizen;
	int ctCount;
	ctCount = file.getCitizenCount();
	int boosterCount;
	boosterCount = file.getBoosterCitizenCount();
	int boosterID;
	int IDcheck;
	int boosterCheck = 0;
	int integer;
	string str;
	char s;
	while (1)
	{
		while (1)
		{
			cout << "\tBooster Dose Vaccinated Citizens" << endl;
			cout << "\t-----------------------------------" << endl;
			cout << "\tID / Name / Cnic" << endl << endl;
			for (int i = 0;i < boosterCount;i++)
			{
				ifstream in;
				in.open("BoosterDoseCitizens.txt");
				u.reachLine(in, 1 + i);
				in >> boosterID;
				in.close();
					for (int j = 0;j < ctCount;j++)
					{
						citizen.getCitizenData(j);
						if (citizen.getID() == boosterID)
						{
							cout << "\t" << citizen.getID() << "   " << citizen.getFirstName() << " " << citizen.getLastName() << "   " << citizen.getCnic() << endl;
							break;
						}
					}
			}
			cout << endl;
			cout << "\t-------------------------" << endl;
			cout << "\tID: ";
			IDcheck = u.integerInput();
			for (int k = 0;k < boosterCount;k++)
			{
				ifstream in3;
				in3.open("BoosterDoseCitizens.txt");
				u.reachLine(in3, 1 + (k * 8));
				in3 >> boosterCheck;
				in3.close();
				if (IDcheck == boosterCheck)
				{
					break;
				}
			}
			if (IDcheck == boosterCheck)
			{
				break;
			}
			system("cls");
			cout << "\tError::002 No such ID Available!" << endl;
		}
		for (int l = 0;l < ctCount;l++)
		{
			ifstream in4;
			in4.open("citizenData.txt");
			u.reachLine(in4, 1 + (l * 15));
			in4 >> boosterCheck;
			if (boosterCheck == IDcheck)
			{
				system("cls");
				cout << "\t             ID: " << IDcheck << endl;
				cout << "\t-----------------------------------" << endl;
				cout << "\tAge: ";
				in4 >> integer;
				cout << integer << endl;
				cout << "\tName: ";
				in4 >> str;
				cout << str << " ";
				in4 >> str;
				cout << str << endl;
				cout << "\tEmail: ";
				in4 >> str;
				cout << str << endl;
				in4 >> str;
				cout << "\tCnic ";
				in4 >> str;
				cout << str << endl;
				cout << "\tContact No. : ";
				in4 >> str;
				cout << str << endl;
				cout << "\tBlood Group: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tCity ";
				in4 >> str;
				cout << str << endl;
				cout << "\tState: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tAddress: ";
				in4 >> str;
				cout << str << endl;
				cout << "\tDOB: ";
				in4 >> integer;
				cout << integer << "/";
				in4 >> integer;
				cout << integer << "/";
				in4 >> integer;
				cout << integer << endl;
				in4.close();
			}
			else
			{
				in4.close();
			}
		}
		cout << "\t-----------------------------" << endl;
		cout << "\t:  Display Another Profile  :" << endl;
		cout << "\t-----------------------------" << endl;
		cout << "\t-----------------------------" << endl;
		cout << "\t:            EXIT           : " << endl;
		cout << "\t-----------------------------" << endl;
		s = _getch();
		if (s == 'd' || s == 'D')
		{
			system("cls");
			continue;
		}
		else if (s == 'e' || s == 'E')
		{
			system("cls");
			break;
		}
		else
		{
			system("cls");
			cout << "\t       Invalid Input! " << endl;
		}
	}
}
//statistical data of vaccination accross the country
void GovOff::VaccinationPercentage()
{
	UsefulFunctions u;
	Filling file;
	Citizen citizen;
	int ctCount;
	ctCount = file.getCitizenCount();
	int regCount;
	regCount = file.getRegisteredCitizenCount();
	int boosterCount;
	boosterCount = file.getBoosterCitizenCount();
	int totalCities;
	totalCities = file.totalVaccinationCities();
	string city;
	string checkCity;
	int ID;
	int regID;
	int dose1;
	int dose2;
	int cityPop = 0;
	int fully = 0;
	int partially = 0;
	int booster = 0;
	double boosterP = 0;
	double fullyP = 0;
	double partiallyP = 0;
	cout << "\t      Vaccination (Pakistan)" << endl;
	cout << "\t-----------------------------------" << endl;
	cout << "\tTotal Population: " << ctCount << endl;
	for (int i = 0;i < regCount;i++)
	{
		ifstream in10;
		in10.open("RegisteredCitizen.txt");
		u.reachLine(in10, 1 + (i * 8));
		in10 >> regID;
		in10.close();
		ifstream in7;
		in7.open("RegisteredCitizen.txt");
		u.reachLine(in7, 2 + (i * 8));
		in7 >> dose1;
		in7.close();
		ifstream in8;
		in8.open("RegisteredCitizen.txt");
		u.reachLine(in8, 4 + (i * 8));
		in8 >> dose2;
		in8.close();
		ifstream in9;
		in9.open("BoosterDoseCitizens.txt");
		for (int j = 0;j < boosterCount;j++)
		{
			in9 >> ID;
			if (ID == regID)
			{
				break;
			}
		}
		in9.close();
		if (ID == regID)
		{
			booster++;
		}
		else if (dose1 == 0 && dose2 == 0)
		{
			fully++;
		}
		else
		{
			partially++;
		}
	}
	if (fully != 0)
	{
		fullyP = (((fully * 1.0) / (ctCount * 1.0)) * 100.0);
		cout << "\tFully Vaccinated: " << fullyP << "%" << endl;
	}
	else
	{
		fullyP = 0.0;
		cout << "\tFully Vaccinated: " << fullyP << "%" << endl;
	}
	if (partially != 0)
	{
		partiallyP = (((partially * 1.0) / (ctCount * 1.0)) * 100.0);
		cout << "\tPartially Vaccinated: " << partiallyP << "%" << endl;
	}
	else
	{
		partiallyP = 0.0;
		cout << "\tPartially Vaccinated: " << partiallyP << "%" << endl;
	}
	if (booster != 0)
	{
		boosterP = (((booster * 1.0) / (ctCount * 1.0)) * 100.0);
		cout << "\tBooster Dose Vaccinated: " << boosterP << "%" << endl;
	}
	else
	{
		boosterP = 0.0;
		cout << "\tBooster Dose Vaccinated: " << boosterP << "%" << endl;
	}
	for (int i = 0;i < totalCities;i++)
	{
		cityPop = 0;
		fully = 0;
		partially = 0;
		booster = 0;
		ifstream in;
		in.open("VaccinesInHold.txt");
		u.reachLine(in, 1 + (i * 5));
		in >> city;
		in.close();
		cout << endl;
		cout << "\t" << city << endl;
		cout << "\t-----------------------------------" << endl;
		for (int j = 0;j < ctCount;j++)
		{
			ifstream in2;
			in2.open("citizenData.txt");
			u.reachLine(in2, 10 + (i * 15));
			in2 >> checkCity;
			in2.close();
			if (checkCity == city)
			{
				cityPop++;
			}
		}
		cout << "\tTotal Population: " << cityPop << endl;
		for (int j = 0;j < ctCount;j++)
		{
			ifstream in3;
			in3.open("citizenData.txt");
			u.reachLine(in3, 1 + ( j * 15));
			in3 >> ID;
			in3.close();
			ifstream in2;
			in2.open("citizenData.txt");
			u.reachLine(in2, 10 + (j * 15));
			in2 >> checkCity;
			in2.close();
			if (checkCity == city)
			{
				for (int k = 0;k < regCount;k++)
				{
					ifstream in4;
					in4.open("RegisteredCitizen.txt");
					u.reachLine(in4, 1 + (k * 8));
					in4 >> regID;
					in4.close();
					if (regID == ID)
					{
						ifstream in5;
						in5.open("RegisteredCitizen.txt");
						u.reachLine(in5, 2 + (k * 8));
						in5 >> dose1;
						in5.close();
						ifstream in6;
						in6.open("RegisteredCitizen.txt");
						u.reachLine(in6, 4 + (k * 8));
						in6 >> dose2;
						in6.close();
						ifstream in11;
						in11.open("BoosterDoseCitizens.txt");
						for (int b = 0;b < boosterCount;b++)
						{
							in11 >> ID;
							if (ID == regID)
							{
								break;
							}
						}
						in11.close();
						if (ID == regID)
						{
							booster++;
						}
						else if (dose1 == 0 && dose2 == 0)
						{
							fully++;
						}
						else
						{
							partially++;
						}
					}
				}
			}
		}
		if (fully != 0)
		{
			cout << "\tFully Vaccinated: " << (((fully * 1.0) / (cityPop * 1.0)) * 100.0) << "%" << endl;
		}
		else
		{
			cout << "\tFully Vaccinated: " << 0.0 << "%" << endl;
		}
		if (partially != 0)
		{
			cout << "\tPartially Vaccinated: " << (((partially * 1.0) / (cityPop * 1.0)) * 100.0) << "%" << endl;
		}
		else
		{
			cout << "\tPartially Vaccinated: " << 0.0 << "%" << endl;
		}
		if (booster != 0)
		{
			cout << "\tBooster Dose Vaccinated: " << (((booster * 1.0) / (ctCount * 1.0)) * 100.0) << "%" << endl;
		}
		else
		{
			cout << "\tBooster Dose Vaccinated: " << 0.0 << "%" << endl;
		}
	}
	cout << endl;
	double orgBoosterP = boosterP;
	double orgFullyP = fullyP;
	double orgPartiallyP = partiallyP;
	cout << endl << endl;
	cout << "\t           Statistics GRAPH" << endl;
	cout << "\t          (Country: Pakistan)" << endl << endl;
	cout << "\t      Fully     Partially   Booster" << endl;
	cout << "\t____________________________________" << endl;
	while (fullyP > 0 || partiallyP > 0 || boosterP > 0)
	{
		cout << "\t|";
		if (fullyP > 5)
		{
			cout << setw(11) << "|  |";
			fullyP -= 5;
		}
		else if (fullyP <= 5 && fullyP > 0)
		{
			cout << setw(11) << orgFullyP;
			fullyP -= 5;
		}
		else
		{
			cout << setw(11) << " ";
		}
		if (partiallyP > 5)
		{
			cout << setw(11) << "|  |";
			partiallyP -= 5;
		}
		else if (partiallyP <= 5 && partiallyP > 0)
		{
			cout << setw(11) << orgPartiallyP;
			partiallyP -= 5;
		}
		else
		{
			cout << setw(11) << " ";
		}
		if (boosterP > 5)
		{
			cout << setw(11) << "|  |";
			boosterP -= 5;
		}
		else if (boosterP <= 5 && boosterP > 0)
		{
			cout << setw(11) << orgBoosterP;
			boosterP -= 5;
		}
		else
		{
			cout << setw(11) << " ";
		}
		cout << endl;
	}
	cout << "\t|" << endl;
	cout << "\t|" << endl;
	cout << "      --------------------------------------" << endl;
}