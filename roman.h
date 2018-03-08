#ifndef ROMAN_H_INC_
#define ROMAN_H_INC_

#include <locale>
#include <ios>
#include <iostream>

template <class charT, class OutputIterator = std::ostreambuf_iterator<charT> >
class roman : public std::num_put < charT, OutputIterator > {
public:
    typedef charT char_type;
    typedef OutputIterator iter_type;

protected:

    virtual iter_type do_put(iter_type out, std::ios_base &, char_type, long v) const {
        return fmt(v, out);
    }

    virtual iter_type do_put(iter_type out, std::ios_base &, char_type, long long v) const {
        return fmt(v, out);
    }

    virtual iter_type do_put(iter_type out, std::ios_base &, char_type, unsigned long v) const {
        return fmt(v, out);
    }

    virtual iter_type do_put(iter_type out, std::ios_base &, char_type, unsigned long long v) const {
        return fmt(v, out);
    }

    template <class T, class Iter>
	Iter fmt(T value, Iter dest) const {

		struct conv {
			int val;
			std::string rep;
		};

		static const conv table[] = {
			{ 1000, "M" },
		{ 900, "CM" },
		{ 500, "D" },
		{ 400, "CD" },
		{ 100, "C" },
		{ 90, "XC" },
		{ 50, "L" },
		{ 40, "XL" },
		{ 10, "X" },
		{ 9, "IX" },
		{ 5, "V" },
		{ 4, "IV" },
		{ 1, "I" }
		};

		for (auto const &c : table) {
			while (value >= c.val) {
				dest = std::copy(c.rep.begin(), c.rep.end(), dest);
				value -= c.val;
			}
		}
		return dest;
	}
};

#endif
