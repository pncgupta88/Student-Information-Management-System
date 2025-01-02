#include <iostream>
#include <vector>
#include<string>
using namespace std;



class Student
{
    string name;
    int age;
    string Phone_number; 
    string e_mail; //@
    int Roll_No;
    char Gender;
    // Subjects

public:

    Student() 
    {
        static int num = 0;
        num++;
        cout << "Enter details of Student " << num << endl;
        cout << "Name : ";
        cin >> name;
        // cout << "Age : ";
        // cin >> age;
        // while(age<=0)
        // {
        //     cout<<"Invalid Age , Enter Again :"<<endl;
        //     cin>>age;
        // }
        cout<<"Enter Phone Number"<<endl;
        cin>>Phone_number;
        while(Phone_number[0] == '0' || Phone_number.length() != 10)
        {
            cout<<"Invalid Phone_number , Enter Again :"<<endl;
            cin>>Phone_number;
        }
        // and so on...
    }

    void get_info()
    {
        // sare print
    }

    void get_age()
    {
        // sare print
    }
    // and so on..
};

int main()
{
    int size;
    cout << "Enter the number of Students in your Class" << endl;
    cin >> size;
    vector<Student> Tenth(size);

    while(true)
    {
        int n;
        cout<<"What Do you Want to do?\n INput 1 if you .. input -1 for nothing"<<endl;
        cin>>n;
        if( n == 1)
        {
            string nm;
            cout<<"Enter name"<<endl;
            cin>>nm;
        }

        else if(n == -1)
        {
            break;
        }
    }

    cout<<"Thank You For Using Our System, Please Visit us Again! ✨";
}

//Data to CSV/Excel file m upload
//Sort 
//Update 
//roll number/Name s data access