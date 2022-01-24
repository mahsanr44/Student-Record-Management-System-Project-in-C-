#include <iostream>// FOR INPUT OUTPUT
#include <fstream>// FOR FILING
#include <windows.h>// FOR SLEEP
#include <cstring>// FOR STRING
#include <conio.h> // for getch che char
#include <process.h>//for exit
#include <stdlib.h>// for SYSTEM()
#include<iomanip>//colouring
using namespace std;
////dorate the whole programe////
int sum1=0;                                 //global variables
	int m;
	string name;
	char adress[20];
	int marks;
	string rollno;
	int choice;
	void add_record()
	{
		system("color 6");
	    sum1=0;
		ofstream paym;
		paym.open("record.txt", ios::out | ios::app);
		{
		    system("cls");
		    cout << "\t\t\t\t*****ENTER RECORD*****" << endl;
		    cout << "\nENTER NAME:" << endl;
		    cin >> name;
		    cout << "ENTER ROLLNO:" << endl;
		    cin >> rollno;
		    cout << "ENTER ADRESS:" << endl;
		    cin >> adress;
		    cout<<endl;
		    cout<<"\t\t\tNOTE! Every book have 100 Marks..."<<endl;
		    cout<<"\n\tSo, How many Subject's Marks You Want to Enter:"<<endl;
		    cin>>choice;
		    for(int i=1;i<=choice;i++)
		{
         s:
		cout << "ENTER MARKS OF SUBJECT NO "<<i<<":"<< endl;
		cin >> m;
		if(m>100)
		{
			cout<<"PLEASE ENTER LESS THAN 100 MARKS"<<endl;
			goto s;                              //goto statement is used to move control directly to specific location 
		}
		else
		    {
		        sum1 = sum1 + m;
	        }
	    }
        paym << name<< " " << rollno << " " << adress << " " << sum1 << " "  << endl; //writing data in file by using insertion operator "<<"
		// output stream for computer;
		paym.close();  //closing file
		}
	}
	void show()
	{
		system("color B");
		int a = 0;     //integer intiliaze with zero
		ifstream paymmm;      //input file stream with object paymmm
		paymmm.open("record.txt", ios::in);    //opening file
		paymmm >> name >> rollno >> adress >> sum1;    //program reading data from file output data to a program 
		if (!paymmm)     //check if file not opened;
		{
			cout << "YET NO RECORD ENTER" << endl;
		}
		else    //if file is open then visit the file from start to end   
			while (!paymmm.eof())      //eof end of file
			{
				a++;
				cout<<"\nRECORD NO:"<<a<<endl;
				cout  << "\n\tI)" << "NAME: " << name << endl;
				cout  << "\tII)" << "ROLLNO: " << rollno << endl;
				cout  << "\tIII)" << "ADRSSS: " << adress << endl;
				cout  << "\tIV)" << "MARKS: " << sum1 << endl;
				cout << "............................." << endl;
				paymmm >> name >> rollno >> adress >> sum1;      //program reading data from file
			}
	}///////
	void search()
	{
		system("color C");
	    int a=0,f=0;
	    string rollno3;
		ifstream book;
		book.open("record.txt", ios::in);
		book >> name>> rollno >> adress >>sum1 ;// program reading data from file 
		cout << "ENTER ROLLNO TO SEARCH A RECORD THAT YOU WANT:" << endl;
		cin >> rollno3;
		if (!book) 
		    { 
			    cout << "SORRY! NO RECORD FOUND."; 
			}
		else
			while (!book.eof())
			{
				if (rollno3==rollno)
				{
				f = 1;
					a++;
				cout<<"\nRECORD NO:"<<a<<endl;
				cout  << "\n\tI)" << "NAME: " << name << endl;
				cout  << "\tII)" << "ROLLNO: " << rollno << endl;
				cout  << "\tIII)" << "ADRSSS: " << adress << endl;
				cout  << "\tIV)" << "MARKS: " << sum1 << endl;
				cout << "............................." << endl;
     		break;
				}
				else
				book >> name >> rollno >>adress>>sum1;//  program reading data from file
			}
		if(f==0)
		{
			cout<<"THIS ROLLNO HAS NO RECORD"<<endl;
		}
		book.close();
	}
	///////////////
