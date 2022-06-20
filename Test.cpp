#include <iostream>
#include <fstream>
#include <string>
#include <charconv>
#include <chrono>
#include <thread>
#include <stdio.h> 
#include <time.h>

using namespace std;

#define PIN_LED 1; 
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
	cout << "This is a 30 minute benchmark stress testing the temperature of the CPU." << endl;
	cout << "If the temperature is or exceeds 80 degrees the external fan will turn on." << endl << endl;
	cout << "At the end of the test the average temperature will be displayed." << endl;
	//std::system("vcgencmd measure_temp");
	cout << "\033[0m";
	int i;
	int counter = 1;
	int aVariable;
	int average = 0;
	bool error = false;
	bool toggle = false;
	double minute = 0;
	cout << "Will this test use a trojan?" << endl;
	cout << "\033[36m" << "(1)" << "\033[0m" << " means it will " << "\e[4mUSE\e[0m" <<" a trojan with the benchmark." << endl;
	cout << "\033[36m" << "(2)" << "\033[0m" << " means the benchmark will run " << "\e[4mWITHOUT\e[0m" << " a trojan." << endl;
	cin >> aVariable;
	if(aVariable == 1)
	{
		cout << "The benchmark will " << "\033[32m"<< "\e[4mRUN\e[0m" << "\033[0m" <<" with a trojan!" << endl;
	//	std::system("g++ temp_checker2.cpp");
	//	std::system("./a.out");
	}
	if(aVariable == 2)
	{
		cout << "The benchmark will NOT run with a trojan!" << endl;
	//	std::system("g++ temp_checker.cpp");
	//	std::system("./a.out");
	}
	while(aVariable != 1 && error == false && aVariable != 2 && error == false)
	{
		cout << "I'm sorry but the only options I can read is the number 1 to use a trojan, and the number 2 to not include a trojan in this test." << endl;
		cin >> aVariable;
		if(aVariable == 1)
		{
			cout << "The benchmark will RUN with a trojan!" << endl;
		}
		if(aVariable == 2)
		{
			cout << "The benchmark will NOT run with a trojan!" << endl;
		}
		if(aVariable == 1 || aVariable == 2)
		{
			error = true;
		}
	}
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
		if(aVariable == 1)
		{
			value1 = value1 + 10000;
			num_char[0] = num_char[0] + 1;
		}
		//cout << "\e[4mThe current temperature in degrees is:\e[0m" << " " << "\033[0m";
		//cout << "\033[0m";
		average = average + value1;
		counter++;
		//cout << value1 << endl;
		if(value1 >= 79999)
		{
			std::system("gpio mode 1 out");
			std::system("gpio toggle 1");
			toggle = true;
			minute++;
		}
		if(toggle == true)
		{
			if(value1 <= 79999)
			{
				std::system("gpio mode 1 out");
				std::system("gpio toggle 1");
				toggle = false;
			}
		}
		for(i=0; i < 60; i++)
		{
			delay(1);
			//printf("%d seconds have passed\n", i+1);
		}
	}
	average = average / 30;
	char num_char[MAX_DIGITS + sizeof(char)];
	std:: sprintf(num_char, "%d", average);
	cout << "The " << "\e[4maverage\e[0m" << " temperature in degrees is: ";
	if(average <= 60000)
	{
		cout << "\033[32m";
		cout << num_char[0] << num_char[1] << "." << num_char[2] << "\033[36m" << "(" << counter << ")" << endl;
		cout << "\033[0m";
	}
	else if (average <= 79999)
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
	if(toggle == true)
	{
		std::system("gpio toggle 1");
	}
	cout << "The power was on for: " << "\033[31m" << minute << "\033[0m" << " minutes. " << endl;

	return 0;
}
