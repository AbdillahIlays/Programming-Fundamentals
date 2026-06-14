#include<iostream>
#include<string>
#include<cctype>
#include<iomanip>
#include<fstream>

using namespace std;

const int MAX = 60; //Maximum Strength of Class
int StdCount = 0;
int TotalMarks = 310; //3 Quizzes of 10*3, 2 assignments of 100*2, Mid of 30 and Final of 50

struct Student
{
	string name;
	int Roll_No;
	char Section;
	double Quiz[3];
	double Assignment[2];
	double Mid;
	double Final;



}STUDENTS[MAX];


void menu();

void Add();

void DisplayStd();

void DisplayTabular();

void Update();

void SearchByRollNumber();

void PerformanceCalculation();

void Topper();

void ClassPerformance();

double Calculate_Obtained_Marks(int index);

char Calculate_Grade(double Percentage);

void Delete();

void StoreData();

void LoadData();

void SortByPercentage();

int main()
{

	cout << "\"This System can Store Records of Maximum 60 Students.\"\n";

	LoadData();
	int choice;



	do {

		menu();
		cout << "Enter your choice : ";
		cin >> choice;

		while (choice < 1 || choice>12 || cin.fail())
		{

			cin.clear(); // will clear the error falg if any
			cin.ignore(1000, '\n'); //will ignore first 1000 characters or characters until \n from buffer 

			cout << "Invalid Input.\nEnter Again : ";
			cin >> choice;
		}

		if (choice == 1)
		{
			if (StdCount == MAX) cout << "Limit exceeded. No more records can be entered.\n";
			else Add();
		}
		else if (choice == 2)
		{
			PerformanceCalculation();
		}

		else if (choice == 3)
		{
			DisplayStd();
		}
		else if (choice == 4)
		{
			Topper();
		}
		else if (choice == 5)
		{
			SearchByRollNumber();
		}
		else if (choice == 6)
		{
			ClassPerformance();
		}
		else if (choice == 7)
		{
			DisplayTabular();
		}
		else if (choice == 8)
		{
			StoreData();
		}
		else if (choice == 9)
		{
			Update();
		}
		else if (choice == 10)
		{
			Delete();
		}

		else if (choice == 11)
		{
			SortByPercentage();
		}

		else
		{
			cout << "Thank You!";
		}


		cout << endl << endl << "\a";




	} while (choice != 12);




	cout << endl;
	system("pause");
	return 0;
}
void menu()
{
	cout << "1:  Add a Student\n2:  Performance Calculations\n3:  Display All Recordeds in Detail\n4:  Find Topper\n5:  Search by Roll Number\n6:  Class Performance\n7:  Display in Tabular View\n8:  Store data\n9:  Update a Record\n10: Delete a Record\n11: Sort By Percentage\n12: Exit" << endl << endl;

}
void Add()
{
	bool notAlpha;
	do {

		notAlpha = false;

		cin.ignore(1000, '\n');
		cout << "Enter name of Student : ";
		getline(cin, STUDENTS[StdCount].name);

		for (int i = 0; STUDENTS[StdCount].name[i] != '\0'; i++)
		{
			if (!isalpha(STUDENTS[StdCount].name[i]) && !isspace(STUDENTS[StdCount].name[i]))
			{
				notAlpha = true;
				break;
			}
		}

		if (notAlpha) cout << "Please Enter alphabetic Name.\n";

	} while (notAlpha);

get:
	cout << "Enter Student's Roll Number : ";
	cin >> STUDENTS[StdCount].Roll_No;

	if (StdCount > 0)
	{
		for (int i = 0; i < StdCount; i++)
		{
			if (STUDENTS[StdCount].Roll_No == STUDENTS[i].Roll_No)
			{
				cout << "Roll Number Already exists.\n";
				goto get;
			}

		}
	}
	while (STUDENTS[StdCount].Roll_No < 1 || STUDENTS[StdCount].Roll_No >60 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid Roll Number.\n";
		cout << "Enter Student's Roll Number : ";
		cin >> STUDENTS[StdCount].Roll_No;
	}

	cout << "Enter Student's Section (A-H) : ";
	cin.ignore(1000, '\n');
	cin >> STUDENTS[StdCount].Section;

	while ((STUDENTS[StdCount].Section < 'A' || STUDENTS[StdCount].Section > 'H') && (STUDENTS[StdCount].Section < 'a' || STUDENTS[StdCount].Section > 'h'))
	{
		cin.ignore(1000, '\n');
		cout << "Invalid Input. Enter Sections Between A-H : ";
		cin >> STUDENTS[StdCount].Section;
	}

	if (islower(STUDENTS[StdCount].Section)) STUDENTS[StdCount].Section = toupper(STUDENTS[StdCount].Section);

	cin.ignore(1000, '\n');
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter marks in Quiz " << i + 1 << "(0-10) : ";
		cin >> STUDENTS[StdCount].Quiz[i];

		while (STUDENTS[StdCount].Quiz[i] < 0 || STUDENTS[StdCount].Quiz[i] > 10 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Invalid Inputs.\n";
			cout << "Enter marks in Quiz " << i + 1 << "(0-10) : ";
			cin >> STUDENTS[StdCount].Quiz[i];
		}
	}

	for (int i = 0; i < 2; i++)
	{
		cout << "Enter marks in Assignment " << i + 1 << "(0-100) : ";
		cin >> STUDENTS[StdCount].Assignment[i];

		while (STUDENTS[StdCount].Assignment[i] < 0 || STUDENTS[StdCount].Assignment[i] > 100 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Invalid Inputs.\n";
			cout << "Enter marks in Assignment " << i + 1 << "(0-100) : ";
			cin >> STUDENTS[StdCount].Assignment[i];
		}
	}

	cout << "Enter Student's Marks in Mid (0-30) : ";
	cin >> STUDENTS[StdCount].Mid;

	while (STUDENTS[StdCount].Mid < 0 || STUDENTS[StdCount].Mid >30 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Invalid Input.\n";
		cout << "Enter Student's Marks in Mid (0-30) : ";
		cin >> STUDENTS[StdCount].Mid;
	}
	cout << "Enter Student's Marks in Final Exam (0-50) : ";
	cin >> STUDENTS[StdCount].Final;

	while (STUDENTS[StdCount].Final < 0 || STUDENTS[StdCount].Final >50 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Invalid Input.\n";
		cout << "Enter Student's Marks in Final (0-50) : ";
		cin >> STUDENTS[StdCount].Final;
	}

	cout << "\033[30m\033[47m\"Your Record is Added Successfully!\"\033[0m" << endl;


	StdCount++;
}
void DisplayStd()
{
	cout << endl;
	for (int i = 0;i < 60;i++) cout << "* ";
	cout << endl;
	if (StdCount == 0) cout << "No Record Found.\n";
	else
	{
		for (int i = 0; i < StdCount; i++)
		{
			cout << "\033[4mStudent " << i + 1 << "\033[0m :-" << endl<<endl;
			cout << "Student's Name : " << STUDENTS[i].name << endl;
			cout << "Student's Roll Number : " << STUDENTS[i].Roll_No << endl;
			cout << "Student's Section : " << STUDENTS[i].Section << endl<<endl;
			cout << "Student's Quiz Marks out of 10 :- " << endl<<endl;

			for (int j = 0; j < 3; j++)
				cout << "Quiz " << j + 1 << " : " << STUDENTS[i].Quiz[j] << endl;
			cout << endl <<"Student's Assignment Marks out of 100 :- " << endl<<endl;
			for (int j = 0; j < 2; j++)
				cout << "Assignment " << j + 1 << " : " << STUDENTS[i].Assignment[j] << endl;

			cout <<endl <<"Student's Mid Marks out of 30 : " << STUDENTS[i].Mid << endl;
			cout << "Student's Final Marks out of 50 : " << STUDENTS[i].Final << endl<<endl;



		}
	}

	for (int i = 0;i < 60;i++) cout << "* ";
	cout << endl<<endl;


}
void Update()
{

	if (StdCount == 0)
	{
		cout << "There is no record of any Student.\n";
		return;
	}
	int roll;
	cout << "Enter Roll Number of Student : ";
	cin >> roll;

	while (roll < 1 || roll>60 || cin.fail())
	{

		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Invalid Roll Number.\n";
		cout << "Enter Roll Number of Student : ";
		cin >> roll;
	}

	bool exist = false;
	int index;

	for (int i = 0; i < StdCount; i++)
	{
		if (STUDENTS[i].Roll_No == roll)
		{
			exist = true;
			index = i;
			break;
		}
	}

	if (!exist)
	{
		cout << "Record doesn't found.";
		return;
	}

	cout << "Now you can Update Record of Student having roll number " << roll << endl;

	cout << "Student's Name is : " << STUDENTS[index].name << endl;

	char ch;

	cout << "Do you want to change name? (y-yes, any other key for NO) : ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		cin.ignore(1000, '\n');
		cout << "Enter new Name : ";
		getline(cin, STUDENTS[index].name);
	}

	cout << "Do you want to change Section? (y-yes, any other key for NO) : ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		cout << "Enter new Section : ";
		cin >> STUDENTS[index].Section;

		while ((STUDENTS[index].Section < 'A' || STUDENTS[index].Section > 'H') && (STUDENTS[index].Section < 'a' || STUDENTS[index].Section > 'h'))
		{
			cout << "Invalid Input. Enter Sections Between A-H : ";
			cin >> STUDENTS[index].Section;
		}

		if (islower(STUDENTS[index].Section)) STUDENTS[index].Section = toupper(STUDENTS[index].Section);
	}

	cin.ignore(1000, '\n');
	cout << "Do you want to change Quiz' Marks? (y-yes, any other key for NO) : ";
	cin >> ch;

	if (ch == 'y' || ch == 'Y')
	{
		for (int a = 0; a < 3; a++)
		{
			char quizz;

			cout << "Do you want to change marks of Quiz " << a + 1 << " ? (y-yes, any other key for NO) : ";
			cin >> quizz;


			if (quizz == 'y' || quizz == 'Y')
			{
				cout << "Enter new marks in Quiz " << a + 1 << " : ";
				cin >> STUDENTS[index].Quiz[a];

				while (STUDENTS[index].Quiz[a] < 0 || STUDENTS[index].Quiz[a] > 10 || cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');

					cout << "Invalid Inputs.\n";
					cout << "Enter marks in Quiz again " << a + 1 << "(0-10) : ";
					cin >> STUDENTS[index].Quiz[a];
				}

			}
			else continue;
		}

	}

	cout << "Do you want to change Assignments' Marks? (y-yes, any other key for NO) : ";
	cin >> ch;

	if (ch == 'y' || ch == 'Y')
	{
		for (int a = 0; a < 2; a++)
		{
			char ass;

			cout << "Do you want to change marks of Assignment " << a + 1 << " ? (y-yes, any other key for NO) : ";
			cin >> ass;


			if (ass == 'y' || ass == 'Y')
			{
				cout << "Enter new marks in Assignment " << a + 1 << " : ";
				cin >> STUDENTS[index].Assignment[a];


				while (STUDENTS[index].Assignment[a] < 0 || STUDENTS[index].Assignment[a] > 100 || cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');

					cout << "Invalid Inputs.\n";
					cout << "Enter marks in Assignment again " << a + 1 << "(0-100) : ";
					cin >> STUDENTS[index].Assignment[a];
				}


			}
			else continue;



		}

	}


	cout << "Do you want to change Mid Marks? (y-yes, any other key for NO) : ";
	cin >> ch;

	if (ch == 'y' || ch == 'Y')
	{
		cout << "Enter new marks in Mid : ";
		cin >> STUDENTS[index].Mid;

		while (STUDENTS[index].Mid < 0 || STUDENTS[index].Mid>30 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Invalid Input.\n";
			cout << "Enter new marks in Mid : ";
			cin >> STUDENTS[index].Mid;
		}
	}

	cout << "Do you want to change Final Marks? (y-yes, any other key for NO) : ";
	cin >> ch;

	if (ch == 'y' || ch == 'Y')
	{
		cout << "Enter new marks in Final Exam : ";
		cin >> STUDENTS[index].Final;

		while (STUDENTS[index].Final < 0 || STUDENTS[index].Final>50 || cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Invalid Input.\n";
			cout << "Enter new marks in Final : ";
			cin >> STUDENTS[index].Final;
		}
	}

	cout << "\033[30m\033[47m\"Record Updated Successfully.\"\033[0m\a"<<endl<<endl;
	StoreData();



}


