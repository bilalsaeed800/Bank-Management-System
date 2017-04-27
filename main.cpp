#include<iostream>
#include<conio.h>
#include<sstream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<fstream>
#include"INFO.h"
#include"ACCOUNT.h"
using namespace std;

/**********************************
************LOGIN PHASE************
**********************************/
struct LOGIN{
	int ID;
	string password;
};

LOGIN login();

/********************************************************
*****************  FILING FUNCTIONS HEADERS *************
********************************************************/

void create_account(vector<Customer>&,vector<Manager>&);
void Manager_File(vector<Manager>&,Manager&);
void Customer_File(vector<Customer>&,Customer&);
void Password_File(vector<string>&);
void modify_account(vector<Manager>&,vector<string>&);
void delete_account(vector<Customer>&,vector<string>&);
bool Check_file();
void modify_account(vector<Customer>&,vector<string>&,int);
/********************************************************
*****************  MENU FUNCTION ************************
********************************************************/
void Menu(vector<Customer>&,vector<string>&,int);
void Menu(vector<Manager>&,vector<Customer>&,vector<string>&);

/********************************************************
*****************  MAIN FUNCTION ************************
********************************************************/

int main (){
	system("color C7");
	static int starter=0;
	if(starter==0){
		cout<<"*****************************************************\n";
		cout<<"**          BANK MANAGEMENT SYSTEM                 **\n";
		cout<<"*****************************************************\n";
		system("pause");
		system("cls");
		starter++;
	}
	int check1;
	Customer c1(0);
	Manager m1(0);
    vector<Customer> c_vec;
    vector<Manager> m_vec;
    vector<string> pass;
	LOGIN manager_login;
	LOGIN customer_login;
	system("cls");
	Password_File(pass);
	Manager_File(m_vec,m1);
	Customer_File(c_vec,c1);
	if(Check_file()){
	cout<<"First Create A Manager"<<endl;
	Manager obj;
    obj.Write_account(obj);
	}//end if
	Password_File(pass);
	Manager_File(m_vec,m1);
	cout<<"1. MANAGER \n2. CUSTOMER"<<endl;
	cin>>check1;
	if(check1==1){
	manager_login=login();
    if(manager_login.password==pass[0]){
    system("color A0");
	cout<<" ACCESS GRANTED "<<endl;
    system("pause");
	system("cls");
	Menu(m_vec,c_vec,pass);
	}//end if
	else{
	system("color C0");
	cout<<"WRONG PASSWORD "<<endl;
	}
	}//end if
	else if(check1==2){
        customer_login=login();
        for(int i=0;i<c_vec.size();i++){
         	if(customer_login.ID==c_vec[i].get_ID()){
         		if(customer_login.password==pass[i+1]){
         		 system("color A0");
				 cout<<" ACCESS GRANTED "<<endl;
         		 system("cls");
         		 Menu(c_vec,pass,customer_login.ID);
         		}//end if
         		else{
         			system("color C0");
					cout<<"Wrong password"<<endl;
				}//end else
			}//end if
		}//end for
	}//end else if
	else
	cout<<"INVALID INPUT "<<endl;
	
	system("pause");
	main();
	return 0;
}


/*******************************************
************  LOGIN FUNCTION ***************
*******************************************/

LOGIN login(){
	char array[5]; 
	char c;
	int a;
	system("cls");
	LOGIN temp;
	cout<<"ID : ";cin>>temp.ID;cout<<endl;
	cout<<"PASSWORD (only six characters): ";
	int i=0;
	while(i<6)
	{
		a=c=getch();
		if(a==8){
			cout<<"\b \b";
			if(i==0){
			i=0;
			}
			else if(i>0){
			i--;
			}
		}
		else if((a>=0 && a<=7) || (a>=9 && a<=32) || (a==127)){
			cout<<"\nINVALID YOU HAVE TO WRITE IT AGAIN!!"<<endl;
			system("pause");
			return login();
		}
		else{
		array[i]=c;
		cout<<"*";
		i++;
		}
	}
	system("cls");
	temp.password=array;	
	return temp;
}

/********************************************************
*****************  MANAGER MENU *************************
********************************************************/

