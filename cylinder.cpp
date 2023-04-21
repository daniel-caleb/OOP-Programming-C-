#include <iostream>
#include <iomanip> // for setprecision function
using namespace std;

class cylinder {
private:
    double radius, height;
public:
    void getdata() {
        cout << "Enter the radius of the cylinder: ";
        cin >> radius;
		cout << "Enter the height of the cylinder: ";
		cin >> height;
    }
    void surface_area() {
        double surface_area = 2 * 3.142 * radius * (radius + height);
        cout << "The surface area of the cylinder is: ";
        cout << fixed << setprecision(5) << surface_area << endl;
    }
};

int main() {
    cylinder c;
    c.getdata();
    c.surface_area();
    return 0;
}

//Name: Daniel-Caleb Cheruiyot - 21/05045
