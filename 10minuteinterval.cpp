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
	int value1_transfer;
	int big_counter = 0;
	int counter = 1;
	int aVariable;
	int average = 0;
	int stay_on_ptnr = 0;
	int seconds_cntr = 0;
	bool stay_on = false;
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
	while(big_counter < 18) //This is 30 minutes because the LOOP UNDER COUNTS EVERY 100 SECONDS
	{
		while(counter < 10)
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
			cout << "\e[4mThe current temperature in degrees is: \e[0m" << value1 << "\033[0m";
			cout << "\033[0m" << endl;
			//cout << value1 << endl;
			if(value1 >= 79999 && stay_on == false)
			{
				std::system("gpio mode 1 out");
				std::system("gpio toggle 1");
				toggle = true;
				stay_on_ptnr++;
				stay_on = true;
			}
			if(toggle == true)
			{
				if(value1 <= 79999 && stay_on == true)
				{
					std::system("gpio mode 1 out");
					std::system("gpio toggle 1");
					toggle = false;
					seconds_cntr = seconds_cntr + 10;
				}
			}
			for(i=0; i < 10; i++)
			{
				delay(1);
				cout << ("%d seconds have passed\n", i+1) << endl;
			}
			if(seconds_cntr >= 60)
			{
				minute++;
				seconds_cntr = seconds_cntr - 60;
			}
			counter++;
			value1_transfer = value1;
		}
		toggle = false;
		stay_on = false;
		counter = 0;
		//cout << "This is the big counter: "  <<big_counter << endl;
		big_counter++;
		average = average + value1_transfer;
	}
	average = average / 1800;
	char num_char[MAX_DIGITS + sizeof(char)];
	std:: sprintf(num_char, "%d", average);
	cout << "The " << "\e[4maverage\e[0m" << " temperature in degrees is: ";
	if(average <= 60000)
	{
		cout << "\033[32m";
		cout << num_char[0] << num_char[1] << "." << num_char[2] << "\033[36m" << "(" << "30m" << ")" << endl;
		cout << "\033[0m";
	}
	else if (average <= 79999)
	{
		cout << "\033[33m";
		cout << num_char[0] << num_char[1] << "." << num_char[2] << "\033[36m" << "(" << "30m" << ")" << endl;
		cout << "\033[0m";
	}
	else
	{
		cout << "\033[31m";
		cout << num_char[0] << num_char[1] << "." << num_char[2] << "\033[36m" << "(" << "30m" << ")" << endl;
		cout << "\033[0m";
	}
	if(toggle == true)
	{
		std::system("gpio toggle 1");
	}
	cout << "The power was on for: " << "\033[31m" << minute << "\033[0m" << " minutes and " << "\033[33m" << seconds_cntr << "\033[0m" << " seconds." << endl;

	return 0;
}
