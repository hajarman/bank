/*
 _________        .---"""      """---.
:______.-':      :  .--------------.  :
| ______  |      | :                : |
|:______B:|      | |  Little Error: | |
|:______B:|      | |                | |
|:______B:|      | |  Power not     | |
|         |      | |  found.        | |
|:_____:  |      | |                | |
|    ==   |      | :                : |
|       O |      :  '--------------'  :
|       o |      :'---...______...---'
|       o |-._.-i___/'             \._
|'-.____o_|   '-.   '-...______...-'  `-._
:_________:      `.____________________   `-.___.-.
                 .'.eeeeeeeeeeeeeeeeee.'.      :___:
    fsc        .'.eeeeeeeeeeeeeeeeeeeeee.'.
              :____________________________:
*/




//in the name of god

#include<bits/stdc++.h>
#include <iomanip>
#include <ctime>        
#include <chrono>       

using namespace std;

typedef long long ll;

#define pb push_back
#define X first
#define Y second
#define pii pair<int,int>
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define read freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)

const int maxn=2e5+5;
const int mod=1e9+7;
const int inf=1e9;
const int del=728729;

ll poww(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));}

class Bank {
    public:
        void managementPanel();
        void employeePanel();
        void customerPanel();
        void registerCustomer();
        void loginCustomer();
        void customerMenu(string nationalID);
        void listAccounts(string nationalID);
        void makeAccount(string nationalID);
        void deleteAccount(string nationalID);
        void depositMoney(string nationalID) ;
        void withdrawMoney(string nationalID) ;
        void transferMoney(string nationalID) ;
		void empdepositMoney() ;
        void empwithdrawMoney() ;
        void emptransferMoney() ;
        void searchAndWatch();
        void watchAccounts();
        void manageEmployees();
        void changeEmployeeInformation();
        void watchEmployeeInformation();
        void addEmployee() ;
        void manageCustomers();
        void watchCustomerInformation();
        void showtemp() ;
        string hashPassword(string password);
};
void Bank::managementPanel() {
    cout << "Management Panel" << endl;
    string  username="0025565281", cu ;
    int pass=1234 , cp;
    cout <<"enter your username: " <<endl;
    cin >> cu;
    cout <<"enter your password: " <<endl;
    cin >>cp;
    if(cp!=pass or cu!=username){
        cout<<"you are not manager" <<endl;
        return;
    }
    int choice;
    cout << "1. Watch or Add or Change Employee Information" << endl;
    cout << "2. Customer Accounts" << endl;
    cout<< "3. watch temp" <<endl;
    cout << "Enter your choice: "<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            manageEmployees();
            break;
        case 2:
            manageCustomers();
            break;
        case 3 :
        	showtemp();
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}
void Bank::showtemp(){
	ifstream tempFile("temp.txt");
	string line;
	while (getline(tempFile, line)) {
		cout<<line ;
	}
}
void Bank::manageCustomers() {
	int choice;
	cout<<endl<<"1. Watch Customer Information"<<endl;	
	cout<<endl<<"Enter your choice: "<< endl;	
	cin>>choice;

	switch (choice) {
		case 1:
			watchCustomerInformation();
			break;
			break;
		default:
			cout<<endl<<"Invalid choice"<<endl;	
	}
}
void Bank::watchCustomerInformation() {
	string nationalID;
	cout<<endl<<"Enter customer's national ID: "<< endl;	
	cin>>nationalID;

	ifstream customerFile("users.txt");
	string line;
	bool found = false;
	while (getline(customerFile, line)) {
		stringstream ss(line);
		string n, f, b, g, d, s;
		ss >> n >> f >> b >> g >> d >> s;

		if (n == nationalID) {
			found = true;

			cout<<endl<<"National ID: "<<n<<endl;	
			cout<<"Full Name: "<<f<<endl;	
			cout<<"Birth Date: "<<b<<endl;	
			cout<<"Gender: "<<g<<endl;	
			cout<<"Employment Date: "<<d<<endl;	
			cout<<"Salary: "<<s<<endl;	

			break;
		}
	}
	customerFile.close();

	if (!found) {
		cout<<endl<<"Invalid national ID"<<endl;	
	}
}
void Bank::manageEmployees() {
	int choice;
	cout<<endl<<"1. Watch Employee Information"<<endl;	
	cout<<"2. Add Employee"<<endl;	
	cout<<"3. Change Employee Information"<<endl;	
	cout<<endl<<"Enter your choice: "<< endl;	
	cin>>choice;

	switch (choice) {
		case 1:
			watchEmployeeInformation();
			break;
		case 2:
			addEmployee();
			break;
		case 3:
			changeEmployeeInformation();
			break;
		default:
			cout<<endl<<"Invalid choice"<<endl;	
	}
}
void Bank::watchEmployeeInformation() {
	string nationalID;
	cout<<endl<<"Enter employee's national ID: "<< endl;	
	cin>>nationalID;

	ifstream employeesFile("employees.txt");
	string line;
	bool found = false;
	while (getline(employeesFile, line)) {
		stringstream ss(line);
		string n, f, b, g, d, s;
		ss >> n >> f >> b >> g >> d >> s;

		if (n == nationalID) {
			found = true;

			cout<<endl<<"National ID: "<<n<<endl;	
			cout<<"Full Name: "<<f<<endl;	
			cout<<"Birth Date: "<<b<<endl;	
			cout<<"Gender: "<<g<<endl;	
			cout<<"Employment Date: "<<d<<endl;	
			cout<<"Salary: "<<s<<endl;	

			break;
		}
	}
	employeesFile.close();

	if (!found) {
		cout<<endl<<"Invalid national ID"<<endl;	
	}
}


