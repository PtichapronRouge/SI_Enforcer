#ifndef RATIOHELPER_HPP
#define RATIOHELPER_HPP

#include <ratio>
#include <iostream>

template <intmax_t Num, intmax_t Den>
struct PlotRatio
{
    static void plot()
    {
        std::cout << Num << " / " << Den << std::endl;
    }
};

template <intmax_t Den>
struct PlotRatio<0, Den>
{
    void plot()
    {
        std::cout << 0 << std::endl;
    }
};

template <intmax_t Num, intmax_t Den>
void plotRatio(std::ratio<Num, Den>)
{
    PlotRatio<Num, Den>::plot();
}

using Unit = std::ratio<1,1>;
using Zero = std::ratio<0,1>;

#endif
