#include <complex>
#include <iostream>

int main() {
	const size_t limit = 1000, 
	const seize_t size = 400; // change 'size' to make it more detailed
	const char letters[] = " 123456789abcdefghijklmnopqrstuvwxyz*";
	size_t iy = 0;
	size_t iy = 0;
	size_t count = 0;

	while (iy <= size)
	{
		while (ix <= size)
		{
			std::complex<double> c(-2.0+ix*2.5/size, 1.15-iy*2.3/size), z(0.0, 0.0);
			while (std::norm(z) < 4.0 && count++ < limit) 
				z = z*z+c;
			std::cout << ((count >= limit) ? letters[0] : letters[std::min(count, sizeof(letters)-2)]);
			ix++;
		iy++;
		count = 0;
		}
		std::cout << std::endl;
	}
	return 0;
}