# 7snake Problem

This project resolves the 7Snakes problem, which is described as follows:

Given a grid of integers, find one pair (two) of 7-Snakes A and B that has the property that the sum of the integers in 7-Snake A is exactly the same as the sum of integers in 7-Snake B.

# Proposed Solution

The strategy used to solve the 7Snake problem was looking recursively for 7Snakes in a given grid until two distinct snakes with the same sum of integers be found. A hashtable is kept to group 7-snakes with the same sum of integers (sum of integers is key), so whenever a 7-sneak is added to the hash, it is checked whether it is distinct of the others with the same key. If so, the programs ends, otherwise it keeps searching.

# Technology

```
C++, Windows MingGW G++ compiler version 6.3.0
```

# How to compile

```
g++ 7snakes.cpp -o exec
```

# How to execute

Given an input file, according to the specified sample, in.txt:

```
exec.exe < in.txt
```

The user can enter as many test cases as he wants in the same file. If he wants to redirect the output to a file:

```
exec.exe < in.txt > out.txt
```

# Sample input

```
10
227,191,234,67,43,13,48,211,253,243
36,95,229,209,49,230,46,16,190,49
206,130,85,67,104,93,128,243,38,173
234,82,191,153,170,99,124,60,12,31
192,9,24,127,183,241,139,21,244,66
93,200,66,16,189,42,209,113,215,4
182,141,153,64,229,55,115,139,12,187
133,241,35,255,126,39,110,147,24,241
2,202,191,159,223,128,154,109,6,200
173,44,163,196,159,232,135,159,117,175
4
1,1,0,7
1,5,0,6
3,3,4,5
4,77,6,7
4
1,1,0,7
2,2,0,6
3,3,4,5
4,5,6,7
```

# Sample output

```
# TestCase 1
# Sum of integers: 986
191 (0,1) 234 (0,2) 229 (1,2) 209 (1,3) 67 (0,3) 43 (0,4) 13 (0,5) 
227 (0,0) 36 (1,0) 206 (2,0) 234 (3,0) 82 (3,1) 9 (4,1) 192 (4,0) 

#TestCase 2
FAIL

# TestCase 3
# Sum of integers: 24
1 (0,0) 2 (1,0) 3 (2,0) 3 (2,1) 4 (2,2) 6 (3,2) 5 (3,1) 
1 (0,1) 5 (1,1) 0 (1,2) 0 (0,2) 7 (0,3) 6 (1,3) 5 (2,3) 
```