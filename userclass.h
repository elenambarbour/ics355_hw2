/* 
userclass.h

Class that handles the methods and functions
for the user account
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class userAccount {
private:
int balance;
int admin;
string name;
string currency;
string allowedCurrency[3];

//friend class userList;

public:
//userAccount constructors
userAccount();
~userAccount();

//Accessor Functions
int getBalance();
void dumpContents();
string getName();
string getCurrency();
bool currencyIsAllowed(const string&);
bool GetAdmin();

//Mutators Functions
void initEmpty();
void destroyElem();
void addBalance(int);
void subBalance(int);
void setBalance (const int);
void setCurrency(const string&);
void setName(const string&);
void setAllowedCurrency();
void SetAdmin();



};
