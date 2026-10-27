#include <iostream>
#include <string>

using namespace std;

class Student{
private:
    string studentName;
    int studentAge;

public:
    Student(string newName = "John Doe", int newAge = 18){
        studentName = newName;
        studentAge = newAge;
        cout << "Constructor Called." << endl;
    }

    ~Student(){
        cout << "Destructor Called." << endl;
    }

    Student(const Student &copyStudent){
        cout << "Copy Constructor Called." << endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

    Student& operator=(const Student &copyStudent){
        cout << "Copy Assignment Operator Called." << endl;

        if(this != &copyStudent){
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
        }

        return *this;
    }

    void printDetails(){
        cout << studentName << " " << studentAge << endl;
    }
};

int main(){

    const int j = 5;

    // Static memory allocation
    Student studentList[j];

    string namesList[j] = {"Cyrill","Cj","Jofjof","Kit","Clover"};
    int ageList[j] = {15,16,18,19,16};

    for(int i=0;i<j;i++){
        studentList[i] = Student(namesList[i], ageList[i]);
    }

    cout << "\nStudent List\n";

    for(int i=0;i<j;i++){
        studentList[i].printDetails();
    }

    return 0;
}