void DisplayTabular()
{

	cout << endl;

	cout << "| " << left << setw(10) << "Roll_No" << setw(30) << "| Name"
		<< setw(10) << "| Section" << setw(10) << "| Marks" << setw(15) << "| Percentage" << setw(8) << "| Grade" << endl << endl;

	cout << fixed << setprecision(2) << left;

	for (int i = 0;i < StdCount;i++)
	{
		double Obtained = Calculate_Obtained_Marks(i);
		double Per = (Obtained / TotalMarks) * 100;

		cout << "| " << left << setw(10) << STUDENTS[i].Roll_No << "| " << setw(28) << STUDENTS[i].name
			<< "| " << setw(8) << STUDENTS[i].Section << "| " << setw(8) << Obtained << "| " << setw(13) << Per << "| " << setw(6) << Calculate_Grade(Per) << endl;
	}

}




void SearchByRollNumber()
{

	int roll;
	double Obtained, Per;
	char Grade;

	cout << "Enter Roll Number of Student : ";
	cin >> roll;

	while (roll < 1 || roll>60 || cin.fail())
	{

		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Invalid Roll Number.\n";
		cout << "Enter Roll Number of Student : ";
		cin >> roll;
	}

	bool exist = false;
	int index;

	for (int i = 0; i < StdCount; i++)
	{
		if (STUDENTS[i].Roll_No == roll)
		{
			exist = true;
			index = i;
			break;
		}
	}

	if (!exist)
	{
		cout << "Record doesn't found.";
		return;
	}

	cout << endl;
	for (int i = 0;i < 60;i++) cout << "* ";
	cout << endl;

	cout << "Student's Name : " << STUDENTS[index].name << endl;

	cout << "Section : " << STUDENTS[index].Section << endl<<endl;
	cout << "Quiz Marks out of 10 :- " << endl<<endl;

	for (int j = 0; j < 3; j++)
		cout << "Quiz " << j + 1 << " : " << STUDENTS[index].Quiz[j] << endl;
	cout << endl<<"Assignment Marks out of 100 :- " << endl<<endl;
	for (int j = 0; j < 2; j++)
		cout << "Assignment " << j + 1 << " : " << STUDENTS[index].Assignment[j] << endl;

	cout << endl<<"Mid Marks out of 30 : " << STUDENTS[index].Mid << endl;
	cout << "Final Marks out of 50 : " << STUDENTS[index].Final << endl<<endl;

	Obtained = Calculate_Obtained_Marks(index);
	Per = (Obtained / TotalMarks) * 100;


	//Overall Performance of Student


	cout << "Total Obtained Marks : " << Obtained << endl;
	cout << fixed << setprecision(2) << "Percentage : " << Per << endl;
	cout << "Grade : " << Calculate_Grade(Per) << endl;

	cout << endl;
	for (int i = 0;i < 60;i++) cout << "* ";
	cout << endl;


}

