#include "string_stack.h"
#include <exception>

using namespace std;

int main()
{
    try{
    cout<<"1. Checking constructor..." << endl;
    cout<<"with correct values... "<<endl;
        Stack myStack_1 (2,5), myStack_2 (1);
    cout<<"with incorrect..."<<endl;
        Stack myStack_3 (-123,0);
    }
    catch(bad_alloc&)
    {
        cout<<"error: can't allocate stack memory"<<endl;
    }
    catch(exception& err)
    {
        cout<<"error: "<< err.what() << endl;
    }
    try{
    cout<<"2. Checking push..." << endl;
        Stack myStack_1(2,5);
        myStack_1.push("abcd");
        myStack_1.push("123456789");
    }
    catch(bad_alloc&)
    {
        cout<<"error: can't allocate string memory"<<endl;
    }
    catch(exception& err)
    {
        cout<<"error: "<< err.what() << endl;
    }
    try{
    cout<<"3. Checking pop and peek..."<<endl;
        Stack myStack_4(1);
        myStack_4.pop();
        myStack_4.pop();
        myStack_4.pop();
        myStack_4.peek();
        myStack_4.peek();
    }
    catch( ... )
    {
        cout << "error in pop or peek string form stack"<< endl;
    }
    try{
    cout<<"4. Checking length and maxsize..."<<endl;
        Stack myStack1(5);
        myStack1.push("abc");
        myStack1.push("cba");
        if ( myStack1.length() != 2 )
            throw logic_error("length doesnt work");
        myStack1.pop();
        myStack1.peek();
        if ( myStack1.length() != 1 )
            throw logic_error("length doesnt work");
        if ( myStack1.maxsize() != 5)
            throw logic_error("length doesnt work");
    
    cout<<"5. Checking stack+char* and stack-char*&..."<<endl;
        Stack myStack(2);
        myStack + "abc";
        myStack + "123";
        myStack + "cde";
        char* str = myStack.pop();
        if ( strcmp(str,"123") )
            throw logic_error("stack+ doesnt push string correct");
        myStack.push("5");
        myStack-str;
        if ( strcmp(myStack.pop(),"abc") )
            throw logic_error("stack- doesnt pop string correct");
        if( strcmp(str,"5") )
            throw logic_error("stack- doesnt save strint correct");

    }
    catch(exception& err)
    {
        cout<<"error: "<<err.what()<<endl;
    }
    try{
        cout << "6. Checking stack1 = stack2..."<<endl;
        Stack s1(2,10), s2(3,10);
        s1.push("123");
        s2.push("abc"); s2.push("cba");
        cout<<"trying stack1 = stack2 ..."<<endl;
        s1 = s2;

        if ( strcmp(s1.pop(),s2.pop()) && strcmp(s1.pop(),s2.pop()) ) 
            throw logic_error("stack1 != stack2");
        cout << "stack1 == stack2 " << endl;
    }
    catch (exception& err)
    {
        cout << "error: "<< err.what() << endl;
    }   
    cout << "Testing completed!" << endl;
    return 0;
}   
