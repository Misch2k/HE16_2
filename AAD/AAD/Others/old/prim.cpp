#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int prim[100000] ={};
	int count=2;
	int count1=2;
	int i,x;
	
	prim[0]=1;
	prim[1]=2;
	
	for (i=3;i<=100000;i++){
		for (x=1;x<count;x++){
			if (i%prim[x]==0){
				break;
			}
			if (x==count-1){
				prim[count] = i;
				count++;
			}
		}
			
	}
	cout << count << endl;	
	for (int r=0; r<count; r++){
		cout << prim[r] << endl;
	}
    return 0;

}