void PerformanceCalculation()
{

	if (StdCount == 0)
	{
		cout << "No Record Found.\n";
		return;
	}

	cout << endl;
	for (int i = 0;i < 60;i++) cout << "* ";
	cout << endl<<endl;

	for (int i = 0; i < StdCount;i++)
	{
		double Obtained_Marks = 0, Percentage = 0;
		char Grade;

		Obtained_Marks = Calculate_Obtained_Marks(i);/*called function and passed index of the student
		whose Obtained Marks are to be calculated*/

		Percentage = (Obtained_Marks / TotalMarks) * 100;


		Grade = Calculate_Grade(Percentage);


		cout << setprecision(2) << fixed;
		cout << "Student Name : " << STUDENTS[i].name << "--->Roll Number : " << STUDENTS[i].Roll_No << "--->Total Obtained Marks : " << Obtained_Marks << "--->Percentage : " << Percentage << "--->Grade : " << Grade << endl;
	}
	cout << endl;
	for (int i = 0;i < 60;i++) cout << "* ";
	cout << endl;
}

void Topper()
{
	double MaxPer = 0;
	int topper[MAX]; //Making Array bcz there can be multiple toppers
	int topCount = 0;

	if (StdCount == 0)
	{
		cout << "No record Found.\n";
		return;
	}

	for (int i = 0; i < StdCount;i++)
	{
		double Obtained_Marks = 0, Percentage = 0;

		Obtained_Marks = Calculate_Obtained_Marks(i);
		Percentage = (Obtained_Marks / TotalMarks) * 100;

		if (Percentage > MaxPer) MaxPer = Percentage;

	}

	for (int i = 0;i < StdCount;i++)
	{
		double Obtained = 0, Per = 0;

		Obtained = Calculate_Obtained_Marks(i);
		Per = (Obtained / TotalMarks) * 100;

		if (Per == MaxPer)
		{
			topper[topCount++] = i;
		}
	}

	cout << fixed << setprecision(2) << "Total number of Toppers with Maximum Percentage of " << MaxPer << "% : " << topCount << endl << endl;
	cout << "\033[30m\033[47mName | Roll Number | Section\033[0m" << endl << endl;

	for (int i = 0;i < topCount;i++)
	{
		cout << STUDENTS[topper[i]].name << " | " << STUDENTS[topper[i]].Roll_No << " | " << STUDENTS[topper[i]].Section << endl << endl;
	}
}

