#include <iostream>
#include <ctype.h>
#include <sstream>
#include <cmath>
using namespace std;

//A simple calculator to find either relative focal length or distance, to maintain same framing on subject

//The code takes as input, in order, these four values: current focal length, current distance from subject, target static value, and type of operation (either find focal length or distance, with a char input 'd' or 'f', either upper or lower cased)

class Calculator{
	private:
		int FLength;
		double Dist;
		double Target;
		
	public:
		Calculator(int x, double y, double z){
			FLength = x, Dist = y, Target = z;
		}
		//Simple rule of thirds, with exception check
		double calculate(char a){
			try {
				if(a == 'd' || a == 'D'){
					return ((Target*Dist)/FLength);
				}
				else if (a == 'f' || a == 'F'){
					return ((Target*FLength)/Dist);
				}
				else {
					throw 99;
				}
			}
			catch (...){
				cout << "Error - ";
			}
			return 0;
		}
};

//Here the value "ops" from main is identified, which outputs the name of the operation to carry out
string defineOps(char t){
		if (t == 'd' || t == 'D'){
			return "Distance";
		}
		else if (t == 'f' || t == 'F'){
			return "Focal Length";
		}
		return "Error";
}

bool checkVar (string a) {
	stringstream stream;
	stream << a;
	string str;
	stream >> str;
	bool res;
	if (a == "0") {
		return false;
	}
	
	//cout << " checking int " << str;
	//cout << "string" << str << endl;
	for (int i = 0, d = 0; i < str.length();i++) {
		if (isdigit(str[i]) && d < 2) {
			//cout << "\na" << str[i];
			res = true;
		} else if (str[i] == '.' && d < 1) {
			d++;
			//cout << "\ndot" << d;
			//system("pause");
		} else {
			//cout << "\nb";
			res = false;
			//cout << " spotted non number ";
			break;
		}
	}
	return res;
}

string checkUI (string a) {
	while (checkVar(a) == false) {
		cout << "Input Error, please enter a valid number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> a;
	}
	return a;
}

char checkOps (string a) {
	char strToChar = a[0];
	while (defineOps(strToChar) == "Error" || a.length() > 1) {
		cout << "Input Error, please enter a valid operation : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> a;
		strToChar = a[0];
	}
	return strToChar;
}

int main() {
	double p;
	double q;
	double r;
	char s;
	
	string ops;
	//Here you can specify preferred distance unit, in this case its meters
	string units = " meters";
	string targetUnit;
	string res;
	string userinput;
	string resultPres;
	
	cout << "Please enter your current Focal Length: ";
	cin >> userinput;
	p = stod(checkUI(userinput));
	
	system("clear");
	cout << p << "mm" << endl;
		
	cout << "\nPlease enter your current Distance from subject: ";
	cin >> userinput;
	q = stod(checkUI(userinput));
	
	system("clear");
	cout << p << "mm" << endl;
	cout << q << units << endl;
	
	cout << "\nPlease enter what you wish to find ('f' for focal length, 'd' for distance): ";
	cin >> userinput;
	ops = defineOps(checkOps(userinput));
	
	system("clear");
	
	cout << "Finding " << ops << endl;
	cout << "*************************" << endl;
	
	if (ops == "Distance"){
		s = 'd';
		res = units;
		targetUnit = "mm";
		cout << "\nPlease enter your Target Focal Length: ";
	    cin >> userinput;
	    r = stod(checkUI(userinput));
	    resultPres = "be at: \n\n";
	}
	
	if (ops == "Focal Length"){
		s = 'f';
		res = "mm";
		targetUnit = units;
		cout << "\nPlease enter your Target Distance: ";
	    cin >> userinput;
	    r = stod(checkUI(userinput));
	    resultPres = "use \nthis lens: \n\n";
	}
	system("clear");
	
	Calculator reFrame(p, q, r);
	cout << "Finding " << ops << endl;
	cout << "*************************" << endl;
	cout << "\nFocal Length: " << p << "mm \nDistance: " << q << units << "\nTarget: " << r << targetUnit << endl;

	cout << "\n\n*************************"<< "\n\nTo conserve the framing, \nyou would have to " << resultPres << reFrame.calculate(s) << res << "\n\n*************************\n\n";
	cout << "\nPress any key to exit the program...";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}
