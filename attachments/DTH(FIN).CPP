#include<conio.h>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
#include<iostream>

using namespace std;

int g=0, p=0, n=0, flag=0,y=0;
void dispallpack();
int checkpass();
void getfeedb();

struct address
{
	char state[30], city[30], housename[50];
	int houseno; long pincode;
};

class package
{
	int fees;
	long p_id;
	char pname[20];
	char channel[50][20];
	char type[2];
	int count;						//channel count
	void assign();
	int addch(char *,int);
 public:
	package();
	void makepackage();
	void displaypack();

};

package::package()
{
	fees=0;
	count=5;
	strcpy(type," ");
}

void package::assign()
{
srand( (unsigned)time(NULL) ); 
p_id=rand();

}

int package::addch(char s[20], int a)
{
	int flag=0;
	ifstream fin;
	char str[20];
	switch(a)
	{
	 case 1:
		fin.open("P1.txt");
		fin.getline(str,20);
		while(fin)
		{
		  if (strcmpi(str,s)==0)
			{
			  count++;
			  strcpy(channel[count], s);
			  flag=0;
			  break;
			}
		  else
			{
			  flag=1;
			}
		  fin.getline(str,20);
		}
		fin.close();
		if(flag==1)
			 return 1;
		else
			 return 0;

	 case 2:
		fin.open("P2.txt");
		fin.getline(str,20);
		while(fin)
		{
		  if (strcmpi(str,s)==0)
			{
			  count++;
			  strcpy(channel[count], s);
			  flag=0;
			  break;
			}
		  else
			{
			  flag=1;
			}
		  fin.getline(str,20);
		}
		fin.close();
		if(flag==1)
			 return 1;
		else
			 return 0;

	 case 3:
		fin.open("P3.txt");
		fin.getline(str,20);
		while(fin)
		{
		  if (strcmpi(str,s)==0)
			{
			  count++;
			  strcpy(channel[count], s);
			  flag=0;
			  break;
			}
		  else
			{
			  flag=1;
			}
		  fin.getline(str,20);
		}
		fin.close();
		if(flag==1)
			 return 1;
		else
			 return 0;

	 case 4:
		fin.open("P4.txt");
		fin.getline(str,20);
		while(fin)
		{
		  if (strcmpi(str,s)==0)
			{
			  count++;
			  strcpy(channel[count], s);
			  flag=0;
			  break;
			}
		  else
			{
			  flag=1;
			}
		  fin.getline(str,20);
		}
		fin.close();
		if(flag==1)
			 return 1;
		else
			 return 0;

	 case 5:
		fin.open("P5.txt");
		fin.getline(str,20);
		while(fin)
		{
		  if (strcmpi(str,s)==0)
			{
			  count++;
			  strcpy(channel[count], s);
			  flag=0;
			  break;
			}
		  else
			{
			  flag=1;
			}
		  fin.getline(str,20);
		}
		fin.close();
		if(flag==1)
			 return 1;
		else
			 return 0;
	 default:
		return 1;
	}
}


