#include "dimension.hpp"

Dimension::Ratio::Ratio()
: Num(0)
, Den(1)
{}

Dimension::Dimension(Dimension::Fundamental f)
: Dimension()
{
    _exponents[static_cast<Dimension::utype>(f)] = 1;
}

const Dimension::Ratio Dimension::exponent(Dimension::Fundamental f) const
{
    return _exponents[static_cast<Dimension::utype>(f)];
}

