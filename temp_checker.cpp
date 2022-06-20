#include <iostream>
#include <fstream>
#include <string>
#include <charconv>
#include <chrono>
#include <thread>
#include <stdio.h> 
#include <time.h>

using namespace std;

#define MAX_DIGITS 10

void delay(int noseconds)
{
	int milliseconds = 1000000 * noseconds;
	clock_t start_time = clock();
	while(clock() < start_time + milliseconds)
		;
}
int main ()
{
	std::system("clear");
	cout << "\033[33m";
	cout << "This will display the current temperature in degrees every minute." << endl;
	cout << "\033[0m";
	int i;
	int counter = 1;
	int average = 0;
	bool error = false;
	bool toggle = false;
	
	while(counter < 30)
	{
		ifstream inFile;
		int value1;
		//open the file
		inFile.open("/sys/class/thermal/thermal_zone0/temp");
		//read the number from the file
		inFile >> value1;
		char num_char[MAX_DIGITS + sizeof(char)];
		std:: sprintf(num_char, "%d", value1);
		//std:: printf("num_char: %s \n", num_char);
		//close the file
		inFile.close();
		//display the three numbers
		//istream& get (char* s, );
			cout << "The " << "\e[4mcurrent\e[0m" << " temperature in degrees is: ";
	if(value1 <= 60000)
	{
		cout << "\033[32m";
		cout << num_char[0] << num_char[1] << "." << num_char[2] << "\033[36m" << "(" << counter << ")" << endl;
		cout << "\033[0m";
	}
	else if (value1 <= 79999)
	{
		cout << "\033[33m";
		cout << num_char[0] << num_char[1] << "." << num_char[2] << "\033[36m" << "(" << counter << ")" << endl;
		cout << "\033[0m";
	}
	else
	{
		cout << "\033[31m";
		cout << num_char[0] << num_char[1] << "." << num_char[2] << "\033[36m" << "(" << counter << ")" << endl;
		cout << "\033[0m";
	}
		
		//cout << "\e[4mThe current temperature in degrees is:\e[0m" << " " << "\033[0m";
		//cout << "\033[0m";
		average = average + value1;
		counter++;
		//cout << value1 << endl;
		
		for(i=0; i < 60; i++)
		{
			delay(1);
			//printf("%d seconds have passed\n", i+1);
		}
	}
	char num_char[MAX_DIGITS + sizeof(char)];
	std:: sprintf(num_char, "%d", average);

	return 0;
}
