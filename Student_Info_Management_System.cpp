#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student_Details
{
private:
    string First_Name;
    string Middle_Name;
    string Last_Name;
    string Name;
    int Age;
    string Phone_Number;
    string Email_ID;
    int Roll_Number;
    char Gender;

public:
    static int num;
    Student_Details()
    {
        num++;
        cout << "Enter the details of student-" << num << "." << endl;
        cout << "Enter First_Name: ";
        cin >> First_Name;
              
        cout << "Enter Middle_Name ( or type 'skip' to skip): ";
        cin >> Middle_Name;
        if (Middle_Name == "skip")
        {
            Middle_Name = "";
        }

        Name = First_Name + " " + Middle_Name + " " + Last_Name;

        cout << "Enter Last_Name: ";
        cin >> Last_Name;

        cout << "Enter age: ";
        cin >> Age;

        while (Age <= 0)
        {
            cout << "Invalid age!! Please enter valid age." << endl;
            cout << "Enter age: ";
            cin >> Age;
        }

        cout << "Enter students phone number: ";
        cin >> Phone_Number;

        while (Phone_Number.size() != 10 || Phone_Number[0] == '0')
        {
            cout << "Invalid phone number!! Please enter valid phone number." << endl;
            cout << "Enter students phone number: ";
            cin >> Phone_Number;
        }

        cout << "Enter students email ID: ";
        cin >> Email_ID;

        while (Email_ID.find('@') == string ::npos || Email_ID.find('.') == string ::npos || isdigit(Email_ID[0]))
        {
            cout << "Invalid email ID!! Please enter valid email ID." << endl;
            cout << "Enter students email ID: ";
            cin >> Email_ID;
        }

        cout << "Enter roll number: ";
        cin >> Roll_Number;

        while (Roll_Number <= 0)
        {
            cout<< "Invalid roll number!! Please enter valid roll number." << endl;
            cout<< "Enter roll number: ";
            cin>> Roll_Number;
        }

        cout << "Enter gender (M for Male, F for Female, O for Other): ";
        cin >> Gender;

        while (Gender != 'M' && Gender != 'F' && Gender != 'O' && Gender != 'm' && Gender != 'f' && Gender != 'o')
        {
            cout << "Invalid gender!! Please enter valid gender." << endl;
            cin >> Gender;
        }

        cout<<endl;
    }
};

int Student_Details::num = 0;

int main()
{
    int size;
    cout << "Enter the number of students in tenth class: ";
    cin >> size;

    vector<Student_Details> Tenth_Class(size);

    return 0;
}