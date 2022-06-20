# CEECS-Project
Security threat from **thermal sensors** that *deteriorate* the **energy consumption** of *cloud computing data centers*.

This was a very eye-opening experience and conclusively, since Amazon has about **five-hundred-thousand** servers, and the average server that had a Trojan was using more electricity in 30 minutes than the other (0.12 cents) by 0.02 cents, (without a Trojan it was 0.10 cents per 30 minutes), this means that giant companies like Amazon could potentially lose over **172.8 Million Dollars** every year, overpaying for the electricity to operate the cooling of the fans, if their servers get infected with a dangerous Trojan. 

# Results

There is an excel sheet with all the data recorded, calculated, and analyzed.

# Variables

The variables that were measured were the distance from the CPU: 1 foot, 2 feet, and 3 feet, the fan speed (this fan has 3 speeds to choose from), 33%, 66%, and 100%.

This benchmark was taken in a room with a static temperature of 70 degrees.

# About the code

temp_checker & temp_checker0 were designed to see the current temperature of the CPU every minute depending on what type of test the user would like to take. So if they pick "Benchmark with Trojan" temp_checker0 would launch in another terminal and this will also display the temperature every minute for added statistics. 

The code is also designed to color code the temperature to make is easier to read. Green is 60 degrees and lower, orange from 60 - 79, and red 80 degrees and up to signify dangerous/harmful temperatures.

# Conclusion

This test has shown that on a large scale, Trojans can cost millions of dollars in damage in a short amount of time, no wonder there is a lot of preamptive maintanence and personal carefully monitoring their systems.
