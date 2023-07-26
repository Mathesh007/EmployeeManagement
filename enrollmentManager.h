namespace EnrollmentManager
{
    using namespace std;
    class EnrollmentManager
    {
    private:
        map<int, vector<Enrollment::Enrollment>> enrollments;
    public:
        EnrollmentManager(){}
        map<int, vector<Enrollment::Enrollment>>&getEnrollments(){ return enrollments;}
        ~EnrollmentManager(){}
    };
}
