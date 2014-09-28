// Copyright 2014 Renato Tegon Forti, Antony Polukhin.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

//[plugcpp_my_plugin_static
#include <boost/dll/alias.hpp> // for BOOST_DLL_ALIAS
#include "../tutorial_common/plugin_api.hpp"

namespace my_namespace {
    // Forward declaration
    boost::shared_ptr<my_plugin_api> create_plugin();
} // namespace my_namespace

BOOST_DLL_ALIAS(my_namespace::create_plugin, create_plugin)
//]