void package::makepackage()
{
	ifstream f;
	system("cls");
	int num, res, ch, flag=1, choice, o;
	char str[20];
	if(n==1)  //global when modify package
	{
	 p:
	 cout<<"\nWhat would you like to do?:";
	 cout<<"\n1. Add Channels(Total Available Channel=50)";
	 cout<<"\n2. Change Package";
	 cout<<"\n3. Exit";
	 cout<<"\nEnter Choice(1/2):\t";
	 cin>>ch;
	 switch(ch)
	 {
	  case 1:
		cout<<"\nHow many channels would you like to add?\n";
		cin>>num;
		for(int j=0; j<num; j++)
		{
		 system("cls");
		 cout<<"\nDisplaying all packages:";
		 dispallpack();
		 cout<<"\nKindly select from which package would you like to add channel from:\t";
		 cin>>choice;
		 cout<<"\nPlease enter channel name(case sensitive):\n";
		 gets(str);
		 res=addch(str, choice);
		 if(res==1)
			{
			 cout<<"\nChannel Not Found/Invalid Input! Returning to Modify Channels Menu..."<<"\n";
			 goto p;
			}
		 else
			{
			 fees+=50;
			 cout<<"\nChannel Added Succesfully!";
			 getch();
			}
		}
		cout<<"\nYour new channel count is:\t";
		cout<<count;
		cout<<"\nNew Monthly Charges:\t";
		cout<<fees;
		flag=0;
		getch();
		break;
	  case 2:
		flag=1;
		cout<<"\nWhat type of connection would you like?\n";
		cout<<"1. Standard(Rs. 500)\n";
		cout<<"2. HD(Rs. 750)\n";
		cout<<"Enter your choice(1/2):\t";
		cin>>o;
		if(o==1)
			{
			 if(strcmpi(type,"HD")==0)
			 {
				fees-=250;
			 }
			 cout<<"\nStandard Definition has been selected...";
			 strcpy(type,"SD");
			}
		else
			{
			 if(strcmpi(type,"SD")==0)
			 {
				fees+=250;
			 }
			 cout<<"\nHigh Definition has been selected...";
			 strcpy(type,"HD");
			}
		y=1;  						//while changing package fees/channel count should not double
		break;
	  case 3:
		exit(0);
	  default:
		cout<<"Invalid Input! Returning to Modify Channels Menu..."<<"\n";
		goto p;
	 }
	}
	if(flag==1)
	{
	 int choice, i=0; char ch, str[10];
	 cout<<"\nDisplaying all packages:";
	 dispallpack();
	 q:
	 cout<<"\nKindly enter your choice of package(1-5):\t";
	 cin>>choice;
	 switch(choice)
		{
		 case 1:
			i=0;
			f.open("P1.txt");
			f.getline(str, 20);
			strcpy(pname, str);
			f.getline(str, 20);
			while(f)
			{
			 strcpy(channel[i],str);
			 f.getline(str, 20);
			 i++;
			}
			assign();
			cout<<"\nYour Package ID is:\t"<<p_id;
			getch();
			break;

		 case 2:
			f.open("P2.txt");
			f.getline(str, 20);
			strcpy(pname, str);
			f.getline(str, 20);
			while(f)
			{
			 strcpy(channel[i],str);
			 f.getline(str, 20);
			 i++;
			}
			assign();
			cout<<"\nYour Package ID is:\t"<<p_id;
			getch();
			break;

		 case 3:
			f.open("P3.txt");
			f.getline(str, 20);
			strcpy(pname, str);
			f.getline(str, 20);
			while(f)
			{
			 strcpy(channel[i],str);
			 f.getline(str, 20);
			 i++;
			}
			assign();
			cout<<"\nYour Package ID is:\t"<<p_id;
			getch();
			break;

		 case 4:
			f.open("P4.txt");
			f.getline(str, 20);
			strcpy(pname, str);
			f.getline(str, 20);
			while(f)
			{
			 strcpy(channel[i],str);
			 f.getline(str, 20);
			 i++;
			}
			assign();
			cout<<"\nYour Package ID is:\t"<<p_id;
			getch();
			break;

		 case 5:
			f.open("P5.txt");
			f.getline(str, 20);
			strcpy(pname, str);
			f.getline(str, 20);
			while(f)
			{
			 strcpy(channel[i],str);
			 f.getline(str, 20);
			 i++;
			}
			assign();
			cout<<"\nYour Package ID is:\t"<<p_id;
			getch();
			break;

		 default:
			cout<<"\nInvalid!";
			goto q;
		}
	 if(y==0)
	 {
		if(g==1)
		{
		 fees+=750;				//base fee=Rs. 500(not HD), each channel=Rs. 50
		 strcpy(type,"SD");
		}
		else
		{
		 fees+=1000;
		 strcpy(type,"HD");
		}
	 	count+=5;
	 }
	}
	cout<<"\nSuccessful!";
	getch();
}

void package::displaypack()
{
	cout<<"\nYour Package ID is:\t"<<p_id;
	cout<<"\n\nYour Package Name is:\t"<<pname;
	cout<<"\nPackage type:\t"<<type;
	cout<<"\n\nYour Channel Count is:\t"<<count;
	cout<<"\n\nYour Monthly Charges are:\t"<<fees;
	getch();
	cout<<"\nYour Channels are:\n";
	for(int i=0;i<count;i++)
	{
	 if(strcmpi(channel[i]," ")==0)		//////////Test this statement
	 break;
	 cout<<"\n"<<channel[i];
	}
}


class customer
{
	char fname[30];
	char lname[30];
	long id;
	address add;
	long double phonem;
	package pd;
	void assignid();
 public:
	char feedback[300];
	char *retf();
	char *retl();
	long retid();
	void accept();
	void display();
	void mod();
	void mod1();
};

void customer::assignid()
{
srand( (unsigned)time(NULL) );

id=rand();}

