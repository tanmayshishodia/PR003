#include <bits/stdc++.h>
using namespace std;
 
int getDigit(int number)
{
  if (number < 9)
    return number;
  return number / 10 + number % 10;
}
 
int getSize(long d)
{
  string num = to_string(d);
  return num.length();
}
 
long getPrefix(long number, int k)
{
  if (getSize(number) > k)
  {
    string num = to_string(number);
    return stol(num.substr(0, k));
  }
  return number;
}
 
bool prefixMatched(long number, int d)
{
  return getPrefix(number, getSize(d)) == d;
}
 
int sumOfDoubleEvenPlace(long int number)
{
  int sum = 0;
  string num = to_string(number) ;
  for (int i = getSize(number) - 2; i >= 0; i -= 2)
    sum += getDigit(int(num[i] - '0') * 2);
 
  return sum;
}
 
int sumOfOddPlace(long number)
{
  int sum = 0;
  string num = to_string(number) ;
  for (int i = getSize(number) - 1; i >= 0; i -= 2)
    sum += num[i] - '0';
  return sum;
}
 
bool isValid(long int number)
{
  return (getSize(number) >= 13 &&
          getSize(number) <= 16) &&
            (prefixMatched(number, 4) ||
            prefixMatched(number, 5) ||
            prefixMatched(number, 37) ||
            prefixMatched(number, 6)) &&
                ((sumOfDoubleEvenPlace(number) +
                  sumOfOddPlace(number)) % 10 == 0);
}
 
int main()
{
  long int number = 5196081888500645L;
  cin>>number;
  cout << number << " is " <<  (isValid(number) ? "valid.\n" : "invalid.\n");
  return 0;
}