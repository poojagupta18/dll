//  demangle.hpp  --------------------------------------------------------------//

//  Copyright 2015 Klemens Morgenstern

// This file provides a demangling for function names, i.e. entry points of a dll.

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

#include <boost/config.hpp>
#include <string>

#ifndef BOOST_DLL_DEMANGLE_SYMBOL_HPP_
#define BOOST_DLL_DEMANGLE_SYMBOL_HPP_



#if defined(BOOST_MSVC) || defined(BOOST_MSVC_FULL_VER)
#include <boost/detail/winapi/dbghelp.hpp>

namespace boost
{
namespace dll
{
namespace detail
{


inline std::string demangle_symbol(const char *mangled_name)
{
	char unmangled_name[512];

	UnDecorateSymbolName(mangled_name, unmangled_name, 512, UNDNAME_COMPLETE);

	return std::string(unmangled_name);
}
inline std::string demangle_symbol(const std::string& mangled_name)
{
	return demangle_symbol(mangled_name.c_str());
}

}}}
#else

#include <boost/core/demangle.hpp>

namespace boost
{
namespace dll
{
namespace detail
{

using ::boost::core::demangle;

}}}



#endif


#endif /* INCLUDE_BOOST_DEMANGLE_HPP_ */