void Bank::addEmployee() {
	string fullName, nationalID, birthDate, gender, salary;
	cout<<endl<<"Enter employee's full name: "<< endl;	
	getline(cin.ignore(), fullName);
	cout<<endl<<"Enter employee's national ID: "<< endl;	
	cin>>nationalID;

	ifstream testemployeesFile("employees.txt");
	string line;
	bool unique = true;
	while (getline(testemployeesFile, line)) {
		stringstream ss(line);
		string n, f, b, g, d, s;
		ss >> n >> f >> b >> g >> d >> s;

		if (n == nationalID) {
			unique = false;
			break;
		}
	}
	testemployeesFile.close();

	if (!unique) {
		cout<<endl<<"National ID already exists"<<endl;	
		return;
	}

	cout<<endl<<"Enter employee's birth date (dd/mm/yyyy): "<< endl;	
	cin>>birthDate;

	int day, month, year;
	sscanf(birthDate.c_str(), "%d/%d/%d", &day, &month, &year);

	time_t now = time(0);
	tm *ltm = localtime(&now);
	int currentYear = 1900 + ltm->tm_year;

	if (currentYear - year < 18) {
		cout<<endl<<"Employee must be at least 18 years old"<<endl;	
		return;
	}

	cout<<endl<<"Enter employee's gender: "<< endl;	
	cin>>gender;

	stringstream ss;
	ss << put_time(ltm, "%Y-%m-%d %X");
	string date = ss.str();

	cout<<endl<<"Enter employee's salary: "<< endl;	
	cin>>salary;

	ofstream employeesFile("employees.txt", ios::app);
	employeesFile<<nationalID<<" "<<fullName<<" "<<birthDate<<" "<<gender<<" "<<date<<" "<<salary<<endl; 
	employeesFile.close();
}
void Bank::changeEmployeeInformation() {
	string nationalID;
	cout<<endl<<"Enter employee's national ID: "<< endl;	
	cin>>nationalID;

	ifstream employeesFile("employees.txt");
	ofstream tempFile("temp.txt");
	string line;
	bool found = false;
	while (getline(employeesFile, line)) {
		stringstream ss(line);
		string n, f, b, g, d, s;
		ss >> n >> f >> b >> g >> d >> s;

		if (n == nationalID) {
			found = true;

			int choice;
			cout<<endl<<"1. Change Full Name"<<endl;	
			cout<<"2. Change Birth Date"<<endl;	
			cout<<"3. Change Gender"<<endl;	
			cout<<"4. Change Salary"<<endl;	
			cout<<endl<<"Enter your choice: "<< endl;	
			cin>>choice;

			switch (choice) {
				case 1:
					cout<<endl<<"Enter new full name: "<< endl;	
					getline(cin.ignore(), f);
					break;
				case 2:
					cout<<endl<<"Enter new birth date (dd/mm/yyyy): ";	
					cin>>b;
				case 3:
					cout<<endl<<"Enter new gender: "<< endl;	
					cin>>g;
					break;
				case 4:
					cout<<endl<<"Enter new salary: "<< endl;
										cin>>s;
					break;
				default:
					cout<<endl<<"Invalid choice"<<endl;	
					tempFile << line << endl;
					continue;
			}

			time_t now = time(0);
			tm *ltm = localtime(&now);
			stringstream ss2;
			ss2 << put_time(ltm, "%Y-%m-%d %X");
			string date = ss2.str();

			tempFile<<n<<" "<<f<<" "<<b<<" "<<g<<" "<<date<<" "<<s<<endl; 

			continue;
		}
		tempFile << line << endl;
	}
	tempFile.close();
	employeesFile.close();

	if (found) {
		remove("employees.txt");
		rename("temp.txt", "employees.txt");
		cout<<endl<<"Employee information changed successfully"<<endl;	
	} else {
		remove("temp.txt");
		cout<<endl<<"Invalid national ID"<<endl;	
	}
}

