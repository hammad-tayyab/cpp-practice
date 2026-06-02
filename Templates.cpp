# include <iostream>

using namespace std;

//function template
// template <typename T> void swap1(T& a, T& b) //templates are the function to use differnent data type in the same fucntion or classes. its to save your time forom writing long long lines of codes again and agian for differnt data types.
//  { T temp = a;
//      a = b;
//       b = temp;
//      }
//       int main() 
//       { int x = 5, y = 10;
//          swap1(x, y);
//           // Works with int 
//           string s1 = "Hello", s2 = "World";
//            swap1(s1, s2); // Works with string 

//            cout<< "x: " << x << ", y: " << y << endl;
//             cout << "s1: " << s1 << ", s2: " << s2 << endl;
//            return 0; }


//class template
// template <typename T> class Box 
// { private:
//      T data; 
//      public: 
//      Box(T d) : data(d) {} 
//      void display() 
//      { cout << "Data: " << data << endl; } 
//      T getData() { return data; } 
//     }; 
//     int main() 
//     { Box<int> intBox(100); 
//         intBox.display(); 
//         Box<string> strBox("Hello"); 
//         strBox.display(); 
//         return 0; }


// multiple template types
template <class T1, class T2>
class Entry {
public:
    T1 key;
    T2 value;

    Entry(T1 k, T2 v) : key(k), value(v) {}

    void print() {
        cout << "Key: " << key << " | Value: " << value << endl;
    }
};

int main() {
    // An entry with an integer ID and a string name
    Entry<int, string> student(256, "Hammad");
    student.print();

    // An entry with a string code and a double value
    Entry<string, double> product("BTC", 65000.50);
    product.print();

    return 0;
}


// Code reusability - Write once, use with any type
// Type safety - Compile-time type checking
// Performance - No runtime overhead
// Flexibility - Works with built-in and user-defined types