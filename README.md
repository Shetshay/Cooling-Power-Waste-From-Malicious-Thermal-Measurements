# CEECS-Project
Security threat from **thermal sensors** that *deteriorate* the **energy consumption** of *cloud computing data centers*.

This was a very eye-opening experience and conclusively, big companies like Amazon have about **five-hundred-thousand** servers, and the average server that would have a Trojan would use more electricity in 30 minutes than the other server (0.12 cents) by 0.02 cents, (without a Trojan it was 0.10 cents per 30 minutes), this means that giant companies like Amazon could potentially lose over **(will update)** every year, overpaying for the electricity to operate the cooling of the fans, if their servers get infected with a dangerous Trojan. 

# Items/Sources Used

1. https://www.amazon.com/Amazon-Basics-Speed-Circulator-11-Inch/dp/B07BZQKC5M
2. https://www.amazon.com/LoveRPi-Raspberry-Computer-Heatsinks-4GB/dp/B07WHZW881/ref=sr_1_4?crid=1GH6BY8C6YBVR&keywords=raspberry+pi+4gb+2018&qid=1655732147&sprefix=rasberry+pi+4gb+2018%2Caps%2C107&sr=8-4
3. https://www.amazon.com/Iot-Relay-Enclosed-High-Power-Raspberry/dp/B00WV7GMA2/ref=sr_1_4?keywords=DIGITAL+LOGGERS&qid=1655731242&s=electronics&sr=1-4
4. https://www.amazon.com/Electricity-Monitor-Voltage-Overload-Protection/dp/B07DPJ3RGB/ref=sr_1_3?crid=262ZFMKRJVB0B&keywords=power+meter+tka+united&qid=1655731421&sprefix=power+meter+tka+united%2Caps%2C101&sr=8-3 **X2**
5. https://www.amazon.com/Keszoox-Premium-Breadboard-Jumper-Raspberry/dp/B09F6WVHQR/ref=sr_1_3?crid=28ZV0UC8W0Y99&keywords=raspberry+pi+wires&qid=1655732213&sprefix=raspberry+pi+wires%2Caps%2C149&sr=8-3

This stack overflow helped me change the colors for *aesthetics* and **easy readibility**:

1. https://stackoverflow.com/questions/20909942/color-linux-command-output#20910309

# Average Cost per kWh per State

Found the **average** cost per kWh per state here:

https://www.electricrate.com/electricity-rates-by-state/

# The Equation

Example Problem W/ Equation:

1.  **28.3(Watts) x 24(hrs) / 1000 = 0.6792kWh**

*Daily:*

2.  **0.06792kWh x (insert average kWh in your state here(19.20)) = 13.04¢**

*Anually:*

3.  13.04¢ x 365(# of days in a year) = **4,763$**

(PUT THE MONEY THEY WOULD NORMALLY USE HERE)

Found the **cost** of the electricity with this calculator: 

1. https://www.omnicalculator.com/everyday-life/electricity-cost ***(Calculates the cost per year)***
2. https://www.omnicalculator.com/everyday-life/electricity-cost-single-usage ***(Calculates the cost per day)***

# Results

There is an excel sheet with all the data recorded, calculated, and analyzed.

# Variables

The variables that were measured were the distance from the CPU: 1 foot, 2 feet, and 3 feet, and the fan speed (this fan has 3 speeds to choose from), 33%, 66%, and 100%.

This benchmark was taken with the CPU idling at a temperature of 50~ degrees.

# About the code

temp_checker & temp_checker0 were designed to see the current temperature of the CPU every minute depending on what type of test the user would like to take. So if they pick "Benchmark with Trojan" temp_checker0 would launch in another terminal and this will also display the temperature every minute for added statistics. 

The code is also designed to color code the temperature to make is easier to read. Green is 60 degrees and lower, orange from 60 - 79, and red 80 degrees and up to signify dangerous/harmful temperatures.

# Conclusion

This test has shown that on a large scale, Trojans can cost millions of dollars in damage in a short amount of time, no wonder there is a lot of preamptive maintanence and personal carefully monitoring their systems.
