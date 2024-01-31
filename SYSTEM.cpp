#include<iostream>
#include<conio.h>
#include "COVID.h";
#include<string>
#include<windows.h>
#include<fstream>
int main()
{
	system("color F4");
	UsefulFunctions initialize(0);
	Filling file;
	//Update Age of every signed up citizen according to current date at the start of the program
	file.updateAgeDaily();
	int cit = file.getCitizenCount();
	Citizen* citizen = new Citizen;
	RegisteredCitizens* registered = new RegisteredCitizens;
	char s = 'z';
	while (s != 'e')
	{
		cout << "\t--------------------------" << endl;
		cout << "\t:  SUPER Admin Interface  : " << endl;
		cout << "\t--------------------------" << endl;
		cout << "\t--------------------------" << endl;
		cout << "\t:      Admin Interface    : " << endl;
		cout << "\t--------------------------" << endl;
		cout << "\t--------------------------" << endl;
		cout << "\t:     PUBLIC Interface    : " << endl;
		cout << "\t--------------------------" << endl;
		cout << "\t--------------------------" << endl;
		cout << "\t:      GOV Interface      : " << endl;
		cout << "\t--------------------------" << endl;
		cout << "\t--------------------------" << endl;
		cout << "\t:           EXIT          : " << endl;
		cout << "\t--------------------------" << endl;
		s = _getch();
		system("cls");
		cout << endl;
		//Super Admin Section
		if (s == 'S' || s == 's')
		{
			char s1 = 'i';
			while (s1 == 'i' || s1 == 'I')
			{
				Filling file;
				if (file.SuperAdminValidation() == 1)
				{
					system("cls");
					cout << endl;
					cout << "\t  SuperAdmin Access Granted" << endl;
					char sa;
						while (1)
						{
							cout << "\t-----------------------------" << endl;
							cout << "\t:   Start Vaccination Drive  : " << endl;
							cout << "\t-----------------------------" << endl;
							cout << "\t-----------------------------" << endl;
							cout << "\t:        Profile Menu       : " << endl;
							cout << "\t-----------------------------" << endl;
							cout << "\t-----------------------------" << endl;
							cout << "\t:            Exit           : " << endl;
							cout << "\t-----------------------------" << endl;
							sa = _getch();
							if (sa == 's' || sa == 'S')
							{
								UsefulFunctions u;
								u.startVaccinationDrive();
							}
							else if (sa == 'p' || sa == 'P')
							{
								system("cls");
								while (1)
								{
									cout << "\t-----------------------------" << endl;
									cout << "\t:        Add Profile        : " << endl;
									cout << "\t-----------------------------" << endl;
									cout << "\t-----------------------------" << endl;
									cout << "\t:       Remove Profile      : " << endl;
									cout << "\t-----------------------------" << endl;
									cout << "\t-----------------------------" << endl;
									cout << "\t:       Update Profile      : " << endl;
									cout << "\t-----------------------------" << endl;
									cout << "\t-----------------------------" << endl;
									cout << "\t:       Display Profile     : " << endl;
									cout << "\t-----------------------------" << endl;
									cout << "\t-----------------------------" << endl;
									cout << "\t:           <-Back          : " << endl;
									cout << "\t-----------------------------" << endl;
									sa = _getch();
									if (sa == 'a' || sa == 'A')
									{
										system("cls");
										citizen->signUp(initialize.RandomID(), false);
									}
									else if (sa == 'r' || sa == 'R')
									{
										system("cls");
										file.DeleteProfile();
									}
									else if (sa == 'u' || sa == 'U')
									{
										system("cls");
										file.UpdateProfile();
									}
									else if (sa == 'd' || sa == 'D')
									{
										system("cls");
										citizen->displayProfile();
									}
									else if (sa == 'b' || sa == 'B')
									{
										system("cls");
										break;
									}
									else
									{
										system("cls");
										cout << "\t      INVALID INPUT!" << endl;
									}
								}
							}
							else if (sa == 'e' || sa == 'E')
							{
								system("cls");
								break;
							}
							else
							{
								system("cls");
								cout << "\t      INVALID INPUT!" << endl;
							}
						}
						if (sa == 'e' || sa == 'E')
						{
							break;
						}
				}
				else
				{
					cout << "     Incorrect Username or Password!" << endl;
					cout << "\t-------------------------" << endl;
					cout << "\t:      Input AGAIN      : " << endl;
					cout << "\t-------------------------" << endl;
					cout << "\t-------------------------" << endl;
					cout << "\t:       MAIN MENU       : " << endl;
					cout << "\t-------------------------" << endl;
					s1 = _getch();
				}
			}
		}
		//Public Section
		else if (s == 'p' || s == 'P')
		{
			system("cls");
			char s3 = 'z';
			while (s3 != 'm' && s3 != 'M')
			{
				cout << "\t-------------------------" << endl;
				cout << "\t:        SIGN UP        : " << endl;
				cout << "\t-------------------------" << endl;
				cout << "\t-------------------------" << endl;
				cout << "\t:        LOG IN         : " << endl;
				cout << "\t-------------------------" << endl;
				cout << "\t-------------------------" << endl;
				cout << "\t:       MAIN PAGE       : " << endl;
				cout << "\t-------------------------" << endl;
				s3 = _getch();
				if (s3 == 's' || s3 == 'S')
				{
					system("cls");
					UsefulFunctions func;
					//Citizen* temp = citizens;
					//citizens = func.sizeupCitizens(citizens, ++cit);
					//delete[]temp;
					cout << "\tFill The Form to Sign up" << endl;
					cout << "\t-------------------------" << endl;
					citizen->signUp(func.RandomID(), false);
					file.setCitizenCount(++cit);
				}
				else if (s3 == 'l' || s3 == 'L')
				{
					system("cls");
					if (cit <= 0)
					{
						cout << "\tNo Citizen has registered yet." << endl;
					}
					else
					{
						bool l = false;
						string email;
						string password;
						Filling func1;
						int n;
						bool E = true;
						while (l == false)
						{
							cout << "\tFill log in details" << endl;
							cout << "\t-------------------------" << endl;
							cout << "\t: EMAIL: ";
							cin >> email;
							cout << "\t: PASSWORD: ";
							cin >> password;
							n = func1.loginValidation(cit, email, password);
							if (n > 0)
							{
								l = true;
							}
							else
							{
								system("cls");
								cout << "\tWrong Email or Password!" << endl;
							}
							--n;
							if (l == true)
							{
								system("cls");
								char s4 = 'z';
								while (s4 != 'e' && s4 != 'E')
								{
									if (registered->checkRegisteredBool(n) == 1)
									{
										cout << "\t------------------------------" << endl;
										cout << "\t:      You are Registered    : " << endl;
										cout << "\t------------------------------" << endl;
										cout << "\t------------------------------" << endl;
										cout << "\t:      Check Your History    : " << endl;
										cout << "\t------------------------------" << endl;
									}
									else
									{
										if (func1.getAge(n) >= 5)
										{
											cout << "\t------------------------------" << endl;
											cout << "\t:       Get Registered       : " << endl;
											cout << "\t------------------------------" << endl;
										}
										else
										{
											cout << "\t------------------------------" << endl;
											cout << "\t: NOT Eligible : Age below 5  : " << endl;
											cout << "\t------------------------------" << endl;
											E = false;
										}
									}
									cout << "\t------------------------------" << endl;
									cout << "\t:             EXIT           : " << endl;
									cout << "\t------------------------------" << endl;
									s4 = _getch();
									if ((s4 == 'g' || s4 == 'G') && E == true)
									{
										char alergic;
										char policies;
										cout << "\t:        FILL THE FORM       : " << endl;
										cout << "\t------------------------------" << endl;
										cout << "\t: Are you currently Alergic to anything (Y/n) ?" << endl;
										alergic = _getch();
										cout << "\t: Do you accept the policies of NCOC.GOV.PK (Y/n) ?" << endl;
										policies = _getch();
										if ((alergic == 'n' || alergic == 'N') && (policies == 'y' || policies == 'Y'))
										{
											func1.setRegisteredCitizenCount();
											func1.setRegisteredCitizenData(n);
											cout << "\t------------------------------" << endl;
											cout << "\t:    Registration Completed!  : " << endl;
											cout << "\t------------------------------" << endl;
										}
										if ((alergic == 'y' || alergic == 'Y'))
										{
											cout << "\t ------------------------------" << endl;
											cout << "\t :    InEligible : Alergic    : " << endl;
											cout << "\t ------------------------------" << endl;
										}
										if ((policies == 'n' || policies == 'N'))
										{
											cout << "\t--------------------------------" << endl;
											cout << "\t:  Required : Accept Policies  : " << endl;
											cout << "\t--------------------------------" << endl;
										}
									}
									else if (s4 == 'h' || s4 == 'H')
									{
										while (s4 != 'b' && s4 != 'B')
										{
											system("cls");
											cout << "\t------------------------------" << endl;
											cout << "\t:     Vaccination History    : " << endl;
											cout << "\t------------------------------" << endl;
											cout << endl;
											func1.history(n);
											cout << endl;
											cout << "\t------------------------------" << endl;
											cout << "\t:           <- Back          : " << endl;
											cout << "\t------------------------------" << endl;
											s4 = _getch();
										}
										system("cls");
									}
									else if (s4 == 'e' || s4 == 'E')
									{
										system("cls");
									}
									E = true;
								}
							}
						}

					}
				}
				else if (s3 == 'm' || s3 == 'M')
				{
					system("cls");
					s3 = 'm';
				}
				else
				{
					cout << "\tINVALID INPUT!" << endl;
				}
			}
		}
		//Admin Section
		else if (s == 'a' || s == 'A')
		{
		Admin admin;
			char s0;
			while (1)
			{
				system("cls");
				if (file.AdminValidation() == 1)
				{
					while (1)
					{
						system("cls");
						cout << endl;
						cout << "\t   Admin Access Granted!" << endl;
						cout << "\t--------------------------" << endl;
						cout << "\t:      Hire Doctors       : " << endl;
						cout << "\t--------------------------" << endl;
						cout << "\t--------------------------" << endl;
						cout << "\t:        Hire FDO        : " << endl;
						cout << "\t--------------------------" << endl;
						cout << "\t--------------------------" << endl;
						cout << "\t:     Procure Vaccines    : " << endl;
						cout << "\t--------------------------" << endl;
						cout << "\t--------------------------" << endl;
						cout << "\t:           EXIT          : " << endl;
						cout << "\t--------------------------" << endl;
						s0 = _getch();
						if (s0 == 'd' || s0 == 'D')
						{
							Doctor D;
							system("cls");
							D.hireDoctor();
						}
						else if (s0 == 'f' || s0 == 'F')
						{
							FDO F;
							system("cls");
							F.hireFDO();
						}
						else if (s0 == 'p' || s0 == 'P')
						{
							system("cls");
							admin.ProcureVaccines();
						}
						else if (s0 == 'e' || s0 == 'E')
						{
							system("cls");
							break;
						}
						else
						{
							system("cls");
							cout << "\t      INVALID INPUT!" << endl;
						}
					}
				}
				else
				{
					cout << "     Incorrect Username or Password!" << endl;
					while (1)
					{
						cout << "\t-------------------------" << endl;
						cout << "\t:      Input AGAIN      : " << endl;
						cout << "\t-------------------------" << endl;
						cout << "\t-------------------------" << endl;
						cout << "\t:       MAIN MENU       : " << endl;
						cout << "\t-------------------------" << endl;
						s0 = _getch();
						if (s0 == 'm' || s0 == 'M')
						{
							system("cls");
							break;
						}
						else if (s0 == 'i' || s0 == 'I')
						{
							break;
						}
						else
						{
							system("cls");
							cout << "\t      INVALID INPUT!" << endl;
						}
					}
					if (s0 == 'm' || s0 == 'M')
					{
						break;
					}
				}
				if (s0 == 'e' || s0 == 'E')
				{
					system("cls");
					break;
				}
			}
		}
		//Government Section
		else if (s == 'g' || s == 'G')
		{
			char s1 = 'i';
			while (s1 == 'i' || s1 == 'I')
			{
				Filling file;
				GovOff Gov;
				if (file.GovOffValidation() == 1)
				{
					system("cls");
					cout << endl;
					cout << "\t     GOV Official Access" << endl;
					char sa;
					while (1)
					{
						cout << "\t-----------------------------" << endl;
						cout << "\t:      Filter Patients      : " << endl;
						cout << "\t-----------------------------" << endl;
						cout << "\t-----------------------------" << endl;
						cout << "\t:       Vaccination %       : " << endl;
						cout << "\t-----------------------------" << endl;
						cout << "\t-----------------------------" << endl;
						cout << "\t:            Exit           : " << endl;
						cout << "\t-----------------------------" << endl;
						sa = _getch();
						if (sa == 'f' || sa == 'F')
						{
							char g;
							while (1)
							{
								system("cls");
								cout << "\t-----------------------------" << endl;
								cout << "\t:      Fully Vaccinated     : " << endl;
								cout << "\t------------------------------" << endl;
								cout << "\t-----------------------------" << endl;
								cout << "\t:          Partially        : " << endl;
								cout << "\t-----------------------------" << endl;
								cout << "\t-----------------------------" << endl;
								cout << "\t:       Specific Vaccine    : " << endl;
								cout << "\t-----------------------------" << endl;
								cout << "\t-----------------------------" << endl;
								cout << "\t:         Booster Shot      : " << endl;
								cout << "\t-----------------------------" << endl;
								cout << "\t-----------------------------" << endl;
								cout << "\t:             EXIT          : " << endl;
								cout << "\t-----------------------------" << endl;
								g = _getch();
								if (g == 'f' || g == 'F')
								{
									system("cls");
									Gov.fullyVaccinated();
								}
								else if (g == 'p' || g == 'P')
								{
									system("cls");
									Gov.PartiallyVaccinated();
								}
								else if (g == 's' || g == 'S')
								{
									system("cls");
									Gov.SpecificVaccine();
								}
								else if (g == 'b' || g == 'B')
								{
									system("cls");
									Gov.BoosterDose();
								}
								else if (g == 'e' || g == 'E')
								{
									system("cls");
									break;
								}
								else
								{
									system("cls");
									cout << "\t      INVALID INPUT!" << endl;
								}
							}
						}
						else if (sa == 'v' || sa == 'V')
						{
							system("cls");
							Gov.VaccinationPercentage();
						}
						else if (sa == 'e' || sa == 'E')
						{
							system("cls");
							break;
						}
						else
						{
							system("cls");
							cout << "\t      INVALID INPUT!" << endl;
						}
					}
					if (sa == 'e' || sa == 'E')
					{
						break;
					}
				}
				else
				{
					cout << "     Incorrect Username or Password!" << endl;
					cout << "\t-------------------------" << endl;
					cout << "\t:      Input AGAIN      : " << endl;
					cout << "\t-------------------------" << endl;
					cout << "\t-------------------------" << endl;
					cout << "\t:       MAIN MENU       : " << endl;
					cout << "\t-------------------------" << endl;
					s1 = _getch();
				}
			}
		}
		//Exit The Program
		else if (s == 'e' || s == 'E')
		{
			cout << "\tThanks for Using The System!" << endl;
			s = 'e';
		}
		else
		{
			cout << "\t      INVALID INPUT!" << endl;
		}
	}
}