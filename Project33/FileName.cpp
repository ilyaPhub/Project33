#include <iostream>

using namespace std;

class Person {
protected:
    const char* name;
    int age;

public:
    Person(const char* name, int age) : name(name), age(age) {}

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    const char* university;

public:
    Student(const char* name, int age, const char* university)
        : Person(name, age), university(university) {}

    void display() const override {
        Person::display();
        cout << "University: " << university << endl;
    }
};

class Teacher : public Person {
private:
    const char* subjects[5]; 
    int numSubjects;         
    double salary;

public:
    Teacher(const char* name, int age, const char* subj[], int n, double salary)
        : Person(name, age), numSubjects(n), salary(salary) {
        for (int i = 0; i < numSubjects; ++i) {
            subjects[i] = subj[i];
        }
    }

    void display() const override {
        Person::display();
        cout << "Salary: $" << salary << endl;
        cout << "Subjects: ";
        for (int i = 0; i < numSubjects; ++i) {
            cout << subjects[i] << " ";
        }
        cout << endl;
    }
};

class Driver : public Person {
private:
    const char* carNumber;
    const char* licenseSeries;

public:
    Driver(const char* name, int age, const char* carNumber, const char* licenseSeries)
        : Person(name, age), carNumber(carNumber), licenseSeries(licenseSeries) {}

    void display() const override {
        Person::display();
        cout << "Car Number: " << carNumber << ", License Series: " << licenseSeries << endl;
    }
};

class Doctor : public Person {
private:
    const char* specialty;
    int experience;

public:
    Doctor(const char* name, int age, const char* specialty, int experience)
        : Person(name, age), specialty(specialty), experience(experience) {}

    void display() const override {
        Person::display();
        cout << "Specialty: " << specialty << ", Experience: " << experience << " years" << endl;
    }
};

int main() {
    const char* subjects[] = { "Math", "Physics" }; 
    Student student("Alice", 20, "MIT");
    Teacher teacher("Bob", 45, subjects, 2, 5000.0);
    Driver driver("Charlie", 35, "AB1234CD", "B123456");
    Doctor doctor("Diana", 40, "Cardiology", 15);

    student.display();
    cout << endl;

    teacher.display();
    cout << endl;

    driver.display();
    cout << endl;

    doctor.display();
    cout << endl;

    return 0;
}
