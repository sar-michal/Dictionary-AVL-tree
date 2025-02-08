# Dictionary AVL Tree

This project implements a Dictionary using an AVL tree. It was created for the EADS university course and includes various functionalities such as inserting elements, updating information, checking if an element is present, removing elements, clearing contents, printing, and graphing the data structure. The program also contains a function allowing it to read from a file and count all word appearances.

## Features

- **Insert Elements**: Add new elements to the dictionary.
- **Update Info**: Update the information associated with a key.
- **Search**: Check if an element is present in the dictionary.
- **Remove Elements**: Remove elements from the dictionary.
- **Clear Contents**: Clear all elements from the dictionary.
- **Print In Order**: Print the elements of the dictionary in order.
- **Graph**: Graphically represent the AVL tree structure.
- **Read From File**: Read text from a file and count word appearances.

## Installation

To compile and run the project, use the following command:

```sh
g++ main.cpp -o main.exe
./main.exe
```

## Usage
Here is an example of how to use the Dictionary:

```cpp
#include <iostream>
#include "Dictionary.cpp"
using namespace std;

int main() {
    Dictionary<int, string> example;
    cout<<endl<<"--Example--"<<endl;
    cout<<"\t--inserting--"<<endl;
    example.insertElement(1, "John");
    example.insertElement(2, "Blake");
    example.insertElement(3, "Rose");
    example.insertElement(4, "Angela");
    example.insertElement(5, "Francesca");
    example.insertElement(6, "Pablo");
    example.insertElement(7, "March");
    example.insertElement(8, "Vanessa");
    example.insertElement(9, "Steven");
    example.insertElement(10, "Chad");
    example.graph(cout);

    cout<<"\t--removing--"<<endl;
    example.remove(2);
    example.remove(5);
    example.remove(9);
    example.remove(4);
    example.graph(cout);
    cout<<"\t--Printing in order--"<<endl;
    example.printInOrder();
}
```
Terminal output of the example:
```sh
--Example--
        --inserting--
                        10
                9
        8
                        7
                6
                        5
 4
                3
        2
                1
        --removing--
                10
        8
                7
 6
        3
                1
        --Printing in order--
1 John
3 Rose
6 Pablo
7 March
8 Vanessa
10 Chad
```