void Bank::employeePanel() {
    cout << "Employee Panel" << endl;
    int choice;
    cout << "1. Search and Watch Customers and Accounts" << endl;
    cout << "2. Watch One Customer's All Accounts" << endl;
    cout << "3. Make deposit" << endl;
    cout << "4. Make withdraw" << endl;
    cout << "5. Make transfer"<< endl;
    cout << "Enter your choice: "<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            searchAndWatch();
            break;
        case 2:
            watchAccounts();
            break;
        case 3:
            empdepositMoney();
            break;
		case 4 :
	    	empwithdrawMoney();
	    case 5 :
	    	emptransferMoney();
	
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}

void Bank::searchAndWatch() {
	string query;
	cout << "Enter search query: "<<endl;
	cin.ignore();
	getline(cin, query);

	ifstream usersFile("users.txt");
	string line;
	while (getline(usersFile, line)) {
		if (line.find(query) != string::npos) {
			stringstream ss(line);
			string nationalID, password, fullName, birthDate, gender, date;
			ss >> nationalID >> password >> fullName >> birthDate >> gender >> date;

			cout << "National ID: " << nationalID << endl;
			cout << "Full Name: " << fullName << endl;
			cout << "Birth Date: " << birthDate << endl;
			cout << "Gender: " << gender << endl;
			cout << "Registration Date: " << date << endl;

			ifstream accountsFile(nationalID + ".txt");
			while (getline(accountsFile, line)) {
				stringstream ss(line);
				string accountNumber, balance, date;
				ss >> accountNumber >> balance >> date;

				cout<<endl<<"Account Number: "<<accountNumber<<endl;	
				cout<<"Balance: "<<balance<<endl;	
				cout<<"Last Transaction Date: "<<date<<endl;	
			}
			accountsFile.close();
		}
	}
	usersFile.close();
}

void Bank::watchAccounts() {
	string nationalID;
	cout<<endl<<"Enter customer's national ID: "<<endl;	
	cin>>nationalID;

	ifstream accountsFile(nationalID + ".txt");
	string line;
	while (getline(accountsFile, line)) {
		stringstream ss(line);
		string accountNumber, balance, date;
		ss >> accountNumber >> balance >> date;

		cout<<endl<<"Account Number: "<<accountNumber<<endl;	
		cout<<"Balance: "<<balance<<endl;	
		cout<<"Last Transaction Date: "<<date<<endl;	
	}
	accountsFile.close();
}

