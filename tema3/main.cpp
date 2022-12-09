#include <iostream>
#include <string>
#include <memory>
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

		static void takeAnimal(animal *a){
			cout<<"animal "<<a->getName()<<" taken"<<endl;
		}

		static void releaseAnimal(animal *a){
			cout<<"animal "<<a->getName()<<" released"<<endl;
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
	if (this == &a) {
		cout<<"Self assigment"<<endl;
		return *this;
		}
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
		static waterAnimal* createWaterAnimal(const string& name, const int& years, const string& sex, const int& swimmingDepth){
			return new waterAnimal(name, years, sex, swimmingDepth);
		}

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
	nrOfLegs(){};
	
landAnimal::landAnimal(const string& name, const int& years, const string& sex, const int& nrOfLegs)
	:animal(name, years, sex),
	nrOfLegs(nrOfLegs){};

landAnimal::landAnimal(const landAnimal& la)
	:animal(la),
	nrOfLegs(nrOfLegs){

};

landAnimal& landAnimal::operator=(const landAnimal& la)
{
	if (this == &la) {
		cout<<"Self assigment"<<endl;
		return *this;
		}
	animal::operator=(la);
	nrOfLegs = la.nrOfLegs;
	return *this;
}; 	

class takeAnimal {
	public:
		explicit takeAnimal(animal *an)
		: a(an, animal::releaseAnimal)
		{ animal::takeAnimal(a.get());
		 } 
		private:
		shared_ptr<animal> a;
};

int main() {
	
	// Declaring a variable wa1 of type shared_ptr
    shared_ptr<waterAnimal> wa1(waterAnimal::createWaterAnimal("dolphin", 5, "female", 10));
    // Printing the swimmingDepth of the waterAnimal
    cout << wa1 -> getSwimmingDepth() << endl;
	animal *a = new animal("lion", 7, "male");
	{
		takeAnimal ta(a);
		cout<<a->getName()<<endl;
	}
	cout<<"after animal was released"<<endl;
    return 0;
}
