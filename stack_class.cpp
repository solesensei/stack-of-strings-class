#include "string_stack.h"

using namespace std;

Stack::Stack (int x, int y) 
{
    if(x <= 0 || y <= 0)
        throw invalid_argument("constructor args < 0");

    size = x;
    str_size = y; 
    top = -1; //originally empty
    sp = new char* [size];
    for (int i=0;i<size;++i) sp[i] = NULL; //calloc sp
}

Stack::~Stack ()
{
    for (int i = size-1; i>=0; --i)
    {
        if (sp[i] == NULL) continue;
        delete [] sp[i];
    }
    delete [] sp;
}

void Stack::print_stack() const
{
    cout << "Stack: -----" << endl;
    for(int i = top; i>=0; --i)
        cout << sp[i] << endl;
    cout << "------------" << endl;

}

bool Stack::push (const char* str)
{
    if (top >= size-1) //full stack
        return true; 
    int length = strlen(str);
    if ( length >  str_size )
        throw overflow_error("stack string < pushed string");
    sp[ ++top ] = new char [str_size];
    strcpy( sp[top] , str ); 

    return false;
}

bool Stack::operator+ (const char* str)
{
   return push(str);
}

bool Stack::operator- (char* & str)
{
    str = pop();

    return str == NULL ? true : false;
}

char* Stack::pop()
{

    if ( top < 0 ) //empty stack
        return NULL; 
    
    int length = strlen( sp[top] );
    char* pop_str =  new char [ length ]; 
    strcpy( pop_str , sp[top] );
    delete [] sp[top];
    sp[top] = NULL;
    top--;

    return pop_str; 
    
}

char* Stack::peek() const
{
    if (top < 0) //empty stack
        return NULL;
             
    return sp[top];
}

int Stack::length() const
{
    return top+1;
}

int Stack::maxsize() const
{
    return size;
}
