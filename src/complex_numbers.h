#pragma once
#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers {
	class Complex {
	public:
		//constructor
		Complex(double real, double imag);
		
		//get real and imaginary part
		double real() const;
		double imag() const;

		//opreator overloading
		Complex operator+ (Complex const& obj) const;
		Complex operator- (Complex const& obj) const;
		Complex operator* (Complex const& obj) const;
		Complex operator/ (Complex const& obj) const;

		//other imaginary numbers related features
		double abs() const;
		Complex conj() const;
		Complex exp() const;
	private:
		double real_;
		double imag_;
	};
}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
