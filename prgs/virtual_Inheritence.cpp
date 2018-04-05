#include<iostream>
using namespace std;

/* Grandparent, Abstract class */
class person {
  protected:
    string name, gender;
    int age;

  public:
    void get_person() {
      cout << "Enter details: " << endl; 
      cout << "Name: "; cin >> name;
      cout << "Age: "; cin >> age;
      cout << "Gender: "; cin >> gender;
    }
	
    void display() {
      cout << "\nInformation: "<< endl;
      cout << "Name: " << name << endl;
      cout << "Age: " << age << endl;
      cout << "Gender: " << gender << endl;
    }
};

/* Inherit grandparent class as virtual */
class income : virtual public person {
  protected:
    string source;
    float amount;

  public:
    void get_income() {
      cout << "Source of Income:" << endl;
      cin >> source;
      cout << "Amount:" << endl;
      cin >> amount;
    }
	
    void display() {
      cout << "Income from: " << source << endl;
      cout << "Amount: " << amount << endl;
    }
};

/* Inherit grandparent class as virtual */
class expenses : virtual public person {
  protected:
    string purpose;
    float amount;

  public:
    void get_expenses() {
      cout << "Purpose of Expenses:" << endl;
      cin >> purpose;
      cout << "Amount:" << endl;
      cin >> amount;
    }
    void display() {
      cout << "Expenses for: " << purpose << endl;
      cout << "Amount: " << amount << endl;
    }
};

/* Inherit two parent class into one child class */
class programmer : public income, public expenses {
    float net_saving;

  public:
    void display() {
      net_saving = income :: amount - expenses :: amount;
      person :: display();
      income :: display();
      expenses :: display();
      cout << "Net Saving: " << net_saving << endl;
    }
};

int main() {
	programmer p1 = programmer();

	/* Call member functions from grandparent and parent classes */
	p1.get_person();
	p1.get_income();
	p1.get_expenses();

	/* Call display() from derived class 'programmer' */
	p1.display();
	return 0;
}

