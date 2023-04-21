#include <iostream>
using namespace std;
class Rectangle{
	private:
	int length,width;
	public:
	void Get(){
		cout<<"Enter Length and Width"<<endl;
		cin>>length>>width;
	}
	void Area(){
	cout<<"The Area of the Rectangle is: "<<length*width<<" cm2"<<endl;
	}
};
int main(){
	Rectangle r;
	r.Get();
	r.Area();
	return 0;
}
