#include "complex_numbers.h"
#include <cmath>

namespace complex_numbers {
	Complex::Complex(double r, double i)
	{
		real_ = r;
		imag_ = i;
	}

	double Complex::real() const
	{
		return real_;
	}

	double Complex::imag() const
	{
		return imag_;
	}

	Complex Complex::operator+ (Complex const& obj) const
	{
		Complex res{ 0.0, 0.0 };
		res.real_ = real_ + obj.real_;
		res.imag_ = imag_ + obj.imag_;
		return res;
	}

	Complex Complex::operator- (Complex const& obj) const
	{
		Complex res{ 0.0, 0.0 };
		res.real_ = real_ - obj.real_;
		res.imag_ = imag_ - obj.imag_;
		return res;
	}

	Complex Complex::operator* (Complex const& obj) const
	{
		Complex res{ 0.0, 0.0 };
		res.real_ = real_ * obj.real_ - imag_ * obj.imag_;
		res.imag_ = imag_ * obj.real_ + real_ * obj.imag_;
		return res;
	}

	Complex Complex::operator/ (Complex const& obj) const
	{
		Complex res{ 0.0, 0.0 };
		double dividor = pow(obj.real_, 2) + pow(obj.imag_, 2);
		res.real_ = (real_ * obj.real_ + imag_ * obj.imag_) / dividor;
		res.imag_ = (imag_ * obj.real_ - real_ * obj.imag_) / dividor;
		return res;
	}

	double Complex::abs() const
	{
		return sqrt(pow(real_, 2) + pow(imag_, 2));
	}

	Complex Complex::conj() const
	{
		Complex res{ 0.0, 0.0 };
		res.real_ = real_;
		res.imag_ = -imag_;
		return res;
	}

	Complex Complex::exp() const
	{
		Complex res{ 0.0, 0.0 };
		//e^(a+i*b) = e^a * e^(i*b) = e^a * (cos(b) + i * sin(b)) =>
		// => e^a * cos(b) + e^a * sin(b) * i
		//so real = e^a * cos(b)
		// imag = e^a * sin(b)
		res.real_ = std::exp(real_) * cos(imag_);
		res.imag_ = std::exp(real_) * sin(imag_);
		return res;
	}
}