void delet()
	{
	 system("color F");
    	int f=0;
    	string rollno1;
		ifstream book;   //stream class is used to read from file
		book.open("record.txt", ios::in);
		book >> name>> rollno >> adress >>sum1 ;//program reading data from file
		//creating a new file
		ofstream of1;     //stream class is used to write on file
		of1.open("delete.txt", ios::out); 
		if (!of1) 
		    {
			cout << "Error in system" << endl;
			}
		    else
		    {
		cout << "ENTER A ROLLNO TO DELETE RECORD:" << endl;
		cin >> rollno1;
		if (!book)
		{
		cout<<"SORRY! NO RECORD FOUND";
		}
		else
			while (!book.eof())
			{		
				if (rollno1==rollno)
				{
				f = 1;
					cout << "RECORD DELETED SUCCESSFULLY" << endl;
				}
				else
                of1<<name << " " << rollno << " " << adress << " " << sum1 << " " <<endl; // writing data on new file 
                //below line have no concern with above else line statement
				book >> name >> rollno >>adress>>sum1 ;   //program reading data from file
			}
		    if(f==0)
		    {
			    cout<<"THIS ROLLNO HAVE NO RECORD"<<endl;
		    }
		    book.close();
		    of1.close();
		    remove("record.txt");
		    rename("delete.txt", "record.txt");
	}}
	///////
	void update()
	{   
	    system("color 5");
		int f1=0;
		string rollno2;
		ifstream book;
		book.open("record.txt", ios::in);
		book >> name>> rollno >> adress >>sum1 ;
		ofstream of2;
		of2.open("update.txt", ios::out); 
		if (!of2)
		{
		 cout << "Error in system" << endl;
		}
		else
		{
		cout << "ENTER ROLLNO TO UPDATE A RECORD:" << endl;
		cin >> rollno2;
		if (!book)
		{
		cout<<"SORRY! NO RECORD FOUND";
		}
		else
			while (!book.eof())
			{
				
				if (rollno2== rollno)
				{
				f1 = 1;
            system("cls");
		cout << "\t\t\tENTER NEW RECORD" << endl;
		cout << "ENTER  NEW NAME:" << endl;
		cin >> name;
		cout << "ENTER NEW  ROLLNO" << endl;
		cin >> rollno;
		cout << "ENTER  NEW ADRESS:" << endl;
		cin >> adress;
		cout<<endl;
	   cout<<"\t\t\tNOTE! Every book have 100 Marks..."<<endl;
		    cout<<"\n\tSo, How many Subject's Marks You want to Enter:"<<endl;
		cin>>choice;
		for(int i=1;i<=choice;i++)
		{
         s:
		cout << "ENTER THE MARKS OF SUBJECT "<<i<<":"<< endl;
		cin >> m;
		if(m>100)
		{
			cout<<"PLEASE ENTER LESS THAN 100 MARKS"<<endl;
			goto s;     //goto statement is used to move control directly to specific location 
		}
		else
		{
		sum1 = sum1 + m;
	    }
	      }
            of2<< name<< " " << rollno << " " << adress << " " << sum1 << " " <<endl;// program writing data from file
        }      
        else
            of2<<name << " " << rollno << " " << adress << " " << sum1 << " " <<endl;// program writing on file
// below line have no concern with else statement
				book >> name >> rollno >>adress>>sum1 ; 
			}
		if(f1==0)
		{
			cout<<"THIS ROLLNO HAS NO RECORD"<<endl;
		}
		book.close();
		of2.close();
		remove("record.txt");
		rename("update.txt", "record.txt");
	}}
int main()
{
	char x;
	do {
		long int choice;         //for choice in main to calling fun...
		char goback;
		    //for do while loop
		 char select[10];
		    	system("color 4");
		 	cout<<"\n\n";
		 	cout<<"   $$$$  $$$$$  $   $  $$$$$    $$$$  $$   $  $$$$$  $$$$       $$$$$   $$$$$$  $$$$$$  $$$$$$$    $$$$$   $$$$$$      "<<endl;
		 	cout<<"   $       $    $   $  $    $   $     $ $  $    $    $          $   $$  $       $       $     $    $   $$  $     $     "<<endl;
		 	cout<<"   $$$$    $    $   $  $    $$  $$$$  $  $ $    $    $$$$       $$$$$   $$$$$   $       $     $    $$$$$   $     $$    "<<endl;
		 	cout<<"      $    $    $   $  $    $   $     $   $$    $       $       $   $   $       $       $     $    $   $   $     $     "<<endl;
		 	cout<<"   $$$$    $    $$$$$  $$$$$    $$$$  $    $    $    $$$$       $    $  $$$$$$  $$$$$$  $$$$$$$    $    $  $$$$$$      "<<endl;
		 	cout<<"\n\n\n\n\nPRESENTED BY:";
		 	cout<<"\n\t\tM.AHSAN RAZA\n\t\tAQSA NASEER\n\t\tSAHAR FATIMA";
		 	cout<<"\n\nSUBMITTED TO:";
		 	cout<<"\n\t\tMs. IRUM RUBAB\n\n"<<endl;
		 	    system("pause");
		 		system("cls");
		 		system("color 1"); 
			string password ="student";
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t*****LOGIN*****"<<endl;
			cout<<"\n\n\n\n\t\t\t\tInstitute: PMAS-ARID AGRICULTURE UNIVERSITY RAWALPINDI";
		cout << "\n\t\t\t\tPassword : ";
		cin >> select;
		system("cls");
		if (select == password)//if user then call
		{
			do 
			  {
			  	Sleep(500);
				system("color 2");
				cout << "\t\t\t1)ENTER RECORD" << endl;
				cout << "\t\t\t2)SHOW RECORD" << endl;
				cout << "\t\t\t3)SEARCH RECORD" << endl;
				cout << "\t\t\t4)DELETE RECORD" << endl;
				cout << "\t\t\t5)UPDATE RECORD" << endl;
				cout << "\t\t\t6)LOGOUT" << endl;
				cout << "Enter Your Choice:\n";
				cin >> choice;
				system("cls");
				switch (choice)
				{
				case 1:
					add_record(); break;
				case 2:
					show(); break;
				case 3:
					search(); break;
				case 4:
					delet(); break;
				case 5:
					update(); break;
	            case 6:
					exit(0);
				default:
					cout << "Invalid Choice" << endl;
				}
				cout << "Enter y to go back to Main Menu." << endl;
				cin >> goback;
				system("cls");
			  }
			 while
			 (goback == 'y' || goback == 'Y'); 
			 system("cls");
		 } 
		else
		 {
			cout<<"\nOPPS! WRONG PASSWORD\n"<<endl;
		 }
		 cout << "\nENTER Y TO TRY AGAIN" << endl;
		 cin >> x;
	}
	while (x == 'y' || x == 'Y');
}
