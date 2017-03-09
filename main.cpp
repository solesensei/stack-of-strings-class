#include <iostream>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>

using namespace std;


//module: stack_class.cpp
class Stack
{
public:
    Stack (int x = 10, int y = 255); 
    ~Stack ();
    void print_stack() const;
    bool push (const char*);
    char* pop();
    char* peek() const;
    int length() const;
    int maxsize() const;
    bool operator+ (const char*);
    bool operator- (char* &);

private:
    char**  sp; //stack pointer
    int     top; 
    int     size; //stack size
    int     str_size;
    int     unlim_flg; //if size or str_size unlimited 

};

Stack::Stack (int x, int y) 
{
    unlim_flg = 0;
    if(x <= 0) //unlimited size 
        size = unlim_flg = 1;
    else 
        size = x;

    str_size = y; //make str size unlim
    top = -1; //originally empty
    sp = new char* [size];
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
    if ( unlim_flg )
        return -1;
    return size;
}

enum stack_cmd { push, pop, peek, print, length, size, undef, spush, spop, help };
stack_cmd _selector (const char* str)
{
    if ( !strcmp(str,"push") ) return push;
    
    if ( !strcmp(str,"pop") ) return pop;
 
    if ( !strcmp(str,"peek") ) return peek;
    
    if ( !strcmp(str,"print") ) return print;
    
    if ( !strcmp(str,"length") ) return length;
    
    if ( !strcmp(str,"maxsize") ) return size;
   
    if ( !strcmp(str,"stack+") ) return spush;
    
    if ( !strcmp(str,"stack-") ) return spop;
    

    if( !strcmp(str,"/help") ){
        cout << "Stack commands man:----------------" << endl;
        cout << "push   - string to stack"            << endl;
        cout << "pop    - string from stack"          << endl;
        cout << "peek   - string from stack (no del)" << endl;
        cout << "print  - print stack"                << endl;
        cout << "length - number of strings in stack" << endl;
        cout << "size   - maxsize of stack"           << endl;
        cout << "stack+ - push str to stack"          << endl;
        cout << "stack- - pop to str, maxsize = 10 "  << endl;
        cout << "-----------------------------------" << endl;
        return help;
    }

    return undef;
}

char* pop_name[10]; //stack- | store names of cache strings
char* pop_str[10]; //cache strings 
const char* str_find (const char* str) 
{
    for(int i = 9; i>=0; --i)
        if ( pop_name[i] != NULL && !strcmp(pop_name[i],str) ) return pop_str[i];
    return str;
}

//module: main.cpp
int main(int argc, char** argv)
{

    //if (argc == 3)
    int stack_size;
    cout << "Stack size:";
    cin >> stack_size;
    Stack myStack( stack_size ); //init stack
    cout << "print '/help' to man commands" << endl;

    for(int i = 0; i < 10; ++i)
        pop_name[i] = new char [10];

    char cmd[1024]; //command buffer
    bool check = false;
    char* str;
    int cur = 0;

    while (cin >> cmd)
    {
        stack_cmd _sel = _selector(cmd);
        switch(_sel){
            case push:
                
                cin >> cmd;
                while (_selector(cmd) != push){
                    check = myStack.push(cmd); 
                    cin >> cmd;
                } 
                if (check) cout << "Stack fulled!" << endl;

            break;
            case spush:
                
                cin >> cmd;
                if ( myStack + str_find(cmd) ) cout << "Stack fulled!" << endl;
                
            break;
            case spop:

                cin >> pop_name[ cur ]; 
                
                if (  myStack - pop_str[ cur ] ) str = pop_name [ cur ] = NULL;
                else str = pop_str[ cur++ ];
                if ( cur == 10 && (cur = 0) )
                    cout << "end of str buf,\nnext str will overwrite previous" << endl;
            
            case pop: 

                if (_sel != spop) str = myStack.pop();
                if (str)
                    cout << "Poped! : " << str << endl;
                else
                    cout << "Stack empty!" << endl;

            break;
            case peek:
                
                str = myStack.peek();
                if (str)
                    cout << "Peeked! : " << str << endl;
                else
                    cout << "Stack empty!" << endl;
            
            break;
            case print:
                
                myStack.print_stack();   
            
            break;
            case length:
                
                cout << "Stack length: ";
                cout << myStack.length() << endl; 
                
            break;
            case size:
                
                cout << "Stack size: ";
                cout << myStack.maxsize() << endl; 
                
            break;
            case undef: 
               
                _sel = _selector(cmd); 
            
            break;
            case help: cout << "end of man" << endl;
        }

    }
    
    return 0;
} 
