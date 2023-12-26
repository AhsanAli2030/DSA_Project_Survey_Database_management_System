#include "Survey.h"

#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<fstream>

fstream file; /**** Global file variable ****/
/**** Main Global variable Storing info of Number of Surveys ****/
int counterSurveys = 0;
int* responsedSurveys;
int responsingSurvey = 0;
int surveyWhichResponsedAtThatTime = 0; /***** this will be value which will we take from file and wil act as starting for the file for next ****/

/**** Main Global variable Storing info of Number of Surveys ****/
Survey::Survey()
{
	titleOfSurvey = "None";
	
	descriptionOfSurvey = "None";
	numberOfQuestionInt = 0;
	rows= 0;
	checkBoxQuestion = 0;
	
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
	cout << "\n\n" << setw(62) << "#####################";
	cout << "\n\t\t\t\t\t || Survey Creation ||";
	cout << "\n" << setw(62) << "#####################";

	/**** Function Local Variables ****/
	string tempStoringFirstQuestion = "None";
	char temp,temp3;
	int temp2;
	
	/**** Function Local Variables ****/

	/**** 1.Title of Survey ****/
	cout << endl<<endl << "Title of Survey: ";
	cin.ignore();
	getline(cin, titleOfSurvey);
	while (titleOfSurvey.empty())	getline(cin, titleOfSurvey);
	
	/**** 1.Description of Survey ****/
	cout << endl << "Description of Title (optional : Click Enter to Proceed ) : ";
	//	cin.clear();
		//cin.ignore();
	getline(cin, descriptionOfSurvey);
	if (descriptionOfSurvey.empty()) descriptionOfSurvey = "N/A"; /**** Here Empty is and Inbuilt Function which is checking it is white space or not ****/

	cout << endl << "Number of Questions (max upto 20): ";  questionsAgain: getline(cin, numberOfQuestions);
	while (numberOfQuestions.empty())	getline(cin, numberOfQuestions);
	while (!(isNumber(numberOfQuestions)))
	{
		cout << "Please Enter a Digit : ";
		getline(cin, numberOfQuestions);
	}
	while (stoi(numberOfQuestions)>30 || stoi(numberOfQuestions) <0)
	{
		cout << "Please witin Range : ";
		goto questionsAgain;
	}
	numberOfQuestionInt = stoi(numberOfQuestions);
	rows = numberOfQuestionInt;
	cout << "How Much CheckBox Question You Want : "; cin >> temp;
	while (temp - '0' < 0 || temp - '0' > stoi(numberOfQuestions))
	{
		cout << "Questions Demanded Out of Range, Enter Again : ";
		cin >> temp;
	}
	checkBoxQuestion = temp - '0';
	system("pause");
	system("CLS");
	
	cout << endl << setw(60) << "####################";
	cout <<endl<< setw(60) << "!! Survey Filling !!";
	cout << endl << setw(60) << "####################"<<endl;
	cin.clear(); cin.ignore();
	/**** IF check box Question and this matches then this loop will not execute ****/int i = 0;
	for (; i < rows-checkBoxQuestion; i++)
	{
		cout << "\n" << i + 1 << numbering(i) << " Question : ";  getline(cin, twoDMatrixQuestions[i][0]);
		while (twoDMatrixQuestions[i][0].empty())	getline(cin, twoDMatrixQuestions[i][0]);
		/**** In the matrix the first line and coloumn will be off Questions and 2nd coloumn will tell teh options and else are options options ****/
		cout << "\nHow much Options You want : "; again:  cin >> temp; // here again is a label
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
		else if (temp2 == 1)
		{
			cout << "\n\t\t\tThere must be 2 Options : ";
			goto again;
		}
		
		twoDMatrixQuestions[i][1] = temp;  /**** Assigning a char to String ****/
		cin.clear(); cin.ignore();
		for (int j = 0; j < temp2;j++)
		{
			
			
			cout << "Option " << j + 1 << numbering(j) << " : ";   getline(cin, twoDMatrixQuestions[i][j + 2]);
			while (twoDMatrixQuestions[i][j + 2].empty())	getline(cin, twoDMatrixQuestions[i][j + 2]);
		}
		

	}
	
	/**** Check Box Question ****/
	int k = 0;
	for (int j = i; j < rows; j++)
	{
		if (k < checkBoxQuestion)
		{
			cout << "\n" << j + 1 << numbering(j) << " Question : ";  getline(cin, twoDMatrixQuestions[j][0]);
			while (twoDMatrixQuestions[j][0].empty())	getline(cin, twoDMatrixQuestions[j][0]);
			twoDMatrixQuestions[j][2] = "Any Random Range";
			cout << endl << "CheckBox Input : " << twoDMatrixQuestions[j][2];
			k++;
		}
	}
	
	/****                                           Editing Survey                                          ****/
	
	cout << "\n\nDo You want to Edit Survey (y/n) : "; againEditSurvey: cin >> temp;
	if (temp == 'y' || temp == 'Y')
	{
		cout << endl << setw(57) << "#################";
		cout << endl << setw(57) << "!! Survey Edit !!";
		cout << endl << setw(57) << "#################" << endl;
		cout << endl<<setw(75)<<"1.Editing a Question  \t\t 2.Editing option of a Question"; againEditSurvey2: 
		cout << endl <<endl<< setw(57) << "Please Select : ";
		cin >> temp;
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
			while (twoDMatrixQuestions[temp - '0' - 1][0].empty())	getline(cin, twoDMatrixQuestions[temp - '0' - 1][0]);
			cout << "Edit Options (y/n) : "; optionsOfQuestionAgain: cin >> temp3;
			if (temp3 == 'y' || temp3 == 'Y')
			{

				for (int i = 0; i < stoi(twoDMatrixQuestions[temp - '0' - 1][1]); i++)
				{
					cout << "\nOption " << i + 1 << numbering(i) << " : "; cin.clear(); cin.ignore(); getline(cin, twoDMatrixQuestions[temp - '0' - 1][i + 2]);
					while (twoDMatrixQuestions[temp - '0' - 1][i + 2].empty())	getline(cin, twoDMatrixQuestions[temp - '0' - 1][i + 2]);
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
			while (twoDMatrixQuestions[temp - '0' - 1][temp3 - '0' + 2].empty())	getline(cin, twoDMatrixQuestions[temp - '0' - 1][temp3 - '0' + 2]);
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

	cout << endl << setw(60) << "######################";
	cout << endl << setw(60) << "!! Survey Completed !!";
	cout << endl << setw(60) << "######################" << endl;
	system("pause");
	system("CLS");
}









/****                                                 Queue of Survey Creation                                                  ****/
QueueOfSurvey::QueueOfSurvey()
{
	
	maxSize = 20;
	if (maxSize / 2 <= counterSurveys) maxSize *= 2;
	else if (counterSurveys <= maxSize / 4) maxSize /= 2;
	front = 0; rear = -1; counter = 0;
	Nodes = new Survey[maxSize];
	responsedSurveys = new int[maxSize];
	surveyWhichResponsed = 0;
	
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
	this->checkBoxQuestion = inst.checkBoxQuestion;
	int i = 0;
	for (; i < rows - checkBoxQuestion; i++)
	{
		this->twoDMatrixQuestions[i][0]= inst.twoDMatrixQuestions[i][0];
		this->twoDMatrixQuestions[i][1] = inst.twoDMatrixQuestions[i][1];
		
		for (int j = 0; j < (stoi(twoDMatrixQuestions[i][1])); j++)
		{
			this->twoDMatrixQuestions[i][j+2]=inst.twoDMatrixQuestions[i][j + 2];
			
		}

	}
	/**** Check Box Question ****/
	int k = 0;
	for (int j = i; j < rows; j++)
	{
		if (k < checkBoxQuestion)
		{
			this->twoDMatrixQuestions[j][0] = inst.twoDMatrixQuestions[j][0];
			twoDMatrixQuestions[j][2] = "Any Random Range";
			
			k++;
		}
	}
}


void Survey::print(Survey Nodes[])
{
	/**** Function Variables ****/
	char temp='0';
	size_t indexFind = 0;
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
			<< endl << "Total Questions = " << Nodes[(temp - '0') - 1].numberOfQuestions
			<< endl << "CheckBox Question = " << Nodes[(temp - '0') - 1].checkBoxQuestion;
		int i = 0;
		for (; i < (Nodes[(temp - '0') - 1].numberOfQuestionInt)- (Nodes[(temp - '0') - 1].checkBoxQuestion); i++)
		{
			cout << endl<< Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][0];
			
			/**** In Options we have to do Slicing ****/

			for (int j = 0; j < stoi(Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][1]); j++)
			{
				indexFind = (Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2]).find('~');
				cout << "\n\t\t\t"<< (Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2]).substr(0,indexFind);
			}

		}
		/**** Check Box Question ****/
		int k = 0;
		for (int j = i; j < (Nodes[(temp - '0') - 1].numberOfQuestionInt); j++)
		{
			if (k < (Nodes[(temp - '0') - 1].checkBoxQuestion))
			{
				cout << "\n" << j + 1 << numbering(j) << " Question : "<< (Nodes[(temp - '0') - 1].twoDMatrixQuestions[j][0]);
				cout << endl << "CheckBox Input !\n";
				indexFind = (Nodes[(temp - '0') - 1].twoDMatrixQuestions[j][2]).find('@');
				cout << (Nodes[(temp - '0') - 1].twoDMatrixQuestions[j][2]).substr(0,indexFind);
				
				
				k++;
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
			cout << i + 1 << "." << Nodes[i].titleOfSurvey << "\t";
		}
		cout << endl << "Enter The Survey ID : "; cin >> temp;
		while (temp<'0' || (temp - '0')>counterSurveys)
		{
			cout << "!! Invalid input !! Enter Again : ";
			cin >> temp;
		}
		/**** Saving the Survey IDS which are Responsed ****/
		responsedSurveys[responsingSurvey++] = temp - '0' - 1;
		/**** Saving the Survey IDS which are Responsed ****/
		cout << endl << "\t\t\t Survey - ID : " << temp;
		cout << endl << "Title : " << Nodes[(temp - '0') - 1].titleOfSurvey
			<< endl << "Description : " << Nodes[(temp - '0') - 1].descriptionOfSurvey
			<< endl << "Total Questions = " << Nodes[(temp - '0') - 1].numberOfQuestions
			<< endl << "Enter the Total Resposes Recieved : "; cin >> Nodes[(temp - '0') - 1].responses; responsesCounter= stoi(Nodes[(temp - '0') - 1].responses);

		while (stoi(Nodes[(temp - '0') - 1].responses)  < 0)
		{
			cout << "Responses Can Not Be Negative : "; cin >> Nodes[(temp - '0') - 1].responses;
		}
		
		int i = 0;
		for (; i < (Nodes[(temp - '0') - 1].numberOfQuestionInt)-(Nodes[(temp - '0') - 1].checkBoxQuestion); i++)
		{
			responsesCounter = stoi(Nodes[(temp - '0') - 1].responses);
			cout << endl <<"Question - "<<i+1<<" : \n" << Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][0];



			for (int j = 0; j < stoi(Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][1]); j++)
			{

				cout << "\n\t\t\t" << Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2];
				if(j+1== (stoi(Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][1])))
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
						while (stoi(temp2) < 0 || stoi(temp2)>responsesCounter)
						{
							cout << "Responses out of Range : "; cin >> temp2;
						}
						Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2] = Nodes[(temp - '0') - 1].twoDMatrixQuestions[i][j + 2] + "~" + temp2;
						responsesCounter = responsesCounter  - (stoi(temp2));
					}
					

				}
			}

		}
	
		int k = 0;
		for (int j = i; j < (Nodes[(temp - '0') - 1].numberOfQuestionInt); j++)
		{
			if (k < (Nodes[(temp - '0') - 1].checkBoxQuestion))
			{
				cout << "\n" << j + 1 << numbering(j) << " Question : " << (Nodes[(temp - '0') - 1].twoDMatrixQuestions[j][0]);
				cout << endl << "Data Has Been generated by the Public";
				srand(static_cast<unsigned int>(time(0)));
				for (int l = 0; l < stoi(Nodes[(temp - '0') - 1].responses); l++) Nodes[(temp - '0') - 1].twoDMatrixQuestions[j][2] = Nodes[(temp - '0') - 1].twoDMatrixQuestions[j][2]+"@"+to_string(rand() % 501); /**** Limit that will give me betewwen 100 ****/
				
				k++;
			}
		}


		
	}
}
// Function to print numbers separated by '@' from a string
void printNumbers( std::string& str) {
	std::string currentNumber;

	for (char ch : str) {
		if (std::isdigit(ch)) {
			currentNumber += ch;
		}
		else if (ch == '@' && !currentNumber.empty()) {
			std::cout << currentNumber << " "; // Print the complete number
			
			currentNumber.clear();  // Reset for the next number
		}
	}

	// Print the last number if any
	if (!currentNumber.empty()) {
		std::cout << currentNumber;
		
	}
}

