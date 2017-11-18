/*
Author: Elena Barbour
Date: 10/15/17
Takes care of different cases in which the user will input 
different commands. Also takes care of checking whether the 
input is right or not
*/

string getExistingUsername (string login);
string getNewUsername ();
userAccount setUserBalanceAndCurrencyFromFile (string username, userAccount user);
bool checkIfUsernameExists(string username);
userAccount deposit(userAccount user);
userAccount withdraw(userAccount user);
float checkFloat();
char checkChar();
bool CheckUserPassword(string PW, string username);
void saveUserInformation(userAccount user);
