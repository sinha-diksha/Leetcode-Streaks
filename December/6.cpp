/*Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.
Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.



Example 1:

Input: n = 4
Output: 10
Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
Example 2:

Input: n = 10
Output: 37
Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.
Example 3:

Input: n = 20
Output: 96
Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.


Constraints:

1 <= n <= 1000*/

#include <bits/stdc++.h>
using namespace std;

/*Approach 1*/
int totalMoney(int n)
{
  int prev = 1;
  int ans = 1;
  int monPrev = 1;
  for (int i = 1; i < n; i++)
  {
    if ((i % 7) == 0)
    {
      monPrev = (1 + monPrev);
      ans += monPrev;
      prev = monPrev;
    }
    else
    {
      prev = 1 + prev;
      ans += prev;
    }
  }
  return ans;
} // Time complexity: O(n), Space Complexity: O(n)

// Approach 2
int totalMoney2(int n)
{
  int ans = 1;
  int monPrev = 1;
  int prev = 1;
  for (int i = 1; i < n; i++)
  {
    if ((i % 7) == 0)
    {
      monPrev += 1;
      ans += monPrev;
      prev = monPrev;
    }
    else
    {
      prev += 1;
      ans += prev;
    }
  }
  return ans;
} // time Compleity:O(n) Space Complexity:O(1)

// Approach 3
int totalMoney3(int n)
{
  int monday = 1;
  int ans = 0;
  while (n > 0)
  {
    for (int i = 0; i < min(7, n); i++)
    {
      ans += (monday + i);
    }
    monday++;
    n -= 7;
  }
  return ans;
} // time Complexity:O(n) Space Complexity:O(1)

int totalMoney4(int n)
{
  int sum = 0;
  int k = n / 7;
  sum = (k * (2 * 28 + (k - 1) * 7)) / 2;
  int monday = 1 + k;
  for (int i = 0; i < n % 7; i++)
  {
    sum += (monday + i);
  }

  return sum;
} // T.C: O(1), S.C: O(1)

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    cout << totalMoney(n) << endl;
    cout << totalMoney2(n) << endl;
    cout << totalMoney3(n) << endl;
    cout << totalMoney4(n) << endl;
  }
}