void printNumbersForFile(const std::string& str)
{
	std::string currentNumber;

	for (char ch : str) {
		if (std::isdigit(ch)) {
			currentNumber += ch;
		}
		else if (ch == '@' && !currentNumber.empty()) {
			file << currentNumber << " "; // Print the complete number
			currentNumber.clear();  // Reset for the next number
		}
	}

	// Print the last number if any
	if (!currentNumber.empty()) {
		file << currentNumber;
	}
}
void Survey::printResSurvey(Survey Nodes[])
{
	/**** Function Variables ****/
	char temp = '0';
	size_t indexFind=0;
	string temp2 = "0";
	/**** Function Variables ****/
	if (counterSurveys == 0 || responsingSurvey==0) cout << endl << "Sorry! No Survey Created ";

	else
	{
		cout << endl << "\t\t\tAll Responded Surveys are Listed Below" << endl;
		for (int i = 0; i < responsingSurvey; i++)
		{
			cout << i + 1 << "." << Nodes[responsedSurveys[i]].titleOfSurvey << "\t";
		}
		cout << endl << "Enter The Responsed Survey ID : "; cin >> temp;
		while (temp<'0' || (temp - '0')>responsingSurvey)
		{
			cout << "!! Invalid input !! Enter Again : ";
			cin >> temp;
		}
		cout << endl << "\t\t\t Survey - ID : " << temp;
		cout << endl << "Title : " << Nodes[responsedSurveys[(temp - '0') - 1]].titleOfSurvey
			<< endl << "Description : " << Nodes[responsedSurveys[(temp - '0') - 1]].descriptionOfSurvey
			<< endl << "Total Questions = " << Nodes[responsedSurveys[(temp - '0') - 1]].numberOfQuestions
			<< endl << "CheckBox Questions = " << Nodes[responsedSurveys[(temp - '0') - 1]].checkBoxQuestion;
		int i = 0;
		for (; i < (Nodes[responsedSurveys[(temp - '0') - 1]].numberOfQuestionInt)- (Nodes[responsedSurveys[(temp - '0') - 1]].checkBoxQuestion); i++)
		{
			cout << endl <<"Question : " << i + 1 << Nodes[responsedSurveys[(temp - '0') - 1]].twoDMatrixQuestions[i][0];

			/**** In Options we have to do Slicing ****/

			for (int j = 0; j < stoi(Nodes[responsedSurveys[(temp - '0') - 1]].twoDMatrixQuestions[i][1]); j++)
			{
				
				indexFind = (Nodes[responsedSurveys[(temp - '0') - 1]].twoDMatrixQuestions[i][j + 2]).find('~');
				cout << "\n\t\t\t" << (Nodes[responsedSurveys[(temp - '0') - 1]].twoDMatrixQuestions[i][j + 2]).substr(0, indexFind)<<"\t\t\tResponses ="  << (Nodes[responsedSurveys[(temp - '0') - 1]].twoDMatrixQuestions[i][j + 2]).substr(indexFind + 1);
			}

		}
		/**** Check Box Question ****/
		int toHold = '0';
		int k = 0;
		for (int j = i; j < (Nodes[(temp - '0') - 1].numberOfQuestionInt); j++)
		{
			if (k < (Nodes[(temp - '0') - 1].checkBoxQuestion))
			{
				cout << "\n" << j + 1 << numbering(j) << " Question : " << (Nodes[(temp - '0') - 1].twoDMatrixQuestions[j][0]);
				cout << endl << "Data Extracted by the Public is hereunder,\n";
				
				
				
				indexFind = (Nodes[(temp - '0') - 1].twoDMatrixQuestions[j][2]).find('@');
				temp2 = (Nodes[(temp - '0') - 1].twoDMatrixQuestions[j][2]).substr(indexFind + 1);
				printNumbers(temp2);
				//printNumbers((Nodes[(temp - '0') - 1].twoDMatrixQuestions[j][2]));
				k++;
			}
		}
	}
}