void Bank::empdepositMoney() {
	string nationalID, accountNumber;
	double amount;
	cout << "Enter the customer's national ID: "<<endl;
	cin >> nationalID;
	cout << "Enter the 10-digit account number: "<<endl;
	cin >> accountNumber;
	cout << "Enter the amount to deposit: "<<endl;
	cin >> amount;

	ifstream accountsFile(nationalID + ".txt");
	ofstream tempFile("temp.txt");
	string line;
	bool found = false;
	while (getline(accountsFile, line)) {
		stringstream ss(line);
		string a, b, c;
		ss >> a >> b >> c;
		if (a == accountNumber) {
			found = true;
			double balance = stod(b);
			balance += amount;

			time_t now = time(0);
			tm *ltm = localtime(&now);
			stringstream ss2;
			ss2 << put_time(ltm, "%Y-%m-%d %X");
			string date = ss2.str();

			tempFile << a << " " << balance << " " << date << endl;

			continue;
		}
		tempFile << line << endl;
	}
	tempFile.close();
	accountsFile.close();

	if (found) {
		remove((nationalID + ".txt").c_str());
		rename("temp.txt", (nationalID + ".txt").c_str());
		cout<<endl<<"Deposit successful"<<endl;	
	} else {
		remove("temp.txt");
		cout<<endl<<"Invalid account number"<<endl;	
	}
}

void Bank::empwithdrawMoney() {
	string nationalID, accountNumber;
	double amount;
	cout << "Enter the customer's national ID: "<<endl;
	cin >> nationalID;
	cout << "Enter the 10-digit account number: "<<endl;
	cin >> accountNumber;
	cout << "Enter the amount to deposit: "<<endl;
	cin >> amount;

	ifstream accountsFile(nationalID + ".txt");
	ofstream tempFile("temp.txt");
	string line;
	bool found = false;
	while (getline(accountsFile, line)) {
		stringstream ss(line);
		string a, b, c;
		ss >> a >> b >> c;
		if (a == accountNumber) {
			found = true;
			double balance = stod(b);
			balance -= amount;

			time_t now = time(0);
			tm *ltm = localtime(&now);
			stringstream ss2;
			ss2 << put_time(ltm, "%Y-%m-%d %X");
			string date = ss2.str();

			tempFile << a << " " << balance << " " << date << endl;

			continue;
		}
		tempFile << line << endl;
	}
	tempFile.close();
	accountsFile.close();

	if (found) {
		remove((nationalID + ".txt").c_str());
		rename("temp.txt", (nationalID + ".txt").c_str());
		cout<<endl<<"Deposit successful"<<endl;	
	} else {
		remove("temp.txt");
		cout<<endl<<"Invalid account number"<<endl;	
	}
}
void Bank::emptransferMoney() {
	string senderNationalID, recipientNationalID, senderAccountNumber, recipientAccountNumber;
	double amount;

	cout<<endl<<"Enter sender's national ID: "<<endl;	
	cin>>senderNationalID;

	ifstream accountsFile(senderNationalID + ".txt");
	if (!accountsFile.good()) {
		cout<<endl<<"Invalid national ID"<<endl;	
		return;
	}
	accountsFile.close();

	cout<<endl<<"Enter sender's account number: "<<endl;	
	cin>>senderAccountNumber;

	bool found = false;
	accountsFile.open(senderNationalID + ".txt");
	string line;
	while (getline(accountsFile, line)) {
		stringstream ss(line);
		string a, b, c;
		ss >> a >> b >> c;
		if (a == senderAccountNumber) {
			found = true;
			break;
		}
	}
	accountsFile.close();

	if (!found) {
		cout<<endl<<"Invalid account number"<<endl;	
		return;
	}

	cout<<endl<<"Enter recipient's national ID: "<<endl;	
	cin>>recipientNationalID;

	if (recipientNationalID == senderNationalID) {
		cout<<endl<<"Recipient's national ID cannot be the same as sender's"<<endl;	
		return;
	}

	found = false;

	ifstream usersFile("users.txt");
	while (getline(usersFile, line)) {
		stringstream ss(line);
		string u, p, f, b, g, d;
		ss >> u >> p >> f >> b >> g >> d;

		ifstream accountsFile(u + ".txt");
		while (getline(accountsFile, line)) {
			stringstream ss(line);
			string a, b, c;
			ss >> a >> b >> c;
			if (a == recipientAccountNumber) {
				found = true;
				double balance = stod(b);
				balance += amount;

				time_t now = time(0);
				tm *ltm = localtime(&now);
				stringstream ss2;
				ss2 << put_time(ltm, "%Y-%m-%d %X");
				string date = ss2.str();

				ofstream tempFile("temp.txt", ios::app);
				tempFile << a << " " << balance << " " << date << endl;

				tempFile.close();
				remove((u + ".txt").c_str());
				rename("temp.txt", (u + ".txt").c_str());

				break;
			}
		}
	}
}

