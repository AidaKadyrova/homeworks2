#include <iostream>
//#include "array.h"
#include "pointer.h"

using namespace std;

int read()
{
    cout << "enter the number" << endl;
    int n = 0;
    cin >> n;
    return n;
}

int main()
{
    //List * m = new Array();
    List * m = new Pointer();

    int command = 0;
    cout << "1 - add an element to the begin\n2 - add an element to the end\n3 - add an element to some position\n4 - delete element\n5 - is element in list\n6 - print list\n7 - print a number of elements\n8 - delete List\n0 - exit" << endl;
    while(1)
    {
        cout << "enter the command" << endl;
        cin >> command;
        switch(command)
        {
        case 1:
        {
            m->addToBegin(read());
            break;
        }
        case 2:
        {
            m->addToEnd(read());
            break;;
        }
        case 3:
        {
            cout << "enter the position" << endl;
            int position = 0;
            cin >> position;
            m->addToThePosition(read(),position);
            break;
        }
        case 4:
        {
            m->deleteElement(read());
            break;
        }
        case 5:
        {
            m->isElement(read());
            break;
        }
        case 6:
        {
            m->printList();
            break;
        }
        case 7:
        {
            m->printSize();
            break;
        }
        case 8:
        {
            m->deleteList();
            break;
        }
        case 0:
        {
            cout << "goodbye" << endl;
            return 0;
        }
        }
    }

    return 0;
}
