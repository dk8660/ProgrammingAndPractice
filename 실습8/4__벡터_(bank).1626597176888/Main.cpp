#include <iostream>
#include <vector>
using namespace std;

class Account {
	int accNo;
	int id; 
	int balance;
public:
	Account(int accNo, int id, int amount)
	{
		this->accNo = accNo;
		this->id = id; 
		balance = amount;
	}
	
	int getAccNo() const 
	{
	    return accNo;	
	} 
	int getBalance() const
	{
	    return balance;	
	} 
	int getId() const
	{
		return id;
	}
	void setBalance(int amount)
	{
	    balance = amount;	
	} 

};



class Bank {
private:
	vector<Account> b;
	int availableAccNo;
public:
	Bank();
	void create(int id, int amount);
	void deposit(int accNo, int amount);
	void inquiry(int accNo) const;
	void transfer(int fromAccNo, int toAccNo, int amount);
	int findIndex(int accNo) const;
	void printAccs(int id) const; // sort by accNo
};

Bank::Bank()
{
	availableAccNo = 1111;	
}
int Bank::findIndex(int accNo) const{
	for(int i=0;i<b.size();i++) {
		if(accNo == b[i].getAccNo())
			return i;
	}
	return -1;
}
void Bank::create(int id, int amount) {
		b.push_back(Account(availableAccNo,id,amount));
		availableAccNo++;
	}
void Bank::deposit(int accNo, int amount) {
	int index = findIndex(accNo);
	if(index == -1)
		cout << "error 1" << endl;
	else {
		b[index].setBalance(b[index].getBalance() + amount);
		//cout << accNo << " " << b[index].getBalance() << endl;
	}
}
void Bank::inquiry(int accNo) const {
	int index = findIndex(accNo);
	if(index == -1) {
		cout << "error 1";
	}
	else {
		cout << b[index].getBalance() << endl;
	}
}
void Bank::transfer(int fromAccNo, int toAccNo, int amount) {
	int index1 = findIndex(fromAccNo);
	int index2 = findIndex(toAccNo);
	if(index1 == -1 || index2 == -1)
		cout << "error 1" << endl;
	else {
		if(b[index1].getBalance() < amount)
			cout << "error 3" << endl;
		else {
			b[index1].setBalance(b[index1].getBalance() - amount);
			b[index2].setBalance(b[index2].getBalance() + amount);
		}
	}
}
void Bank::printAccs(int id) const {
	bool bo = false;
	for(int i=0;i<b.size();i++) {
		if(id == b[i].getId()) {
			bo = true;
			break;
		}
	}
	if(bo == true) {
		for(int i=0;i<b.size();i++) {
			if(id == b[i].getId()) {
				cout << b[i].getAccNo() << " " << b[i].getBalance() << endl;
			}
		}
	}
	else
		cout << "error 2" << endl;
}
int main()
{
	Bank b;
	string command;
	int id, amount;
	int accNo;
	while(1){
		cin >> command;
		if (command == "new"){// 신규
			cin >> id >> amount; 
			b.create(id, amount);
		}
		else if (command == "deposit"){
			cin >> accNo >> amount;
			b.deposit(accNo, amount);
		}
		else if (command == "inquiry_acc"){
			cin >> accNo;
			b.inquiry(accNo);
		}
		else if (command == "inquiry_id"){
			cin >> id;
			b.printAccs(id);
		}
		else if (command == "transfer"){
			int fromAccNo, toAccNo;
			cin >> fromAccNo >> toAccNo >> amount;
			b.transfer(fromAccNo, toAccNo, amount);
		}
		else if (command == "quit")
			break;
		// withdraw, transfer, id로 accountNo 조회 
	}
	return 0;
}