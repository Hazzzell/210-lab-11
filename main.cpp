//COMSC-210-5293 | Lab 11 | Keng C Chan
//IDE used: Visual Studio Code (VS Code) 
#include <iostream>
using namespace std;

const int NR_GRADES = 2, NR_STUDENTS = 3;

struct Student {
    string name;
    int id;
    int * grades;

    ~Student() {
        if (grades) 
            delete [] grades;
        grades = nullptr;
    }
};

void inputStudent(Student *);
void displayStudent(Student *);

int main() {
    Student *roster = new Student[NR_STUDENTS];
    
    for (int i = 0; i < NR_STUDENTS; i++)
        inputStudent(&roster[i]);
    
    for (int i = 0; i < NR_STUDENTS; i++)
        displayStudent(&roster[i]);
    
    return 0;
}

void inputStudent(Student * sptr) {
    static int nrStu = 1;
    cout << "Input data for Student #" << nrStu << ":\n";
    cout << "Name: ";
    getline(cin, sptr->name);
    cout << "ID: ";
    cin >> sptr->id;
    sptr -> grades = new int[NR_GRADES];
    for (int i = 0; i < NR_GRADES; i++) {
        cout << "Grade #" << i + 1 << ": ";
        cin >> sptr->grades[i];
    }
    cin.ignore();
    cout << endl << endl;
    nrStu++;
}

void displayStudent(Student * sptr) {
    cout << "Student summary:\n";
    cout << "Name: " << sptr->name << endl;
    cout << "ID: " << sptr->id << endl;
    for (int i = 0; i < NR_GRADES; i++)
        cout << "Grade #" << i + 1 << ": " 
             << sptr->grades[i] << endl;
    cout << endl << endl;
}
