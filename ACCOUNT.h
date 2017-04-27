#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<string>
using namespace std;
/*********************************************
************** ACCOUNT CLASS *****************
**********************************************/

class Account{
protected:
     string type;
     double amount;
public:
	Account(double);
    Account();
    void virtual Display () const;
    double Get_Bal() const;
    string get_type()const;
	void setter(string);
    void Set_Bal(int);
    void Set_Bal(double);
    virtual double Deposit(int)=0;
    virtual double Withdraw(int)=0;
};
/*********************************************
************** CURRENT CLASS *****************
**********************************************/

class Current:public Account{
    double x;
public:
	Current(double);
    Current();
    double Deposit(int x);
	void Update();
	double Withdraw(int x);
    void Display()const;
};

/*********************************************
************** SAVING CLASS *****************
**********************************************/

class Saving:public Account{
private:
        int interest,x;
public:
	Saving(int c);
    Saving();
    double Withdraw(int x);
     double Deposit(int x);
    int getInterest () const;
	int Calculate_int();
	void Display()const;
};

#endif
