/*
 * https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
 */

#include <iostream>
#include <string>

std::string removeTrailingZeros(const std::string& input) {
  auto posNonZero = input.find_first_not_of('0');
  return input.substr(posNonZero == std::string::npos ? input.size()-1 : posNonZero);
}

std::string multiply(std::string num1, std::string num2) {
  std::string result(num1.size()+num2.size(), '0');
  for (int indexNum1 = num1.size()-1; indexNum1 >= 0; --indexNum1) {
    int remaining = 0;
    int indexResult = 0;
    for (int indexNum2 = num2.size()-1; indexNum2 >= 0; --indexNum2) {
      indexResult = indexNum1 + indexNum2 + 1;
      int partialSum = (num1.at(indexNum1)-'0') * (num2.at(indexNum2)-'0') + (result.at(indexResult)-'0') + remaining;
      result.at(indexResult) = (partialSum % 10) + '0';
      remaining = partialSum / 10;
    }
    if (indexResult) {
      result.at(indexResult-1) = remaining + '0';
    }
  }
  return removeTrailingZeros(result);
}

using namespace std;

int main()
{
  auto& fout = std::cout;

  string num1;
  getline(cin, num1);

  string num2;
  getline(cin, num2);

  string res = multiply(num1, num2);

  fout << res << "\n";

  return 0;
}
