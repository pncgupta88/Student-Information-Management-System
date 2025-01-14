#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Student_Details
{
private:
    int Age;
    string Phone_Number;
    string Email_ID;
    char Gender;

public:
    string First_Name;
    string Middle_Name;
    string Last_Name;
    string Name;
    int Roll_Number;
    static int num; // Static variable to keep track of the student number
    string Blood_Group;

    // Constructor to input student details
    Student_Details()
    {
        num++;
        cout << "Enter the details of student-" << num << endl;
        cout << "Enter First_Name*: ";
        cin >> First_Name;

        cout << "Enter Middle_Name (or type 'skip' to skip): ";
        cin >> Middle_Name;
        if (Middle_Name == "skip") // Skip middle name if input is 'skip'
        { 
            Middle_Name = "";
        }

        cout << "Enter Last_Name*: ";
        cin >> Last_Name;

        Name = First_Name + " " + Middle_Name + " " + Last_Name;

        // Input and validate age
        cout << "Enter Age*: ";
        cin >> Age;

        while (Age <= 0)
        {
            cout << "Invalid Age!! Please enter valid Age." << endl;
            cout << "Enter Age: ";
            cin >> Age;
        }

        // Input and validate phone number
        cout << "Enter students Phone_Number*: ";
        cin >> Phone_Number;

        while (Phone_Number.size() != 10 || Phone_Number[0] == '0' || !all_of(Phone_Number.begin(), Phone_Number.end(), ::isdigit))
        {
            cout << "Invalid Phone_Number! Please enter valid Phone_Number." << endl;
            cout << "Enter students Phone_Number again: ";
            cin >> Phone_Number;
        }

        // Input and validate email
        cout << "Enter students Email_ID: ";
        cin >> Email_ID;

        while (Email_ID.find('@') == string ::npos || Email_ID.find('.') == string ::npos ||
               isdigit(Email_ID[0]) || Email_ID.find('@') > Email_ID.find('.') || Email_ID.find('.') - Email_ID.find('@') <= 1 ||
               Email_ID.front() == '@' || Email_ID.back() == '@' || Email_ID.front() == '.' || Email_ID.back() == '.' ||
               Email_ID.find(' ') != string ::npos)
        {
            cout << "Invalid Email_ID! Please enter valid Email_ID." << endl;
            cout << "Enter students Email_ID again: ";
            cin >> Email_ID;
        }

        // Input and validate roll number
        cout << "Enter Roll_Number*: ";
        cin >> Roll_Number;

        while (Roll_Number <= 0)
        {
            cout << "Invalid Roll_Number! Please enter valid Roll_Number." << endl;
            cout << "Enter Roll_Number again: ";
            cin >> Roll_Number;
        }

        // Input and validate gender
        cout << "Enter Gender (M/m for Male, F/f for Female, O/o for Other): ";
        cin >> Gender;

        while (Gender != 'M' && Gender != 'F' && Gender != 'O' && Gender != 'm' && Gender != 'f' && Gender != 'o')
        {
            cout << "Invalid Gender! Please enter valid Gender." << endl;
            cout << "Enter Gender again (M/m for Male, F/f for Female, O/o for Other): ";
            cin >> Gender;
        }

        // Input and validate blood group
        cout << "Enter blood group of student: ";
        cin >> Blood_Group;

        while (Blood_Group != "A+" && Blood_Group != "A-" && Blood_Group != "B+" && Blood_Group != "B-" && Blood_Group != "AB+" && Blood_Group != "AB-" && Blood_Group != "O+" && Blood_Group != "O-")
        {
            cout << "Invalid blood group! Please enter valid blood group." << endl;
            cout << "Enter blood group of student again: ";
            cin >> Blood_Group;
        }

        cout << endl;
    }

    // Function to display student details
    void display_details() const
    {
        cout << "Name: " << Name << endl;
        cout << "Roll Number: " << Roll_Number << endl;
        cout << "Phone Number: " << Phone_Number << endl;
        cout << "Email ID: " << Email_ID << endl;
        cout << "Age: " << Age << endl;
        cout << "Gender: " << Gender << endl;
        cout << endl;
    }

    // Getter functions
    char get_Gender()
    {
        return Gender;
    }

    string get_Name() const
    {
        return Name;
    }

    int get_Roll_Number() const
    {
        return Roll_Number;
    }

    // Function to edit age
    int Edit_Age(int New_Age)
    {
        return Age = New_Age;
    }

    // Function to store student data in CSV file
    void saveToCSV(ofstream &outFile)
    {
        outFile << Name << ", " << Roll_Number << ", " << Phone_Number << ", " << Email_ID << ", " << Age << ", " << Gender << ", " << Blood_Group << "\n";
    }
};

