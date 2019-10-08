#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<conio.h>
using namespace std;
void old_customer();
void new_customer();
void show();
void billing();
void display();
void display_name();
void  display_id();
void update();
void remove();
void hard();
void soft();
void enquiry();
void cont();
static int d,m;

/*..................................................class for billing...................................................*/

class bill
{
  public:
  int cid,no_days,date,month;
  char phone[20];
  char name[100];
  char bd[100];
  char add[100];
  float amount;
  	void input();
  	void output();
  	int match_id(int a);
  	int match_name(char b[100]);
};
/*.............................member function to take input.................*/
void bill::input()
{
  cout<<"ENTER CUSTOMER NAME - ";
  fflush(stdin);
  cin.getline(name,100);
  cout<<"ENTER CUSTOMER ID NUMBER - ";
  cin>>cid;
  cout<<"ENTER DATE (dd) - ";
  cin>>date;
  cout<<"ENTER MONTH (mm) - ";
  cin>>month;
  cout<<"CONTACT NUMBER - ";
  fflush(stdin);
  cin.getline(phone,20);
  cout<<"ENTER ADDRESS - ";
  cin.getline(add,100);
  cout<<"REPAIR DESCRIPTION - ";
  cin.getline(bd,100);
  cout<<"DAYS TO COMPLETE - ";
  cin>>no_days;
  cout<<"ENTER BILL AMOUNT - ";
  cin>>amount;
  
}

/*............................member function to display the bill............*/

void bill::output()
{
	cout<<"---------------------------BILL---------------------------"<<endl;
	cout<<"CUSTOMER NAME           - "<<name<<endl;
	cout<<"CUSTOMER ID             - "<<cid<<endl;
	cout<<"DATE                    - "<<date<<"/"<<month<<"/2019"<<endl;
	cout<<"DAYS TO COMPLETE        - "<<no_days<<endl;
	cout<<"PHONE NUMBER            - "<<phone<<endl;
	cout<<"ADDRESS                 - "<<add<<endl;
	cout<<"REPAIR                  - "<<bd<<endl;
	cout<<"NO.OF DAYS              - "<<no_days<<endl;
	cout<<"AMOUNT(incls.all taxes) - "<<amount<<endl;
	cout<<"******************************************************************************************************"<<endl;
}
/*...................member function to conform the id............*/
int bill::match_id(int a)
{
	if(a==cid)
	return 1;
	else
	return 0;
}

/*.....................member function to conform the name.........*/

int bill::match_name(char b[20])
{
	if(b==name)
	return 1;
	else
	return 0;
}
/*...............................................main function............................................................*/
int main()
{
	system("Color 5E");
	cout<<"                        ***********************************  WELCOME TO RT REPAIRS  **************************************"<<endl<<endl;
	cout<<"                        ****************************************HAVE A NICE DAY*******************************************"<<endl<<endl;
	cout<<"DATE(dd) - "<<endl;
	cin>>d;
	cout<<"MONTH(mm) - "<<endl;
	cin>>m;
	cont();
	cout<<endl<<"                                                      THANK YOU                                            "<<endl;
	cout<<endl<<"                                                     VISIT AGAIN                                           "<<endl;
}
void cont()
{
	int choice;
	do
	{
	int b,a;
	cout<<"1 ->HARDWARE REPAIRS"<<endl<<"2 ->SOFTWARE REPAIRS"<<endl;
	cin>>b;
	switch(b){
		case 1:hard();
		      break;
		case 2:soft();
		      break;
	}
	cout<<"******************************************************************************************************"<<endl;
	cout<<"ENTER 1 FOR OLD CUSTOMER \nENTER 2 FOR NEW CUSTOMER"<<endl;
	cout<<"ENTER 3 TO VIEW ALL THE RECORDS"<<endl;
	cout<<"ENTER 4 FOR ENQUIRY OF PROGRESS"<<endl;
	cin>>a;
	
	switch(a)
	{
		case 1:old_customer();
		       break;
		case 2:new_customer();
		       break;
		case 3:show();
		       break;
		case 4:enquiry();
		       break;
	}
	cout<<"ENTER 1 TO CONTINUE....."<<endl;
	cin>>choice;
   }
   while(choice == 1);
}
/*....................................displaying hardware problems........................................................*/
void hard()
{
	cout<<"******************************************************************************************************"<<endl;
	fstream file("hard.txt",ios::in);
	char c;
	c = file.get();
	while(c != EOF){
		cout<<c;
		c = file.get();
	}
}
/*.....................................displaying software problems........................................................*/
void soft()
{
	cout<<"******************************************************************************************************"<<endl;
	fstream file("soft.txt",ios::in);
	char c;
	c = file.get();
	while(c != EOF){
		cout<<c;
		c = file.get();
	}
}

