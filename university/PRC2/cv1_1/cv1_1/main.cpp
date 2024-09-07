#include <iostream>
#include <cmath>

double odmocnina(double x, double epsilon = 1e-6) {
	double a = 0;
	double b = x;
	double c;
	if (x < 0) {
		std::cout << "Inapropriate value" << std::endl;
		return NAN;
	}
	else if (x < 1) {
		a = x;
		b = 1;
	}
		while (true) {
			c = (a + b) / 2;
			double c_square = c * c;
			if (c_square < x - epsilon) {
				a = c;
			}
			else if(c_square > x + epsilon) {
				b = c;
			}
			else {
				break;
			}
		}
		return c;
	}

int main() {
	double x = 0.5;
	double y = odmocnina(x);
	std::cout << "odmocnina (" << x << " = " << y << ")" << std::endl;
}