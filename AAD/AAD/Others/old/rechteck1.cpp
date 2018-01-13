#include <iostream>
using namespace std;

struct Person{
	
	char first_name;
	char past_name;
	int age;
	int height;

	printName(){
		cout << "Person1: " << first_name << " " << past_name << endl;
	}
	
	void printMeasure(){
		cout << "Die Person ist " << age << " alt und " << height << "gross." << endl;
	}
};

int main(){
	Person p1, p2, p3;
	
	p1.first_name = Michel;
	p1.past_name = Kugler;
	p1.age = 26;
	p1.height = 178;
	
	p1.first_name = John;
	p1.past_name = Alias;
	p1.age = 35;
	p1.height = 182;
	
	p1.first_name = Peter;
	p1.past_name = Meier;
	p1.age = 48;
	p1.height = 160;
	
return 0;
}