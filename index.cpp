#include<bits/stdc++.h>
#include "employee.h"
#include "course.h"
#include "enrollment.h"
#include "enrollmentManager.h"
#include "report.h"
#include "logger.h"

using namespace std;

Logger::Logger *Logger::Logger::instance=NULL;

class TrainingManager
{
private:
    Logger::Logger *logger = logger->getInstance();
public:
    void viewAllEmployeeDetails( vector<unique_ptr<Employee::Employee>> &employees)
    {
        logger->updateLogs((string)"Admin Viewed Employee Details");
        cout << "\n===== Employee Details =====" << endl;
        for ( auto &emp : employees)
        {
            cout << "Name: " << emp->getName() << endl;
            cout << "Position: " << emp->getPosition() << endl;
            cout << "Department: " << emp->getDepartment() << endl;
            cout << "---------------------------------" << endl;
        }
    }

    void viewAllCourseDetails( vector<unique_ptr<Course::Course>> &courses)
    {
        logger->updateLogs((string)"Admin Viewed Course Details");
        cout << "\n===== Course Details =====" << endl;
        for ( auto &crs : courses)
        {
            cout << "Title: " << crs->getTitle() << endl;
            cout << "Description: " << crs->getDescription() << endl;
            cout << "Instructor: " << crs->getInstructor() << endl;
            cout << "---------------------------------" << endl;
        }
    }

    void viewEnrollmentDetails(map<int, vector<Enrollment::Enrollment>> &enrollments, vector<unique_ptr<Employee::Employee>> &employees, int empId)
    {
        cout << "\n===== Enrollment Details =====" << endl;
        cout << "Employee: " << (*employees[empId]).getName() << endl;
        map<int, vector<Enrollment::Enrollment>>::iterator itr;
        itr = enrollments.find(empId);

        if (itr == enrollments.end())
        {
            cout << "No Enrollments Found!\n";
        }
        else
        {
            int i = 1;
            for (Enrollment::Enrollment &obj : enrollments[empId])
            {
                cout << "Course " << i++ << ": " << (obj.getCourse()).getTitle() << endl;
            }
        }
    }


