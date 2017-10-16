# ics355_hw2
Currency conversions program for ICS 355

Program was created with C++ to take advantage of the object oriented design of having multiple users with data associated to each user.

Program consists of the following files. <br />
-main.cpp: main function that handles all user input / output to user. Calls functions provided in different files. <br />
-userclass.h: defines the class that has user account information - current balance, preferred currency, username associated with class, and allowed currencies for the account. <br />
-userclass.cpp: Has all functions for accessing the class from inside and outside the class permissions.<br />
-usercase.h: defines prototypes to the functions that take care of different user cases. <br />
-usercase.cpp: handles the case that the user wants to check balance, deposit, withdraw, and see information for the user. <br />
-convert.h: defines the prototypes for anything handling conversions. <br />
-convert.cpp: functions that handle conversion from USD to Euro or Pound and whether or not a conversion is needed. <br />


Please compile by running "make" in the command line. This will make all the files needed to run the program. <br />
Run by typing "./main" into the command line.<br />

Example runs: <br />
make <br />
./main <br />
--(N)ew User (E)xisting User <br />
-- (user) Elena <br />
-- (program) (N)ew User (P)rint User Information (C)heck Balance (W)ithdraw (D)eposit <br />
-- (user) D <br />
-- (program) How much would you like to deposit? <br />
-- (user) jik <br />
-- (program) You have entered the wrong input, please try again <br />
-- (program) (N)ew User (P)rint User Information (C)heck Balance (W)ithdraw (D)eposit <br />
-- (user) D <br />
-- (program) How much would you like to deposit? <br />
-- (user) 800 <br />
-- (program) What is the currency? <br />
-- (user) Pence <br />
-- (program) This currency is not currently supported, please try again <br />
-- (program) (N)ew User (P)rint User Information (C)heck Balance (W)ithdraw (D)eposit <br />
-- (user) D <br />
-- (program) How much would you like to deposit? <br />
-- (user) 800 <br />
-- (program) What is the currency? <br />
-- (user) USD <br />
-- (program) (N)ew User (P)rint User Information (C)heck Balance (W)ithdraw (D)eposit <br />
-- (user) C <br />
-- (program) 800 <br />



