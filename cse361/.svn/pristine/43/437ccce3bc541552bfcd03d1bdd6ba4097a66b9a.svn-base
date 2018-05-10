Lab 0 
CSE332S
ReadMe file
Name: Shuo Wu
Wustl key : wushuo
Student ID: 452666

A brief description of your program

This lab is designed for open a card_file.txt and parse all the 
valid card information into a temporary deck (sort them into a deck),
 then use change functions change the information into different string and 
pass the string into a print function, then print all the valid card information out. 


A description of any design choices you made that deviate from the lab specification and your reasoning behind those decisions


None. If any, I have to say I build four personal function:
1, change_to_rank
2, change_to_suit
3, string_of_card_suit
4, string_of_card_rank 
I use them to change the datatype of useful information of different cards and pass the information into other functions.

A list of the possible return values of your program and what those return values mean

1: -2, can’t open the file  or can’t read the file
2: 2, there is no valid or useful card in the file
3: 1, the command line arguments isn’t two parameter, not size of 2
4: -1, if parse_card function doesn’t work correctly

A discussion of issues you ran into and fixed while working on your lab (it is a good idea to be documenting these as 
you work)

The issue: 
I am trying to test lab0.exe using the command prompt, 
but each time I try to run the .exe file with the .txt argument, 
a Debug Error pops up that says: "Run-Time Check Failure #3 - T". 
The program builds successfully in Visual Studio so I cannot figure out what is going wrong.
 And the last card information will repeat twice.
The reason: I use “while (!ifs.eof())” to determine whether the file still has card information to get.
But when there are some blank or space in this file, my while-loop won’t
 terminate immediately. It will run one more loop if there is a blank or space in this file.
Fix: 
First I used print statement to find where was the error. Then 
I added a if-statement to tell this condition, code: 
if (line == "" || line == " ") {
			break;
		}
This means if the last part of the ifs is “” or “ ”, my while loop will break. 


A list of the test cases you ran and the results of those test cases


In order to test that the program would correctly catch an invalid card_file being inputted into
the command line I tested the following case.
Input: Lab0.exe wrong_name.txt
Output: This file could not be found (followed by the usage function output)
 %errorlevel% -2

Empty file inputted
Input: Lab0.exe blank.txt
Output: No cards in file (followed by usage function output)
echo %errorlevel% 2

Wrong number of command line arguments
Input: Lab0.exe card_file1 card_file2
Output: Wrong number of command line arguments inputted please input one (followed by usage function output)
echo %errorlevel% 1

Invalid cards were simply skipped if the entire deck was made up of invalid cards then the program 
Input: Lab0.exe all_wrong.txt
outputs 
There isn’t any valid or useful cards in this file
echo %errorlevel% -1


Extra Credit

Part III - Linux Programming Environment: (optional, worth up to 5% extra credit)

1,
[wushuo@shell lab0]$

2,
there were none errors on linux.

3, 
input :[wushuo@shell lab0]$ ./lab0_test new.txt ^C

output:

the infomation of a new card is : two && Clubs
the infomation of a new card is : three && Clubs
the infomation of a new card is : four && Clubs
the infomation of a new card is : five && Clubs
the infomation of a new card is : six && Clubs
the infomation of a new card is : seven && Clubs
the infomation of a new card is : eight && Clubs
the infomation of a new card is : nine && Clubs
the infomation of a new card is : ten && Clubs
the infomation of a new card is : jack && Clubs
the infomation of a new card is : queen && Clubs
the infomation of a new card is : king && Clubs
the infomation of a new card is : ace && Clubs
the infomation of a new card is : ace && Diamonds
the infomation of a new card is : king && Diamonds
the infomation of a new card is : queen && Diamonds
the infomation of a new card is : jack && Diamonds
the infomation of a new card is : ten && Diamonds
the infomation of a new card is : nine && Diamonds
the infomation of a new card is : eight && Diamonds
the infomation of a new card is : seven && Diamonds
the infomation of a new card is : six && Diamonds
the infomation of a new card is : five && Diamonds
the infomation of a new card is : four && Diamonds
the infomation of a new card is : three && Diamonds
the infomation of a new card is : two && Diamonds
the infomation of a new card is : two && Hearts
the infomation of a new card is : three && Hearts
the infomation of a new card is : four && Hearts
the infomation of a new card is : five && Hearts
the infomation of a new card is : six && Hearts
the infomation of a new card is : seven && Hearts
the infomation of a new card is : eight && Hearts
the infomation of a new card is : nine && Hearts
the infomation of a new card is : ten && Hearts
the infomation of a new card is : jack && Hearts
the infomation of a new card is : queen && Hearts
the infomation of a new card is : king && Hearts
the infomation of a new card is : ace && Hearts
the infomation of a new card is : ace && Spades
the infomation of a new card is : king && Spades
the infomation of a new card is : queen && Spades
the infomation of a new card is : jack && Spades
the infomation of a new card is : ten && Spades
the infomation of a new card is : nine && Spades
the infomation of a new card is : eight && Spades
the infomation of a new card is : seven && Spades
the infomation of a new card is : six && Spades
the infomation of a new card is : five && Spades
the infomation of a new card is : four && Spades
the infomation of a new card is : three && Spades
the infomation of a new card is : ten && Hearts
the infomation of a new card is : ten && Clubs
the infomation of a new card is : ten && Diamonds

input:[wushuo@shell lab0]$ ./lab0_test all_wrong.txt 
output:There isn't any valid or useful cards in this file
Lab0 is a read card from a file and prient all the card in this file out
you need to set the input as this form : Lab0.exe card_file.txt
run the lab0.exe and set the care_file.txt as it input file

input: [wushuo@shell lab0]$ ./lab0_test blank.txt 
output: There isn't any valid or useful cards in this file
Lab0 is a read card from a file and prient all the card in this file out
you need to set the input as this form : Lab0.exe card_file.txt
run the lab0.exe and set the care_file.txt as it input file

input:[wushuo@shell lab0]$ ./lab0_test blank.txt blank.txt 
output:
Lab0 is a read card from a file and prient all the card in this file out
you need to set the input as this form : Lab0.exe card_file.txt
run the lab0.exe and set the care_file.txt as it input file
please enter two command line arguments for ./lab0_test

