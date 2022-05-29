#include<iostream>
#include<string>
#include<fstream>
using namespace std;




class transaction
{
	int top; // top size containing the element
	int dep_size; // total size of the dep_stack
	int* dep_stack; // stack containg all the deposit amounts seperately.

	int wtop;
	int wd_size;
	int* wd_stack;

	int bal_top;
	int bal_size;
	int* bal_stack;


protected:
	int acc_no;
	int cd_no;
	int phno;
	string name;

public:

	void read_bal_stack();

	void show_acc();

	transaction();
	~transaction();

	// deposit functions.
	
	void Dpush(int new_amt);
	int Dsum();
	void Dstack_read();
	// withdraw functions.

	void Wpush(int withdraw_amt);
	void wdrw_initaializaiton(int amt);
	void wdstack_check();

    int balance();
	void show_transaction(fstream&);

};



