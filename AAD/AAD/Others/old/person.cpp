#include <iostream>
using namespace std;

struct Person {
	string name;
void printName(){
	cout <<"My name is " << name << endl;
	}
};	

int main(){
	Person p;
	p.name = "Michel Kugler";
	p.printName();
return 0;
}