void Bank::customerPanel() {
    cout << "Customer Panel" << endl;
    int choice;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: "<<endl;
    cin >> choice;
    switch (choice) {
        case 1:
            registerCustomer();
            break;
        case 2:
            loginCustomer();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}
void Bank::registerCustomer() {
    cout << "Register Customer" << endl;
    string fullName, nationalID, birthDate, gender, password;
    cout << "Enter your full name: "<<endl;
    getline(cin.ignore(), fullName);
    cout << "Enter your national ID: "<<endl;
    cin >> nationalID;

    ifstream asghar("users.txt");
    
    string line;
    bool unique = true;
    while (getline(asghar, line)) {
        stringstream ss(line);
        string u, p;
        ss >> u >> p;
        if (u == nationalID) {
            unique = false;
            break;
        }
    }
    asghar.close();

    if (!unique) {
        cout<<endl<<"National ID already exists"<<endl;	
        return;
    }
    

    cout << "Enter your birth date (dd/mm/yyyy): "<<endl;
    cin >> birthDate;

    int day, month, year;
    sscanf(birthDate.c_str(), "%d/%d/%d", &day, &month, &year);

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;

    if (currentYear - year < 18) {
        cout<<endl<<"You must be at least 18 years old to register"<<endl;	
        return;
    }

    cout << "Enter your gender: "<<endl;
    cin >> gender;
    cout << "Enter your password: "<<endl;
    cin >> password;

    stringstream ss;
    ss << put_time(ltm, "%Y-%m-%d %X");
    string date = ss.str();

    ofstream usersFile("users.txt", ios::app);
    usersFile<<nationalID<<" "<<hashPassword(password)<<" "<<fullName<<" "<<birthDate<<" "<<gender<<" "<<date<<endl; 
    usersFile.close();

    customerMenu(nationalID);
}

void Bank::loginCustomer() {
    cout<<endl<<"Login Customer"<<endl; 
    string username,password; 
    cout<<endl<<"Username: "; 
    cin>>username; 
    cout<<endl<<"Password: "; 
    cin>>password; 

    ifstream usersFile("users.txt"); 
    string line; 
    bool found=false; 
    while(getline(usersFile,line)) { 
        stringstream ss(line); 
        string u,p; 
        ss>>u>>p; 
        if(u==username && p==hashPassword(password)) { 
            found=true; 
            break; 
        } 
    } 
    usersFile.close(); 

    if(found) { 
        cout<<endl<<"Login successful"<<endl;	
        customerMenu(username);
    } else { 
        cout<<endl<<"Invalid username or password"<<endl;	
    } 
}

void Bank::customerMenu(string nationalID) {
	while (true) {
	    int choice;
	    cout<<endl<<"1. List of Accounts"<<endl; 
	    cout<<"2. Make a New Account"<<endl; 
	    cout<<"3. Delete an Account"<<endl;  
	    cout<<"4. Deposit Money to an Account"<<endl;  
	    cout<<"5. Withdraw Money from an Account"<<endl;  
	    cout<<"6. Transfer Money to Another Account"<<endl;  
	    cout<<"7. Quit"<<endl;  
	    cout<<endl<<"Enter your choice: "<<endl;  
	    cin>>choice;

	    switch (choice) {
	    	case 1:
	    		listAccounts(nationalID);
	    		break;
	    	case 2:
	    		makeAccount(nationalID);
	    		break;
	    	case 3:
	    		deleteAccount(nationalID);
	    		break;
	    	case 4:
	    		depositMoney(nationalID);
	    		break;
	    	case 5:
	    		withdrawMoney(nationalID);
	    		break;
	    	case 6:
	    		transferMoney(nationalID);
	    		break;
	    	case 7:
	    		return;
	    	default:
	    		cout<<endl<<"Invalid choice"<<endl;	
	    }
	}
}
void Bank::listAccounts(string nationalID) {
    ifstream accountsFile(nationalID + ".txt");
    string line;
    while (getline(accountsFile, line)) {
        cout << line << endl;
    }
    accountsFile.close();
}

void Bank::makeAccount(string nationalID) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 9);
    string accountNumber = "";
    for (int i = 0; i < 10; i++) {
        accountNumber += to_string(dis(gen));
    }

    double balance;
    cout << "Enter initial balance: "<<endl;
    cin >> balance;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << put_time(ltm, "%Y-%m-%d %X");
    string date = ss.str();

    ofstream accountsFile(nationalID + ".txt", ios::app);
    accountsFile << accountNumber << " " << balance << " " << date << endl;
    accountsFile.close();
}

