namespace Enrollment
{
using namespace std;
class Enrollment
{
private:
    Employee::Employee &employee;
    Course::Course &course;

public:
    Enrollment(Employee::Employee &emp, Course::Course &crs)
        : employee(emp), course(crs)
    {
    }
    Employee::Employee &getEmployee() const { return employee; }
    Course::Course &getCourse() const { return course; }
    ~Enrollment()
    {
    }
};
}

