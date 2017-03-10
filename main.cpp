#include "string_stack.h"

using namespace std;

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

char* pop_name[p_SIZE]; //stack- | store names of cache strings
char* pop_str[p_SIZE]; //cache strings 
const char* str_find (const char* str) 
{
    for(int i = p_SIZE-1; i>=0; --i)
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

    for(int i = 0; i < p_SIZE; ++i)
        pop_name[i] = new char [p_SIZE];

    char cmd[1024]; //command buffer
    bool check = false;
    char* str = NULL;
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

                if (  myStack - pop_str[ cur ] ){ str = NULL; *pop_name[cur] = '\0'; }
                else str = pop_str[ cur++ ];
                if ( cur == p_SIZE && (cur = 0) )
                    cout << "end of str buf,\nnext str will overwrite previous" << endl;
            
            case pop: 

                if (_sel != spop) str = myStack.pop();
                if (str)
                    cout << "Poped! : " << str << endl;
                else
                    cout << "Stack empty!" << endl;

            break;
            case peek:
                
                if ( myStack.peek() )
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
        /*if (str && !strcmp( str_find(str),str ) )
        {
            delete [] str;
            str = NULL;
        }*/
    }
    for(int i = 0; i<p_SIZE; ++i)
        if (pop_name[i])
            delete [] pop_name[i];
    
    return 0;
} 
