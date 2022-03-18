#include "std_lib_facilities.h"

struct Person
{
public:
	Person() { };
	Person(string nn, int aa)
	{
		const vector<char> bad = {';','?',':','[',']','*','&','^','%','$','#','@','!','.','"','\''};
		if(aa < 0 || aa > 150) { error("Invalid age!"); }

		if(nn == " ") { error("Name can't be empty!"); }

		for(int i = 0; i < bad.size(); ++i)
		{
			if(nn.find(bad[i]) != string::npos) { error("Invalid char in name!"); }
		}
		constructinit(nn, aa);
	};

	void constructinit(string nn, int aa)
	{
		name = nn;
		age = aa;
	}

	string get_name() { return name; }
	int get_age() { return age; }

private:
	string name;
	int age;
};

ostream& operator<<(ostream& os, Person& p)
{
	os << p.get_name() << ' ' << p.get_age() << '\n';

	return os;
}

istream& operator>>(istream& is, Person& p)
{
	string name;

	int age;

	cout << "Enter the name: ";

	cin >> name;

	cout << "Enter the age: ";
	cin >> age;

	p = Person(name, age);

	return is;
}

int main()
{
	try
	{
		Person Goofy("Goofy", 63);
		cout << Goofy;

		Person one;

		cin >> one;

		cout << one;

		cout << "Type the name and the age: (use 'end' to stop)" << '\n';
		vector <Person> persons;
		for(Person two; cin >> two;)
		{
			if(two.get_name() == "end") break;
			else persons.push_back(two);
		}

		for(Person p:persons)
			cout << p << '\n';

	return 0;
	}


	catch(exception& e){
		cerr << e.what() << '\n';
	return 1;
	}


	catch(...){
		cerr << "Idk what happened" << '\n';
		return 2;
	}
}
