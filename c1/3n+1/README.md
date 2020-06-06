# 1.6.1 The 3n + 1 Problem

PC/UVa IDs: 110101/100, Popularity: A, Success rate: low Level: 1

## Description

Consider the following algorithm to generate a sequence of numbers.
Start with an integer n. If n is even, divide by 2. If n is odd, multiply
by 3 and add 1. Repeat this process with the new value of n, terminating when n = 1.

For example, the following sequence of numbers will be generated for n = 22:
22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

It is conjectured (but not yet proven) that this algorithm will terminate at n =
1 for every integer n. Still, the conjecture holds for all integers up to at
least 1,000,000. For an input n, the cycle-length of n is the number of
numbers generated up to and including the 1. In the example above, the cycle
length of 22 is 16.

Given any two numbers i and j, you are to determine the
maximum cycle length over all numbers between i and j, including both endpoints.

## Input

The input will consist of a series of pairs of integers i and j, one pair of integers per line. All integers will be less than 1,000,000 and greater than 0.

## Output

For each pair of input integers i and j, output i, j in the same order in which they
appeared in the input and then the maximum cycle length for integers between and
including i and j. These three numbers should be separated by one space, with all three
numbers on one line and with one line of output for each line of input.

### Sample Input

``` text
1 10
100 200
201 210
900 1000
```

### Sample Output

``` text
1 10 20
100 200 125
201 210 89
900 1000 174
```

### Running

1. Generate random input:

    ```python
    # generate a list of 1000 pairs with min val 1 and max val 99999
    python randomPairGenerator.py -h
    python randomPairGenerator.py -m 1 -x 99999 -n 1000
    python randomPairGenerator.py -min 1 -max 99999 -num 1000
    ```

2. Run:

    `make` or `make release`
    `./a.out`
    `./a.out < [input]`

### Notes

Brute force is easy:

- iterate thru i...j and find max cycle length
- as expected runs slow on large i, j ranges and large input

Faster:

- since we're basically finding the max a bunch of times over potentially repeated ranges,
    memoization seems like a good way to optimize and save repeated computation
- ideas:
  - do straight up DP, memoize as we go
  - could also precompute max over intervals based on input

### Runtime

<table>
<tr>
<th>
    Input
</th>
<th>
    Brute Force
</th>
<th>
    DP
</th>
</tr>
<tr>
<td>

    sample.txt

</td>
<td>

```text
real    0m0.037s
user    0m0.001s
sys     0m0.001s
```

</td>
<td>

```text
real    0m0.070s
user    0m0.001s
sys     0m0.002s
```

</td>
</tr>
<tr>
<td>

    small_n100_min1_max99999.txt

</td>
<td>

```text
real    0m0.951s
user    0m0.943s
sys     0m0.005s
```

</td>
<td>

```text
real    0m0.071s
user    0m0.065s
sys     0m0.004s
```

</td>
</tr>
<tr>
<td>

    small_n200_min1_max100000.txt

</td>
<td>

```text
real    0m1.667s
user    0m1.613s
sys     0m0.009s
```

</td>
<td>

```text
real    0m0.111s
user    0m0.069s
sys     0m0.004s
```

</td>
</tr>
<tr>
<td>

    big_n1000_min1_max99999.txt

</td>
<td>

```text
real    0m8.411s
user    0m8.196s
sys     0m0.040s
```

</td>
<td>

```text
real    0m0.423s
user    0m0.279s
sys     0m0.008s
```

</td>
</tr>

</table>
