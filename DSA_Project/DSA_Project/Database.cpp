#include "Database.h"
#include "Survey.h"
#include<iomanip>
#include<fstream>
fstream file2;
Database::Database()
{
	firstTimeDatabaseEntry = 0;
	usernameOrId ="None";
	password = "None";
	
}
void Database::security()
{
	cout << "\n\n" << setw(62) << "  #######################";
	cout << "\n\t\t\t\t\t || Database Security ||";
	cout << "\n" << setw(62) << "  #######################";
	cin.clear(); cin.ignore();
	cout << endl << "\tAdmin Credentials"
		<< endl << "Username/ID : "; getline(cin, usernameOrId); 
	cout  << "Paswword : "; getline(cin, password); 
	cout << endl;
	system("pause");
	system("CLS");
}
bool Database::securityCheck()
{
	string temp = "0", temp2 = "0"; int i = 0;
	cout << "\n\n" << setw(62) << "  #######################";
	cout << "\n\t\t\t\t\t || Database Security ||";
	cout << "\n" << setw(62) << "  #######################"; cin.clear(); cin.ignore();
	tryAgain:
	cout << endl << "\tAdmin Credentials"
		<< endl<<"Username/ID : "; getline(cin, temp); 
	cout  << "Paswword : "; getline(cin, temp2);

	if (temp == this->usernameOrId && temp2 == this->password)	return true;
	else
	{
		if (i == 2) return false;
		cout << endl << "\tWrong Credentials ! Enter Again ";
		i++;
		
		goto tryAgain;
	}
		
	
		
	
}
void	Database::readSecurity()
{
	
	string option;
	file2.open("Security.txt", ios::in);
	if (file2)
	{
		getline(file2, option);
		firstTimeDatabaseEntry = stoi(option);

		getline(file2, option);
		usernameOrId = option;

		getline(file2, option);
		password = option;
	}
	else cout << "";
	
	file2.close();
	

}