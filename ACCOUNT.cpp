#include<iostream>
#include<string>
#include<stdlib.h>
#include<windows.h>
#include"ACCOUNT.h"
using namespace std;

/*********************************************
************** ACCOUNT CLASS *****************
**********************************************/
Account::Account(double y){ }

Account::Account(){ }

void Account::Display () const{
    	cout<<"Account Type : "<<type<<endl;
}

double Account::Get_Bal() const{
    	 return amount;
}
    
string Account::get_type()const{
	return type;
}
	
void Account::setter(string s){
		type=s;
}

void Account::Set_Bal(int x){
    	amount=x;
}

void Account::Set_Bal(double x){
    	amount=x;
}
    
/*********************************************
************** CURRENT CLASS *****************
**********************************************/

Current::Current(double f):Account(f){
		x=f;
}

Current::Current():Account(){
    	type="current";
    	cout<<"Enter the initial balance : ";cin>>x;cout<<endl;
    if(x<250){
        cout<<"NOt sufficient balance to open the account "<<endl;
        system("pause");
        exit(0);    
	}
    Account::Set_Bal(x);
}

double Current::Deposit(int x){
		amount+=x;
		return amount;	
}

void Current::Update(){
	static int count=0;
        if(count<1){
        	if(amount<10000){
            	cout<<"Your account balance is less than limit !!!"<<endl;
            	amount=amount-250;
            	count++;
            	if(amount<0){
            		amount=0;
            		cout<<"Value reached max level !! "<<endl;
        		}//end if
        	}//end if
    	}//end if
}

double Current::Withdraw(int x){
	if(x<=amount){
		amount-=x;
		Update();
	}//end if
	else 
	cout<<"INVALID AMOUNT !!!"<<endl;
    return amount;
}
void Current::Display()const{
		 Account::Display();
        cout<<"Amount : "<<Account::Get_Bal()<<endl; 
}   


/*********************************************
************** SAVING CLASS *****************
**********************************************/

Saving::Saving(int c){
		interest=x=c;
}
    
Saving::Saving():Account(){
    	type="saving";
         cout<<"Enter the initial balance : ";cin>>x;cout<<endl;
         Account::Set_Bal(x);
         interest=(amount/100)*10;
		Calculate_int();
}
double Saving::Withdraw(int x){
    	if(x<=amount)
		amount-=x;
		else 
		cout<<"INVALID AMOUNT !!!"<<endl;
        return amount;    	
}

double Saving::Deposit(int x){
    	amount+=x;
    	interest=(amount/100)*10;
        Calculate_int();
}

int Saving::getInterest () const{
    	return interest;
}

int Saving::Calculate_int(){
		amount+=interest;
}
	
void Saving::Display()const{
		 Account::Display();
        cout<<"Amount : "<<Account::Get_Bal()<<endl;  
}