// Sorting function to sort data by student name
bool sortbyName(const Student_Details &a, const Student_Details &b)
{
    return a.Name < b.Name;
}

// Function to search student by roll number
void searchby_Roll_Number(const vector<Student_Details> &info, const int &searched_Roll_Number)
{
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i].get_Roll_Number() == searched_Roll_Number)
        {
            info[i].display_details();
        }
    }
}

// Initialize static variable
int Student_Details::num = 0;

int main()
{
    int size;
    cout << "Enter the number of students in tenth class: ";
    cin >> size;
    cout << endl;
    vector<Student_Details> info(size);

    // Sorting the student details by name
    sort(info.begin(), info.end(), sortbyName);

    // Open a CSV file to store data
    ofstream outFile("student_details.csv");
    if (!outFile)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Write the header for CSV file
    outFile << "Name, Roll Number, Phone Number, Email ID, Age, Gender, Blood Group\n";

    while (true)
    {
        int next_Choice;
        cout << "Enter 1 to details of all students." << endl;
        cout << "Enter 2 to get student details by student's roll number." << endl;
        cout << "Enter 3 to display total number of students in tenth class." << endl;
        cout << "Enter 4 to display total number of boys, girls and others." << endl;
        cout << "Enter 5 to edit age by name." << endl;
        cout << "Enter 6 to exit program." << endl<< endl;;
        cout << "Enter your next choice: ";             
        cin >> next_Choice;
        cout << endl;

        // Counting boys, girls, and others
        int maleCount = 0, femaleCount = 0, otherCount = 0, totalStudents = size;

        for (int i = 0; i < info.size(); i++)
        {
            if (info[i].get_Gender() == 'M' || info[i].get_Gender() == 'm')
            {
                maleCount++;
            }
            else if (info[i].get_Gender() == 'F' || info[i].get_Gender() == 'f')
            {
                femaleCount++;
            }
            else
            {
                otherCount++;
            }
        }

        // Menu options for the user
        switch (next_Choice)
        {
        case 1:
            cout << "Details of all students:" << endl
                 << endl;
            for (int i = 0; i < size; i++)
            {
                cout << "The detail of student " << i + 1 << " is:" << endl;
                info[i].display_details();
            }
            break;

        case 2:        
            int searched_Roll_Number;
            cout << "Enter student's roll number to get details: "<<endl;;
            cin >> searched_Roll_Number;
            cout << "The detail of roll number " << searched_Roll_Number << " are:" << endl;
            searchby_Roll_Number(info, searched_Roll_Number);
            break;
        
        case 3:
            cout << "The total number of students in tenth class are: " << info.size() << endl<< endl;;
            break;

        case 4:
            cout << "The total number of boys, girls and others are:" << endl;
            cout << "The number of boys are: " << maleCount << endl;
            cout << "The number of girls are: " << femaleCount << endl;
            cout << "The number of others are: " << otherCount << endl
                 << endl;
            break;

        case 5:
            cout << "Editing age by roll number." << endl;
            cout << "Enter student roll number to edit age: ";
            cin >> searched_Roll_Number;
            for (int i = 0; i < info.size(); i++)
            {
                if (info[i].get_Roll_Number() == searched_Roll_Number)
                {
                    int New_Age;
                    cout << "Enter new age: ";
                    cin >> New_Age;
                    info[i].Edit_Age(New_Age);
                    cout << "Age of " << searched_Roll_Number << " is updated sucessfully!."<<endl<< endl;
                }
            }
            break;

        case 6:
            // Save all student data to CSV file
            for (int i = 0; i < size; i++)
            {
                info[i].saveToCSV(outFile);
            }
            cout << "Data saved to 'student_details.csv'. Exiting the program." << endl;
            cout << "Thank you! for working with us. Goodbye!" << endl;
            outFile.close();
            return 0;
            
        default:
            cout << "Enter a valid choice.";
            break;
        }
    }

    return 0;
}