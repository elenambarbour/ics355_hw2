#include <iostream>

#include "userclass.h"



using namespace std;

userAccount Dave; 

int main() {

int x =0;
Dave.setBalance(45);
x = Dave.getBalance();

cout << "hello world" << endl;
cout << x << endl;
}
