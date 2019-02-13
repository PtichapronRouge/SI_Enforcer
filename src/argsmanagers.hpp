#ifndef UTILITY_HPP
#define UTILITY_HPP

template <typename ...Args>
struct ArgCounter;

template <>
struct ArgCounter<>
{
    static unsigned int count(unsigned int accu) {return accu;}
};

template <typename Head, typename ...Tail>
struct ArgCounter<Head, Tail...>
{
    static unsigned int count(unsigned int accu) {return ArgCounter<Tail...>::count(1+accu);}
};

template <typename ...Args>
unsigned int argCount() {return ArgCounter<Args...>::count(0);}

template <typename ...Args>
unsigned int argCount(Args...) {return ArgCounter<Args...>::count(0);}

template <unsigned int index, typename ...Args>
struct ArgIndex;

template<typename Head, typename ...Tail>
struct ArgIndex<0, Head, Tail...>
{
    using Type = Head;
};

template <unsigned int index, typename Head, typename ...Tail>
struct ArgIndex<index, Head, Tail...>
{
    using Type = typename ArgIndex<index-1, Tail...>::Type;
};

struct InvalidIndexType{};
template <unsigned int index>
struct ArgIndex<index>
{};


#endif
