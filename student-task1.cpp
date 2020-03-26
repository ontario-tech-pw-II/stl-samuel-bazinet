// Student class is implemented based on string and do not need any change

#include <iostream>
#include <string>
#include <list>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(char const *);
		string getname();


		Person(); 				// default constructor
		Person(const char *);
		Person(const Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();

};

void Person::setname(char const *n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:
      	
      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(char const *, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

Student::Student(): grade(0)
{
}

Student::Student(char const *n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}

int main()
{  

	Student s[10];
	s[0].setname("Sam");
	s[0].setgrade(50);
	s[1].setname("Liam");
	s[1].setgrade(60);
	s[2].setname("Will");
	s[2].setgrade(50);
	s[3].setname("George");
	s[3].setgrade(90);
	s[4].setname("Cassy");
	s[4].setgrade(37);
	s[5].setname("Mindy");
	s[5].setgrade(25);
	s[6].setname("Malcolm");
	s[6].setgrade(70);
	s[7].setname("Jessica");
	s[7].setgrade(20);
	s[8].setname("Ellysa");
	s[8].setgrade(95);
	s[9].setname("Maria");
	s[9].setgrade(99);

	list<Student> c;
	list<Student>::iterator is;
	list<Student>::reverse_iterator ir;
	bool notTop = 0;

	c.push_back(s[0]);
	for (int i = 1; i < 10; i++) {
		for (is = c.begin(); is !=c.end(); is++) {
			if (is->getgrade() > s[i].getgrade()) {
				c.insert(is,s[i]);
				notTop = 1;
				break;
			}
		}
		if (!notTop) {
			c.push_back(s[i]);
		}
		notTop = 0;
	}
	cout << "Prints in ascending order: " << endl;
	for (is = c.begin(); is != c.end(); is++) {
		cout << *is << endl;
	}
	cout << endl << "Prints in descending order: " << endl;
	for (ir = c.rbegin(); ir != c.rend(); ir++)  {
		cout << *ir << endl;
	}
}