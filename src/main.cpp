#include <iostream>
#include <vector>
#include <ranges>
#include "TML/Array.hpp"

template <typename T>
constexpr auto typeName()
{
    std::string_view name, prefix, suffix;
    #ifdef __clang__
        name = __PRETTY_FUNCTION__;
        prefix = "auto typeName() [T = ";
        suffix = "]";
    #elif defined(__GNUC__)
        name = __PRETTY_FUNCTION__;
        prefix = "constexpr auto typeName() [with T = ";
        suffix = "]";
    #elif defined(_MSC_VER)
        name = __FUNCSIG__;
        prefix = "auto __cdecl typeName<";
        suffix = ">(void)";
    #endif
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
}

int main()
{
    std::vector<int> v;
    std::cout << typeName<std::ranges::range_value_t<decltype(v)>>() << std::endl;
    return 0;
}