void Bank::deleteAccount(string nationalID) {
    string accountNumber;
    cout << "Enter the 10-digit account number: "<<endl;
    cin >> accountNumber;

    ifstream accountsFile(nationalID + ".txt");
    ofstream tempFile("temp.txt");
    string line;
    bool found = false;
    while (getline(accountsFile, line)) {
        stringstream ss(line);
        string a, b, c;
        ss >> a >> b >> c;
        if (a == accountNumber) {
            found = true;
            continue;
        }
        tempFile << line << endl;
    }
    tempFile.close();
    accountsFile.close();

    if (found) {
        remove((nationalID + ".txt").c_str());
        rename("temp.txt", (nationalID + ".txt").c_str());
        cout<<endl<<"Account deleted successfully"<<endl;	
    } else {
        remove("temp.txt");
        cout<<endl<<"Invalid account number"<<endl;	
    }
}


void Bank::depositMoney(string nationalID) {
	string accountNumber;
	double amount;
	cout << "Enter the 10-digit account number: "<<endl;
	cin >> accountNumber;
	cout << "Enter the amount to deposit: "<<endl;
	cin >> amount;

	ifstream accountsFile(nationalID + ".txt");
	ofstream tempFile("temp.txt");
	string line;
	bool found = false;
	while (getline(accountsFile, line)) {
		stringstream ss(line);
		string a, b, c;
		ss >> a >> b >> c;
		if (a == accountNumber) {
			found = true;
			double balance = stod(b);
			balance += amount;

			time_t now = time(0);
			tm *ltm = localtime(&now);
			stringstream ss2;
			ss2 << put_time(ltm, "%Y-%m-%d %X");
			string date = ss2.str();

			tempFile << a << " " << balance << " " << date << endl;

			continue;
		}
		tempFile << line << endl;
	}
	tempFile.close();
	accountsFile.close();

	if (found) {
		remove((nationalID + ".txt").c_str());
		rename("temp.txt", (nationalID + ".txt").c_str());
		cout<<endl<<"Deposit successful"<<endl;	
	} else {
		remove("temp.txt");
		cout<<endl<<"Invalid account number"<<endl;	
	}
}


