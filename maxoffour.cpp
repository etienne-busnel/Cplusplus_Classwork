#include <iostream>

int main()
{
	int a, b, c, d, max;

	std::cout << "Enter four integers\n";
	std::cin >> a >> b >> c >> d;
	max = max_of_four(a,b,c,d);
	std::cout << "The maximum number is " << max;
		
}

int max_of_four(int a, int b, int c, int d)
//Will return the highest of the four integers
{
	int max = a;
	
	if (max < b) {
		max = b;
	}

	if (max < c) {
		max = c;
	}

	if (max < d) {
		max = d;
	}

	return max;
}