void Menu(vector<Manager>&m_vec,vector<Customer>&c_vec,vector<string>&pass){
	int inp;
	system("cls");
		cout<<"1. DISPLAY PERSONAL INFO "<<endl;
     	cout<<"2. CREATE NEW ACCOUNT "<<endl;
		cout<<"3. DELETE AN ACCOUNT "<<endl;
		cout<<"4. DISPLAY ALL ACCOUNTS LIST "<<endl;
		cout<<"5. MODIFY ACCOUNT'S DATA "<<endl;
		cout<<"6. EXIT "<<endl;
		cout<<"ENTER YOUR CHOICE (1-6) : "<<endl;
		cin>>inp;
    	switch(inp){
    	case 1:
        {
        m_vec[0].Display();
        system("pause");
        Menu(m_vec,c_vec,pass);
        break;	
    	}//end case1
        case 2:
        {
        create_account(c_vec,m_vec);
        system("pause");
		Menu(m_vec,c_vec,pass);	
		break;				
        }//end case2              						
		case 3:
        {
        delete_account(c_vec,pass);
        system("pause");
        Menu(m_vec,c_vec,pass);
		break;
        }//end case3	
		case 4:
		{
		c_vec[0].read_file();
		system("pause");
        Menu(m_vec,c_vec,pass);
		break;
        }//end case4      					    	 
        case 5:
        {     
        modify_account(m_vec,pass);
		system("pause");                           
	  	Menu(m_vec,c_vec,pass);
		break;
        }//end case 5
        case 6:
        {
        	cout<<"Successfully exit...........!!!! "<<endl;
        	system("pause");
			break;
        }
        default:
        {
        	system("color C0");
        	cout<<"INVALID INPUT"<<endl;
        	system("pause");
        	Menu(m_vec,c_vec,pass);
        }
	}//end switch
}

/*******************************************************
**************  CUSTOMER MENU **************************
*******************************************************/

void Menu(vector<Customer>&c_vec,vector<string>&pass,int id){
	system("cls");
    int choice;
	char c;
	cout<<"1.DISPLAY YOUR PROFILE "<<endl;
	cout<<"2.WITHDRAW YOUR AMOUNT "<<endl;
	cout<<"3.DEPOSIT AMOUNT IN ACCOUNT "<<endl;
	cout<<"4.EDIT YOUR PROFILE "<<endl;
	cout<<"5.EXIT "<<endl;
	cout<<"ENTER YOUR CHOICE : ";cin>>choice;cout<<endl;
	if(choice==1){
	c_vec[id].Display();
	system("pause");
	}//end if
	else if(choice==2){
		int x;
		cout<<"ENTER THE AMOUNT YOU WANT TO WITHDRAW : ";cin>>x;cout<<endl;
		c_vec[id].Withdraw(x);
		system("pause");
		Menu(c_vec,pass,id);
	}//end else if
	else if(choice==3){
		int x;
		cout<<"ENTER THE AMOUNT YOU WANT TO DEPOSIT : ";cin>>x;cout<<endl;
		c_vec[id].Deposit(x);
		system("pause");
		Menu(c_vec,pass,id);
	}//end else if
	else if(choice==4){
		modify_account(c_vec,pass,id);
		system("pause");
		Menu(c_vec,pass,id);
	}
	else if(choice==5){
		cout<<"Successfully termianting ! "<<endl;
	}
	else{
		cout<<"INVALID INPUT"<<endl;
	}	
}

/****************************************************************
******************* SET PASSWORD FUNCTION  ***************************
****************************************************************/
 
void set_pass(vector<string> &v1){
		ofstream enter("password.txt");
		for(int j=0;j<v1.size();j++){
		  enter<<v1[j]<<"\n";
		}
}

/****************************************************************
******************* CHECK FUNCTION  ***************************
****************************************************************/
 
bool Check_file(){
	string line;
	int counter=0;
	ifstream from_file("manager.txt");
		while(getline(from_file,line))
		{
			counter++;
		}
	from_file.close();
	if(counter==0)
	return true;
	else
	return false;
}

/****************************************************************
******************* MANGER MODIFY FUNCTION  *********************
****************************************************************/
 
void modify_account(vector<Manager>&vec,vector<string>&pass){
 	string ph;
    string hhh,ppp;
	remove("manager.txt");
	remove("manag.txt");
	remove("password.txt");
	cin.ignore();
	for(int i=0;i<pass.size();i++){
		if(i==0){
			cout<<"Enter the new pasword "<<endl;
			cin>>pass[0];
		}//end if
  	}//end for
   	set_pass(pass);
  	cout<<"Enter New Cell Number "<<endl;
  	cin>>ph;
  	vec[0].set_celldd(ph);
  	cin.ignore();
  	cout<<"Enter New Address "<<endl;
  	getline(cin,hhh);
   	vec[0].set_Add(hhh);
	vec[0].Write_account(vec[0]);
}

/****************************************************************
******************* CUSTOMER MODIFY FUNCTION  *******************
****************************************************************/ 
void modify_account(vector<Customer>&vec,vector<string>&pass,int id){
 	string ph;
    string hhh,ppp;
	remove("semester.txt");
	remove("semes.txt");
	remove("password.txt");
	cin.ignore();
//	for(int i=0;i<pass.size();i++){
//		if(i==0){
			cout<<"Enter the new pasword "<<endl;
			cin>>pass[id];
//		}//end if
//  	}//end for
   	set_pass(pass);
  	cout<<"Enter New Cell Number ";cin>>ph;cout<<endl;
  	vec[id].set_celldd(ph);
  	cin.ignore(0);
  	cout<<"Enter New Address ";getline(cin,hhh);cout<<endl;
   	vec[id].set_Add(hhh);
	vec[id].write_account(vec[id]);
}

/****************************************************************
******************* DELETE FUNCTION  ***************************
****************************************************************/

