# ics355_hw2
Currency conversions program for ICS 355

Program was created with C++ to take advantage of the object oriented design of having multiple users with data associated to each user. This program is a simple command-line driven financial calculator that supports multiple
currencies, and can add, subtract values from a user's account. In addition to this it prevents
the user from entering invalid data, such as currencies it does not support.

Program consists of the following C++ files. <br />
- main.cpp: main function that handles all user input / output to user. Calls functions provided in different files. <br />
- userclass.h: defines the class that has user account information - current balance, preferred currency, username associated with class, and allowed currencies for the account. <br />
- userclass.cpp: Has all functions for accessing the class from inside and outside the class permissions.<br />
- usercase.h: defines prototypes to the functions that take care of different user cases. <br />
- usercase.cpp: handles the case that the user wants to check balance, deposit, withdraw, and see information for the user. <br />
- convert.h: defines the prototypes for anything handling conversions. <br />
- convert.cpp: functions that handle conversion from USD to Euro or Pound and whether or not a conversion is needed. <br />
- admincase.h: defines the prototypes for anything handling the admin commands <br />
- admincase.cpp: functions that handle the commands from the admin user. <br />
- md5.h: defines the prototypes for the downloaded md5 hashing algorithm file <br />
- md5.cpp: functions that handle the md5 hashing. <br />

The Program consists of the following TXT files:  <br />
- admin.txt: hidden file that holds the name, salt, and hashpassword for the admin account <br />
- .pass.txt: hidden file that holds the name, salt, and hashpassword for all accounts in the "database" <br />\
- .passTemp.txt: hidden file that that is used to rewrite the .pass.txt file <br />
- .userInfo.txt: hidden file that holds the name, balance, and preferred currency for all account in the "database" <br />
- .userInfoTemp.txt: hidden file that that is used to rewrite the .userInfo.txt file <br />



Please compile by running "make" in the command line. This will make all the files needed to run the program. <br />
Run by typing "./main" into the command line.<br />


Example run of Admin Account Options and Commands (Print ALL USER INFO FROM DATABASE + REMOVE USER):
![admin_print_remove](https://user-images.githubusercontent.com/10985239/33012229-633b4b62-cd84-11e7-8f36-55450e7ba468.jpg)


Example run of User Transfer:
![user_transfer](https://user-images.githubusercontent.com/10985239/33011842-332c7c58-cd83-11e7-97a4-dd3be3350738.jpg)


Example Run of User with Insufficient Funds:
![user_insufficient_funds](https://user-images.githubusercontent.com/10985239/33011869-4811ab48-cd83-11e7-91d7-edd136917335.jpg)