void Bank::withdrawMoney(string nationalID) {
	string accountNumber;
	double amount;
	cout << "Enter the 10-digit account number: "<<endl;
	cin >> accountNumber;
	cout << "Enter the amount to deposit: "<<endl;
	cin >> amount;

	ifstream accountsFile(nationalID + ".txt");
	ofstream tempFile("temp.txt");
	string line;
	bool found = false;
	while (getline(accountsFile, line)) {
		stringstream ss(line);
		string a, b, c;
		ss >> a >> b >> c;
		if (a == accountNumber) {
			found = true;
			double balance = stod(b);
			balance -= amount;

			time_t now = time(0);
			tm *ltm = localtime(&now);
			stringstream ss2;
			ss2 << put_time(ltm, "%Y-%m-%d %X");
			string date = ss2.str();

			tempFile << a << " " << balance << " " << date << endl;

			continue;
		}
		tempFile << line << endl;
	}
	tempFile.close();
	accountsFile.close();

	if (found) {
		remove((nationalID + ".txt").c_str());
		rename("temp.txt", (nationalID + ".txt").c_str());
		cout<<endl<<"Deposit successful"<<endl;	
	} else {
		remove("temp.txt");
		cout<<endl<<"Invalid account number"<<endl;	
	}
}
void Bank::transferMoney(string nationalID) {
	string senderAccountNumber, recipientAccountNumber;
	double amount;
	cout << "Enter your 10-digit account number: "<<endl;
	cin >> senderAccountNumber;
	cout << "Enter the recipient's 10-digit account number: "<<endl;
	cin >> recipientAccountNumber;
	cout << "Enter the amount to transfer: "<<endl;
	cin >> amount;

	ifstream accountsFile(nationalID + ".txt");
	ofstream tempFile("temp.txt");
	string line;
	bool found = false;
	while (getline(accountsFile, line)) {
		stringstream ss(line);
		string a, b, c;
		ss >> a >> b >> c;
		if (a == senderAccountNumber) {
			found = true;
			double balance = stod(b);
			if (balance < amount) {
				cout<<endl<<"Insufficient balance"<<endl;	
				tempFile << line << endl;
				continue;
			}
			balance -= amount;

			time_t now = time(0);
			tm *ltm = localtime(&now);
			stringstream ss2;
			ss2 << put_time(ltm, "%Y-%m-%d %X");
			string date = ss2.str();

			tempFile << a << " " << balance << " " << date << endl;

			continue;
		}
		tempFile << line << endl;
	}
	tempFile.close();
	accountsFile.close();

	if (found) {
		remove((nationalID + ".txt").c_str());
		rename("temp.txt", (nationalID + ".txt").c_str());
	} else {
		remove("temp.txt");
		cout<<endl<<"Invalid account number"<<endl;	
		return;
	}

	ifstream usersFile("users.txt");
	string recipientNationalID = "";
	while (getline(usersFile, line)) {
		stringstream ss(line);
		string u, p, f, b, g, d;
		ss >> u >> p >> f >> b >> g >> d;

		ifstream accountsFile(u + ".txt");
		while (getline(accountsFile, line)) {
			stringstream ss(line);
			string a, b, c;
			ss >> a >> b >> c;
			if (a == recipientAccountNumber) {
				found = true;
				double balance = stod(b);
				balance += amount;

				time_t now = time(0);
				tm *ltm = localtime(&now);
				stringstream ss2;
				ss2 << put_time(ltm, "%Y-%m-%d %X");
				string date = ss2.str();

				ofstream tempFile("temp.txt", ios::app);
				tempFile << a << " " << balance << " " << date << endl;

				tempFile.close();
				remove((u + ".txt").c_str());
				rename("temp.txt", (u + ".txt").c_str());

				break;
			}
		}
	}
}

string Bank::hashPassword(string password) {
    hash<string> hasher;
    size_t hash = hasher(password);
    return to_string(hash);
}

int main() {
	migmig ;
    
    cout<<"Welcome to the Bank Management System"<<endl<<endl; 
    cout<<"1. Management Panel"<<endl; 
    cout<<"2. Employee Panel"<<endl; 
    cout<<"3. Customer Panel"<<endl; 
    cout<<endl<<"Enter your choice: "<<endl; 
    int choice; 
    Bank bank; 
    cin>>choice; 
    switch(choice) { 
        case 1: bank.managementPanel(); break; 
        case 2: bank.employeePanel(); break; 
        case 3: bank.customerPanel(); break; 
        default: cout<<endl<<"Invalid choice"<<endl; break; 
    }
    return 0; 
}