/*** Dequeue Operation ****/
void QueueOfSurvey::dequeue()
{
	/**** Function Variables ****/
	string fileName = "";
	counterSurveys = counter;
	size_t indexFind = 0;
	/**** Function Variables ****/
	for (int i = front; i < (this->counter) ; i++)
	{
		file.open("D:\\SEMESTER-3\\DSA\\DSA Project\\Visual Studio Files\\DSA_Project\\DataBase\\Created_Surveys\\"+to_string(this->front+1)+"." + ".txt", ios::app); // file open

		file << "Survey ID : " << this->front + 1;
		file << endl << "Survey Title : " << Nodes[front].titleOfSurvey;
		file << endl << "Survey Description : " << Nodes[front].descriptionOfSurvey;
			file << endl << "Survey Questions : " << Nodes[front].numberOfQuestions;
		file << endl << "Check box Questions : " << Nodes[front].checkBoxQuestion;

		int k = 0;
		for (; k < (Nodes[front].numberOfQuestionInt) - (Nodes[front].checkBoxQuestion); k++)
		{
			file << endl << Nodes[front].twoDMatrixQuestions[k][0];
			file << endl << stoi(Nodes[front].twoDMatrixQuestions[k][1]);
			/**** In Options we have to do Slicing ****/

			for (int j = 0; j < stoi(Nodes[front].twoDMatrixQuestions[k][1]); j++)
			{
				
				file << "\n" << (Nodes[front].twoDMatrixQuestions[k][j + 2]);
			}

		}
		/**** Check Box Question ****/
		int n = 0;
		for (int j = k; j < (Nodes[front].numberOfQuestionInt); j++)
		{
			if (n < (Nodes[front].checkBoxQuestion))
			{
				file << "\n" << j + 1 << numbering(j) << " Question : " << (Nodes[front].twoDMatrixQuestions[j][0]);
				indexFind=Nodes[front].twoDMatrixQuestions[j][2].find("@");
				file << endl << "CheckBox Input : " << (Nodes[front].twoDMatrixQuestions[j][2]).substr(0,indexFind);

				n++;
			}
		}
		
		file << endl << "&";

		file.close();  // file Close 




		front++;
		
	}
	
	/**** in file we have to update global variable CounterSurveys ****/
}
/*** Dequeue Operation ****/
/**** Deleting Memory at End ****/
QueueOfSurvey::~QueueOfSurvey()
{
	delete[] Nodes;
}

