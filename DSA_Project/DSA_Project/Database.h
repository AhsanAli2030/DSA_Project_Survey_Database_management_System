#pragma once
#include "Database.h"
#include<iostream>
using namespace std;
class Database
{
public:
	Database();
	~Database(){}
	void security();
	bool securityCheck();
	int firstTimeDatabaseEntry; /*** when we will read file we will read its value ****/
	void readSecurity();
	string username()
	{
		return usernameOrId;
	}
	string getpassword()
	{
		return password;
	}
private:
	string usernameOrId,password;
	
};

