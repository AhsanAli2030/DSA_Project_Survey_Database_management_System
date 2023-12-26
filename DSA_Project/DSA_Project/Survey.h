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
	int numberOfQuestionInt, rows, checkBoxQuestion;
	
	

	
	
	
};

class QueueOfSurvey :public Survey
{
public:
	QueueOfSurvey();
	~QueueOfSurvey();
	void enqueue(const Survey& instance);
	void dequeue();
	void dequeueResponsed();
	
	void printSurvey() { print(Nodes); }
	
	void adding_responses() { add_responses(Nodes); }
	void save_important_file();
	void printRespondedSurvey() { printResSurvey(Nodes); }
	/**** GEtter Function ****/
	int getCounter()
	{
		return counter;
	}
	void breakAll();
	int get_survey_which_responsed() { return surveyWhichResponsed; }
	int fileRead();
private:
	int front, rear, counter, maxSize, surveyWhichResponsed;
	
	Survey* Nodes;

	
};

