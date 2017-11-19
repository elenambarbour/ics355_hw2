/*
Author: Elena Barbour
Date: 10/15/17
Takes care of different cases in which the user will input 
different commands. Also takes care of checking whether the 
input is right or not
*/



void PrintAllUserInfo(userAccount admin);
bool CheckAdminPassword(string PW, string admin);
void AddAccount(string username, float balance, string currency, string PW);
string AddPassword();
bool IsValidPassword (string password);
void RemoveAccount(string removeUsername);