void delete_account(vector<Customer>&h,vector<string>&mmm1){
     int idd;
	 remove("semester.txt");
     remove("semes.txt");
     remove("password.txt");
     cout<<"Enter the ID := ";cin>>idd;
     for(int i=0;i<h.size();i++){
    	if(idd==h[i].get_ID()){
	 		h.erase(h.begin()+i);
	 		mmm1.erase(mmm1.begin()+(i+1));
  		}//end if
  	 }//end for
  	 for(int i=0;i<h.size();i++){
     		h[i].write_account(h[i]);
	 }//end for
	 set_pass(mmm1);
}

/****************************************************************
******************* CREATE FUNCTION  ***************************
****************************************************************/

void create_account(vector<Customer>&h,vector<Manager>&mmm){
	info *ptr;
	if(h.size()==0){
	ptr->set1_id((mmm[mmm.size()-1].get_ID())+1);
	}//end if
	if(h.size()!=0){
    ptr->set1_id((h[h.size()-1].get_ID())+1);
    }//end if
    Customer temp;
 	temp.write_account(temp);
}
/************************************************************************
************************    MANAGER FILE  *******************************
*************************************************************************/

void Manager_File(vector<Manager>&mmm,Manager &u1){
	int counter=0;
	string line;
	int i1;
	string s1,s2,s3,s4;
	string li1;
	ifstream manager("manag.txt");
	if(manager.is_open())
	{
		while(getline(manager,line))
		{
			if(counter==0)
			{
					istringstream buffer(line);
					buffer>>i1;
					u1.set_id(i1);
			}//end if
			if(counter==1)
			{
					istringstream buffer(line);
					buffer>>s1;
					u1.set_name(s1);
			}//end if
			if(counter==2)
			{
					istringstream buffer(line);
					buffer>>s2;
					u1.set_fathe_name(s2);	 
			}//end if
			if(counter==3)
			{
					istringstream buffer(line);
					buffer>>s3;
					u1.set_Add(s3);	 
			}//end if
			if(counter==4)
			{
					istringstream buffer(line);
					buffer>>li1;
					u1.set_celldd(li1);
			}//end if
			if(counter==5)
			{
					istringstream buffer(line);
					buffer>>s4;
					u1.set_CI(s4);
		    }//end if
		 	counter++;	
	    }//end while
	mmm.push_back(u1);
	}//end if
manager.close();
}//end func

/*************************************************************************
*************************    CUSTOMER FILE  ******************************
*************************************************************************/

void Customer_File(vector<Customer>&h,Customer&q1){
	double d1;
	string line;
	int i1;
	string s1,s2,s3,s4,s5;
	string li1;
	int count=0;
	ifstream customer("semes.txt");
	if(customer.is_open()){
		while(getline(customer,line)){
			if(count==0){
					istringstream buffer(line);
					buffer>>i1;
					q1.set_id(i1);
			}//end if
			if(count==1){
					istringstream buffer(line);
					buffer>>s1;	
					q1.set_name(s1);	
			}//end if
			if(count==2){
					istringstream buffer(line);
					buffer>>s2;		
					q1.set_fathe_name(s2);
			}//end if
			if(count==3){
					istringstream buffer(line);
					buffer>>s3;			
					q1.set_Add(s3);	
			}//end if
			if(count==4){
					istringstream buffer(line);
					buffer>>li1;
					q1.set_celldd(li1);
			}//end if
			if(count==5){
					istringstream buffer(line);
					buffer>>s4;
					q1.set_CI(s4);	
		    }//end if
			if(count==6){
						istringstream buffer(line);
						buffer>>s5;
						q1.set_type(s5);		
			}//end if
			if(count==7){
					istringstream buffer(line);
					buffer>>d1;
					q1.set_bal(d1);
					h.push_back(q1);
					count=-1;
			}//end if
			count++;	
	    }//end while
    }//end if
	customer.close();
}//end func

/********************************************
********  PASSWORD FILE *********************
********************************************/

void Password_File(vector<string>&mmm1){
	string line,s1,s2="0";
	ifstream password("password.txt");
	if(password.is_open()){
		while(getline(password,line)){
			istringstream buffer(line);
					buffer>>s1;
					if(s2!=s1){
					s2=s1;
					mmm1.push_back(s1);
					}//end if
		}//end while
	}//end if
password.close();
}//end func

/******************************************************
*****************  ENCRYPT FILE ***********************
******************************************************/

void encrypt_file(vector<info*>&vec){
	ofstream pass("password.txt",ios::app);
	string line("zahid");
	for(int i=0;i<vec.size();i++){
		vec[i]=vec[i]+line[i];
	}
	
}

/******************************************************
*****************  DECRYPT FILE ***********************
******************************************************/
void decrypt_file(vector<info*>&vec){
	ofstream to_file("password.txt",ios::app);
	string line("zahid");
	for(int i=0;i<vec.size();i++){
		vec[i]=vec[i]+line[i];
	}
	
}
