#include "CuckooHashing.h"
#include "Survey.h"
#include<string>
#include<fstream>
#include<iomanip>
string countingFiles = "0";
bool CuckooHashing::insert()
{
	ifstream file("D:\\SEMESTER-3\\DSA\\DSA Project\\Visual Studio Files\\DSA_Project\\DataBase\\Important Data.txt", ios::in);
	if (file)
	{
		getline(file, countingFiles);
		
		
	}
	file.close();
	
	for (int i = 0; i < stoi(countingFiles); i++)
		 insertHelper(i, table1, max_kicks);
	
		
	return true;
	

}

bool CuckooHashing::insertHelper(int key, vector<int>& table, int kicksCount)
{
	
		if (kicksCount == 0) {
			cout << "\nUnable To Insert Key " << key << "!";
			return false;
		}
		int index = hashFunction1(key);
		if (table[index] == -1)
		{
			table[index] = key;
			return true;
		}

		int kickedKey = table[index];
		table[index] = key;

		if (!insertHelper(kickedKey, (table == table1) ? table2 : table1, kicksCount - 1))
		{
			table[index] = kickedKey;
			return false;
		}

		
	

	return true;

}

int CuckooHashing::hashFunction1(int key) { return key % tableSize; }

bool CuckooHashing::search(QueueOfSurvey& inst)
{
	int data = 0;
	cout << endl << "Please Enter The Survey Id : "; cin >> data;
	
	int index1 = hashFunction1(data);
	int index2 = hashFunction2(data);

	bool keyExist = (table1[index1] == data) || table2[index2] == data;
	if (!keyExist) {
		cout << endl << "Survey Not Found";
		return false;
	}
	else
	{
		cout << endl << "\t\tSurvey Found";
		inst.printSurvey(data);

	}
	

}

bool CuckooHashing::remove()
{
	int data = 0;
	cout << endl << "Please Enter The Survey Id : "; cin >> data;

	int index1 = hashFunction1(data);
	int index2 = hashFunction2(data);

	bool keyExist = (table1[index1] == data) || table2[index2] == data;
	if (!keyExist) {
		cout << endl << "Survey Not Found";
		return false;
	}
	else
	{
		
		auto it1 = find(table1.begin(), table1.end(), data);
		auto it2 = find(table2.begin(), table2.end(), data);

		if (it1 != table1.end()) {
			*it1 = -1;
			return true;
		}
		else if (it2 != table2.end()) {
			*it2 = -1;
			return true;
		}
		return false;
	}
}

void CuckooHashing::display() const
{
	cout << "\n\n" << setw(81) << " #########################################";
	cout << "\n\t\t\t\t\t|| Cuckoo Hashing Tables Visualization ||";
	cout << "\n" << setw(83) << " #########################################\n\n";
	std::cout << "Table 1: \t\t";
	for (int val : table1) {
		std::cout << val << " ";
	}
	std::cout << "\n\nTable 2: \t\t";
	for (int val : table2) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}