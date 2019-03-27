# stack-of-strings-class
class stack of strings

#### how it works: 
```bash
$ make pr
$ input | ./pr 
```
or
```bash
$ ./pr
```
to test
```bash
$ make test
$ ./test
```
#### commands: (/help) 
```c
push   - string to stack
pop    - string from stack
peek   - string from stack (no del)
print  - print stack
length - number of strings in stack
size   - maxsize of stack
stack+ - push str to stack
stack- - pop to str, maxsize = 10
```        
#### examples:
```c
push 1 2 3 4 5 push // now 1-5 in stack
pop // 1-4 in stack
peek // 1-4 in stack
stack- str //now str = 4, 1-3 in stack
stack+ s //stack: 1 2 3 s
stack+ str //stack: 1 2 3 s 4
pop pop pop pop pop 
stack empty!
```