void QueueOfSurvey::breakAll()
{
	surveyWhichResponsed = responsingSurvey;
	
}

void QueueOfSurvey::dequeueResponsed()
{
	/**** Function Variables ****/
	
	size_t indexFind = 0;
	/**** Function Variables ****/
	for (int i = surveyWhichResponsedAtThatTime; i < surveyWhichResponsed; i++)
	{
		file.open("D:\\SEMESTER-3\\DSA\\DSA Project\\Visual Studio Files\\DSA_Project\\DataBase\\Responsed_Surveys\\" + to_string(surveyWhichResponsedAtThatTime + 1) + "." + ".txt", ios::app); // file open

		file << "Survey ID : "<<surveyWhichResponsedAtThatTime + 1;
		file << endl<<"Survey Title : " << Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].titleOfSurvey;
		file << endl << "Survey Description : " << Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].descriptionOfSurvey;
		file << endl << "Survey Questions : " << Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].numberOfQuestions;
		file << endl << "CheckBox Questions : " << Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].checkBoxQuestion;

		int k = 0;
		for (; k < (Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].numberOfQuestionInt) - (Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].checkBoxQuestion); k++)
		{
			file << endl << Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].twoDMatrixQuestions[k][0];

			/**** In Options we have to do Slicing ****/

			for (int j = 0; j < stoi(Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].twoDMatrixQuestions[k][1]); j++)
			{
				
				file << endl << (Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].twoDMatrixQuestions[k][j + 2]);
				cout << (Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].twoDMatrixQuestions[k][j + 2]);
				
			}

		}
		/**** Check Box Question ****/
		int toHold = '0';
		int l = 0;
		for (int j = k; j < (Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].numberOfQuestionInt); j++)
		{
			if (l < (Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].checkBoxQuestion))
			{
				file << "\n" << j + 1 << numbering(j) << " Question : " << (Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].twoDMatrixQuestions[j][0]);
				file << endl << "Data Extracted by the Public is here under,";



				file << endl << (Nodes[responsedSurveys[surveyWhichResponsedAtThatTime]].twoDMatrixQuestions[j][2]);

				
				l++;
			}
		}
		surveyWhichResponsedAtThatTime++;
		file.close();



		

	}
}
void QueueOfSurvey::save_important_file()
{
	
	file.open("D:\\SEMESTER-3\\DSA\\DSA Project\\Visual Studio Files\\DSA_Project\\DataBase\\Important Data.txt", ios::out);
	
	file << this->counter;		/**** for the Counter which is used in Comparing it is used ****/
	file <<endl<< this->front;		/**** for the Survey Questions we will update front by this ****/

	file << endl << surveyWhichResponsed;		/*** in comparison ****/
	file << endl << surveyWhichResponsedAtThatTime; /*** used in Assigning ****/

	/***** responsed Survey Indexes ****/
	file<< endl;
	if(surveyWhichResponsed!=0)	
		for (int i = 0; i < surveyWhichResponsed; i++) file << responsedSurveys[i] << endl;
	file.close();

}

