/* 
userclass.h

Class that handles the methods and functions
for the user account
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class Admin : public userAccount {
private:
string adminPass;

//friend class userList;

public:
//userAccount constructors
Admin();
~Admin();

//Accessor Functions
int getBalance();
void dumpContents();
void dumpUserAccountList();
string getName();
string getCurrency();
bool currencyIsAllowed(const string&);

//Mutators Functions
void initEmpty();
void destroyElem();
void addUser();
void removeUser();
void addBalance(int);
void subBalance(int);
void setBalance (const int);
void setCurrency(const string&);
void setName(const string&);
void setAllowedCurrency();



};
