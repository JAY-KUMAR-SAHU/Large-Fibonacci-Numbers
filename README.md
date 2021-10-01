# Large-Fibonacci-Numbers
To find very large Fibonacci numbers.

Generally in C/C++, the largest number data types can hold upto 18 digits 
but Fibonacci numbers can become much larger than 18 digits like 20000th 
Fibonacci number has 4180 digits(approximately) 
which cannot be stored in long int, long long int.

So, we need to store individual characters of the number in a string or  an array.

The given code can find upto 50000 Fibonacci numbers very fast.
After 50000, system specifications decide whether the output will be slow or fast.

The program is limited by the MAX_SIZE  of integer array possible i.e.,MEMORY
and TIME required for execution only. 
