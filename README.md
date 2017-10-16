# ics355_hw2
Currency conversions program for ICS 355

Program consists of the following files.
main.cpp: main function that handles all user input / output to user. Calls functions provided in different files.
userclass.h: defines the class that has user account information - current balance, preferred currency, username associated with class, and allowed currencies for the account.
userclass.cpp: Has all functions for accessing the class from inside and outside the class permissions.
usercase.h: defines prototypes to the functions that take care of different user cases.
usercase.cpp: handles the case that the user wants to check balance, deposit, withdraw, and see information for the user.
convert.h: defines the prototypes for anything handling conversions.
convert.cpp: functions that handle conversion from USD to Euro or Pound and whether or not a conversion is needed.


Please compile by running "make" in the command line. This will make all the files needed to run the program.
Run by typing "./main" into the command line.

Example runs:
make
./main
>>(N)ew User (E)xisting User
>> (user) Elena
>> (program) (N)ew User (P)rint User Information (C)heck Balance (W)ithdraw (D)eposit
>> (user) D
>> (program) How much would you like to deposit?
>> (user) jik
>> (program) You have entered the wrong input, please try again
>> (program) (N)ew User (P)rint User Information (C)heck Balance (W)ithdraw (D)eposit
>> (user) D
>> (program) How much would you like to deposit?
>> (user) 800
>> (program) What is the currency?
>> (user) Pence
>> (program) This currency is not currently supported, please try again
>> (program) (N)ew User (P)rint User Information (C)heck Balance (W)ithdraw (D)eposit
>> (user) D
>> (program) How much would you like to deposit?
>> (user) 800
>> (program) What is the currency?
>> (user) USD
>> (program) (N)ew User (P)rint User Information (C)heck Balance (W)ithdraw (D)eposit
>> (user) C
>> (program) 800

