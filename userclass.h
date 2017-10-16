/* 
userclass.h
*/
#include <string>
#include <cstring>

using namespace std;
class userAccount {
private:
int balance;
string name;
string currency;
friend class userList;

public:
//userAccount constructors
userAccount();
~userAccount();

//Accessor Functions
int getBalance();
void dumpContents();
void getName();
string getCurrency();

//Mutators Functions
void initEmpty();
void destroyElem();
void addBalance(int);
void subBalance(int);
void setCurrency(const string&);
void setName(const string&);



};
