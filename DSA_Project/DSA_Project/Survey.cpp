#include "Survey.h"
#include "Queue.h"
#include<string>
Survey::Survey()
{
	titleOfSurvey = "None";
	Queue instanceOfQueue; /**** As the Survey object is created then the Queue object is also Created ****/
	descriptionOfSurvey = "None";

}

void Survey::create_new_survey()
{
	
	/**** Function Local Variables ****/
	
	/**** Function Local Variables ****/

	/**** 1.Title of Survey ****/
	cout << endl << "Title of Survey: "; cin >> titleOfSurvey;
	/**** 1.Description of Survey ****/
	cout << endl << "Description of Title (optional : Click Enter to Proceed ) : "; 
	cin.ignore();
	getline(cin, descriptionOfSurvey);
	if (descriptionOfSurvey.empty()) descriptionOfSurvey="N/A"; /**** Here Empty is and Inbuilt Function which is checking it is white space or not ****/


	

}