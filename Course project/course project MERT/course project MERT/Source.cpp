#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void studentInfo()
{
	cout << "Ime na studenta: Mert Mustafov Kamberov, Rakovoditel na kursovata zadacha: Elena Kalcheva\n";
	cout << "Da se razraboti programa s tekstovo menu i otdelni funkcii za obrabotka na chislovi danni pri slednite iziskvaniya:\n";
	cout << "- Tekstovoto menu pozvolyava potrebitelyat da izbira dali da vuvejda dannite ot klaviaturata ili da obrabotva veche vyvedeni v tekstov fayl danni. Faylyt se posochva ot potrebitelya.\n";
	cout << "- Vyvejda se celochislen masiv s do 100 elementa i se izvejda na ekrana.\n";
	cout << "- Zapisvat se v nov masiv chislata, sudurjashti cifrata 7.\n";
	cout << "- Sortira se noviya masiv i se izvejda na ekrana.\n";
}
void displayMenu()
{
	cout << "===================================================== \n";
	cout << " \t\tMENU \t \n ";
	cout << "===================================================== \n";
	cout << " 1.Add new records\n";
	cout << " 2.Add file\n";
}
void addNew()
{
	cout << "You have selected to add new records: \n";
}
void addFile()
{
	cout << "You have selected to add file! \n";
}
int numLen(int num)//vrushta kolko cifri ima edno chislo
{
	int len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return len;
}
bool has7(int num)//vrushta dali sudurja cifrata 7
{
	int digit;
	int n = num;
	bool is7 = false;
	for (int i = 1; i <= numLen(num); i++)
	{
		digit = n % 10;
		if (digit == 7)
		{
			is7 = true;
		}
		n /= 10;
	}
	return is7;
}
void display(int arr[], int len)
{
	int k;
	for (k = 0; k < len; k++)
	{
		printf("\n Element [%d] = %d", k, arr[k]);
	}

}
int sort(int arr[], int len)
{
	int n = len;
	int temp;
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = 0; j < (n - i - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr[len];
}
int counterOf7(int arr[], int len) {
	int counter = 0;
	int digit, temp;
	for (int i = 0; i < len; i++)//obhojda vsqko chislo ot masiva
	{
		temp = arr[i];//pomoshtna promenliva, chiqto duljina namalqva s 1 sled vsqka proverka na cifra
		while (numLen(temp) > 0)//obhojda vsqka cifra na chisloto
		{
			digit = temp % 10;
			if (digit == 7)
			{
				counter++;
			}
			temp /= 10;
		}
	}
	return counter;
}
bool isInt(string input)
{
	bool isNeg = false;
	int itr = 0;
	if (input.size() == 0)
		return false;
	if (input[0] == '-')
	{
		isNeg = true;
		itr = 1;
	}

	for (int i = itr;i < input.size();i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}
int main()
{
	bool newRecords = false;
	int yourChoice, n, j = 0;
	int arr[100], arr7[100];
	string input;

	studentInfo();
	//function to display Menu

	displayMenu();
	do {//proverqva dali vuvedeniq int e 1 ili 2
		do//proverqva dali vuvedenoto chislo e int
		{
			cout << "Enter your choice:";
			cin >> input;
			if (!isInt(input) || stoi(input) <= 0)
			{
				cout << "invalid!" << endl;
			}
		} while (!isInt(input));
		yourChoice = stoi(input);
		switch (yourChoice)
		{
		case 1: addNew();newRecords = true; break;
		case 2: addFile();break;
		default: cout << "invalid" << endl; break;
		}
	} while (yourChoice != 1 && yourChoice != 2);

	if (newRecords)//Proverqva dali potrebitelq iska da vuvejda novi danni
	{

		do
		{
			cout << "Length of the array: ";  cin >> input;
			if (!isInt(input) || stoi(input)<=0)
			{
				cout << "invalid!" << endl;
			}
		} while (!isInt(input) || stoi(input) <= 0);
		n = stoi(input);

		cout << "Adding elements to the array!" << endl;
		for (int i = 0; i < n; i++)
		{
			do // proverka za vuvejdane na pravilni danni
			{
				printf("Enter arr[%d]= ", i);cin >> input;//vuvejdane na elementi v masiva
				if (!isInt(input))
				{
					cout << "invalid!" << endl;
				}
			} while (!isInt(input));
			arr[i] = stoi(input);
		}
		cout << "Printing array" << endl;
		display(arr, n);
		for (int i = 0; i < n; i++)
		{
			if (has7(arr[i]))
			{
				arr7[j] = arr[i];
				j++;
			}
		}
		sort(arr7, j);
		cout << "\n************* Printing sorted array7 **************" << endl;
		display(arr7, j);
		cout << "\n************* Printing count of sevens **************" << endl;
		cout << counterOf7(arr7, j);
	}
	else {
		/// CHETENE OT TEKSTOV FAYL ///
		string filename;
		ifstream myfile, myfileReader;
		int textLen = 0;
		cout << "Enter text file name: ";
		cin >> filename;
		myfile.open(filename);
		myfileReader.open(filename);
		/////////
		if (!myfile.is_open())
		{
			cout << "Error";
			return 1;
		}
		////////////IZVEJDA KOLKO ELEMENTA IMA V TEKSTOVIQ FAYL I PROVERQVA DALI SA POVECHE OT 100///////////////////

		while (myfileReader.good())
		{
			myfileReader >> input;
			if (!isInt(input)) // proverqvame elementite vuv faila
			{
				cout << "Invalid elements in the file!" << endl;
				return 1;
			}
			else
			{
				textLen++; // izvlichame broq na elemenite 
			}

		}
		if (textLen > 100)
		{
			cout << "Error! Text file has too many elements!";
			return 1;
		}
		cout << "Length of the array: " << textLen << endl;
		/////////
		int i = 0;

		///VUVEJDANE NA CHISLATA OT FAYLA V MASIVA///
		cout << "Adding elements to the array!" << endl;
		int number;
		while (myfile.good())
		{
			myfile >> number;
			arr[i++] = number;
		}
		///////
		myfile.close();
		/// Printirane na masiva
		cout << "Printing array:" << endl;
		display(arr, textLen);

		for (int i = 0; i < textLen; i++)
		{
			if (has7(arr[i]))
			{
				arr7[j] = arr[i];
				j++;
			}
		}
		sort(arr7, j);
		cout << "\n************* Printing sorted array7 **************" << endl;
		display(arr7, j);
	}
	
	/**************ZAPISVANE NA NOVIQ MASIV VAV TXT FAYL******************/

	ofstream outputfile("output.txt");
	if (outputfile.is_open())
	{
		for (int i = 0; i < j; i++)
		{
			outputfile << arr7[i] << endl;
		}
		outputfile.close();
	}
	else cout << "Unable to open file!";
	/********************************************************************/
	return 0;
}