#include "Survey.h"

#include<string>
#include<iomanip>
int counterSurveys = 0; /**** Main Global variable Storing info of Number of Surveys ****/
Survey::Survey()
{
	titleOfSurvey = "None";
	
	descriptionOfSurvey = "None";
	numberOfQuestionInt = 0;
	rows= 0;
	
}
Survey::~Survey()
{

}
/**** Function for Checking Wheter it is string or number ****/
bool isNumber(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
/**** Function for Checking Wheter it is string or number ****/

/**** Function for Printing Number 1st 2nd etc ****/
string numbering(int num)
{
	if (num + 1 == 1) return "st";
	else if ((num + 1 == 2)) return "nd";
	else if ((num + 1 == 3)) return "rd";
	else return "th";
}
/**** Function for Printing Number 1st 2nd etc ****/
void Survey::create_new_survey()
{

	/**** Function Local Variables ****/
	string tempStoringFirstQuestion = "None";
	char temp,temp3;
	int temp2;
	/**** Function Local Variables ****/

	/**** 1.Title of Survey ****/
	cout << endl << "Title of Survey: ";
	cin.ignore();
	getline(cin, titleOfSurvey);
	/**** 1.Description of Survey ****/
	cout << endl << "Description of Title (optional : Click Enter to Proceed ) : ";
	//	cin.clear();
		//cin.ignore();
	getline(cin, descriptionOfSurvey);
	if (descriptionOfSurvey.empty()) descriptionOfSurvey = "N/A"; /**** Here Empty is and Inbuilt Function which is checking it is white space or not ****/

	cout << endl << "Number of Questions (max upto 20): ";  getline(cin, numberOfQuestions);
	while (!(isNumber(numberOfQuestions)))
	{
		cout << "Please Enter a Digit : ";
		getline(cin, numberOfQuestions);
	}
	
	numberOfQuestionInt = stoi(numberOfQuestions);
	rows = numberOfQuestionInt;
	cout << setw(60) << "!! Survey Filling !!";
	for (int i = 0; i < rows; i++)
	{
		cout << "\nEnter the " << i + 1 << numbering(i) << " Question : "; cin.clear(); cin.ignore(); getline(cin, twoDMatrixQuestions[i][0]);
		/**** In the matrix the first line and coloumn will be off Questions and 2nd coloumn will tell teh options and else are options options ****/
		cout << "How much Options You want : "; again:  cin >> temp; // here again is a label
		while (!(temp>= '0' && temp<= '9'))
		{
			cout << "Please Enter a Digit : ";
			cin.clear(); cin.ignore();
			cin >> temp;
		}
		temp2 = temp - '0';
		if (temp2 > 5 || temp2 < 0)
		{
			cout << "\n\t\t\tInvalid Input !! Enter Again : ";
			goto again;
		}
		twoDMatrixQuestions[i][1] = temp;  /**** Assigning a char to String ****/
		
		for (int j = 0; j < temp2;j++)
		{
			cout << "\nOption " << j + 1 << numbering(j) << " : "; cin.clear(); cin.ignore(); getline(cin, twoDMatrixQuestions[i][j+2]);
		}

	}
	

	/****                                           Editing Survey                                          ****/
	
	cout << "\n\n\t\t\tDo You want to Edit Survey (y/n) : "; againEditSurvey: cin >> temp;
	if (temp == 'y' || temp == 'Y')
	{
		cout << "\n1.Editing a Question  \t\t 2.Editing option of a Question"; againEditSurvey2: cin >> temp;
		switch (temp)
		{
		case '1': {
			cout << endl << "Enter the Question # "; againEnter: cin >> temp;
			if (temp <= '0' || temp > numberOfQuestionInt + '0')
			{
				cout << "Invalid\tEnter Again : ";
				goto againEnter;
			}
			cout << endl << "Please Enter Again the Question # " << temp << " : "; cin.clear(); cin.ignore(); getline(cin, twoDMatrixQuestions[temp - '0' - 1][0]);
			cout << "Edit Options (y/n) : "; optionsOfQuestionAgain: cin >> temp3;
			if (temp3 == 'y' || temp3 == 'Y')
			{

				for (int i = 0; i < stoi(twoDMatrixQuestions[temp - '0' - 1][1]); i++)
				{
					cout << "\nOption " << i + 1 << numbering(i) << " : "; cin.clear(); cin.ignore(); getline(cin, twoDMatrixQuestions[temp - '0' - 1][i + 2]);
				}
			}
			else if (temp3 == 'n' || temp3 == 'N') break;
			else
			{
				cout << "!! Invalid Input !! Please Enter Again : ";
				goto optionsOfQuestionAgain;
			}
			break;
		}
		case'2':
				{	
			cout << endl << "Enter the Question # "; againEnter2: cin >> temp;
			if (temp <= '0' || temp > numberOfQuestionInt + '0')
			{
				cout << "Invalid\tEnter Again : ";
				goto againEnter2;
			}
			cout << endl << "Options for this Question are as Follows ," << endl;
			for (int i = 0; i < stoi(twoDMatrixQuestions[temp - '0' - 1][1]); i++)	cout << "Option - " << i + 1 << " : " << twoDMatrixQuestions[temp - '0' - 1][i + 2] << "\t";
			cout << endl << "Enter Option to Edit : "; EnterAgain: cin >> temp3;
			if (temp3 <= '0' || temp3 > stoi(twoDMatrixQuestions[temp - '0' - 1][1]) + '0')
			{
				cout << endl << "Invalid Input\tEnter Again : ";
				goto EnterAgain;
			}
			cout << "Enter Again Option - " << temp3; cin.clear(); cin.ignore(); getline(cin, twoDMatrixQuestions[temp - '0' - 1][temp3 - '0' + 2]);
			
				break; 
				}
		default: {cout << "!! Invalid Input !! Please Enter Again : ";
			goto againEditSurvey2;
			break; }
		}
	}
	else if (temp == 'n' || temp == 'N') cout << endl;
	else
	{
		cout << "!! Invalid Input !! Please Enter Again : ";
		goto againEditSurvey;
		
	}

	cout << endl << "\t\t\t****SURVEY COMPLETED****";
}









/****                                                 Queue of Survey Creation                                                  ****/
QueueOfSurvey::QueueOfSurvey()
{
	
	maxSize = 20;
	if (maxSize / 2 <= counterSurveys) maxSize *= 2;
	else if (counterSurveys <= maxSize / 4) maxSize /= 2;
	front = 0; rear = -1; counter = 0;
	Nodes = new Survey[maxSize];
	

}
void QueueOfSurvey::enqueue(const Survey& instance)
{
	Nodes[counter].push(instance);
	
	counter++;
	front = 0;
	rear++;
	counterSurveys++;
	
}
/**** it is a sense of Copy Constructor ****/
void Survey::push(const Survey& inst)
{
	
	this->titleOfSurvey = inst.titleOfSurvey;
	
	this->descriptionOfSurvey = inst.descriptionOfSurvey;
	this->numberOfQuestions = inst.numberOfQuestions;
	this->numberOfQuestionInt = inst.numberOfQuestionInt;
	this->rows = inst.rows;


	for (int i = 0; i < rows; i++)
	{
		this->twoDMatrixQuestions[i][0]= inst.twoDMatrixQuestions[i][0];
	
		this->twoDMatrixQuestions[i][1] = inst.twoDMatrixQuestions[i][1];

		for (int j = 0; j < stoi(twoDMatrixQuestions[i][1]); j++)
		{
			this->twoDMatrixQuestions[i][j+2]=inst.twoDMatrixQuestions[i][j + 2];
			
		}

	}
}


void Survey::print(Survey Nodes[])
{
	/**** Function Variables ****/
	char temp='0';
	/**** Function Variables ****/
	if (counterSurveys == 0) cout << endl << "Sorry! No Survey Created ";

	else
	{
		cout << endl << "\t\t\tAll Surveys are Listed Below" << endl;
		for (int i = 0; i < counterSurveys; i++)
		{
			cout << i + 1 << "." << Nodes[i].titleOfSurvey << "\t";
		}
		cout << endl << "Enter The Survey ID : "; cin >> temp;
		while (temp<'0' || (temp - '0')>counterSurveys)
		{
			cout << "!! Invalid input !! Enter Again : ";
			cin >> temp;
		}
		cout << endl << "\t\t\t Survey - ID : " << temp;
		cout << endl << "Title : " << Nodes[(temp - '0') - 1].titleOfSurvey
			<< endl << "Description : " << Nodes[(temp - '0') - 1].descriptionOfSurvey
			<< endl << "Total Questions = " << Nodes[(temp - '0') - 1].numberOfQuestions;

		for (int i = 0; i < Nodes[(temp - '0') - 1].numberOfQuestionInt; i++)
		{
			cout << endl<< Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][0];
			
			

			for (int j = 0; j < stoi(Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][1]); j++)
			{
				cout << "\n\t\t\t"<< Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2];
			}

		}
	}
}


