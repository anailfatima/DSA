#include <iostream>
#include <string>

std::string reverseString(std::string n, int s, std::string newString)
{
    if (s == 0)
    {
        //return std::strimg(1,n[0]) ---returns only last character
        return newString+n[0];
    }

    else
    {
        newString += n[s];
        return reverseString(n, s - 1, newString);
        // reverseString(n, s - 1, newString);
        // return newString;
    }
}
    using namespace std;
    int main()
    {

        string n = "hello";
        int s = n.size();

       // cout << n[0] << endl;
        cout << reverseString(n, s - 1,"");
        return 0;
    }