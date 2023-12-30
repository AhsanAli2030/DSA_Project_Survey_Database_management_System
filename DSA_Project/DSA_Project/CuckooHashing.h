#pragma once
#include "Survey.h"
#include<vector>
class CuckooHashing:public QueueOfSurvey
{

private:
	int tableSize=10; /*** we will dynamicall increase the size where we need if Data grows larger then we will add its size ****/
	// if 
	int max_kicks;

	vector<int> table1;
	vector<int> table2;

	bool insertHelper(int key,vector<int>& table, int kicksCount);
	int hashFunction1(int key);
	int hashFunction2(int key)
	{
		return (key / tableSize) % tableSize;
	}
public:
	CuckooHashing() :table1(tableSize, -1), table2(tableSize, -1) {
		int check = toQueueCheck(tableSize); /*** Increase the Size if Survey Size Increases ****/
		tableSize = check;
		max_kicks = 10;
	}
	bool insert();
	
	void display() const;
		
	


	

	bool search(QueueOfSurvey& inst);
	bool remove();
};

