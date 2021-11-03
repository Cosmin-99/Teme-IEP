#include <iostream>

using namespace std;

class Shape
{
protected:
    // const int width, height;
    int width, height;

public:
    // Shape(int a, int b): width(a) , height(b)
    // {

    // };

    Shape(int a, int b) {
        width = a;
        height = b;
    };

    ~Shape() {
        cout << "Destructor call" << endl;
    }

    Shape(const Shape &object){
        width = object.width;
        height = object.height;
    }

    Shape &operator=(const Shape &object){
        width = object.width;
        height = object.height;
        return *this;
    }

// Shape &operator=(const Shape &object) 
//     {
//         if (this == &object)
//             return *this;
    
//         this->~Shape();

//         new (this) Shape(object.width, object.height);
//         return *this;
//     }

    // Shape &operator=(const Shape &object) = delete;

    virtual int area(){
        return 0;
    }

    virtual int perimeter(){
        return 0;
    }
};

class Square : public Shape
{
public:
    Square(int a, int b) : Shape(a, b)
    {

    };
    int area()
    {
        return (width * width);
    }

    int perimeter()
    {
        return 4 * width;
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(int a, int b) : Shape(a, b)
    {
       
    };
    int area()
    {
        return (width * height);
    }

    int perimeter()
    {
        return 2 * (width + height);
    }
};

class Rhombus : public Shape
{
public:
    Rhombus(int a, int b) : Shape(a, b){

    };

    int area()
    {
        return (width * height);
    }

    int perimeter() {
        return (4 * width);
    }
};

int main()
{

    //maked sure objects are initialized before they're used
    Rectangle rect(5, 3);
    Square squ(2, 0);
    Rhombus rho(4, 6);
    Shape shape(100, 100);

    cout << shape.area() << endl;
    cout << shape.perimeter() << endl;
    cout << rect.area() << endl;
    cout << squ.area() << endl;
    cout << rho.area() << endl;
    cout << rect.perimeter() << endl;
    cout << squ.perimeter() << endl;
    cout << rho.perimeter() << endl;

    //be carefully, this is a copy constructor call, not copy assignment operator
    Square newSquare = squ;

    Rectangle newRectangle(6, 9);

    // this is a copy assignnent operator (now is deleted because, I tell to compiler that I don't want to use it)
    newRectangle = rect;

    cout << "New Square" << endl;

    cout << newSquare.area() << endl;
    cout << newSquare.perimeter() << endl;

    cout << "New Rectangle" << endl;

    cout << newRectangle.area() << endl;
    cout << newRectangle.perimeter() << endl;

    //finally, all objects are destroyed (destructor is called)

    return 0;
}