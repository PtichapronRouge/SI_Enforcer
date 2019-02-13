#ifndef DIMENSION_HPP
#define DIMENSION_HPP

#include "argsmanagers.hpp"
#include "ratiohelper.hpp"

#include <ratio>

enum Name : unsigned int
{
    Mass = 0,
    Distance = 1,
    Time = 2,
    Temperature = 3,
    Matter = 4,
    Current = 5,
    Intensity = 6
};

template <typename ...Ratios>
struct Dimension
{
    template<unsigned int index>
    typename ArgIndex<index, Ratios...>::Type fundDim() const
    {
        return typename ArgIndex<index, Ratios...>::Type();
    }

    typename ArgIndex<0, Ratios...>::Type _rmass;
    typename ArgIndex<1, Ratios...>::Type _rdistance;
    typename ArgIndex<2, Ratios...>::Type _rtime;
    typename ArgIndex<3, Ratios...>::Type _rtemperature;
    typename ArgIndex<4, Ratios...>::Type _rmatter;
    typename ArgIndex<5, Ratios...>::Type _rcurrent;
    typename ArgIndex<6, Ratios...>::Type _rintensity;
};

using MassFund          = Dimension<Unit, Zero, Zero, Zero, Zero, Zero, Zero>;
using DistanceFund      = Dimension<Zero, Unit, Zero, Zero, Zero, Zero, Zero>;
using TimeFund          = Dimension<Zero, Zero, Unit, Zero, Zero, Zero, Zero>;
using TemperatureFund   = Dimension<Zero, Zero, Zero, Unit, Zero, Zero, Zero>;
using MatterFund        = Dimension<Zero, Zero, Zero, Zero, Unit, Zero, Zero>;
using CurrentFund       = Dimension<Zero, Zero, Zero, Zero, Zero, Unit, Zero>;
using IntensityFund     = Dimension<Zero, Zero, Zero, Zero, Zero, Zero, Unit>;


#endif