    void employerView(vector<unique_ptr<Course::Course>> &courses, vector<unique_ptr<Employee::Employee>> &employees, map<int, vector<Enrollment::Enrollment>> &enrollments)
    {
        logger->updateLogs((string)"Admin Logged In");
        int choice;
        while (true)
        {
            cout << "\nChoose an option:\n";
            cout << "1. Enter Course details\n";
            cout << "2. Enter Employee details\n";
            cout << "3. Enroll Employee in a Course\n";
            cout << "4. View All Employee Details\n";
            cout << "5. View All Course Details\n";
            cout << "6. View Enrollment Details\n";
            cout << "7. Track Progress for all employees\n";
            cout << "8. View Logs\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                logger->updateLogs((string)"Admin Created Course");
                string title, description, instructor;
                int totalTasks;
                cout << "Enter Course Title: ";
                cin >> title;
                cout << "Enter Course Description: ";
                cin.ignore();
                getline(cin,description);
                cout << "Enter Course Instructor: ";
                getline(cin,instructor);
                cout << "Enter Total Tasks: ";
                cin >> totalTasks;
                courses.push_back(make_unique<Course::Course>(title, description, instructor,totalTasks));
                break;
            }
            case 2:
            {
                logger->updateLogs((string)"Admin Enrolled Employee");
                string name, position, department;
                cout << "Enter Employee Name: ";
                cin >> name;
                cout << "Enter Employee Position: ";
                cin.ignore();
                getline(cin,position);
                cout << "Enter Employee Department: ";
                getline(cin,department);
                employees.push_back(make_unique<Employee::Employee>(name, position, department));
                break;
            }
            case 3:
            {
                int employeeIndex, courseIndex;
                cout << "Enter the index of the employee: ";
                cin >> employeeIndex;
                cout << "Enter the index of the course: ";
                cin >> courseIndex;
                logger->updateLogs((string)"Admin Enrolled Employee "+to_string(employeeIndex)+" to course "+to_string(courseIndex));

                if (employeeIndex < 0 || employeeIndex >= employees.size() || courseIndex < 0 || courseIndex >= courses.size())
                {
                    cout << "Invalid index for employee or course." << endl;
                }
                else
                {
                    Course::Course* curCourse = (*courses[courseIndex]).Course::getCopy(*courses[courseIndex]);
                    Enrollment::Enrollment enrol = Enrollment::Enrollment(*employees[employeeIndex], *curCourse);

                    enrollments[employeeIndex].push_back(enrol);
                }

                    break;
            }

            case 4:
                viewAllEmployeeDetails(employees);
                break;
            case 5:
                viewAllCourseDetails(courses);
                break;
            case 6:
            {
                logger->updateLogs((string)"Admin Viewed Enrollment Details");
                int employeeIndex;
                cout << "Enter the index of the employee: ";
                cin >> employeeIndex;

                if (employeeIndex < 0 || employeeIndex >= employees.size())
                {
                    cout << "Invalid index for employee or course." << endl;
                }
                else
                {
                    viewEnrollmentDetails(enrollments, employees ,employeeIndex);
                }
                break;
            }
            case 7:
                {
                    logger->updateLogs((string)"Admin Viewed Training Report");
                    cout<<"\nTraining Report"<<endl;
                    cout<<"---------------"<<endl;
                    for(int empId=0; empId<employees.size(); empId++)
                    {
                        Employee::Employee currentEmployee = *employees[empId];
                        cout<<endl<<empId+1<<": "<<currentEmployee.getName()<<endl;
                        Report::Report report;
                        for(auto enrollment : enrollments[empId])
                        {
                            report.getReport(enrollment.getCourse());
                        }
                    }
                    break;
                }
            case 8:
                {
                    logger->viewLogs();
                    break;
                }
            case 9:
                logger->updateLogs((string)"Admin Logged Out");
                cout << "Exiting the program.\n\n";
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    void employeeView(vector<unique_ptr<Course::Course>> &courses, vector<unique_ptr<Employee::Employee>> &employees, map<int, vector<Enrollment::Enrollment>> &enrollments)
    {
        int empId;
        cout<<"\nEnter Employee Id: ";
        cin>>empId;
        Employee::Employee currentEmployee = *employees[empId];
        logger->updateLogs((string)"Employee "+to_string(empId)+" logged in");
        int choice;
        while(true)
        {
            cout << "\nChoose an option:\n";
            cout << "1. View Enrolled Courses\n";
            cout << "2. Update Progress\n";
            cout << "3. View progress\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice)
            {
            case 1:
                {
                    logger->updateLogs((string)"Employee"+ to_string(empId) +"Viewed Enrollment Details");
                    viewEnrollmentDetails(enrollments, employees ,empId);
                    break;
                }
            case 2:
                {
                    logger->updateLogs((string)"Employee "+to_string(empId)+" updated progress");
                    int courseId;
                    cout<<"\nEnter Course ID to update progress:";
                    cin>>courseId;
                    map<int, vector<Enrollment::Enrollment>>::iterator itr;
                    itr=enrollments.find(empId);
                    if(itr==enrollments.end())
                    {
                        cout<<"No enrollment found\n";
                    }
                    else
                    {
                        for(auto obj : enrollments[empId])
                        {
                            if((obj.getCourse()).getTitle()==(*courses[courseId]).getTitle())
                            {
                                (obj.getCourse()).updateTasks();
                            }
                        }
                    }
                    break;
                }
            case 3:
                {
                    logger->updateLogs((string)"Employee "+to_string(empId)+" viewed his report");
                    cout<<"\nTraining Report"<<endl;
                    cout<<"---------------"<<endl;
                    cout<<empId+1<<": "<<currentEmployee.getName()<<endl;
                    Report::Report report;
                    for(auto enrollment : enrollments[empId])
                    {
                        report.getReport(enrollment.getCourse());
                    }
                    break;
                }
            case 4:
                {
                    logger->updateLogs((string)"Employee "+to_string(empId)+" logged out");
                    cout<<endl;
                    return;
                }
            default:
                {
                     cout << "Invalid choice. Please try again.\n";
                }
            }
        }

    }
    void TrainingManage()
    {
        vector<unique_ptr<Course::Course>> courses;
        vector<unique_ptr<Employee::Employee>> employees;
        EnrollmentManager::EnrollmentManager obj=EnrollmentManager::EnrollmentManager();
        map<int, vector<Enrollment::Enrollment>> enrollments;
        enrollments = obj.getEnrollments();
        int choice;

        while(true)
        {
            cout<<"Choose your role:\n";
            cout<<"1.Employer\n";
            cout<<"2.Employee\n";
            cout<<"3.Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice)
            {
            case 1:
                {
                    employerView(courses,employees,enrollments);
                    break;
                }
            case 2:
                {
                    employeeView(courses,employees,enrollments);
                    break;
                }
            case 3:
                {
                    cout << "Exiting the program.\n";
                    return;
                }
            default:
                {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        }
    }
};

int main()
{
    TrainingManager index;
    index.TrainingManage();
    return 0;
}
