#include "lib.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <sstream>

TEST(version_test_case, version_test)
{
  EXPECT_GT(lib::version_patch(), 0);
  EXPECT_GT(lib::version_major(), 0);
  EXPECT_GT(lib::version_minor(), 0);
}

TEST(read_stream, read_one_ip)
{
  std::stringstream ss("11.22.33.44\t other sring part");
  std::vector<lib::IpAddress> expected{{11,22,33,44}};

  EXPECT_EQ(expected, lib::readIpStream(ss));
}

TEST(read_stream, read_three_ip)
{
  std::stringstream ss("11.22.33.44\t other sring part\n"
                       "22.33.11.44\t other sring part\n"
                       "44.33.22.11\t other sring part\n");
  std::vector<lib::IpAddress> expected{
    {11,22,33,44},
    {22,33,11,44},
    {44,33,22,11}
    };

  EXPECT_EQ(expected, lib::readIpStream(ss));
}

TEST(read_stream, not_read_empty_strings)
{
  std::stringstream ss("\tother sring part\n22.33.11.44\t other sring part\n\n");
  std::vector<lib::IpAddress> expected{{22,33,11,44}};

  EXPECT_EQ(expected, lib::readIpStream(ss));
}

TEST(sorting, backward_sorting)
{
  std::vector<lib::IpAddress> actual{
    {1, 1, 234, 8},
    {222, 82, 198, 61},
    {222, 173, 235, 246},
    {222, 130, 177, 64}
    };
  const std::vector<lib::IpAddress> expected{
    {222, 173, 235, 246},
    {222, 130, 177, 64},
    {222, 82, 198, 61},
    {1, 1, 234, 8}
    };

  std::sort(actual.begin(), actual.end(), std::greater<>());

  EXPECT_EQ(expected, actual);
}

TEST(filtering, filter_by_first_byte)
{
  const std::vector<lib::IpAddress> pool{
    {123, 82, 198, 61}, 
    {1, 173, 235, 246}, 
    {2, 130, 177, 64},
    };
  const std::vector<lib::IpAddress> expected{{123, 82, 198, 61}};

  EXPECT_EQ(expected, lib::filter(123, pool));
}

TEST(filtering, filter_by_two_bytes)
{
  const std::vector<lib::IpAddress> pool{
    {1, 32, 198, 61},
    {1, 173, 235, 246},
    {2, 31, 177, 64},
    {4, 173, 1, 2}
    };
  const std::vector<lib::IpAddress> expected{{1, 32, 198, 61}};

  EXPECT_EQ(expected, lib::filter(1, 32, pool));
}

TEST(filtering, filter_by_any_byte)
{
  const std::vector<lib::IpAddress> pool{
    {1, 32, 198, 61},
    {2, 1, 235, 246},
    {2, 31, 1, 64},
    {4, 173, 4, 1},
    {4, 32, 198, 61}
    };
  const std::vector<lib::IpAddress> expected{
    {1, 32, 198, 61},
    {2, 1, 235, 246},
    {2, 31, 1, 64},
    {4, 173, 4, 1}
    };

  EXPECT_EQ(expected, lib::filter_any(1, pool));
}

TEST(printing, print_pool)
{
  std::stringstream out;
  const char expected[] = "1.32.198.61\n2.1.235.246\n";
  const std::vector<lib::IpAddress> pool{
    {1, 32, 198, 61},
    {2, 1, 235, 246},
    };

  lib::printIp(pool, out);

  EXPECT_EQ(expected, out.str());
}