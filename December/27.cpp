/*
1578. Minimum Time to make rope colourful

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.



Example 1:


Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
Example 2:


Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
Example 3:


Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.


Constraints:

n == colors.length == neededTime.length
1 <= n <= 105
1 <= neededTime[i] <= 104
colors contains only lowercase English letters.*/

#include <bits/stdc++.h>
using namespace std;

int minCostTwo(string colors, vector<int> &neededTime)
{
  int ans = 0;
  int n = colors.size();
  if (n == 1)
  {
    return 0;
  }
  int s = 0;
  int e = 1;
  while (e < n)
  {
    if (colors[s] == colors[e])
    {
      if (neededTime[s] < neededTime[e])
      {
        ans += neededTime[s];
        s = e;
        e++;
      }
      else
      {
        ans += neededTime[e];
        e++;
      }
    }
    else
    {
      s = e;
      e++;
    }
  }
  return ans;
}

int minCostOne(string colors, vector<int> &neededTime)
{
  int ans = 0;
  int n = colors.size();
  for (int i = 0; i < n - 1; i++)
  {
    if (colors[i] == colors[i + 1])
    {
      ans += min(neededTime[i], neededTime[i + 1]);
      neededTime[i + 1] = max(neededTime[i], neededTime[i + 1]);
    }
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {

    string s;
    cin >> s;
    int n = s.length();
    vector<int> neededTime(n);
    for (int i = 0; i < n; i++)
    {
      cin >> neededTime[i];
    }
    cout << minCostTwo(s, neededTime) << endl;
    cout << minCostOne(s, neededTime) << endl;
    }
}
