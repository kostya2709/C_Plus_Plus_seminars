#include <iostream>
 
bool fermat()
{
    const int max_value = 1000;
 
    // Non-trivial infinite loop with no side effects is UB
    for (int a = 1, b = 1, c = 1; true; )
    {
        if (((a * a * a) == ((b * b * b) + (c * c * c)))) {
			std::cout << a << ' ' << b << ' ' << c << '\n';
		 	return true; // disproved :()
		}
        a++;
        if (a > max_value)
        {
            a = 1;
            b++;
        }
        if (b > max_value)
        {
            b = 1;
            c++;
        }
        if (c > max_value)
            c = 1;
    }
 
    return false; // not disproved
}
 
int main()
{
    std::cout << "Fermat's Last Theorem ";
    fermat()
        ? std::cout << "has been disproved!\n"
        : std::cout << "has not been disproved.\n";
}
