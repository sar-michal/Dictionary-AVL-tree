#include <iostream>
#include "Task3.cpp"
using namespace std;
int main()
{
    Dictionary<int, string> test1;
    test1.insertElement(1, "John");
    test1.insertElement(2, "Blake");
    test1.insertElement(3, "Rose");
    test1.insertElement(4, "Angela");
    test1.insertElement(5, "Francesca");
    test1.graph(cout);
    test1.printInOrder();
    cout<<"--copying--"<<endl;
    Dictionary<int, string> test2(test1);
    test2.graph(cout);
    test2.printInOrder();
    cout<<"--clearing and assigning--"<<endl;
    test1.clearContents();
    test1 = test2;
    test1.graph(cout);
    cout<<"--searching--"<<endl;
    string infoToFind = "NULL";
    test1.search(5, infoToFind);
    cout<<"found: "<<infoToFind<<endl;
    cout<<"--removing--"<<endl;
    test2.insertElement(6, "Pablo");
    test2.insertElement(7, "March");
    test2.insertElement(8, "Vanessa");
    test2.insertElement(9, "Steven");
    test2.insertElement(10, "Chad");
    test2.insertElement(11, "Marcello");
    test2.insertElement(12, "Juan");
    test2.insertElement(13, "Joanne");
    test2.insertElement(14, "Frank");
    test2.graph(cout);
    test2.printInOrder();
    cout<<"After removal"<<endl;
    test2.remove(8);
    test2.graph(cout);
    test2.printInOrder();
    cout<<"--readFromFile--"<<endl;
    Dictionary<string, int> test3;
    readFromFile(test3, "Tetris.txt");
    test3.printInOrder();
    cout<<"--END--"<<endl;
}