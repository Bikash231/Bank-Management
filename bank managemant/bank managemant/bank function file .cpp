#include "bank header file.h"
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

void transaction::show_acc()
{
	cout <<"\nFull name       : \t"<< name<<endl;
	cout <<"\nPhone number    : \t"<< phno << endl;
	cout <<"\nAccount number  : \t"<< acc_no << endl;
	cout <<"\nCard number     : \t"<< cd_no << endl;
	cout <<"\nCurrent balance : \t"<< balance() << endl;
}

transaction::transaction()
{
	cout << "\ncreating your new account.";
	cout << "\nplease enter the following things."<<endl;
	int account_no;
	int card_no;
	int phn_no;
	string new_name;
	cout << "enter the name : \t \n";
	getline(cin, new_name);
	cout << "enter the account number. : \t \n";
	cin >> account_no;
	cout << "enter the card no. : \t \n";
	cin >> card_no;
	cout << "enter phone no. : \t \n ";
	cin >> phn_no;
	acc_no = account_no;
	cd_no = card_no;
	phno = phn_no;
	name = new_name;
	


	// deposit stack initializing....
	int start_bal;
	cout << "enter starting balance : \t\n";
	cin >> start_bal;
	dep_size = 1;
	top = 0;
	dep_stack = new int[dep_size];
	dep_stack[top] = start_bal;
	cout << "deposit starting bal is : \t\n" << dep_stack[top]; // checking the deposit starting balance.

	// witdrw stack initializing...
	wd_size = 1;
	wtop = 0;
	wd_stack = new int[wd_size];
	wd_stack[wtop] = 0;

	// balance stack initiliaztion..
	bal_size = 1;
	bal_top = 0;
	bal_stack = new int[bal_size];
	bal_stack[bal_top] = start_bal;

	// new withdraw stack.
}

transaction :: ~transaction()
{
	delete [] dep_stack;
	delete[] wd_stack;
	delete[] bal_stack;
}

void transaction::read_bal_stack()
{
	for (int i = 0; i < bal_size; i++)
	{
		cout << "\n blance is : \t" << bal_stack[i];
	}
}
// deposit functions...

void transaction::Dpush(int new_amt)
{
	dep_size++;
	bal_size++;
	top++;
	if (wd_stack[wtop] != 0)
	{
		dep_stack[top] = new_amt;
		int tmp;
		tmp = bal_stack[bal_top] + new_amt;
		bal_top++;
		bal_stack[bal_top] = tmp;

	}
	else
	{
		dep_stack[top] = new_amt;
		int temp;
		temp = bal_stack[bal_top] + new_amt;
		bal_top++;
		bal_stack[bal_top] = temp;
	}

	//cout << "\ntop elt : \t\n" << dep_stack[top];               // checking the value of the top stack 
	//cout << "\nprev elt : \t\n" << dep_stack[top - 1];           // checking the value of the prev. stack
}

int transaction::Dsum()
{
	int Dsum = 0;
	for (int i = 0; i < dep_size; i++)
	{
		Dsum = Dsum + dep_stack[i];
		//cout << "\ncheck : \t " << i  <<"\t"<<Dsum;   checkimng the Dsum alogorithm.
	}
	return Dsum;
}

void transaction::Dstack_read()
{
	for (int i = 0; i < dep_size; i++)
	{
		cout << "\nDeposit value : \t" << i <<" : \t" << dep_stack[i];
	}
}

// withdrw stack initializing.....
// dont make withdraw negative...

void transaction::wdrw_initaializaiton(int amt)
{
	wd_stack[wtop] = bal_stack[bal_top]-amt;

	bal_size++;
	bal_top++;
	int temp;
	temp = wd_stack[wtop];
	bal_stack[bal_top] = temp;
	cout << "\n withdraw starting balance is : \t \n" << wd_stack[wtop];
}

void transaction::Wpush(int withdrw_amt)
{
	int dep_sum;
	if (wd_stack[wtop] == 0)
	{
		wdrw_initaializaiton(withdrw_amt);
	}
	else
	{
		try
		{
			if (withdrw_amt <= bal_stack[bal_top]&&wd_stack[wtop]!=0)
			{
				wd_size++;
				bal_size++;
				dep_sum = bal_stack[bal_top]- withdrw_amt;
				wtop++;
				bal_top++;
				wd_stack[wtop] = dep_sum;
				bal_stack[bal_top] = dep_sum;
				//cout << "\nwithdrw top element : \t \n" << wd_stack[top];
				//cout << "\n withdrw prev element : \t \n" << wd_stack[top - 1];
			}
			else
			{
				throw(withdrw_amt);
			}

		}
		catch (int false_amt)
		{
			cout << "\nAcesss denied - withdraw amount can't be more then: " << Dsum();
		}
	}
	
	
}

void transaction::wdstack_check()
{
	for (int k = 0; k < wd_size; k++)
	{
		cout << "\nWithdraw value : \t" << k  << " : \t" << wd_stack[k];
	}
}

int transaction::balance()
{
	return bal_stack[bal_top];
}

void transaction:: show_transaction(fstream &fio)
{
	//fio.seekg(ios::beg);

	int* deposit_stack;
	int deposit_size;
	deposit_size = dep_size;
	cout << "\n\t\tAccount report"<<endl;     // checking the status...
	deposit_stack = dep_stack;

	int* withdraw_stack;
	int withdraw_size;
	withdraw_size = wd_size;
	withdraw_stack = wd_stack;


	for (int i = 0; i < deposit_size; i++)
	{
		//cout << "\nstack value : \t" << i << " : \t" << deposit_stack[i];
		fio <<"Deposit - \t"<< deposit_stack[i] << endl;
	}
	//fio << "withdraw start";  // withdraw start is here...

	// writing withdraw values into the userfile.txt.

	for (int k = 0; k < withdraw_size; k++)
	{
	//	cout << "\nwithdraw stack value : \t" << k << " : \t" << withdraw_stack[k];  // checking content of withdraw stack
		fio <<"Withdraw - \t"<< withdraw_stack[k]<<endl;
	}
	fio.seekg(ios::beg);
	string line;
	while (!fio.eof())
	{
		//cout << "\nreading\n";
		getline(fio, line);
		cout << line<<endl;
	}




















	/*bool withdraw = false;
	string line = "";
	while (!fio.eof())
	{
		getline(fio, line);
		if (line == "withdraw start") {
			withdraw = true;
		}

		if (!withdraw)
		{
			cout << "Deposit: \t" << line << endl;
			//code goes here
			continue;
		}

		//deposit code goes here

		cout << "Withdraw: \t" << line << endl;
		
	}
	*/
}