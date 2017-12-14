# stack-of-strings-class
class stack of strings

#### how it works: 

    :make pr
    :input | ./pr 

or

    :./pr

to test

    :make test
    :./test

#### commands: (/help) 

        push   - string to stack
        pop    - string from stack
        peek   - string from stack (no del)
        print  - print stack
        length - number of strings in stack
        size   - maxsize of stack
        stack+ - push str to stack
        stack- - pop to str, maxsize = 10
        
#### examples:

      push 1 2 3 4 5 push // now 1-5 in stack
      pop // 1-4 in stack
      peek // 1-4 in stack
      stack- str //now str = 4, 1-3 in stack
      stack+ s //stack: 1 2 3 s
      stack+ str //stack: 1 2 3 s 4
      pop pop pop pop pop 
      stack empty!
      
 -----------
      
## Stack of strings class

На Си++ реализован и протестирован новый класс, представляющий
абстрактный тип данных, т.е. такой, пользователи которого могут обращаться
только к публичными операциями, предусмотренными создателем класса, и не имеют
информации о внутреннем его устройстве.

 -----------

### стек строк (string stack)

строка понимается в стиле Си: char *, на конце \0.

Стек в обычном понимании (первый вошел -- последний вышел), в котором
хранятся строки с владением, т.е. при уничтожении вся выделенная под них
память освобождается.


Реализованные операции:

    stack::push( char* ) // положить копию строки
    char* stack::pop() // вернуть верхний элемент с удалением из стека
    char* stack::peek() // вернуть копию верхнего элемента без удаления
    int stack::length() // текущий размер
    int stack::maxsize() // максимальный размер (или -1, если "неограничен")
    stack + char* // синоним push
    stack - char*& // синоним pop, записывающий результат во второй операнд
    
