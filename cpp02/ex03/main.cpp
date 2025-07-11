#include "Fixed.hpp"
#include "Point.hpp"

int main() {
	// Define triangle vertices A, B, C
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(5), Fixed(0));
	Point c(Fixed(0), Fixed(5));

	std::cout << "Triangle vertices:\n";
	std::cout << "A: (" << a.getX() << ", " << a.getY() << ")\n";
	std::cout << "B: (" << b.getX() << ", " << b.getY() << ")\n";
	std::cout << "C: (" << c.getX() << ", " << c.getY() << ")\n";

	// Prepare test points (static array)
	Point tests[] = {
		Point(Fixed(1.0f),   Fixed(1.0f)),    // 1 inside
		Point(Fixed(2.5f),   Fixed(2.0f)),    // 2 inside
		Point(Fixed(0.0f),   Fixed(0.0f)),    // 3 vertex A
		Point(Fixed(5.0f),   Fixed(0.0f)),    // 4 vertex B
		Point(Fixed(0.0f),   Fixed(5.0f)),    // 5 vertex C
		Point(Fixed(2.3f),   Fixed(0.0f)),    // 6 edge AB
		Point(Fixed(0.0f),   Fixed(2.5f)),    // 7 edge AC
		Point(Fixed(2.0f),   Fixed(2.5f)),    // 8 inside
		Point(Fixed(3.0f),   Fixed(1.5f)),    // 9 inside
		Point(Fixed(-1.0f),  Fixed(0.0f)),    // 10 outside
		Point(Fixed(6.0f),   Fixed(6.0f)),    // 11 outside
		Point(Fixed(2.5f),   Fixed(2.5f)),    // 12 outside
		Point(Fixed(4.9f),   Fixed(0.1f)),    // 13 outside
		Point(Fixed(0.1f),   Fixed(4.9f)),    // 14 outside
		Point(Fixed(1.25f),  Fixed(1.25f)),   // 15 inside
		Point(Fixed(2.6f),   Fixed(2.6f)),    // 16 outside
		Point(Fixed(1.87f), Fixed(0.62f)),  // 17 inside
		Point(Fixed(3.12f), Fixed(1.88f)),  // 18 on edge
		Point(Fixed(2.5f),   Fixed(2.6f)),    // 19 outside
		Point(Fixed(2.5f),   Fixed(2.48f))   // 20 inside
	};
	std::size_t nTests = sizeof(tests) / sizeof(tests[0]);

	// Test each point
	for (std::size_t i = 0; i < nTests; ++i) {
		const Point& p = tests[i];
		bool inside = bsp(a, b, c, p);
		std::cout << "Test Point " << (i + 1) << ": (" << p.getX() << ", " << p.getY() << ") is "
				<< (inside ? "inside" : "outside") << " the triangle.\n";
	}

	return 0;
}
