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

TEST_CASE(
    "HTML generator outputs paragraph start and end",
    "[HTMLGenerator]"
){
    HTMLGenerator generator;
    generator.startParagraph();
    generator.endParagraph();
    REQUIRE(wcscmp(generator.getText(), L"<p></p>") == 0);
}
