namespace Report
{
    using namespace std;

    class Report
    {
    public:
        Report(){}
        void getReport(Course::Course course)
        {
            cout<<"\nCourse:"<<course.getTitle()<<endl;
            cout<<"Total:"<<course.getTotalTasks()<<endl;
            cout<<"Completed:"<<course.getCompletedTasks()<<endl;
            cout<<"Progress: ";
            double progress = (100.0*course.getCompletedTasks())/(10.0*course.getTotalTasks());
            for(int i =1;i<=10;i++)
            {
                if((i-progress)<=0.5)cout<<"#";
                else cout<<".";
            }
            cout<<endl;
        }
        ~Report(){}
    };
}