void ClassPerformance()
{
	if (StdCount == 0)
	{
		cout << "No Student Found.\n";
		return;
	}


	for (int i = 0;i < 40;i++) cout << "* ";
	cout << endl;

	double Q1_Total = 0, Q2_Total = 0, Q3_Total = 0;
	double A1_Total = 0, A2_Total = 0;
	double MidTotal = 0, FinalTotal = 0, Obtained_Marks;
	double Class_Percentage = 0, Percentage, MaxPer = 0, MinPer = 100;
	double MinMid = 30, MaxMid = 0, MinFinal = 50, MaxFinal = 0;

	for (int i = 0;i < StdCount;i++)
	{
		Percentage = 0, Obtained_Marks = 0;

		Obtained_Marks = Calculate_Obtained_Marks(i);
		Percentage = (Obtained_Marks / TotalMarks) * 100;
		Class_Percentage += Percentage;

		if (Percentage > MaxPer) MaxPer = Percentage;
		if (Percentage < MinPer) MinPer = Percentage;

		Q1_Total += STUDENTS[i].Quiz[0]; //will divide these quizzes no. of students to get average marks
		Q2_Total += STUDENTS[i].Quiz[1];
		Q3_Total += STUDENTS[i].Quiz[2];

		A1_Total += STUDENTS[i].Assignment[0]; //will divide these Assignments no. of students to get average marks
		A2_Total += STUDENTS[i].Assignment[1];

		if (STUDENTS[i].Mid > MaxMid) MaxMid = STUDENTS[i].Mid;
		if (STUDENTS[i].Mid < MinMid) MinMid = STUDENTS[i].Mid;

		if (STUDENTS[i].Final > MaxFinal) MaxFinal = STUDENTS[i].Final;
		if (STUDENTS[i].Final < MinFinal) MinFinal = STUDENTS[i].Final;

		MidTotal += STUDENTS[i].Mid;
		FinalTotal += STUDENTS[i].Final;
	}

	double Avg = Class_Percentage / StdCount;

	cout << "Maximum Percentage in Class : " << MaxPer << endl;
	cout << "Minimum Percentage in Class : " << MinPer << endl;
	cout << "Class Average Percentage : " << Avg << endl<<endl;

	cout << "Quiz 1 Average Marks : " << Q1_Total / StdCount << endl;
	cout << "Quiz 2 Average Marks : " << Q2_Total / StdCount << endl;
	cout << "Quiz 3 Average Marks : " << Q3_Total / StdCount << endl<<endl;

	cout << "Assignment 1 Average Marks : " << A1_Total / StdCount << endl;
	cout << "Assignment 2 Average Marks : " << A2_Total / StdCount << endl<<endl;

	cout << "Maximum Marks in Mid : " << MaxMid << endl;
	cout << "Minimum Marks in Mid : " << MinMid << endl;
	cout << "Average Marks in Mid : " << MidTotal / StdCount << endl<<endl;

	cout << "Maximum Marks in Final : " << MaxFinal << endl;
	cout << "Minimum Marks in FInal : " << MinFinal << endl;
	cout << "Average Marks in Final : " << FinalTotal / StdCount << endl<<endl;


	for (int i = 0;i < 40;i++) cout << "* ";
	cout << endl;
}

