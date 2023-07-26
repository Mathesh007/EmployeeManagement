namespace Employee
{
using namespace std;
class Employee
{
private:
    string name;
    string position;
    string department;

public:
    Employee(string &name,string &position,string &department)
        : name(name), position(position), department(department)
    {
    }
    string &getName() { return name; }
    string &getPosition() { return position; }
    string &getDepartment() { return department; }
};
}

