/*
 * util.hpp
 *
 *  Created on: Feb 12, 2017
 *      Author: ruanbo
 */

#ifndef UTIL_HEAD_HPP_
#define UTIL_HEAD_HPP_

#include "../Log.hpp"


void utils_tests();

void utils2_tests();

void util_entry()
{
    utils_tests();

    utils2_tests();

    Log("end of util_entry");
}





#endif /* UTIL_HEAD_HPP_ */