void Survey::add_responses(Survey Nodes[])
{
	/**** Function Variables ****/
	char temp = '0';
	int responsesCounter = 0;
	string temp2;
	/**** Function Variables ****/
	if (counterSurveys == 0) cout << endl << "Sorry! No Survey ";
	else
	{
		cout << endl << "\t\t\tAll Surveys are Listed Below" << endl;
		for (int i = 0; i < counterSurveys; i++)
		{
			cout << i + 1 << "." << Nodes[0].titleOfSurvey << "\t";
		}
		cout << endl << "Enter The Survey ID : "; cin >> temp;
		while (temp<'0' || (temp - '0')>counterSurveys)
		{
			cout << "!! Invalid input !! Enter Again : ";
			cin >> temp;
		}
		cout << endl << "\t\t\t Survey - ID : " << temp;
		cout << endl << "Title : " << Nodes[(temp - '0') - 1].titleOfSurvey
			<< endl << "Description : " << Nodes[(temp - '0') - 1].descriptionOfSurvey
			<< endl << "Total Questions = " << Nodes[(temp - '0') - 1].numberOfQuestions
			<< endl << "Enter the Total Resposes Recieved : "; cin >> Nodes[(temp - '0') - 1].responses; responsesCounter= stoi(Nodes[(temp - '0') - 1].responses);

		while (stoi(Nodes[(temp - '0') - 1].responses)  < 0)
		{
			cout << "Responses Can Not Be Negative : "; cin >> Nodes[(temp - '0') - 1].responses;
		}

		for (int i = 0; i < Nodes[(temp - '0') - 1].numberOfQuestionInt; i++)
		{
			cout << endl <<"Question - "<<i+1<<" : \n" << Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][0];



			for (int j = 0; j < stoi(Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][1]); j++)
			{

				cout << "\n\t\t\t" << Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2];
				if(j== (stoi(Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][1]))-1)
				{
					Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2] = Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2] + "~" + to_string(responsesCounter);
				}
				else
				{
					if(responsesCounter <= 0)
					{ 
						Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2] += "~0"; /**** tilde Operator for checking resposnses of options ****/
					}
					else
					{
						cout << endl << "\n\t\t\tEnter Resposes Recieved : "; cin >> temp2;
						while (stoi(temp2) < 0)
						{
							cout << "Responses Can Not Be Negative : "; cin >> temp2;
						}
						Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2] = Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2] + "~" + temp2;
						responsesCounter = responsesCounter  - (stoi(temp2));
					}
					

				}
			}

		}



	}
}
/**** Deleting Memory at End ****/
QueueOfSurvey::~QueueOfSurvey()
{
	delete[] Nodes;
}