void customer::accept()
{
	cout<<"\nPlease enter your details:";
	cout<<"\nFirst Name:\t";
	gets(fname);
	cout<<"\nLast Name:\t";
	gets(lname);
	cout<<"\nPhone Number:\t";
	cin>>phonem;
	cout<<"\nPlease enter your address:\n";
	cout<<"State:\t";
	cin>>add.state;
	cout<<"\nCity:\t";
	cin>>add.city;
	cout<<"\nHousename:\t";
	cin>>add.housename;
	cout<<"\nHouse Number:\t";
	cin>>add.houseno;
	cout<<"\nPincode:\t";
	cin>>add.pincode;
	assignid();
	cout<<"\nYour customer ID is:\t"<<id;
	cout<<"\nPlease remember your customer ID as it is mandatory to login!";
	cout<<"\nPersonal details accepted successfully.";
	cout<<"\nPress enter to continue to Package Selection...\n";
	getch();
	pd.makepackage();
}

void customer::display()
{
	cout<<"\nDisplaying your original details:";
	cout<<"\nFirst Name:\t"<<fname;
	cout<<"\nLast Name:\t"<<lname;
	cout<<"\nCustomer ID:\t"<<id;
	cout<<"\nPhone number:\t"<<phonem;
	getch();
	cout<<"\n\nDisplaying your address:\n";
	getch();
	cout<<"\nState:\t"<<add.state;
	cout<<"\nCity:\t"<<add.city;
	cout<<"\nHouse name:\t"<<add.housename;
	cout<<"\nHouse number:\t"<<add.houseno;
	cout<<"\nPincode:\t"<<add.pincode;
	cout<<"\n";
	pd.displaypack();
}

char* customer::retf()
{
	return fname;
}

char* customer::retl()
{
	return lname;
}

long customer::retid()
{
	return id;
}

void customer::mod()
{
	cout<<"\nPlease enter your details:";
	cout<<"\nFirst Name:\t";
	gets(fname);
	cout<<"\nLast Name:\t";
	gets(lname);
	cout<<"\nPhone Number:\t";
	cin>>phonem;
	cout<<"\nPlease enter your address:\n";
	cout<<"State:\t";
	cin>>add.state;
	cout<<"\nCity:\t";
	cin>>add.city;
	cout<<"\nHousename:\t";
	cin>>add.housename;
	cout<<"\nHouse Number:\t";
	cin>>add.houseno;
	cout<<"\nPincode:\t";
	cin>>add.pincode;
	cout<<"\nAccepted!!";
}

void customer::mod1()
{
	n=1;
	pd.makepackage();
}


void dispallpack()
{
	fstream f;
	char ch;
	cout<<"\n\n";
	f.open("P1.txt", ios::in);
	while(f.get(ch))
	{
	 cout<<ch;
	}
	f.close();
	getch();
	cout<<"\n\n";
	f.open("P2.txt", ios::in);
	while(f.get(ch))
	{
	 cout<<ch;
	}
	f.close();
	getch();
	cout<<"\n\n";
	f.open("P3.txt", ios::in);
	while(f.get(ch))
	{
	 cout<<ch;
	}
	f.close();
	getch();
	cout<<"\n\n";
	f.open("P4.txt", ios::in);
	while(f.get(ch))
	{
	 cout<<ch;
	}
	f.close();
	getch();
	cout<<"\n\n";
	f.open("P5.txt", ios::in);
	while(f.get(ch))
	{
	 cout<<ch;
	}
	f.close();
	getch();
	cout<<"\n\n";
}


void writef()
{
	customer ob;
 	ofstream f;
	if(p==1)						//Write to trial file
	{
		f.open("trial.dat", ios::binary| ios::app);
		ob.accept();
		f.write((char*)&ob, sizeof(ob));
		f.close();
	}
	else
	{
		f.open("customers.dat", ios::binary|ios::app);
		ob.accept();
		f.write((char*)&ob, sizeof(ob));
		f.close();
	}
}

void readf()
{
 	ifstream f;
 	customer ob;
 	if(p==1)
	{
		f.open("trial.dat", ios::binary);
		while(f.read((char*)&ob, sizeof(ob)))
		{
		 ob.display();
		}
		f.close();
	}
 	else
	{
		f.open("customers.dat", ios::binary);
		while(f.read((char*)&ob, sizeof(ob)))
		{
		 ob.display();
		}
		f.close();
	}
}


int search(char* s, char* t, int a)
{
 	customer ob;
	ifstream fin;
 	fin.open("customers.dat", ios::binary|ios::in);
 	while(fin.read((char*)&ob,sizeof(ob)))
	{
	 if((strcmpi(s,ob.retf())==0)&&(strcmpi(t,ob.retl())==0)&&(a==ob.retid()))
	 {
		flag=1;
		cout<<"\nHELLO!\t"<<s<<" "<<t;
		break;
	 }
	 else
	 {
		flag=0;
	 }
 	}
 	return flag;
}


