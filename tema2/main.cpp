#include <iostream>
#include <string>
using namespace std;

class animal{
	private:
		string name;
		int years;
		string sex;
		
	public:
	    animal();
		animal(const string& name, const int& years, const string& sex);
		~animal();
		animal(const animal& a);
		animal& operator=(const animal& a);
		
		string getName(){
			return name;
		}

		int getYears(){
			return years;
		}

		string getSex(){
			return sex;
		}
		
		void eat(){
			cout<<"eating"<<endl;
		}
		
		void sleep(){
			cout<<"sleeping"<<endl;
		}
};

animal::animal()
	:name(),
	years(),
	sex(){
	cout<<"Animal created"<<endl;
};

animal::animal(const string& name, const int& years, const string& sex)
	:name(name),
	years(years),
	sex(sex){
		cout<<"Animal created"<<endl;
	};

animal::~animal(){
    cout<<"Destructor called"<<endl;
};

animal::animal(const animal& a)
	:name(a.name),
	years(a.years),
	sex(a.sex){
		cout<<"Copy constructor called"<<endl;
};

animal& animal::operator=(const animal& a){
	cout<<"Copy assignment operator called"<<endl;
	if (this == &a) return *this;
	name = a.name;
	years = a.years;
	sex = a.sex;
	return *this;
};
	
class waterAnimal : public animal{
    private:
		int swimmingDepth;
		waterAnimal(const waterAnimal& wa);
		waterAnimal& operator=(const waterAnimal& wa);
		
	public:
		waterAnimal();
		waterAnimal(const string& name, const int& years, const string& sex, const int& swimmingDepth);

		int getSwimmingDepth(){
			return swimmingDepth;
		}
		
		void swim(){
			cout<<"swimming"<<endl;
		}
};

waterAnimal::waterAnimal()
	:animal(),
	swimmingDepth(){};	

waterAnimal::waterAnimal(const string& name, const int& years, const string& sex, const int& swimmingDepth)
	:animal(name, years, sex),
	swimmingDepth(swimmingDepth){};

class landAnimal : public animal{
	private:
		int nrOfLegs;

	public:
	    landAnimal();
		landAnimal(const string& name, const int& years, const string& sex, const int& nrOfLegs);
		landAnimal(const landAnimal& la);
		landAnimal& operator=(const landAnimal& la);
	
		int getNrOfLegs(){
			return nrOfLegs;
		}

		void run(){
			cout<<"running"<<endl;
		}
};
	
landAnimal::landAnimal()
	:animal(),
	nrOfLegs(nrOfLegs){};
	
landAnimal::landAnimal(const string& name, const int& years, const string& sex, const int& nrOfLegs)
	:animal(name, years, sex),
	nrOfLegs(nrOfLegs){};

landAnimal::landAnimal(const landAnimal& la)
	:animal(la),
	nrOfLegs(nrOfLegs){

};

landAnimal& landAnimal::operator=(const landAnimal& la)
{
	if (this == &la) return *this;
	animal::operator=(la);
	nrOfLegs = la.nrOfLegs;
	return *this;
};

int main() {
	
	// calling the constructors
    animal a1("bear", 22, "male");
 	landAnimal la1("tiger", 31, "male", 4);

    // calling the copy constructor
    animal a3(a1);
    cout<<a3.getName()<<endl;

    // calling the copy assignment operator
    landAnimal la2;
    la2 = la1;
    cout<<la2.getNrOfLegs()<<endl;

    return 0;
}




