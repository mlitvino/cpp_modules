#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Fixed t1(3.12f);
	Fixed t2(-3.31f);
	Fixed t3(4.4444f);
	Fixed t4(3);
	Fixed t5(-300);
	Fixed t6(6.666666666f);
	Fixed t7(6.666666666f);

	std::cout << "\nStored numbers\n\n";

	std::cout << "t1 - " << t1 << std::endl;
	std::cout << "t2 - " << t2 << std::endl;
	std::cout << "t3 - " << t3 << std::endl;
	std::cout << "t4 - " << t4 << std::endl;
	std::cout << "t5 - " << t5 << std::endl;
	std::cout << "t6 - " << t6 << std::endl;
	std::cout << "t7 - " << t7 << std::endl;

	std::cout << "\nArithmetic operations\n\n";

	std::cout << "3.12 + 3.12 = " << t1 + t1 << std::endl;
	std::cout << "3.12 - 3.12 = " << t1 - t1 << std::endl;
	std::cout << "-300 / 4.4444 = " << t5 / t3 << std::endl;
	std::cout << "4.4444 * -3.31 = " << t3 * t2 << std::endl;
	std::cout << "6.66... / 6.66.. = " << t6 / t7 << std::endl;

	std::cout << "\nComparsion operations\n\n";

	std::cout << "3.12 > 3.12 - " << (t1 > t1 ? "YES" : "NO") << std::endl;
	std::cout << "3.12 == 3.12 - " << (t1 == t1 ? "YES" : "NO") << std::endl;
	std::cout << "-300 != 4.4444 - " << (t5 != t3 ? "YES" : "NO") << std::endl;
	std::cout << "4.4444 < -3.31 - " << (t3 < t2 ? "YES" : "NO") << std::endl;
	std::cout << "6.66... == 6.66.. - " << (t6 == t7 ? "YES" : "NO") << std::endl;

	std::cout << "\nIncrement/Decrement\n\n";

	std::cout << "t1++ - " << t1++ << std::endl;
	t1--;
	std::cout << "++t1 - " << ++t1 << std::endl;

	std::cout << "t2-- - " << t2-- << std::endl;
	t2++;
	std::cout << "--t2 - " << --t2 << std::endl;

	return 0;
}

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }
