//Programmer Name: Muhammad Danyal
//Reg.NO:4304-BSSE-F21-B
// in this program i am doing marks management by using linklist by object oriented approch.
#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
class linklist {
private:
	node* FIRST;
	node* CUR ;
	node* PREV;
public:
	linklist() 
	{
		FIRST = NULL;
		CUR = NULL;
		PREV = NULL;
	}
	void set();
	void display();
	bool search(int &);
	void deletion(int &);
	void deletefirst();
	void updation(int &);
	void intsertion();
	void sort();
	void average();
};
void linklist::set() {
	char q;
	do {
		CUR = new node;
		CUR->next = NULL;
		cout << "Enter Marks:";
		cin >> CUR->data;
		if (FIRST == NULL)
			FIRST = PREV = CUR;
		else {
			PREV->next = CUR;
			PREV = CUR;
		}
		cout << "Did you want to do entry?(y for yes/n for no)" << endl;
		cin >> q;
	} while (q == 'y');
}
void linklist::display() {
	CUR = FIRST;
	while (CUR != NULL) {
		cout << "Marks:" << CUR->data << endl;
		CUR = CUR->next;
	}
}
bool linklist::search(int& s) {	
	CUR = FIRST;
	while (CUR) {
		if (s == CUR->data) {			
			return true;
		}
		CUR = CUR->next;	
	}
	if (!true) {		
		return false;
	}
}
void linklist::updation(int& s) {
	if (search(s) == true) {
		cout << "Enter Marks:";
		cin >> CUR->data;
	}
	else
		cout << "Marks not found\n";
}
void linklist:: deletion( int& s) {
	
	 CUR = FIRST;
	while (CUR->next->data != s) {
		CUR = CUR->next;
	}
	node* todelete = CUR->next;
	CUR->next = CUR->next->next;
	delete todelete;
}
void linklist::deletefirst() {
	node* todelete = FIRST;
	FIRST = FIRST->next;
	delete todelete;
}

void linklist::intsertion() {
	int choice;
	cout << "What you wan to do? \n";
	cout << "1.Insert at tail.\n";
	cout << "2.Insert at head.\n";
	cin >> choice;
	if (choice == 1) {
		node* mnode = new node;
		cout << "Enter marks:";
		cin >> mnode->data;
		CUR = FIRST;
		while (CUR->next != NULL) {
			CUR = CUR->next;
		}
		CUR->next = mnode;
		mnode->next = NULL;
	}
	if (choice == 2) {
		node* mnode = new node;
		cout << "Enter marks:";
		cin >> mnode->data;
		mnode->next = FIRST;
		FIRST = mnode;
	}
}
void linklist::sort() {	
		int temp;
		node* i, * j;
		for (i = FIRST; i != NULL; i = i->next)
		{
			for (j = i->next; j != NULL; j = j->next)
			{
				if (i->data > j->data)
				{
					temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
			}
		}	
	/*int temp=0;
	PREV = FIRST;
	CUR = NULL;
	while (PREV->next) {
		CUR = PREV->next;
		while (CUR) {
			if (PREV->data > CUR->data) {
				temp = PREV->data;
				PREV->data = CUR->data;
				CUR->data=temp;
				CUR = CUR->next;
			}
			else {
				CUR = CUR->next;
			}			
			PREV = PREV->next;
		}
	}*/
	/*for (int i = 0; i < 20; i++) {
		PREV = FIRST;
		CUR = FIRST->next;
		while (CUR != NULL) {
			if (PREV->data > CUR->data) {
				temp = CUR->data;
				CUR->data = PREV->data;
				PREV->data = temp;
			}
			PREV = PREV->next;
			CUR = CUR->next;
		}
	}*/
	cout << "Data sorted successfully \n";
}
void linklist::average() {
	int sum = 0,n=0;
	float avg;
	CUR = FIRST;
	while (CUR != NULL) {
		sum += CUR->data;
		++n;
		CUR = CUR->next;
	}
	avg = static_cast<float>(sum) / n;
	cout << "Average:" << avg << endl;
}
int main() {
	int choice, s;	
	linklist l;	
	while (true) {
		cout << "_____MAIN MENU______" << endl;
		cout << " 1.Create linklist " << endl;
		cout << " 2.Display linklist" << endl;
		cout << " 3.Search " << endl;
		cout << " 4.Deletion " << endl;
		cout << " 5.Updation " << endl;
		cout << " 6.Insertion " << endl;
		cout << " 7.Sorting " << endl;
		cout << " 8.class average" << endl;
		cout << " 9.Exit" << endl;
		cout << "What you want to do? \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "--------------create linklist--------------\n";
			l.set();
			break;
		case 2:
			system("cls");
			cout << "--------------Display linklist--------------\n";
			l.display();
			break;
		case 3:
			system("cls");
			cout << "--------------search--------------\n";
			cout << "Enter the marks you want to search:";
			cin >> s;
			if (l.search(s) == true) {
				cout << "Marks Found\n";
			}
			else
				cout << "not found\n";
			break;
		case 4:
			system("cls");
			cout << "--------------Deletion--------------\n";
			cout << "what you want to do:" << endl;
			cout << "1.Delete element without first.\n";
			cout << "2.Delete first element.\n";
			cin >> choice;
			if (choice == 1) {
				cout << "Enter the marks you want to delete:";
				cin >> s;
				l.deletion(s);
				cout << "sucessfully deleted" << endl;
			}
			if (choice == 2) {
				l.deletefirst();
				cout << "sucessfully deleted the first node" << endl;
			}
			break;
		case 5:
			system("cls");
			cout << "--------------Updation--------------\n";
			cout << "Enter the marks you want to update:";
			cin >> s;
			l.updation(s);
			break;
		case 6:
			system("cls");
			cout << "--------------Insertion--------------\n";
			l.intsertion();
			break;
		case 7:
			system("cls");
			cout << "--------------Sorting--------------\n";
			l.sort();
			break;
		case 8:
			system("cls");
			cout << "--------------class average--------------\n";
			l.average();
			break;
		case 9:
			exit(0);
		default:
			cout << "Enter a valid input.\n";
			break;
		}
	}
}