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
float balance;
int admin;
string name;
string currency;
string pass;
string salt;
string allowedCurrency[3];

//friend class userList;

public:
//userAccount constructors
userAccount();
~userAccount();

//Accessor Functions
float getBalance();
void dumpContents();
string getName();
string getCurrency();
bool currencyIsAllowed(const string&);
bool GetAdmin();
string GetSalt();
string GetPassword();

//Mutators Functions
void initEmpty();
void destroyElem();
void addBalance(float);
bool subBalance(float);
void setBalance (const float);
void setCurrency(const string&);
void setName(const string&);
void setAllowedCurrency();
void SetSalt(const string& salty);
void SetAdmin();
void SetPassword(const string& username, const string&);



};
