A positive integer may be expressed as a sum of different prime numbers (primes), in one way or
another. Given two positive integers n and k, you should count the number of ways to express n as a
sum of k different primes. Here, two ways are considered to be the same if they sum up the same set
of the primes. For example, 8 can be expressed as 3 + 5 and 5 + 3 but they are not distinguished.
When n and k are 24 and 3 respectively, the answer is two because there are two sets {2, 3, 19} and
{2, 5, 17} whose sums are equal to 24. There are no other sets of three primes that sum up to 24. For
n = 24 and k = 2, the answer is three, because there are three sets {5, 19}, {7, 17} and {11, 13}. For
n = 2 and k = 1, the answer is one, because there is only one set {2} whose sum is 2. For n = 1 and
k = 1, the answer is zero. As 1 is not a prime, you shouldn’t count {1}. For n = 4 and k = 2, the
answer is zero, because there are no sets of two different primes whose sums are 4.
Your job is to write a program that reports the number of such ways for the given n and k.
Input
The input is a sequence of datasets followed by a line containing two zeros separated by a space. A
dataset is a line containing two positive integers n and k separated by a space. You may assume that
n ≤ 1120 and k ≤ 14.
Output
The output should be composed of lines, each corresponding to an input dataset. An output line
should contain one non-negative integer indicating the number of ways for n and k specified in the
corresponding dataset. You may assume that it is less than 231
.
Sample Input
24 3
24 2
2 1
1 1
4 2
18 3
17 1
17 3
17 4
100 5
1000 10
1120 14
0 0
Sample Output
2
3
1
0
0
2
1
0
1
55
200102899
2079324314