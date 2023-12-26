
#include <iostream>
#include<iomanip>

#include "Survey.h"

using namespace std;

/**** Main Function Prototypes****/
string main_startUP();
void survey_management_mysten();
void database_management_system();
void fileWrite();

/**** Main Function Prototypes****/


/**** Global Variables ****/
QueueOfSurvey instanceOfQueueOfSurvey;
Survey instanceOfSurvey;
/**** Global Variables ****/

int main()
{

	instanceOfQueueOfSurvey.fileRead();
	
	/**** Main Variables****/
	string option;
	/**** Function Variables****/

	

	option=main_startUP();                                                   /**** Main Function ****/
	if (option == "1") survey_management_mysten();
	else if (option == "2") database_management_system();


	fileWrite();


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
	
	/**** Function Variables****/
	cout << "\n\n" << setw(150) << "----------------------------------------------------------------------";
	cout << "\n          ********************************************************************* || Welcome To Survey Management,Here you can do the Following Tasks || ******************************************************************************";
	cout << "\n" << setw(150) << "----------------------------------------------------------------------";
	while(1) /**** Remain in the Loop Until Work is done of This loop ****/
	{
		cout << "\n\n" << setw(62) << "###############";
		cout << "\n\t\t\t\t\t       || Main Menu ||";
		cout << "\n" << setw(62) << "###############";

		cout << "\n\n" << "1.Creating a New Survey"
			<< "\n" << "2.Adding Responses For Data Analysis"
			<< "\n" << "3.View Created Surveys"
			<< "\n" << "4.View Responsed Surveys"
			<< endl << "5.Database" <<
			endl << "6.Exit"
		<< "\t\t\tPlease Select Option : "; cin >> option;
	while (option != "1" && option != "2" && option != "3" && option != "4" && option!="5" && option != "6")
	{
		cout <<right<< setw(77)   << "Please Select the Available Options: "; cin >> option;
	}
	if (option == "1")
	{
		instanceOfSurvey.create_new_survey();

		instanceOfQueueOfSurvey.enqueue(instanceOfSurvey);


	}
	else if (option == "3") instanceOfQueueOfSurvey.printSurvey();

	else if (option == "2") instanceOfQueueOfSurvey.adding_responses();

	else if (option == "4") instanceOfQueueOfSurvey.printRespondedSurvey();
	else if (option == "5")
	{
		database_management_system();
		break;
	}
	else if (option == "6")
	{
		instanceOfQueueOfSurvey.breakAll();
		break;
	}
	
	
		
	}
}
void database_management_system()
{

	
	cout << endl << "Chlo Hanana Bachy ise Pora kro ";
	
}
/**** FIle Write Operations ****/
void fileWrite()
{
	/**** Created  Survey Saving ****/

	if (instanceOfQueueOfSurvey.getCounter() == 0) cout << ""; // no survey Created
	else instanceOfQueueOfSurvey.dequeue();

	/**** Created  Survey Saving ****/

	/**** Responsed  Survey Saving ****/
	if (instanceOfQueueOfSurvey.get_survey_which_responsed() == 0) cout << "";
	else instanceOfQueueOfSurvey.dequeueResponsed();
	
	/**** Responsed  Survey Saving ****/

	/**** Important Data Save File ****/
	if (instanceOfQueueOfSurvey.getCounter() == 0) cout << "";
	else instanceOfQueueOfSurvey.save_important_file();

	/**** Important Data Save Saving ****/

}





/**** Main Function Declarations****/

