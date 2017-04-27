#ifndef INFO_H
#define INFO_H
#include<string>
#include<vector>
#include"ACCOUNT.h"
using namespace std;
class info{
protected:
    static int n;
     int ID;
	string Name;
	string Father_name;
	string Cell_number;
	string Address;
	string CNIC;
	string Password;
public:
	info();
	int get_static();
    info(int u);
	void setvalues();
	void virtual reset_password()=0;
	void Display()const;
	void set_cell();	
	void set_address();
	void set1_id(int i);
	int get_ID()const;
	string get_password();
	string get_name();
	string get_fathername();
	string get_cell();
	string get_address();
	string get_CNIC();
};

/*********************************************
************** MANAGER CLASS *****************
**********************************************/

class Manager:public info{
public:
	Manager(int y);
	Manager();
	void Display();
	void set_id(int i);
	void set_name(string h);
	void set_fathe_name(string b);
	void set_Add(string c);
	void set_celldd(string r);
	void set_CI(string a);
	void virtual reset_password();
	void Write_account(Manager &obj);
	
};

class Customer:public info{
private:
	static int N;
	protected:
	Account *u;
public:
	Customer(int i);
	void set_id(int i);
	void set_name(string h);
	void set_fathe_name(string b);
	void set_Add(string c);
	void set_celldd(string r);
	void set_CI(string a);
	void set_type(string s);
	void set_bal(double z);
	double BALANCE();
	Customer();
	void read_file();
	void Display()const;
	void M_Display()const;
	void virtual reset_password();
    int get();
	void Menu();
	Customer operator = (Customer &y);
	void write_account(Customer &obj);
	void Withdraw(int);
	void Deposit(int);
};

#endif
