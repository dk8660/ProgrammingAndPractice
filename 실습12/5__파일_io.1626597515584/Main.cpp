#include <iostream>
#include <fstream>
using namespace std;

char inputString[1000];

int main() {
	ofstream outFile("output.txt"); //파일 쓰기
	
	outFile << "Hello! my name is kim" << endl;
	outFile << "I like c++" << endl;
	outFile << "Actually, i hate c++" << endl;
	
	outFile.close();
	
	// ifstream inFile("output.txt");
	// string buffer;
	// while(inFile.peek() != EOF) {
	// 	getline(inFile, buffer);
	// 	cout << buffer << endl;
	// }
	// inFile.close();
	
	// int count = 0;
	// ifstream inFile("output.txt");
	// while(!inFile.eof()) {
	// 	inFile.getline(inputString, 100);
	// 	cout << inputString << endl;
	// 	count++;
	// }
	// inFile.close();
	// cout << count << endl;
	
	// count = 0;
	// ifstream inFile("output.txt");
	// while(!inFile.eof()) {
	// 	inFile.get(a);
	// 	cout << a;
	// 	count++;
	// }
	// inFile.close();
	// cout << count << endl;
	// return 0;
}