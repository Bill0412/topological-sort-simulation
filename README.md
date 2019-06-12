# Automated Test for topological sort in C++
This is a university course work, I was in charge of the test part and I wrote an automated test program for that.
To be more specifically, it's a randomized simulation program.


## Problem Specification
This is not the major part, but for clarity, I list the problem here.
### P3 Hashing - Hard Version (20 point(s))<br/>
Given a hash table of size N, we can define a hash function H(x)=x%N. Suppose that the linear probing is used to solve collisions, we can easily obtain the status of the hash table with a given sequence of input numbers.

However, now you are asked to solve the reversed problem: reconstruct the input sequence from the given status of the hash table. Whenever there are multiple choices, the smallest number is always taken.

Input Specification:
Each input file contains one test case. For each test case, the first line contains a positive integer N (≤1000), which is the size of the hash table. The next line contains N integers, separated by a space. A negative integer represents an empty cell in the hash table. It is guaranteed that all the non-negative integers are distinct in the table.

Output Specification:
For each test case, print a line that contains the input sequence, with the numbers separated by a space. Notice that there must be no extra space at the end of each line.

Sample Input:
```$xslt
11
33 1 13 12 34 38 27 22 32 -1 21
```

Sample Output:
```$xslt
1 13 12 21 33 34 38 27 22 32
```
