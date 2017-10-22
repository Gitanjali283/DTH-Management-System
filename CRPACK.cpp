#include<fstream>
#include<iostream>
#include<conio.h>
 
 using namespace std;
int main()

{
	ofstream fout;     
	fout.open("P1.txt");
	fout<<"Z SPECIAL"<<'\n';
	fout<<"Z Cinema"<<'\n';
	fout<<"Z Show"<<'\n';
	fout<<"Z World"<<'\n';
	fout<<"Z Studio"<<'\n';
	fout<<"Z Regional"<<'\n';
	cout<<"DONE";
    return 0;
	getch();
}
