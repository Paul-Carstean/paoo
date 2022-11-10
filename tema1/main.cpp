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

animal::animal(const string& c)
	:color(c){
		cout<<"Animal created"<<endl;
	};
	
animal::animal()
:color(){
	cout<<"Animal created"<<endl;
};

animal::~animal(){
//    delete[] &color;
    cout<<"Destructor called"<<endl;
}
	
class waterAnimal : public animal{
    private:
		waterAnimal(const waterAnimal& wa){};
		waterAnimal& operator=(const waterAnimal& wa);
		
	public:
		waterAnimal(const string& color);
		~waterAnimal();
		
		void swim(){
			cout<<"swiming"<<endl;
		}
};

waterAnimal::waterAnimal(const string& color)
	:animal(color){};


waterAnimal::~waterAnimal()
	{};	

class landAnimal : public animal{
	public:
	    landAnimal();
		landAnimal(const string& color);
		~landAnimal();
	
		void run(){
			cout<<"running"<<endl;
		}
};

landAnimal::landAnimal(const string& color)
	:animal(color){};
	
landAnimal::landAnimal()
	:animal(){};
	

landAnimal::~landAnimal()
	{};

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




