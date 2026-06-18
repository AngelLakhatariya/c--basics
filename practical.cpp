#include <iostream> 
#include <string>

using namespace std;

//QUESTION 1 

class Rectangle {
    private:
      double length;
      double width;

    public:
      void setLength(double l) {
        length = l;
      }
      void setWidth(double w) {
        width = w;
      }
 
    double getLength() const {
        return length;
    }
     
    double getWidth() const {
        return width;
    }

    double calculateArea() const {
        return length * width;
    }
    
};

int main () {

  Rectangle rect;

  rect.setLength(10.5);
  rect.setWidth(5.0);

  cout<< "--- Rectangle Details ---" << endl;
  cout<< "Length: " << rect.getLength() << endl;
  cout<< "Width: " << rect.getWidth() << endl;
  cout<< "Calculated Area: " << rect.calculateArea() << endl;

}


// QUESTION 2

class Employee {
  private:
    string name;
    double salary;
    string designation;
public:
    void setName(string n) {
      name = n;
    }
    void setSalary(double s) {
      salary = s;
    }
    void setDesignation(string d) {
      designation = d;
    }

    string getName() const {
      return name;
    }
    double getSalary() const {
      return salary;
    }
    string getDesignation() const {
      return designation;
    }
};

int main() {

  Employee emp;

  emp.setName("Angel Lakhatariya");
  emp.setSalary(85000.50);
  emp.setDesignation("Web Developer");

  cout << "--- Employee Details ---" << endl;
  cout << "Name: " << emp.getName() << endl;
  cout << "Designation: " << emp.getDesignation() << endl;
  cout << "Salary: " << emp.getSalary() << endl;
}


// QUESTION 3

class Shape {
  protected:
    string color;
    double area;

  public: 
    void setColor(string c) {
      color = c;
    }
    string getColor() const {
      return color;
    }
    double getArea() const {
      return area;
    }

    virtual void calculateArea() = 0;

    virtual ~Shape() {

    }
};

class Circle : public Shape {
  private:
    double radius;

  public: 
    void setRadius(double r) {
      radius = r;
    }
    void calculateArea() override {
      area = 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
  private:
    double length;
    double width;

  public: 
    void  setDimensions(double l, double w) {
      length = l;
      width = w;
    }

    void calculateArea() override {
      area = length * width;
    }
};

int main() {
  
  cout << "--- Shape Abstraction ---" << endl;

  Circle circ;
  circ.setColor("Blue");
  circ.setRadius(5.0);
  circ.calculateArea();
  
  cout << "Circle Color: " << circ.getColor() << " calculated Area: " << circ.getArea() << endl;

  Rectangle rec;
  rec.setColor("Yellow");
  rec.setDimensions(4.0, 7.0);
  rec.calculateArea();

  cout<< "Rectangle Color: " << rec.getColor() << " Calculated Area: " << rec.getArea() << endl;
}
 

// QUESTION 4

class Shape {
  protected:
     string color;
     double area;

  public:
     void setColor(string c) {
      color = c;
     }
     string getColor() const {
      return color;
     }
     double getArea() const {
      return area;
     }

     virtual void calculateArea() = 0;

     virtual void display() const {
       cout << "Generic Shape Color: " << color << " Area: " << area << endl;
     }

     virtual ~Shape() {}
};

class Circle : public Shape {
  private:
     double radius;

  public: 
     void setRadius(double r) {
      radius = r;
     }
     void calculateArea() override {
      area = 3.14 * radius * radius;
     }

     void display() const override {
      cout << "[Polymorphism] Circle   Color: " << color << " Radius: " << radius << " Area: " << area << endl;
     } 
};

class Rectangle : public Shape {
  private:
     double length;
     double width;

  public:
     void setDimensions(double l, double w) {
        length = l;
        width = w;
     }
     void calculateArea() override {
        area = length * width;
     }

     void display() const override {
       cout << "[Polymmorphism] Rectangle  Color: " << color << " Dimensions: " << length << "x" << width << " Area: " << area << endl;
     }
};

int main() {
  
   Circle c;
   c.setColor("Yellow");
   c.setRadius(3.0);
   c.calculateArea();

   Rectangle r;
   r.setColor("Green");
   r.setDimensions(5.0, 5.0);
   r.calculateArea();

   Shape * shapeArray[2];
   shapeArray[0] = &c;
   shapeArray[1] = &r;

   cout << "---Demonstrating Shape Polymorphism ---" << endl;
   for(int i = 0; i < 2; i++) {
      shapeArray[i]->display();
   }
}


// QUESTION 5

class Animal {
  public:
    virtual void sound() const = 0;
    virtual void move () const = 0;

    virtual ~Animal() {}
};

class Dog : public Animal {
  public:
    void sound() const override {
      cout << "Dog says: woof! woof!" << endl;
    }
    void move() const override {
      cout << "Dog Action: Running of all 4 legs." << endl;
    }
};

class Bird : public Animal {
  public:
    void sound() const override {
      cout << " Bird says: Chirp! Chirp!" << endl;
    }
    void move() const override {
      cout << "Bird Action: Flying through the Air." << endl;
    }
};

int main() {

   cout << "--- Animal Polymorphism Array ---" << endl;

   Animal* zoo[2];
   zoo[0] = new Dog();
   zoo[1] = new Bird();

   for (int i = 0; i < 2; i++) {
      zoo[i] ->sound();
      zoo[i] ->move();
      cout << "-------------------------------" << endl;
   }

   delete zoo[0];
   delete zoo[1];
}




