/*
Lists the users 
*/


#include <string>
#include <cstring>

using namespace std;
class userList {

private:
userAccount name;
userAccount balance;


public:
//userAccount constructors
userList();
~userList();

//Accessor Functions
int getUsers();
void dumpUsers();
void findName();

//Mutators Functions
void initEmpty();
void destroyElem();
void setBalance(int);
void setName(const string&);



};
