#include <iostream>
#include <fstream>
#include <string>
#include <charconv>
#include <chrono>
#include <thread>
#include <stdio.h> 
#include <time.h>
//libraries we are using.
using namespace std;

#define MAX_DIGITS 10

void delay(int noseconds) //This code will convert the second into 60 seconds, one minute.
{
	int milliseconds = 1000000 * noseconds; // 1000000 * 1
	clock_t start_time = clock();
	while(clock() < start_time + milliseconds)
		;
}
int main ()
{
	std::system("clear"); // clears screen
	cout << "\033[33m"; // changes color to orange
	cout << "This is a 30 minute benchmark stress testing the temperature of the CPU." << endl;
	cout << "If the temperature is or exceeds 80 degrees the external fan will turn on." << endl << endl;
	cout << "At the end of the test the average temperature will be displayed." << endl;
	//std::system("vcgencmd measure_temp"); //check temperature file
	cout << "\033[0m"; // change color back to white
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
	if(aVariable == 1) // If the user picks 1 the trojan test will begin.
	{
		cout << "The benchmark will " << "\033[32m"<< "\e[4mRUN\e[0m" << "\033[0m" <<" with a trojan!" << endl;
	//	std::system("g++ temp_checker2.cpp"); // This was to open and launch another file to check the temperature in another console (per minute)
	//	std::system("./a.out"); // This was to open and launch another file to check the temperature in another console (per minute)
	}
	if(aVariable == 2) // If the user picks 2 the trojan will not be in the test.
	{
		cout << "The benchmark will NOT run with a trojan!" << endl;
	//	std::system("g++ temp_checker.cpp"); // This was to open and launch another file to check the temperature in another console (per minute)
	//	std::system("./a.out"); // This was to open and launch another file to check the temperature in another console (per minute)
	}
	while(aVariable != 1 && error == false && aVariable != 2 && error == false) // If the user doesn't pick 1 OR 2 it will display an error message.
	{
		cout << "I'm sorry but the only options I can read is the number 1 to use a trojan, and the number 2 to not include a trojan in this test." << endl;
		cin >> aVariable;
		if(aVariable == 1) // Benchmark will run with trojan.
		{
			cout << "The benchmark will RUN with a trojan!" << endl;
		}
		if(aVariable == 2) // Benchmark will not run with trojan.
		{
			cout << "The benchmark will NOT run with a trojan!" << endl;
		}
		if(aVariable == 1 || aVariable == 2) // Error handling, if one is true, the while loop ends and the test will begin.
		{
			error = true;
		}
	}
	while(counter < 30)
	{
		ifstream inFile;
		int value1; // value1 will be our temperature.
		//open the file
		inFile.open("/sys/class/thermal/thermal_zone0/temp"); // Location of temperature in Rasberry Pi
		//read the number from the file
		inFile >> value1;
		char num_char[MAX_DIGITS + sizeof(char)]; // Convert value1 into a char array so we can cout it at the end of the program for statistics.
		std:: sprintf(num_char, "%d", value1); // Converst value1 into a char array
		//std:: printf("num_char: %s \n", num_char);
		//close the file
		inFile.close();
		//display the three numbers
		//istream& get (char* s, );
		if(aVariable == 1) // This test will add +10 degrees to the temperature if the user wanted to run the benchmark with the Trojan
		{
			value1 = value1 + 10000; // We add +10 Degrees here.
			num_char[0] = num_char[0] + 1; // We even add +1 degree here same thing for the char array.
		}
		//cout << "\e[4mThe current temperature in degrees is:\e[0m" << " " << "\033[0m";
		//cout << "\033[0m";
		average = average + value1; // We will calculate the average of the degrees of the 30 minute test.
		counter++; // Counter will increment
		//cout << value1 << endl;
		if(value1 >= 79999) // If the value is higher then 79999 degrees the fan will turn on.
		{
			std::system("gpio mode 1 out"); // Set the rasberry pi to SEND voltage
			std::system("gpio toggle 1"); // Sends voltage to this specific pin#.
			toggle = true; // We tell the computer that the fan is ON.
			minute++; // We add one minute here, that's how long the fan will stay on.
		}
		if(toggle == true) // If the fan is ON.
		{
			if(value1 <= 79999) //AND if the CPU is less than 79999 degrees, we can turn off the fan to save power.
			{
				std::system("gpio mode 1 out"); // Set the rasberry pi to SEND voltage
				std::system("gpio toggle 1"); // Sends voltage to this specific pin#.
				toggle = false; // We tell the computer that the fan is now OFF
			}
		}
		for(i=0; i < 60; i++) //60 is the seconds, hence a minute.
		{
			delay(1); //1 second for delay but that gets multiplied by 1000000 in the void delay function above.
			//printf("%d seconds have passed\n", i+1);
		}
	}
	average = average / 30; // Now once we have the cumulative average added all together, we divide by 30 since this is how long the test was to get the average.
	char num_char[MAX_DIGITS + sizeof(char)]; // Again we convert the AVERAGE into a char array to use for cout in the end.
	std:: sprintf(num_char, "%d", average); // Again we convert the AVERAGE into a char array to use for cout in the end.
	cout << "The " << "\e[4maverage\e[0m" << " temperature in degrees is: ";
	if(average <= 60000) // If the average is less than 60 degrees, the output of the degrees will be the color green to signify nominal temperatures.
	{
		cout << "\033[32m";
		cout << num_char[0] << num_char[1] << "." << num_char[2] << "\033[36m" << "(" << counter << ")" << endl; // We use num_char[0,1,2] to cout a fluid readible degree for the user.
		cout << "\033[0m";
	}
	else if (average <= 79999) // If the average is less than 79 degrees, the output of the degrees will be the color orange to signify cautious temperatures.
	{
		cout << "\033[33m";
		cout << num_char[0] << num_char[1] << "." << num_char[2] << "\033[36m" << "(" << counter << ")" << endl; // We use num_char[0,1,2] to cout a fluid readible degree for the user.
		cout << "\033[0m";
	}
	else // If the average is higher than 79 degrees the output will be the color red to signify dangerous and harmful temperatures.
	{
		cout << "\033[31m";
		cout << num_char[0] << num_char[1] << "." << num_char[2] << "\033[36m" << "(" << counter << ")" << endl; // We use num_char[0,1,2] to cout a fluid readible degree for the user.
		cout << "\033[0m";
	}
	if(toggle == true) // Since we are out of the while loop now with the GPIO pin that toggles the fan, it could potentially still stay on. We have this here to turn it off after the test is over so we don't get any false readings, exception handling.
	{
		std::system("gpio toggle 1"); // Toggles the voltage of this specific pin#.
	}
	cout << "The power was on for: " << "\033[31m" << minute << "\033[0m" << " minutes. " << endl; // This will display the time in minutes how long the external fan was on.

	return 0;
}
