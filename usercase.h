/*
Author: Elena Barbour
Date: 10/15/17
Takes care of different cases in which the user will input 
different commands. Also takes care of checking whether the 
input is right or not
*/

string getExistingUsername ();
string getNewUsername ();
bool checkIfUsernameExists(string username);
userAccount deposit(userAccount user);
userAccount withdraw(userAccount user);
float checkFloat();
char checkChar();
void saveUserInformation(userAccount user);
