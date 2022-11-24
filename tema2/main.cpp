#include <iostream>
#include <string>
using namespace std;

class animal{
	private:
		string color;
		
	public:
	    animal();
		animal(const string& c);
		~animal();
		animal(const animal& a);
		animal& operator=(const animal& a);
		
		string getColor(){
			return color;
		}
		
		void eat(){
			cout<<"eating"<<endl;
		}
		
		void sleep(){
			cout<<"sleeping"<<endl;
		}
};

animal::animal()
:color(){
	cout<<"Animal created"<<endl;
};

animal::animal(const string& c)
	:color(c){
		cout<<"Animal created"<<endl;
	};

animal::~animal(){
    cout<<"Destructor called"<<endl;
};

animal::animal(const animal& a)
	:color(a.color){
};

animal& animal::operator=(const animal& a){
	if (this == &a) return *this;
	color = a.color;
	return *this;
};
	
class waterAnimal : public animal{
    private:
		waterAnimal(const waterAnimal& wa);
		waterAnimal& operator=(const waterAnimal& wa);
		
	public:
		waterAnimal(const string& color);
		~waterAnimal();
		
		void swim(){
			cout<<"swiming"<<endl;
		}
};

waterAnimal::~waterAnimal()
	{};	

waterAnimal::waterAnimal(const string& color)
	:animal(color){};

class landAnimal : public animal{
	public:
	    landAnimal();
		landAnimal(const string& color);
		~landAnimal();
		landAnimal(const landAnimal& la);
		landAnimal& operator=(const landAnimal& la);
	
		void run(){
			cout<<"running"<<endl;
		}
};
	
landAnimal::landAnimal()
	:animal(){};
	
landAnimal::landAnimal(const string& color)
	:animal(color){};

landAnimal::~landAnimal()
	{};

landAnimal::landAnimal(const landAnimal& la)
	:animal(la){

};

landAnimal& landAnimal::operator=(const landAnimal& la)
{
	if (this == &la) return *this;
	animal::operator=(la);
	return *this;
};

int main() {
	
	// calling the constructors
    animal a1("black");
 	landAnimal la1("yellow");

    // calling the copy constructor
    animal a3(a1);
    cout<<a3.getColor()<<endl;

    // calling the copy assignment operator
    landAnimal la2;
    la2 = la1;
    cout<<la2.getColor()<<endl;

    return 0;
}




