#pragma once
#include<iostream>
#include<string>
using namespace std;
class QueueOfSurvey;
class Survey
{
public:
	Survey();

	~Survey(); /**** Have to delete 2d Matrix ****/
	void create_new_survey();
	void push(const Survey& inst);
	friend class QueueOfSurvey;
	void print(Survey Nodes[]);
	void add_responses(Survey Nodes[]);
	void printResSurvey(Survey Nodes[]);
private:
	string titleOfSurvey,descriptionOfSurvey, numberOfQuestions,twoDMatrixQuestions[20][7], responses; /*** if 5 options then 2 will be also ***/
	int numberOfQuestionInt, rows;
	


	
	friend class QueueOfSurvey;
	
};

class QueueOfSurvey :public Survey
{
public:
	QueueOfSurvey();
	~QueueOfSurvey();
	void enqueue(const Survey& instance);
	void printSurvey() { print(Nodes); }
	
	void adding_responses() { add_responses(Nodes); }
	
	void printRespondedSurvey() { printResSurvey(Nodes); }
	
private:
	int front,rear,counter,maxSize;
	
	Survey* Nodes;

	
};

