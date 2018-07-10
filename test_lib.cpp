#include "lib.h"

#define BOOST_TEST_MODULE test_lib

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_version)

BOOST_AUTO_TEST_CASE(test_version_valid)
        {
                BOOST_CHECK(lib::version_patch() > 0);
                BOOST_CHECK(lib::version_major() > 0);
                BOOST_CHECK(lib::version_minor() > 0);
        }

BOOST_AUTO_TEST_SUITE_END()