int QueueOfSurvey::fileRead()
{

	string fileData = "0";
	size_t indexFind = 0;
	/**** Firstly we will take the important data ****/
	// if important file is there then we know that there has been data because it has been created at end of file on first time
	file.open("D:\\SEMESTER-3\\DSA\\DSA Project\\Visual Studio Files\\DSA_Project\\DataBase\\Important Data.txt", ios::in);
	if (file)
	{
		getline(file, fileData);
		this->counter = stoi(fileData);
		counterSurveys = this->counter;
		getline(file, fileData);
		this->front = stoi(fileData);

		getline(file, fileData);
		this->surveyWhichResponsed = stoi(fileData);

		getline(file, fileData);
		surveyWhichResponsedAtThatTime = stoi(fileData);
		responsingSurvey = surveyWhichResponsedAtThatTime;
			
		for (int i = 0; i < surveyWhichResponsed; i++)
		{
			getline(file, fileData);
			responsedSurveys[i] = stoi(fileData);
			
		}
	}
	else return 0;
	file.close();
	/**** Now we will take the data for Creating Surveys ****/	
	
	for (int i = 0; i < (this->counter); i++)
	{
		file.open("D:\\SEMESTER-3\\DSA\\DSA Project\\Visual Studio Files\\DSA_Project\\DataBase\\Created_Surveys\\" + to_string(i + 1) + "." + ".txt", ios::in); // file open
		
		getline(file, fileData);
		
		getline(file, fileData);
		indexFind = fileData.find(": ");
		this->Nodes[i].titleOfSurvey = fileData.substr(indexFind + 2);
		
		getline(file, fileData);
		indexFind = fileData.find(": ");
		this->Nodes[i].descriptionOfSurvey = fileData.substr(indexFind + 2);
		
		getline(file, fileData);
		
		indexFind = fileData.find(": ");
		this->Nodes[i].numberOfQuestions = fileData.substr(indexFind + 2);  this->Nodes[i].numberOfQuestionInt = stoi(this->Nodes[i].numberOfQuestions);
	
		
		getline(file, fileData);
		indexFind = fileData.find(": ");
		this->Nodes[i].checkBoxQuestion = stoi(fileData.substr(indexFind + 2));

		
		int k = 0;
		for (; k < (Nodes[i].numberOfQuestionInt) - (Nodes[i].checkBoxQuestion); k++)
		{
			getline(file, fileData);
			
			this->Nodes[i].twoDMatrixQuestions[k][0] = fileData;
		
			getline(file, fileData);
			this->Nodes[i].twoDMatrixQuestions[k][1] =fileData;
	
			
			/**** In Options we have to do Slicing ****/
			
			for (int j = 0; j < stoi(Nodes[i].twoDMatrixQuestions[k][1]); j++)
			{
				
				getline(file, fileData);
			indexFind = fileData.find("~");
				this->Nodes[i].twoDMatrixQuestions[k][j + 2] = fileData.substr(indexFind+1);
				
			}

		}
		/**** Check Box Question ****/
		int n = 0;
		for (int j = k; j < (Nodes[i].numberOfQuestionInt); j++)
		{
			if (n < (Nodes[i].checkBoxQuestion))
			{
				getline(file, fileData);
				indexFind = fileData.find(": ");
				Nodes[i].twoDMatrixQuestions[j][0]= fileData.substr(indexFind + 2);

				getline(file, fileData);
				indexFind = fileData.find(": ");
				Nodes[i].twoDMatrixQuestions[j][2]= fileData.substr(indexFind + 2);

				getline(file, fileData);
				n++;
			}
		}

		

		file.close();  // file Close 
	}
	
	/**** Now we will take the data for Responded Surveys ****/

	
	
	for (int i = 0; i < surveyWhichResponsed; i++)
	{
		file.open("D:\\SEMESTER-3\\DSA\\DSA Project\\Visual Studio Files\\DSA_Project\\DataBase\\Responsed_Surveys\\" + to_string(i+ 1) + "." + ".txt", ios::in); // file open

		getline(file, fileData);
		
		getline(file, fileData);
		
		getline(file, fileData);
		

		getline(file, fileData);
		

		getline(file, fileData);
		

		int k = 0;
		for (; k < (Nodes[responsedSurveys[i]].numberOfQuestionInt) - (Nodes[responsedSurveys[i]].checkBoxQuestion); k++)
		{
			getline(file, fileData);
			Nodes[responsedSurveys[i]].twoDMatrixQuestions[k][0] = fileData;
			

			/**** In Options we have to do Slicing ****/

			for (int j = 0; j < stoi(Nodes[responsedSurveys[i]].twoDMatrixQuestions[k][1]); j++)
			{
				getline(file , fileData);
				
				(Nodes[responsedSurveys[i]].twoDMatrixQuestions[k][j + 2]) = fileData;
				

			}

		}
		/**** Check Box Question ****/
		int toHold = '0';
		int l = 0;
		for (int j = k; j < (Nodes[responsedSurveys[i]].numberOfQuestionInt); j++)
		{
			if (l < (Nodes[responsedSurveys[i]].checkBoxQuestion))
			{
				getline(file, fileData);
				indexFind = fileData.find(": ");
				(Nodes[responsedSurveys[i]].twoDMatrixQuestions[j][0]) = fileData.substr(indexFind + 2);
				
				getline(file, fileData);
			

				getline(file, fileData);
				(Nodes[responsedSurveys[i]].twoDMatrixQuestions[j][2]) = fileData;


				
				l++;
			}
		}
		
		file.close();





	}
	

}