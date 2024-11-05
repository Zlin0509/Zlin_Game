//
// Created by 27682 on 2024/11/3.
//

#include <iostream>
#include <string>
using namespace std;

class Book
{
protected:
    string title;
    string publisher;
    double price;

public:
    Book(const string& t, const string& p, double pr) : title(t), publisher(p), price(pr)
    {
    }

    virtual void show() const
    {
        cout << "Title: " << title << ", Publisher: " << publisher << ", Price: $" << price << endl;
    }
};

class ChildBook : public Book
{
private:
    int ageRange;

public:
    ChildBook(const string& t, const string& p, double pr, int age)
        : Book(t, p, pr), ageRange(age)
    {
    }

    void show() const override
    {
        Book::show();
        cout << "Age Range: " << ageRange << " years" << endl;
    }
};

class TeachBook : public Book
{
private:
    string gradeLevel;
    string subject;

public:
    TeachBook(const string& t, const string& p, double pr, const string& grade, const string& sub)
        : Book(t, p, pr), gradeLevel(grade), subject(sub)
    {
    }

    void show() const override
    {
        Book::show();
        cout << "Grade Level: " << gradeLevel << ", Subject: " << subject << endl;
    }
};

class Student
{
protected:
    string name;
    int age;
    string origin;
    string phone;

public:
    Student(const string& n, int a, const string& o, const string& p)
        : name(n), age(a), origin(o), phone(p)
    {
    }

    virtual void show() const
    {
        cout << "Name: " << name << ", Age: " << age << ", Origin: " << origin << ", Phone: " << phone << endl;
    }
};

// 大学生类
class StuCollege : public Student
{
protected:
    string college;
    string major;
    string dormAddress;
    int grade;

public:
    StuCollege(const string& n, int a, const string& o, const string& p, const string& col, const string& maj,
               const string& dorm, int gr)
        : Student(n, a, o, p), college(col), major(maj), dormAddress(dorm), grade(gr)
    {
    }

    void show() const override
    {
        Student::show();
        cout << "College: " << college << ", Major: " << major << ", Dorm Address: " << dormAddress << ", Grade: " <<
            grade << endl;
    }
};

class StuZAFU : public StuCollege
{
private:
    string campus;

public:
    StuZAFU(const string& n, int a, const string& o, const string& p, const string& col, const string& maj,
            const string& dorm, int gr, const string& cam)
        : StuCollege(n, a, o, p, col, maj, dorm, gr), campus(cam)
    {
    }

    void show() const override
    {
        StuCollege::show();
        cout << "Campus: " << campus << endl;
    }
};

class Rectangle
{
protected:
    double x, y;

public:
    Rectangle(double width, double height) : x(width), y(height)
    {
    }

    double getArea() const { return x * y; }
};

class Desk
{
protected:
    double height;

public:
    Desk(double h) : height(h)
    {
    }

    double getHeight() const { return height; }
};

class RectDesk : public Rectangle, public Desk
{
private:
    string color;

public:
    RectDesk(double side, double h, const string& col)
        : Rectangle(side, side), Desk(h), color(col)
    {
    }

    void show() const
    {
        cout << "Height: " << height << ", Area: " << getArea() << ", Color: " << color << endl;
    }
};

class Worker
{
protected:
    string name;
    int age;

public:
    Worker(const string& n, int a) : name(n), age(a)
    {
    }

    virtual void show() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Manager : virtual public Worker
{
protected:
    string position;
    string department;

public:
    Manager(const string& n, int a, const string& pos, const string& dep)
        : Worker(n, a), position(pos), department(dep)
    {
    }

    void show() const override
    {
        Worker::show();
        cout << "Position: " << position << ", Department: " << department << endl;
    }
};

class Designer : virtual public Worker
{
protected:
    string title;
    string specialty;

public:
    Designer(const string& n, int a, const string& t, const string& spec)
        : Worker(n, a), title(t), specialty(spec)
    {
    }

    void show() const override
    {
        Worker::show();
        cout << "Title: " << title << ", Specialty: " << specialty << endl;
    }
};

class DesManager : public Manager, public Designer
{
private:
    double salary;

public:
    DesManager(const string& n, int a, const string& pos, const string& dep, const string& t, const string& spec,
               double sal)
        : Worker(n, a), Manager(n, a, pos, dep), Designer(n, a, t, spec), salary(sal)
    {
    }

    void show() const override
    {
        Manager::show();
        Designer::show();
        cout << "Salary: $" << salary << endl;
    }
};

int main()
{
    Book book("T", "A", 49.99);
    book.show();
    ChildBook childBook("1", "B", 29.99, 8);
    childBook.show();
    TeachBook teachBook("C", "C", 59.99, "Zafu", "xxx");
    teachBook.show();

    Student student("Zlin", 20, "Hometown", "13819582557");
    student.show();
    StuCollege stuCollege("Zlin", 21, "Hometown", "12345", "Zaaaaaf", "Physics", "Dorm 1", 3);
    stuCollege.show();
    StuZAFU stuZAFU("Sunt", 22, "Hometown", "123-456-7890", "None", "None", "Dorm 2", 4,
                    "Main Campus");
    stuZAFU.show();

    RectDesk rectDesk(4.0, 2.0, "Red");
    rectDesk.show();

    Worker worker("A", 30);
    worker.show();
    Manager manager("B", 40, "shabi", "HR");
    manager.show();
    Designer designer("C", 35, "laji", "UI/UX");
    designer.show();
    DesManager desManager("D", 45, "feiwu", "Design Dept", "Lead Designer", "Industrial Design", 80000);
    desManager.show();

    return 0;
}
