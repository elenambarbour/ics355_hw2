/* 
userclass.h
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class userAccount {
private:
int balance;
string name;
string currency;
string allowedCurrency[3] = {"USD", "Pound", "Euro"};

//friend class userList;

public:
//userAccount constructors
userAccount();
~userAccount();

//Accessor Functions
int getBalance();
void dumpContents();
void getName();
string getCurrency();
bool currencyIsAllowed(const string&);

//Mutators Functions
void initEmpty();
void destroyElem();
void addBalance(int);
void subBalance(int);
void setCurrency(const string&);
void setName(const string&);



};
