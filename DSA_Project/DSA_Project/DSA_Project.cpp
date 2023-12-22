
#include <iostream>
#include<iomanip>

#include "Survey.h"

using namespace std;

/**** Main Function Prototypes****/
string main_startUP();
void survey_management_mysten();
/**** Main Function Prototypes****/


int main()
{

	
	/**** Main Variables****/
	string option;
	/**** Function Variables****/

	

	option=main_startUP();                                                   /**** Main Function ****/
	if (option == "1") survey_management_mysten();


	



	return 0;
}
/**** Main Function Declarations****/
string main_startUP()
{
	/**** Function Variables****/
	string option = "0";
	/**** Function Variables****/
	cout << right << setw(130) << "-------------------------------------------\n";
	cout << setw(130) << "  || SURVEY AND DATABASE MANAGEMENT SYSTEM ||\n";
	cout << setw(130) << "-------------------------------------------\n";

	cout << "\n\n\n";
	cout << setw(99) << "1.SURVEY MANAGEMENT\t\t\t" << "2.DATABASE MANAGEMENT\n\n";
	cout << setw(116) << "Please Select : "; cin >> option;
	while (option != "1" && option != "2")
	{
		cout << endl << setw(129) << "Please Select the Available Options: "; cin >> option;
	}

	return option;
}

void survey_management_mysten()
{
	
	/**** Function Variables****/
	string option;
	QueueOfSurvey instanceOfQueueOfSurvey;
	Survey instanceOfSurvey;
	/**** Function Variables****/
	
	cout << "\n\n!! Welcome To Survey Management,Here you can do the Following Tasks !!";
	while(1) /**** Remain in the Loop Until Work is done of This loop ****/
	{
		

	cout << "\n\n\t\t\t\t" << "1.Creating a New Survey"
		<< "\n\t\t\t\t" << "2.Adding Responses For Data Analysis"
		<< "\n\t\t\t\t" << "3.View Created Surveys"
		<< "\n\t\t\t\t" << "4.View Responsed Surveys"
		<< "\nPlease Select Option : "; cin >> option;
	while (option != "1" && option != "2" && option != "3" && option != "4")
	{
		cout << endl  << "Please Select the Available Options: "; cin >> option;
	}
	if (option == "1")
	{
		instanceOfSurvey.create_new_survey();
		instanceOfQueueOfSurvey.enqueue(instanceOfSurvey);
		
		
	}
	else if (option == "3")
	{
		instanceOfQueueOfSurvey.printSurvey();
	}
	else if (option == "2")
	{
		instanceOfQueueOfSurvey.adding_responses();
	}
	
	
		
	}
}

/**** Main Function Declarations****/

