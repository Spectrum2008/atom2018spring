#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dllist.hpp"

TEST_CASE("TLList basics") {
  DLList list;

  CHECK(list.get_Size() == 0);
}
