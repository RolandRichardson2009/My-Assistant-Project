#include <iostream>
#include<fstream>
#include<string>

using namespace std;

void delete_line(const char* file_name, int n)
{
	// open file in read mode or in mode 
	ifstream is(file_name);

	// open file in write mode or out mode 
	ofstream ofs;
	ofs.open("temp.txt", ofstream::out);

	// loop getting single characters 
	char c;
	int line_no = 1;
	while (is.get(c))
	{
		// if a newline character 
		if (c == '\n')
			line_no++;

		// file content not to be deleted 
		if (line_no != n)
			ofs << c;
	}

	// closing output file 
	ofs.close();

	// closing input file 
	is.close();

	// remove the original file 
	remove(file_name);

	// rename the file 
	rename("temp.txt", file_name);
}

int main()
{

	//Define variable userInputVar so that 
	//it can be used in game loop to 
	//end loop if needed.
	char userInputVar = ' ';
	fstream myFile;
	string search;
	string fullUserStatementVar;
	string* fullUserStatementPtr;
	fullUserStatementPtr = &fullUserStatementVar;
	int offset;
	string line;
	ifstream Myfile;
	int currentIndexVar = 1;
	int* currentIndexPtr;
	currentIndexPtr = &currentIndexVar;

	//Begin application loop
	do
	{
		system("cls");
		cout << "Please choose an option from the following choices:\n";
		cout << "1. Hey Assistant, can you remember something for me?\n";
		cout << "2. Hey Assistant, I have a question.\n";
		cout << "3. Hey Assistant, list all my notes.\n";
		cout << "4. Hey Assistant, remove one of my notes.\n";
		cout << "5. I'm done.\n";
		cin >> userInputVar;

		switch (userInputVar)
		{
		case '1':

			//////////////////Demonstrate how to write the contents from the display to a file.////////////////////////////

			//Appending an existing File
			//Begin Appending to File//////////////////////////////////////////////////////////////////////////////////////


			myFile.open("example.txt", ios::app);//write
			if (myFile.is_open())
			{
				cin.ignore();
				cout << "Please tell me what you want me to remember!\n";
				getline(cin, fullUserStatementVar);
				myFile << fullUserStatementVar << endl;
				myFile.close();
			}
			//End Write to File//////////////////////////////////////////////////////////////////////////////////////

			break;

		case '2':

			////////////////////////TASK: Demonstrate how to search the data in a file.////////////////////////////////

			//Begin Search File////////////////////////////////////////////////////////////////////////////////////////////
			Myfile.open("example.txt");
			cout << "What can I look up for you?\n";
			cin >> search;
			if (Myfile.is_open())
			{
				while (!Myfile.eof())
				{
					getline(Myfile, line);
					if ((offset = line.find(search, 0)) != string::npos)
					{
						cout << "Entry " << currentIndexVar << ": ";
						cout << line << endl;
					}
					currentIndexVar++;
				}
				currentIndexVar = 1;
				Myfile.close();
			}
			else
				cout << "File opening error" << endl;
			system("pause");
			//End Search File/////////////////////////////////////////////////////////////////////////////////////////////

			break;

		case '3':
			cout << "These are the notes I have saved for you...\n";

			//Read from File

	/////////////////////////////////////////////////////////////////////////////////////////

			myFile.open("example.txt", ios::in);//read
			if (myFile.is_open())
			{
				string line;
				while (getline(myFile, line))
				{
					cout << "Entry " << currentIndexVar << ": ";
					cout << line << endl;
					currentIndexVar++;
				}
				currentIndexVar = 1;
				myFile.close();
			}
			system("pause");
			/////////////////////////////////////////////////////////////////////////////////////////
			break;

		case '4':
			cout << "Remove a note.\n";

			cout << "These are the notes I have saved for you...\n";

			//Read from File

	/////////////////////////////////////////////////////////////////////////////////////////

			myFile.open("example.txt", ios::in);//read
			if (myFile.is_open())
			{
				string line;
				while (getline(myFile, line))
				{
					cout << "Entry " << currentIndexVar << ": ";
					cout << line << endl;
					*currentIndexPtr = currentIndexVar++;
				}

				myFile.close();
			}
			system("pause");

			cout << "Please choose the file you wish to delete: ";
			cin >> userInputVar;
			system("pause");
			if ((userInputVar - '0') >= 0 && (userInputVar - '0') < *currentIndexPtr)
			{
				delete_line("example.txt", userInputVar);
			}

			*currentIndexPtr = 1;
			break;

		case '5':
			cout << "See you later!!!\n";
			return 0;
			break;

		default:
			cout << "that is not a valid option. Please try again.\n";
			break;

		}

	} while (userInputVar != '5');

	return 0;
}
