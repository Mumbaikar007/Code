#include <iostream>
#include <string>

int main ()
{
  std::string str="We think in generalities, but we live in detailsb";
                                           // (quoting Alfred N. Whitehead)

  std::string str2 = str.substr (0,str.size()-1) ;     // "think"

  str2 += toupper(str[str.size()-1]);

  std::cout << str2 << "\n";

  return 0;
}