void Delete()
{
	if (StdCount == 0)
	{
		cout << "No Record found.\n";
		return;
	}

	int roll;
	cout << "Enter Roll Number of Student : ";
	cin >> roll;

	while (roll < 1 || roll>60 || cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Invalid Input.\n";
		cout << "Enter Valid Roll Number : ";
		cin >> roll;
	}

	int index;
	bool found = false;

	for (int i = 0;i < StdCount;i++)
	{
		if (STUDENTS[i].Roll_No == roll)
		{
			found = true;
			index = i; //If found.. Get the index of the student where it lies in array and then start further processing
			break;
		}
	}

	if (!found)
	{
		cout << "Record Not Found.\n";
		return;
	}

	cout << "Student's Name is : " << STUDENTS[index].name << endl;
	cout << "Processing............" << endl;

	for (int i = index;i < StdCount - 1;i++)
	{
		STUDENTS[i] = STUDENTS[i + 1];
	}
	cout << "\033[30m\033[47m\"Record Deleted Successfully.\"\033[0m";
	STUDENTS[StdCount - 1] = Student{}; //Now the record has been deleted and the last one containes empty values
	StdCount--;
	
}

void StoreData()
{
	ofstream intoFile("Student_Data.txt");
	if (!intoFile.is_open())
	{
		cout << "Error Occured. Data couldn't get saved.\n";
		return;
	}


	intoFile << "Roll_No | Name | Section | Quiz1 | Quiz2 | Quiz3 | Assignment1 | Assignment2 | Mid | Final" << endl;

	for (int i = 0; i < StdCount; i++)
	{

		string TName = STUDENTS[i].name; /*initializing to a new variable because there may be
		spaces in name and while loading it will read name without spaces */

		for (int j = 0;TName[j] != '\0';j++)
		{
			if (TName[j] == ' ') TName[j] = '_';
		}

		intoFile << STUDENTS[i].Roll_No << " " << TName << " " << STUDENTS[i].Section << " ";

		for (int j = 0; j < 3; j++)
			intoFile << STUDENTS[i].Quiz[j] << " ";

		for (int j = 0; j < 2; j++)
			intoFile << STUDENTS[i].Assignment[j] << " ";

		intoFile << STUDENTS[i].Mid << " " << STUDENTS[i].Final << endl;
	}

	intoFile.close();
	cout << "\033[30m\033[47m\"Data saved successfully!\ " << StdCount << " records stored.\"\033[0m\n";
}