/*........................................displaying preferences for old customer...........................................*/
void old_customer()
{
	cout<<"******************************************************************************************************"<<endl;
	int ch;
	cout<<"\nENTER 1 TO DISPLAY PREVIOUS BILL RECORD";
	cout<<"\nENTER 2 TO UPDATE PREVIOUS BILL ";
	cout<<"\nENTER 3 TO DELETE BILL RECORD ";
	cout<<"\nENTER 4 TO CREATE NEW BILL ";
	cin>>ch;
	switch(ch)
	{
		case 1:display();
		       break;
		case 2:update();
		       break;
	   	case 3:remove();
		       break;
		case 4:billing();
		       break;
	}
}
/*........................................displaying preferences for new customer..............................................*/
void new_customer()
{
	billing();
}
/*................................................to display alll customer details............................*/
void show()
{
   string pass ="";
   char ch;
   cout << "Enter password\n";
   ch = _getch();
   while(ch != 13){                                    
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "RT123")
   {
   	cout<<"ACESS GRANTED "<<endl;
	bill vinay1;
	fstream file("billdetails.txt",ios::ate|ios::in|ios::binary);
	int size = file.tellp();
	int objects = file.tellp()/sizeof(vinay1);
	file.seekg(0);
	cout<<"******************************************************************************************************"<<endl;
	cout<<"TOTAL SIZE OF RECORD - "<<size<<endl;
	cout<<"TOTAL CUSTOMERS IN RECORD - "<<objects<<endl;
	for(int i = 0;i<objects;i++)
	{
		file.read((char *)&vinay1,sizeof(vinay1));
		vinay1.output();
	}
	file.close();
   }
   else
   {
   	 cout<<endl<<"ACCESS DENIED"<<endl;
   }
}
/*.................................function for billing...................*/
void billing()
{
	string pass ="";
   char ch;
   cout << "Enter password\n";
   ch = _getch();
   while(ch != 13){                                     
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "RT123")
   {
   	cout<<"ACCESS GRANTED"<<endl;
	bill vinay2;
	cout<<"******************************************************************************************************"<<endl;
	fstream file("billdetails.txt",ios::app|ios::out|ios::binary);
	vinay2.input();
	vinay2.output();
	file.write((char *)&vinay2,sizeof(vinay2));
	file.close();
   }
   else
   {
   	cout<<"ACCESS DENIED"<<endl;
   }
}
/*.................................main display function to search and display............*/
void display()
{
	cout<<"******************************************************************************************************"<<endl;
	int se;
    cout<<"\nENTER 1 TO SEARCH BY NAME,2 TO SEARCH BY ID - ";
    cin>>se;
    switch(se)
    {
    	case 1:display_name();
    	         break;
    	case 2:display_id();
    	       break;
	}
}
/*................................to display by name of costumer...............*/
void display_name()
{
	string pass ="";
   char ch;
   cout << "Enter password\n";
   ch = _getch();
   while(ch != 13){                                     
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "RT123")
   {
   	cout<<"ACCESS GRANTED"<<endl;
	bill vinay;
	cout<<"******************************************************************************************************"<<endl;
	char see_name[20];
	fstream file("billdetails.txt",ios::in|ios::binary);
	int flag = 0;
	fflush(stdin);
	cout<<"ENTER THE NAME - ";
	cin.getline(see_name,20);
	file.seekg(0);
	for(int i = 0;i<10;i++)
	{
		file.read((char *)&vinay,sizeof(vinay));
		if(vinay.match_name(see_name)==1)
		{
			flag = 1;
			break;
		}
	}
	if(flag==1)
	{
		vinay.output();
	}
	else
	{
		cout<<endl<<"CUSTOMER NAME NOT FOUND";
		exit(0);
	}
	file.close();
    }
    else
    {
    	cout<<"ACCESS DENIED"<<endl;
	}
}
/*...............................to display by id of costumer.......................*/
void display_id()
{   
     string pass ="";
   char ch;
   cout << "Enter password\n";
   ch = _getch();
   while(ch != 13){                                    
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "RT123"){
   	cout<<"ACCESS GRANTED"<<endl;
	bill vinay3;
	cout<<"******************************************************************************************************"<<endl;
	do
  {
	int see_id;
	fstream file("billdetails.txt",ios::in|ios::out|ios::binary);
	int flag = 0;
	cout<<"ENTER COSTUMER ID - "<<endl;
	cin>>see_id;
	cout<<"******************************************************************************************************"<<endl;
	file.seekg(0);
	for(int i = 0;i<10;i++)
	{
		file.read((char *)&vinay3,sizeof(vinay3));
		if(vinay3.match_id(see_id)==1)
		{
			flag = 1;
			break;
		}
	}
	if(flag==1)
	{
		vinay3.output();
		break;
	}
	else
	{
		cout<<"CUSTOMER ID NOT FOUND"<<endl;
	    break;
	}
	file.close();
  }while(1);
  }
  else
  {
  	cout<<"ACCESS DENIED";
  }
}
/*...............to update the details of costumer..........................*/
void update()
{
	string pass ="";
   char ch;
   cout << "Enter password\n";
   ch = _getch();
   while(ch != 13){                                     
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "RT123"){
   	cout<<"ACCESS GRANTED"<<endl;
	bill vinay4;
	cout<<"******************************************************************************************************"<<endl;
	cout<<"USE ID TO UPDATE "<<endl;
	fstream file("billdetails.txt",ios::ate|ios::in|ios::out|ios::binary);
	int du = 0;
  do
  {
	int see_id;
	
	int flag = 0;
	cout<<"ENTER COSTUMER ID - "<<endl;
	cin>>see_id;
	cout<<"******************************************************************************************************"<<endl;
	file.seekg(0);
	for(int i = 0;i<10;i++)
	{
		file.read((char *)&vinay4,sizeof(vinay4));
		du = du + sizeof(vinay4);
		if(vinay4.match_id(see_id)==1)
		{
			flag = 1;
			break;
		}
	}
	if(flag==1)
	{
		vinay4.output();
		break;
	}
	else
	{
		cout<<"CUSTOMER ID NOT FOUND"<<endl;
		break;
	}
  }while(1);
	du = du / sizeof(vinay4);
	du = (du-1)*sizeof(vinay4);
	file.seekp(du);
	cout<<"ENTER THE NEW DETAILS - - "<<endl;
	vinay4.input();
	file.write((char *)&vinay4,sizeof(vinay4));
	file.close();
    }
    else
    {
    	cout<<"ACCESS DENIED"<<endl;
	}
}
/*.................to delete the details of a costumer.......................*/
void remove()
{
	string pass ="";
   char ch;
   cout << "Enter password\n";
   ch = _getch();
   while(ch != 13){                                     
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "RT123")
   {
   	cout<<"ACCESS GRANTED"<<endl;
	bill vinay5;
	int du = 0;
	fstream file("billdetails.txt",ios::ate|ios::in|ios::out|ios::binary);
	fstream FILE("billdetails2.txt",ios::in|ios::out|ios::binary);
	int total_size = file.tellp();
	int total_objects = file.tellp()/sizeof(vinay5);
    do
  {
	int see_id;
	
	int flag = 0;
	cout<<"ENTER COSTUMER ID - "<<endl;
	cin>>see_id;
	cout<<"******************************************************************************************************"<<endl;
	file.seekg(0);
	for(int i = 0;i<10;i++)
	{
		file.read((char *)&vinay5,sizeof(vinay5));
		du = du + sizeof(vinay5);
		if(vinay5.match_id(see_id)==1)
		{
			flag = 1;
			break;
		}
	}
	if(flag==1)
	{
		vinay5.output();
		break;
	}
	else
	{
		cout<<"CUSTOMER ID NOT FOUND"<<endl;
		break;
	}
  }while(1);
	file.seekg(0);
	FILE.seekg(0);
	du = du / sizeof(vinay5);
	for(int i = 0;i<du-1;i++)
	{
		file.read((char *)&vinay5,sizeof(vinay5));
		FILE.write((char *)&vinay5,sizeof(vinay5));
    }
    file.seekg(0);
    int loc = du*sizeof(vinay5);
    file.seekg(loc);
    for(int i=0;i<total_objects-du-1;i++)
    {
    	file.read((char *)&vinay5,sizeof(vinay5));
    	FILE.write((char *)&vinay5,sizeof(vinay5));
	}
	FILE.seekg(0);
	cout<<endl<<"THE CUSTOMER INFORMATION IS DELETED";
   }
   else
   {
   	cout<<"ACCESS DENIED"<<endl;
   }
}
/*..........................................enquiry function..........................*/
void enquiry()
{
	string pass ="";
   char ch;
   cout << "Enter password\n";
   ch = _getch();
   while(ch != 13){                                     
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   
   if(pass == "RT123")
   {
   	cout<<"ACCESS GRANTED"<<endl;
	bill vinay6;
	int eid;
	fstream file("billdetails.txt",ios::ate|ios::in|ios::binary);
	int date_con,days,mon,mon_days = 30;
	char name_con[20];
	int diff,left;
	int size = file.tellp();
	int objects = file.tellp()/sizeof(vinay6);
	file.seekg(0);
	cout<<"ENTER CUSTOMER ID - ";
	cin>>eid;
	
	cout<<"******************************************************************************************************"<<endl;
	
	for(int i = 0;i<objects;i++)
    {
		file.read((char *)&vinay6,sizeof(vinay6));
		if(vinay6.match_id(eid)==1)
		{
			date_con = vinay6.date;
			days = vinay6.no_days;
			mon = vinay6.month;
			break;
	    }
	}
	if(m%2 != 0 && m == 8)
	{
		mon_days = 31;
	}
	else
	{
		if(m == 02)
		mon_days = 29;
		else
		mon_days = 30;
	}
	if(m == mon)
	{
	  diff = d - date_con;
	  left = days - diff;
	}
	else
	{
		int lft_pre_mon = mon_days - date_con;
		int early = lft_pre_mon + d;
		left = days - early;
	}
	if(left)
	{
		if(left == 1)
		{
			cout<<vinay6.name<<" ,YOUR LAPTOP REPAIR IS NOT COMPLETED,SO KINDLY COME TOMMORROW TO COLLECT IT."<<endl;
	    }
	    else
	    {
	      cout<<vinay6.name<<" ,YOUR LAPTOP REPAIR IS NOT YET COMPLETED,SO KINDLY COME AFTER "<<left<<" DAYS TO COLLECT IT."<<endl;	
		}
	}
	else
	{
		cout<<vinay6.name<<" ,PLEASE WAIT FOR FEW MINUTES"<<endl;
	}
    }
    else
    {
    	cout<<"ACCESS DENIED"<<endl;
	}
	
}

