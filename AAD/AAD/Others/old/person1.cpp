#include <iostream>
using namespace std;

struct Person{
	
	string first_name;
	string past_name;
	int age;
	int height;

	printName(){
		cout << "Person: " << first_name << " " << past_name << endl;
	}
	
	void printMeasure(){
		cout << "Die Person ist " << age << " alt und " << height << "gross." << endl;
	}
};

int main(){
	Person p1, p2, p3;
	
	p1.first_name = "Michel";
	p1.past_name = "Kugler";
	p1.age = 26;
	p1.height = 178;
	p1.printName();
	p1.printMeasure();
	
	p2.first_name = "John";
	p2.past_name = "Alias";
	p2.age = 35;
	p2.height = 182;
	p2.printName();
	p2.printMeasure();
	
	p3.first_name = "Peter";
	p3.past_name = "Meier";
	p3.age = 48;
	p3.height = 1;
	p3.printName();
	p3.printMeasure();
	
	
return 0;
}