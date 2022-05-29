#include<iostream>
#include"bank header file.h"
#include<string>
#include<fstream>

using namespace std;

int main()
{
	/*transaction t1;
	//int depamt;
	t1.Dpush(400);
	t1.Dpush(200);
	t1.Dpush(300);
	t1.Dstack_read();

	// int wdamt;
	t1.wdrw_initaializaiton();
	t1.Wpush(10);
	t1.Wpush(80);
	t1.Wpush(10000); // checking the excption here -  withdraw can't be more than balance. using exception handling .
	t1.wdstack_check();  // checking withdraw stack..

	t1.balance(); // checking withdraw top value..
	*/
		transaction t1;
		
		
		fstream fio;

		fio.open("userfile.txt", ios::out | ios::in);
		if (!fio)
		{
			cout << "\nfile not exsit";
		}
		else
		{
			cout << "\nFile created sucessfully";
			/*	//cout << "\nfile created sucessfully";
			int* deposit_stack;
			int deposit_size;
			deposit_size = t1.return_dep_size();
			cout << "\ngoing to take stack value";     // checking the status...
			deposit_stack = t1.return_dep_stack();

			int* withdraw_stack;
			int withdraw_size;
			withdraw_size = t1.return_wd_size();
			withdraw_stack = t1.return_wd_stack();

			// writing deposit values into the userfile.txt.

			for (int i = 0; i < deposit_size; i++)
			{
				cout << "\nstack value : \t" << i << " : \t" << deposit_stack[i];
				fio << deposit_stack[i] << endl;
			}
			fio << "withdraw start";  // withdraw start is here...

			// writing withdraw values into the userfile.txt.

			for (int k = 0; k < withdraw_size - 1; k++)
			{
				cout << "\nwithdraw stack value : \t" << k << " : \t" << withdraw_stack[k];  // checking content of withdraw stack
				fio << endl << withdraw_stack[k] - withdraw_stack[k + 1];
			}
			*/
		}
	
	//t1.show_acc();    // checking show accout function.
		cout << "\n choose 1 for deposit:\n choose 2 for withdraw:\n choose 3 for show transaction:\n choose 4 for show account:\n choose 5 for current balance:\n";
	int choice;
	do
	{
		cout << "\nEnter choice : ";
		cin >> choice;
		//t1.wdrw_initaializaiton();

		switch (choice)
		{
		case 1: // deposit.
			int amt;
			cout << "\nEnter the deposit amount" << endl;
			cin >> amt;
			t1.Dpush(amt);
			break;
		case 2: // withdraw.
			int amount;
			cout << "\nEnter the withdraw amount" << endl;
			cin >> amount;
			t1.Wpush(amount);
			break;
		case 3:  // show transaction.
			t1.show_transaction(fio);
			break;
		case 4: // show account.
			t1.show_acc();
			break;
		case 5: // current balance.
			cout<<"\curent value is : \t"<<t1.balance();
			break;
		case 99: // exit function.
			cout << "\nbye bye." << endl;
			break;
		default:
			cout << "\n invalid choice ";
			break;
		}
	} while (choice != 99);
}