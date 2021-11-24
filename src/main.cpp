#include <iostream>

using namespace std;

class Shape
{
protected:
    int width, height;
    Shape *insideShape;

public:
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

    Shape operator+=(const Shape &object)
    {
        width += object.width;
        height += object.height;
    }

    // Shape &operator+=(const Shape &object)
    // {
    //     width += object.width;
    //     height += object.height;
    //     return *this;
    // }

    Shape &operator=(const Shape &object) 
    {
        //if we have same refferences, just return current object refference
        if (this == &object)
            return *this;

        //otherwise, do usual operations
        width = object.width;
        height = object.height;

        //in case that we're using pointers, before delete, make sure you have a new copy of the original value
        //in the case below (commented), it can be seen that we first try to delete the old angle,
        //and assign the new value over an already deleted field.That's not good, because our program will throw an exception/error.
        //----------------------------
        // delete insideShape;
        // insideShape = new Shape(*object.insideShape);

        Shape *copyOriginal = insideShape;
        insideShape = new Shape(*object.insideShape);
        delete copyOriginal;

        return *this;
    }

    virtual int getWidth() {
        return width;
    }

    virtual int getHeight()
    {
        return height;
    }

    virtual int area(){
        return 0;
    }

    virtual int perimeter(){
        return 0;
    }
};

class Square : public Shape
{
private:
    int angle;
    Shape *insideShape;

public:
    Square(int a, int b, int c) : Shape(a, b)
    {
        angle = c;
    }

    Square& operator=(const Square& object) {
        //if we have same refferences, just return current object refference
        if (this == &object)
            return *this;

        //otherwise, copy class fields
        angle = object.angle;

        //and make sure you're copy also the base class fiels, by call his copy assignment operator
        // Shape::operator=(object);

        return *this;
    }

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
    // Rectangle rect(5, 3);
    // Square squ(2, 0);
    // Rhombus r1(2, 2);

    // cout << "Rect width " << rect.getWidth() << endl;
    // cout << "Rect height " << rect.getHeight() << endl;
    // cout << "Square width " << squ.getWidth() << endl;
    // cout << "Square height " << squ.getHeight() << endl;
    // cout << "Rhombus width " << r1.getWidth() << endl;
    // cout << "Rhombus height " << r1.getHeight() << endl;

    // r1 += squ += rect;

    // //bad things will happens if we're not return the current object refference if we try to use += operator
    // cout << "Rhombus area " << r1.area() << endl;
    // cout << "Rhombus perimeter " << r1.perimeter() << endl;
    // cout << "Rhombus width " << r1.getWidth() << endl;
    // cout << "Rhombus height " << r1.getHeight() << endl;


    Square sq1(2, 2, 2);
    Square sq2(1, 1, 1);
    sq2 = sq1;
    cout << "Square width " << sq2.getWidth() << endl;
    cout << "Square height " << sq2.getHeight() << endl;

    return 0;
}