void LoadData()
{
	ifstream FromFile("Student_Data.txt");

	if (!FromFile.is_open())
	{
		cout << "No Data Found. File Not Opened.\n";
		return;
	}

	string Head;
	getline(FromFile, Head);

	StdCount = 0;
	while (FromFile >> STUDENTS[StdCount].Roll_No && StdCount < MAX)
	{
		if (StdCount >= MAX) break;

		FromFile >> STUDENTS[StdCount].name;

		for (int j = 0;STUDENTS[StdCount].name[j] != '\0';j++)
		{
			if (STUDENTS[StdCount].name[j] == '_') STUDENTS[StdCount].name[j] = ' ';
		}

		FromFile >> STUDENTS[StdCount].Section;

		for (int i = 0;i < 3;i++) FromFile >> STUDENTS[StdCount].Quiz[i];
		for (int i = 0;i < 2;i++) FromFile >> STUDENTS[StdCount].Assignment[i];

		FromFile >> STUDENTS[StdCount].Mid >> STUDENTS[StdCount].Final;

		StdCount++;
	}

	FromFile.close();

	cout << "\033[30m\033[47m";
	if (StdCount > 0) cout << "\"Successfully Loaded Data of " << StdCount << " Students.\"\n";
	else cout << "\"No Record was Loaded.\"\n";
	cout << "\033[0m";






}
void SortByPercentage()
{

	if (StdCount == 0)
	{
		cout << "No records to sort.\n";
		return;
	}

	for (int i = 0;i < StdCount - 1;i++) //using bubble sort technique to sort in descending order
	{
		for (int j = 0;j < StdCount - i - 1;j++)
		{
			double per1 = (Calculate_Obtained_Marks(j) / TotalMarks) * 100;
			double per2 = (Calculate_Obtained_Marks(j + 1) / TotalMarks) * 100;

			if (per2 > per1)
			{
				Student temp = STUDENTS[j];
				STUDENTS[j] = STUDENTS[j + 1];
				STUDENTS[j + 1] = temp;
			}
		}
	}

	cout << "\033[30m\033[47m\"Students have been Sorted in descending order according to Percentage!\"\033[0m" << endl;
	DisplayTabular();
	cout << endl;



}


double Calculate_Obtained_Marks(int index)

{

	double  Obtained_Marks = 0;

	for (int j = 0;j < 3;j++) Obtained_Marks += STUDENTS[index].Quiz[j]; // Adding Quiz Marks into total obtained marks
	for (int j = 0;j < 2;j++) Obtained_Marks += STUDENTS[index].Assignment[j]; // Adding Assignment Marks into total obtained marks

	Obtained_Marks += STUDENTS[index].Mid + STUDENTS[index].Final; // Adding Mid and Final Marks into total obtained marks

	return Obtained_Marks; //Returning toal obtained marks to the function that called it
}

char Calculate_Grade(double Percentage)
{
	char Grade;

	if (Percentage >= 83) Grade = 'A';
	else if (Percentage >= 75) Grade = 'B';
	else if (Percentage >= 65) Grade = 'C';
	else if (Percentage >= 50) Grade = 'D';
	else Grade = 'F';

	//E grade is not required in the requirements

	return Grade;

}