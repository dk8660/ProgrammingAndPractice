#include <iostream>
#include <vector>
using namespace std;

class Account {
	int account_number;  //계좌번호
	int id;
	int balance;  //잔액
public:
	Account(int number, int id_, int b)
	{
		account_number = number;
		id = id_;
		balance = b;
	}
	
	int getAccNo()
	{
		return account_number;
	} 
	int getBalance()
	{
		return balance;
	} 
	void setBalance(int money)
	{
		balance += money;
	}

};

int findIndex(int acn, vector<Account> b)
{
	for(int i=0;i<b.size();i++){
		if(acn == b[i].getAccNo())
			return i;
	}
	return -1;
}

int main()
{
	vector<Account> b;
	string command;
	
	int number = 1111;
	int id_;
	int ba;
	while(1){
		cin >> command;
		if (command == "new"){// 신규
			cin >> id_ >> ba;
			b.push_back(Account(number,id_,ba));
			number++;
		}
		else if (command == "deposit"){
			int number_;
			cin >> number_;
			int money;
			cin >> money;
			int index = findIndex(number_,b);
			if(index == -1)
				continue;
			b[index].setBalance(money);
		}		
		else if (command == "inquiry"){
			int number_;
			cin >> number_;
			int index = findIndex(number_,b);
			if(index == -1)
				continue;
			cout << "balance: " << b[index].getBalance() << endl;
		}	
		else if (command == "quit")
			break;
	}
	return 0;
}