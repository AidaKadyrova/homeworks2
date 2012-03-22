#include <iostream>
//#include "arraystack.h"111
#include "stack.h"
#include "pointerstack.h"

using namespace std;


int main()
{
    //Stack * m = new ArrayStack();
    Stack * m = new PointerStack();
    int command = 0;
    cout << "1 - push element to stack\n2- pop\n3 - print last element\n4 - print stack\n5 - print size\n0 - exit" << endl;
    while(1)
    {
        cout << "enter the command" << endl;
        cin >> command;
        switch(command)
        {
        case 1:
        {
            int n = 0;
            cout << "enter the number  ";
            cin >> n;
            m->push(n);
            break;
        }
        case 2:
        {
            cout << "deleted  " << m->pop() << endl;
            break;
        }
        case 3:
        {
            cout << m->front() << endl;
            break;
        }
        case 4:
        {
            m->printStack();
            break;
        }
        case 5:
        {
            m->printSize();
            break;
        }
        case 0:
        {
            cout << "goodbye" << endl;
            return 0;
        }
        }
    }
    delete m;
    return 0;
}
