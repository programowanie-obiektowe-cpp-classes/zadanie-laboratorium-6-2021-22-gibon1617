#pragma once

#include "Human.hpp"

#include <algorithm>
#include <list>
#include <vector>
#include <iterator>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > ret_v(people.size());
    
    auto lambda = [&](Human& ludz){ ludz.birthday(); transform(people.cbegin(), people.cend(), ret_v.rbegin(), [](const Human& h) { return h.isMonster() ? 'n' : 'y'; }); };
    for_each(people.begin(), people.end(), [&](Human& val){ lambda(val); } );
    
    return ret_v;
}
