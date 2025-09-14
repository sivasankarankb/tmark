# include <iostream>
# include <cwchar>
# include "catch2/catch_test_macros.hpp"
# include "mdparser.h"
# include "htmlgen.h"

TEST_CASE(
    "Parser plugins accept text elements",
    "[MdParserPlugin]"
){
    MdParserPlugin plugin;
    plugin.addTextElement(L"text");
}

TEST_CASE("Parsing with no plugin installed is allowed", "[MdParser]"){
    MdParser parser;
    parser.parseLine(L"JustSomeText");
}

TEST_CASE("Parsing plain text produces text element", "[MdParser]"){
    MdParser parser;
    HTMLGenerator generator;
    parser.addPlugin(&generator);
    parser.parseLine(L"JustSomeText");
    REQUIRE(wcscmp(generator.getText(), L"JustSomeText") == 0);
}
