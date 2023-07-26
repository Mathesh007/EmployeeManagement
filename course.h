namespace Course
{
using namespace std;
class Course
{
private:
    string title;
    string description;
    string instructor;
    int totalTasks;
    int completedTasks;

public:
    Course(string &title, string &description, string &instructor, int totalTasks)
        : title(title), description(description), instructor(instructor), totalTasks(totalTasks)
    {
        completedTasks=0;
    }
    Course(Course *course)
    {
        title=(*course).getTitle();
        description=(*course).getDescription();
        instructor=(*course).getInstructor();
        totalTasks=(*course).getTotalTasks();
        completedTasks=0;
    }
    string &getTitle() { return title; }
    string &getDescription() { return description; }
    string &getInstructor() { return instructor; }
    int getTotalTasks() { return totalTasks; }
    int getCompletedTasks() { return completedTasks; }

    void updateTasks()
    {
        if(completedTasks==totalTasks)
        {
            cout<<"\nCourse Completed Already!\n";
            return;
        }
        char choice;
        cout<<"\nCompleted Task no."<<completedTasks+1<<"?\nEnter(y/n):";
        while(true)
        {
            cin>>choice;
            switch(choice)
            {
            case 'y':
            case 'Y':
                {
                    completedTasks++;
                    return;

                }
            case 'n':
            case 'N':
                {
                    return;
                }
            default:
                cout<<"Invalid Choice ! Enter your choice again: ";
            }
        }
    }
};
}