void dispdat(char* a, char* b, int c)			//no flags required
{
 	customer ob;
 	ifstream fin;
 	fin.open("customers.dat", ios::binary|ios::in);
 	while(fin.read((char*)&ob,sizeof(ob)))
 	{
	 if((strcmpi(a,ob.retf())==0)&&(strcmpi(b,ob.retl())==0)&&(c==ob.retid()))
	 {
		ob.display();
		break;
	 }
 	}
}	


void modifydet(char* u, char* y)
{
 	int ch;
 	customer ob;
 	ifstream fin;
 	ofstream fout;
 	fin.open("customers.dat", ios::binary);
 	fout.open("temp.dat", ios::binary);
 	cout<<"\nWhat would you like to modify?(1/2):";
 	cout<<"\n1. Personal Details";
 	cout<<"\n2. Package Details";
 	cout<<"\nEnter:\t";
 	cin>>ch;
 	if(ch==1)
	{
	 while(fin.read((char*)&ob,sizeof(ob)))
	 {
		if((strcmpi(u,ob.retf())==0)&&(strcmpi(y,ob.retl())==0))
		{
		 ob.mod();
		}
		fout.write((char*)&ob,sizeof(ob));
	 }
	}
	else
	{
	 while(fin.read((char*)&ob,sizeof(ob)))
	 {
		if((strcmpi(u,ob.retf())==0)&&(strcmpi(y,ob.retl())==0))
		{
		 ob.mod1();
		}
		fout.write((char*)&ob,sizeof(ob));
	 }
	}
 	fout.close();
 	fin.close();
 	remove("customers.dat");
 	rename("temp.dat","customers.dat");
}


void getfeedb(char *a, char* b, int c)
{
 	customer ob;
 	ifstream fin;
 	ofstream fout;
 	fin.open("customers.dat", ios::binary);
 	fout.open("temp.dat", ios::binary);
 	while(fin.read((char*)&ob,sizeof(ob)))
 	{
	 if((strcmpi(a,ob.retf())==0)&&(strcmpi(b,ob.retl())==0)&&(c==ob.retid()))
	 {
	 	cout<<"\nPlease Enter your Feedback!\n";
	 	gets(ob.feedback);
	 }
	 fout.write((char*)&ob,sizeof(ob));
 	}
 	fout.close();
 	fin.close();
 	remove("customers.dat");
 	rename("temp.dat","customers.dat");
}


void deletecust(char *a, char* b, int c)
{
	customer ob;
	int f=0;
 	ifstream fin;
 	ofstream fout;
 	fin.open("customers.dat", ios::binary);
 	fout.open("temp.dat", ios::binary);
 	while(fin.read((char*)&ob,sizeof(ob)))
 	{
	 f=1;
	 if((strcmpi(a,ob.retf())==0)&&(strcmpi(b,ob.retl())==0)&&(c==ob.retid()))
	 {
		f=0;
	 }
	 if(f==1)
	 	fout.write((char*)&ob,sizeof(ob));
 	}
 	fout.close();
 	fin.close();
 	remove("customers.dat");
 	rename("temp.dat","customers.dat");
} 


int checkpass()
{
	int i=0;
	char ch;
	char pswd[20];
	cout<<"\nPlease Enter the Password(Case Sensitive):\t";
	while((int)ch!=13)
	{
	 ch=getch();
	 if(ch!=13)
	 {
		cout<<"*";
		pswd[i]=ch;
		i++;
	 }
	}
	pswd[i]='\0';
	if(strcmpi(pswd,"password")==0)
		return 1;
	else
		return 0;
}


