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
friend class userList;

public:
//userAccount constructors
userAccount();
~userAccount();

//Accessor Functions
int getBalance();
void dumpContents();
void getName();

//Mutators Functions
void initEmpty();
void destroyElem();
void setBalance(int);
void setName(const string&);



};
