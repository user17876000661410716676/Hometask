#include "long_numbers.hpp"

using biv::LongNumber;

LongNumber::LongNumber() : numbers(nullptr), length(1), sign(1) {
	numbers = new int[length];
	numbers[0] = 0;
}

LongNumber::LongNumber(const char* const str) {
	int first_digit = 0;
	int str_length = get_length(str);
	sign = 1;

	if (str[0] == '-') {
		sign = -1;
		first_digit++;
	} else {
		sign = 1;
	}

	while (str[first_digit] == 0 && (first_digit < str_length - 1)) {
		first_digit++;
	}

	length = str_length - first_digit;
	numbers = new int[length];

	for (int i = 0; i < length; i++) {
		numbers[i] = str[str_length - 1 - i] - '0';
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {
	length = x.length;
	sign = x.sign;
	numbers = x.numbers;

	x.numbers = nullptr;
	x.length = 0;
}

LongNumber::~LongNumber() {
	length = 0;
	delete[] numbers;
	numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) {
	int str_length = get_length(str);
	if (str[0] == '-') {
		sign = -1;
		length = str_length - 1;
	} else {
		sign = 1;
		length = str_length;
	}

	delete[] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[length - i - 1] - '0';
	}

	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x)return *this;
	delete[] numbers;
	length = x.length;
	sign = x.sign;

	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}

	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	if (this == &x) return *this;

	length = x.length;
	sign = x.sign;

	delete[] numbers;
	numbers = x.numbers;
	x.numbers = nullptr;

	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (sign != x.sign || length != x.length) {
		return false;
	}

	for (int i = 0; i < length; i++) {
		if (numbers[i] != x.numbers[i]) {
			return false;
		}
	}

	return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	if (sign != x.sign || length != x.length) {
		return true;
	}
	for (int i = 0; i < length; i++) {
		if (numbers[i] != x.numbers[i]) {
			return true;
		}
	}
	return false;
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign != x.sign) {
		return sign > x.sign;
	}
	if (length != x.length) {
		return (sign > 0) ? (length > x.length) : (length < x.length);
	}
	for (int i = length - 1; i >= 0; i--) {
		if (numbers[i] != x.numbers[i]) {
			return numbers[i] > x.numbers[i];
		}
	}
	return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
	if (sign != x.sign) {
		return sign < x.sign;
	}
	if (length != x.length) {
		return (sign < 0) ? (length > x.length) : (length < x.length);
	}
	for (int i = length - 1; i >= 0; i--) {
		if (numbers[i] != x.numbers[i]) {
			return numbers[i] < x.numbers[i];
		}
	}
	return false;
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	bool abs_greater = 1;
	int max_length = ((length > x.length) ? length : x.length);
	int main_sign = sign;
	int borrowed = 0;
	int* result = new int[max_length + 1];

	if (sign == x.sign) {
		for (int i = 0; i < max_length; i++) {
			int a = (i < length) ? numbers[i] : 0;
			int b = (i < x.length) ? x.numbers[i] : 0;
			int sum = a + b + borrowed;

			result[i] = sum % 10;
			borrowed = sum / 10;
		}

		if (borrowed != 0) {

			result[max_length] = borrowed;
			max_length++;
		}
	}
	else {
		LongNumber y = x;
		y.sign = x.sign * -1;
		return *this - y;
	}

	while (result[max_length - 1] == 0 && max_length > 1) {
		max_length--;
	}

	LongNumber res;
	res.numbers = new int[max_length];
	res.length = max_length;
	res.sign = main_sign;

	for (int i = 0; i < max_length; i++) {
		res.numbers[i] = result[i];
	}
	if (res.length == 1 && res.numbers[0] == 0) res.sign = 1;

	delete[] result;
	return res;
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	bool abs_greater = 1;
	int max_length = (length > x.length) ? length : x.length;
	int borrowed = 0;
	int* result = new int[max_length];

	if (sign == x.sign) {
		if (length != x.length) {
			abs_greater = length > x.length;
		}
		else {
			for (int i = length - 1; i >= 0; i--) {
				if (numbers[i] != x.numbers[i]) {
					abs_greater = numbers[i] > x.numbers[i];
					break;
				}
			}
		}

		const LongNumber* larger = abs_greater ? this : &x;
		const LongNumber* lower = abs_greater ? &x : this;

		for (int i = 0; i < max_length; i++) {
			int a = ((i < larger->length) ? larger->numbers[i] : 0) - borrowed;
			int b = (i < lower->length) ? lower->numbers[i] : 0;

			if (a < b) {
				a = a + 10;
				borrowed = 1;
			}
			else {
				borrowed = 0;
			}

			result[i] = a - b;
		}
	}
	else if (sign != x.sign) {
		LongNumber y = x;
		y.sign = x.sign * -1;
		return *this + y;
	}

	while (result[max_length - 1] == 0 && max_length > 1) {
		max_length--;
	}

	LongNumber res;
	res.numbers = new int[max_length];
	res.length = max_length;
	res.sign = (abs_greater) ? sign : -x.sign;

	for (int i = 0; i < max_length; i++) {
		res.numbers[i] = result[i];
	}
	if (res.length == 1 && res.numbers[0] == 0) res.sign = 1;

	delete[] result;
	return res;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	int max_length = length + x.length;
	int* result = new int[max_length]();

	for (int i = 0; i < length; i++) {
		int carried = 0;
		for (int j = 0; j < x.length; j++) {
			int mul = numbers[i] * x.numbers[j] + result[i + j] + carried;
			result[i + j] = mul % 10;
			carried = mul / 10;
		}

		if (carried > 0) {
			result[i + x.length] = carried;
		}
	}

	while (result[max_length - 1] == 0 && max_length > 1) {
		max_length--;
	}

	LongNumber res;
	res.sign = sign * x.sign;
	res.length = max_length;
	res.numbers = new int[res.length];
	for (int i = 0; i < max_length; i++) {
		res.numbers[i] = result[i];
	}

	if (res.length == 1 && res.numbers[0] == 0) res.sign = 1;

	delete[] result;
	return res;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	if (x.length == 0 || (x.length == 1 && x.numbers[0] == 0) || length < x.length) {
		return LongNumber("0");
	}

	LongNumber result("0");
	LongNumber one("1");

	LongNumber dividend(*this);
	LongNumber divisor(x);

	dividend.sign = divisor.sign = 1;

	while (dividend > divisor || dividend == divisor) {
		dividend = dividend - divisor;
		result = result + one;
	}

	result.sign = sign * x.sign;

	if (result.length == 1 && result.numbers[0] == 0) result.sign = 1;

	return result;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	if (x.length == 0 || (x.length == 1 && x.numbers[0] == 0) || length < x.length) {
		return *this;
	}

	LongNumber result("0");
	LongNumber one("1");

	LongNumber dividend(*this);
	LongNumber divisor(x);

	dividend.sign = divisor.sign = 1;

	while (dividend > divisor || dividend == divisor) {
		dividend = dividend - divisor;
	}

	result = dividend;
	result.sign = sign * x.sign;

	if (result.length == 1 && result.numbers[0] == 0) result.sign = 1;

	return result;
}

int LongNumber::get_digits_number() const noexcept {
	return length;
}

int LongNumber::get_rank_number(int rank) const {
	if (rank < 0 || rank >= length) return 0;
	return numbers[rank];
}

bool LongNumber::is_negative() const noexcept {
	return sign == -1;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------

int LongNumber::get_length(const char* const str) const noexcept {
	int ln = 0;
	while (str[ln] != 0) {
		++ln;
	}
	return ln;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------

namespace biv {
	std::ostream& operator << (std::ostream& os, const LongNumber& x) {
		if (x.sign == -1) {
			os << '-';
		}
		for (int i = x.length - 1; i >= 0; i--) {
			os << x.numbers[i];
		}
		return os;
	}
}