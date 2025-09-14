# include <cwchar>
# include "catch2/catch_test_macros.hpp"
# include "htmlgen.h"

TEST_CASE(
    "HTML generator outputs text element",
    "[HTMLGenerator]"
){
    HTMLGenerator generator;
    generator.addTextElement(L"text");
    REQUIRE(wcscmp(generator.getText(), L"text") == 0);
}
