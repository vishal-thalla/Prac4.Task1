#include <iostream> 
#include <iomanip>
#include <string>

// Calculates the average hours worked by the employees.
/* divide the program into little functions
getAverage
displayArray
loadArray
*/

using namespace std; 

const int MAX_ARR_SIZE= 10000;
const int EXIT_CODE = 999;
const string DASHES = "----------------------------------------------------------------------\n", 
	SGET_HOURS = "Enter the hours worked by employee #",
	SSHOW_HOURS = "The hours you entered are: ",
	SDISPLAY_1 = "The employee(s) worked an average of ",
	SDISPLAY_2 = " hours this week.",
	SERROR_1 = "You have entered ",
	SERROR_2 = ". It is invalid. Program terminated.",
	SERROR_3 = " and indicated that it is invalid. Program terminated.",
	SAB_1 = "You have entered ",
	SAB_2 = ", which is an abnormal input. Please confirm input (Y or N): ";

int loadArray(int arr[], int& length){
	int input, last , emp =0;
	char yOrn = ' ';
	length = 0;
	
	while (input >= 0 && input != EXIT_CODE){
		cout << SGET_HOURS << ++emp << " : ";
		cin >> input;
		if (input == EXIT_CODE || input < 0 || input > 50)/* must not skip 0s */	
			return input; // jump out of function with give last input
		else {
			if (input == 0 || input > 40){
				cout << SAB_1 << input << SAB_2;
				cin  >> yOrn;				
				if (yOrn == 'N')
					return input;
			}
			arr[length++] = input; 		
		}
	}
	return 0; // should never get here but just in case loop exits and continues with function
}

void displayArray(int arr[], int length){
	string hours = "";
	
	cout << SSHOW_HOURS;
	for (int i = 0; i < length ; i++)
		cout << arr[i] << " ";
	cout << endl;
}

double getAverage(int arr[], int length){
	int sum = 0; // have to init 
	for (int i = 0; i < length ; i++){
		sum += arr[i];
	}
	return (double)sum / length;
}

int main ()
{
	int hours[MAX_ARR_SIZE], last, length;	
	
	cout << "Enter " << EXIT_CODE<< " to stop input\n";
	last  = loadArray(hours, length);
	cout << DASHES;
	if (last == EXIT_CODE) { // the 999 exit code
		displayArray(hours, length);
		cout << SDISPLAY_1 << fixed 	<< setprecision(1)  
			<< getAverage(hours, length) << SDISPLAY_2 << endl;
	}
	else if (last < 0 || last > 50) // invalid value
		cout << SERROR_1 << last << SERROR_2 << endl;
	else if (last == 0 || last > 40) // abnormal value
		cout << SERROR_1 << last << SERROR_3 << endl;
	cout << DASHES;	

	return 0;
}

