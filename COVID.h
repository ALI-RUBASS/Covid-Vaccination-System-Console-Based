#ifndef COVID_H
#define COVID_H
#include<string>
using namespace std;
//Classes (Members & Function Prototype)
class Dob {
public:
    int day;
    int month;
    int year;
};
class Person {
protected:
    int ID;
    string firstName;
    string lastName;
    string email;
    string cnic;
    string contactNumber;
};
class Admin : public Person {
public:
    void ProcureVaccines();
};
class Doctor : public Person {
public:
    void hireDoctor();
};
class FDO : public Person {
public:
    void hireFDO();
};
class GovOff : public Person {
public:
    void fullyVaccinated();
    void PartiallyVaccinated();
    void SpecificVaccine();
    void BoosterDose();
    void VaccinationPercentage();
};
class Citizen : public Person {
protected:
    int age;
    string bloodType;
    string city;
    string state;
    string address;
    string password;
    bool eligible;
public:
    Dob dob;
    void signUp(int, bool);
    void getCitizenData(int);
    void setToTemporaryFile();
    void getDataToObject(int ID, int age, string citizenData[10], int dob[3]);
    void displayProfile();
    void setAge(int);
    int getID();
    string getCity();
    string getFirstName();
    string getLastName();
    string getCnic();
};
class RegisteredCitizens : public Citizen
{
public:
    bool checkRegisteredBool(int);
};
class Vaccine {
public:
    string name;
    string manufacturer;
    string supplierID;
    int doses;
    double price;
    int vaccineID;
};
class Filling {
public:
    bool SuperAdminValidation();
    int getCitizenCount();
    void setCitizenCount(int);
    int getRegisteredCitizenCount();
    int getBoosterCitizenCount();
    void setBoosterCitizenCount();
    void setRegisteredCitizenCount();
    void setCitizenData(string data[10], int ID, int ageDob[4], bool);
    int loginValidation(int, string, string);
    int getAge(int);
    void setRegisteredCitizenData(int);
    void history(int);
    void DeleteProfile();
    int listProfiles();
    void UpdateProfile();
    bool AdminValidation();
    void updateBudgetUsed(double);
    void updateVaccinesData(string city, Vaccine& vaccine);
    void updateVaccineCitiesCount();
    void updateAgeDaily();
    bool GovOffValidation();
    int totalVaccinationCities();
};
class UsefulFunctions {
private:
    static int ID;
public:
    UsefulFunctions(int);
    UsefulFunctions();
    static int RandomID();
    void reachLine(ifstream&, int);
    int integerInput();
    int calculateAge(int ageDob[4]);
    void currentDate(int date[3]);
    void startVaccinationDrive();
    void updateLiveVaccines(string, string, int, string, int, char);
    void updateLiveReg(int, int, char);
    void updateLiveBooster(int);
};
class Warehouse {
public:
    Vaccine type[2];
    double latitude;
    double longitude;
};
class VaccinationCenter {
protected:
    Warehouse warehouse;
    FDO fdo;
    Doctor doc;
};
#endif