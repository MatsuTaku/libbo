//
//  bo.hpp
//
//  Created by 松本拓真 on 2018/05/16.
//

#ifndef BIT_OPERATION_HPP
#define BIT_OPERATION_HPP

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

#include "bo/popcnt.hpp"
#include "bo/bextr.hpp"
#include "bo/ctz.hpp"
#include "bo/clz.hpp"
#include "bo/select.hpp"
#include "bo/swapnext.hpp"

#endif /* BIT_OPERATION_HPP */
