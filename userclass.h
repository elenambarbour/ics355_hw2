/* 
userclass.h
*/


class userAccount {

int balance;

public:
//userAccount constructors
userAccount();
~userAccount();

//Accessor Functions
int getBalance();

//Mutators Functions
void initEmpty();
void destroyElem();
void setBalance(int);



};