int main()
{
//	clrscr();
	int choice, temp, res;
	char ch,ch1,ans='y';
	x:
	system("cls");
	cout<<"\n\t\t\t WELCOME TO myDTH SERVICE\n";
	do
	{
	 cout<<"\n\t1. New Connection\n";
	 cout<<"\t2. Trial\n";
	 cout<<"\t3. Existing Connection\n";
	 cout<<"\t4. Admin Login\n";
	 cout<<"\t5. Exit\n";
	 cout<<"\n\tEnter your option(1/2/3/4/5)\t";
	 cin>>choice;
	 system("cls");
	 switch(choice)
	 {
		case 1:
			cout<<"\nWhat type of connection would you like?\n";
			cout<<"1. Standard(Rs. 500)\n";
			cout<<"2. HD(Rs. 750)\n";
			cout<<"(NOTE: This is only the price for set-top connection,\n";
			cout<<"\tchannels have to be paid for seperately.)\n";
			cout<<"Enter your choice(1/2):\t";
			cin>>temp;
			if(temp==1)
			{
				cout<<"You have selected Standard Connection. Your base fee is Rs.500\n";
				cout<<"Please Enter your Details for registration:\n";
				g=1;						//when writing data, fee=500+(50*5) else 750+(50*5)
				writef();
			}
			else
			{
				cout<<"You have selected HD Connection. Your base fee is Rs.750\n";
				cout<<"Please Enter your Details for registration:\n";
				writef();
			}
			cout<<"\nWould you like to continue?(Y to go to Main Menu/N to exit)";
			ch=getche();
			if((ch=='y')||(ch=='Y'))
				goto x;
			else
				exit(0);
		case 2:
			cout<<"\nWould you like to apply for a trial connection for a month?(Y/N)\n";
			ch1=getche();
			if((ch1=='y')||(ch1=='Y'))
			{
			 p=1;
			 writef();
			}
			else
			{
			 int m;
			 cout<<"\nDo you want to return to the main menu or exit(1/2)?\t";
			 cin>>m;
			 if(m==1)
			  goto x;
			 else
			  exit(0);
			}
			break;
		case 3:
			int n, b, v, z;
			char fnm[10], lnm[10];
			cout<<"\nPlease Enter First Name, Last Name and ID to login:\n";
			cout<<"\nEnter First Name:\t";
			gets(fnm);
			cout<<"\nEnter Last Name:\t";
			gets(lnm);
			cout<<"\nEnter ID:\t";
			cin>>n;
			b=search( fnm , lnm, n);
			if(b==0)
			{
				cout<<"\nINVALID!! Returning to Main Menu!";
				getch();
				goto x;
			}
			w:
			cout<<"\nWhat would you like to do?";
			cout<<"\n1. View Details";
			cout<<"\n2. Modify Details";
			cout<<"\n3. Feedback";
			cout<<"\n4. Unsubscribe";
			cout<<"\n5. Return to Main Menu";
			cout<<"\nEnter Choice(1/2/3):\t";
			cin>>v;
			switch(v)
			{
				case 1:
				dispdat(fnm , lnm, n);
				break;

				case 2:
				modifydet(fnm, lnm);
				break;

				case 3:
				getfeedb(fnm , lnm, n);
				break;
			
				case 4:
				char uns;
				cout<<"\nAre you SURE you want to unsubscribe?(y/n)\t";		
				uns=getche();
				if((uns=='y')||(uns=='Y'))
				{
					cout<<"\nUnsubscribing....";
					getch();
					deletecust(fnm , lnm, n);
					cout<<"\n\nDone...Returning to Main Menu.... Bye Bye :(";
					getch();
					goto x;
				}
				else
				{
					cout<<"\nReturning to User Menu.. :D";
					getch();
					goto w;
				}
				break;

				case 5:
				cout<<"\nLogging Out and returning to Main Menu...";
				getch();
				goto x;

				default:
				cout<<"\nERROR! Returning to main menu!";
				goto x;
			}
			cout<<"\nWould you like to return to User Menu, Main Menu, or exit?(1/2/3):\t";
			cin>>z;
			if(z==1)
			{
				cout<<"\nReturning to User Menu...";
				getch();
				goto w;
			}
			else if(z==2)
			{
				cout<<"\nReturning to Main Menu...";
				getch();
				goto x;
			}
			else
			{
				cout<<"\nExiting....";
				exit(0);
			}
		case 4:
			res=checkpass();
			if(res==1)
			{
				l:
				cout<<"\n1. Display all the existing members";
				cout<<"\n2. Display all the trial members";
				cout<<"\n3. Return to Main Menu";
				cout<<"\nEnter Choice(1/2/3):\t";
				int q;
				cin>>q;
				if(q==1)
				{
					p=0;
					readf();
					getch();
					goto l;
				}
				else if(q==2)
				{
					p=1;
					readf();
					getch();
					goto l;
				}
				else
				{
					cout<<"\nLogging Out.....";
					getch();
					goto x;
				}
			}
			else
			{
				cout<<"\nWrong Password! Returning to Main Menu!";
				goto x;
			}
		case 5:
			exit(0);
		default:
			cout<<"Error!!";
	 cout<<"Do you want to Continue?(y/n)";
	 ans=getche();
	 }
	}while((ans=='y')||(ans=='Y'));
	getch();
	return 0;
}
