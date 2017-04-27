#include<iostream>
#include"INFO.h"
#include<string>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<windows.h>
#include"ACCOUNT.h"
using namespace std;

/********************************************************
******************  INFO CLASS **************************
*********************************************************/
info::info():ID(n){   
		++n;	
}

int info::get_static(){
    	return n;
}

info::info(int u){
    	Password=" ";
    	Name=" ";
    	Father_name=" ";
    	Address=" ";
    	CNIC=" ";
    	ID=u;
    	Cell_number=u;
}
    
void info::setvalues(){
		cout<<"Enter Password : ";cin.ignore(0);getline(cin,Password);cout<<endl;
		cout<<"Enter Name : ";cin.ignore(0);getline(cin,Name);cout<<endl;
		cout<<"Enter Father Name : " ;cin.ignore(0);getline(cin,Father_name);cout<<endl;
		cout<<"Enter Cell Number : ";cin>>Cell_number;cout<<endl;
		cout<<"Enter Address : ";cin.ignore(0);getline(cin,Address);cout<<endl;
		cout<<"Enter CNIC : ";cin.ignore(0);getline(cin,CNIC);cout<<endl;
}
	
void info::Display()const{
	cout<<"ID : "<<ID<<endl;
	cout<<"Name : "<<Name<<endl;
	cout<<"Father Name : "<<Father_name<<endl;
	cout<<"Cell Number : "<<Cell_number<<endl;
	cout<<"Address : "<<Address<<endl;
	cout<<"CNIC : "<<CNIC<<endl;
}
	
void info::set_cell(){
		cout<<"ENTER NEW CELL NUMBER : ";cin>>Cell_number;cout<<endl;
}
	
void info::set_address(){
		cout<<"ENTER NEW ADDRESS : ";cin.ignore();getline(cin,Address);cout<<endl;
}

void info::set1_id(int i){
		n=i;
}
	
int info::get_ID()const{
		return ID;
}

string info::get_password()
{
		return Password;
}
	
string info::get_name(){
		return Name;
}
	
string info::get_fathername(){
		return Father_name;
}
	
string info::get_cell(){
		return Cell_number;
}
	
string info::get_address(){
		return Address;
}
	
string info::get_CNIC(){
	return CNIC;	
}
/********************************************************
******************  MANAGER CLASS **************************
*********************************************************/

Manager::Manager(int y):info(y){  }

Manager::Manager():info(){
	  info::setvalues();
}

void Manager::Display(){
	string line;
	ifstream k("manager.txt");
	while(getline(k,line))
	{
		cout<<line<<endl;
	}//end while
}

void Manager::set_id(int i){
		ID=i;
}

void Manager::set_name(string h){
		Name=h;
}

void Manager::set_fathe_name(string b){
		Father_name=b;
}

void Manager::set_Add(string c){
		Address=c;
}

void Manager::set_celldd(string r){
		Cell_number=r;
}
	
void Manager::set_CI(string a){
		CNIC=a;
}

void Manager::reset_password(){
		cout<<"Enter the password "<<endl;
		cin.ignore();
		getline(cin,Password);	
}
	
void Manager::Write_account(Manager &obj){
	ofstream to_file("manager.txt");
	ofstream file("manag.txt");
	ofstream obj1("password.txt",ios::in | ios::app);
	if(to_file.is_open()){
		obj1<<obj.Password<<"\n";
		to_file<<"\nID : "<<obj.get_ID();
		file<<obj.get_ID()<<"\n";
		to_file<<"\nNAME : "<<obj.get_name();
		file<<obj.get_name()<<"\n";
		to_file<<"\nFATHER NAME : "<<obj.get_fathername();
		file<<obj.get_fathername()<<"\n";
		to_file<<"\nADDRESS : "<<obj.get_address();
		file<<obj.get_address()<<"\n";
		to_file<<"\nCell number : "<<obj.get_cell();
		file<<obj.get_cell()<<"\n";
		to_file<<"\nCNIC : "<<obj.get_CNIC();
		file<<obj.get_CNIC()<<"\n";
	}//end if
	else
	cout<<"could not open file!"<<endl;
	to_file.close();
	file.close();
		obj1.close();
}

/********************************************************
******************  CUSTOMER CLASS **************************
*********************************************************/

Customer::Customer(int i):info(i){
		u=new Current(0);
}

void Customer::set_id(int i){
		ID=i;
}

void Customer::set_name(string h){
		Name=h;
}

void Customer::set_fathe_name(string b){
		Father_name=b;
}

void Customer::set_Add(string c){
		Address=c;
}

void Customer::set_celldd(string r){
		Cell_number=r;
}

void Customer::set_CI(string a){
		CNIC=a;
}

void Customer::set_type(string s){
		u->setter(s);
}

void Customer::set_bal(double z){
		u->Set_Bal(z);
}

double Customer::BALANCE()
{
	return u->Get_Bal();
}

Customer::Customer(){
			info::setvalues();
			char c;
			cout<<"Enter c to create a current and s for saving "<<endl;
			cin>>c;
			if(c=='s'){
			u=new Saving;
			}
			else if(c=='c'){
			u=new Current ;	
			}
			else {
			cout<<"in valid "<<endl;
			}
			++N;
}

void Customer::write_account(Customer &obj){
	ofstream to_file("semester.txt",ios::in | ios::app);
	ofstream file("semes.txt",ios::in | ios::app);
	ofstream file1("password.txt",ios::app);
	if(to_file.is_open()){
		file1<<obj.get_password()<<"\n";
		to_file<<"\nID : "<<obj.get_ID();
		file<<obj.get_ID()<<"\n";
		to_file<<"\nNAME : "<<obj.get_name();
		file<<obj.get_name()<<"\n";
		to_file<<"\nFATHER NAME : "<<obj.get_fathername();
		file<<obj.get_fathername()<<"\n";
		to_file<<"\nADDRESS : "<<obj.get_address();
		file<<obj.get_address()<<"\n";
		to_file<<"\nCell number : "<<obj.get_cell();
		file<<obj.get_cell()<<"\n";
		to_file<<"\nCNIC : "<<obj.get_CNIC();
		file<<obj.get_CNIC()<<"\n";
		to_file<<"\nACCOUNT TYPE : "<<obj.u->get_type();
		file<<obj.u->get_type()<<"\n";
		to_file<<"\nBALANCE : "<<obj.u->Get_Bal();
		file<<obj.u->Get_Bal()<<"\n";
	}
	else
	cout<<"could not open file!"<<endl;
	to_file.close();
}

void Customer::read_file(){
	string line;
	ifstream from_file("semester.txt");
	from_file.seekg(0);
	if(from_file.is_open()){
		while(getline(from_file,line)){
			cout<<line<<'\n';
		}
	}
	else
	cout<<"cannot open file!!"<<endl;
	from_file.close();
}

void Customer::Withdraw(int w){
	u->Withdraw(w);
}

void Customer::Deposit(int d){
	u->Deposit(d);
}

void Customer::Display()const
{
	info::Display();
	u->Display();	
}

void Customer::reset_password()
{
	cout<<"Enter the pasword "<<endl;
	cin.ignore();
	getline(cin,Password);
}

int Customer::get()
{
	return N;
}

Customer Customer::operator = (Customer &y){
			Name=y.Name;
			ID=y.ID;
			Father_name=y.Father_name;
			Cell_number=y.Cell_number;
			Address=y.Address;
			CNIC=y.CNIC;
			Password=y.Password;
}


int info::n=1;	
int Customer::N=0;

