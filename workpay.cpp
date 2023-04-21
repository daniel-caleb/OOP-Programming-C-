#include <iostream>

using namespace std;

class Employee {
    private:
        float hourly_wage;
        int regular_hours;
        int overtime_hours;
        
    public:
        Employee(float wage, int reg_hrs, int ot_hrs) {
            hourly_wage = wage;
            regular_hours = reg_hrs;
            overtime_hours = ot_hrs;
        }
        
        float calculate_salary() {
            float regular_pay = hourly_wage * regular_hours;
            float overtime_pay = (hourly_wage * 1.5) * overtime_hours;
            float total_pay = regular_pay + overtime_pay;
            return total_pay;
        }
};

int main() {
    Employee emp(2500, 20, 10);
    float salary = emp.calculate_salary();
    cout << "Weekly salary: Kshs " << salary << endl;
    return 0;
}

