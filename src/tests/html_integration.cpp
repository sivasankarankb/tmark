# include <cwchar>
# include "catch2/catch_test_macros.hpp"
# include "mdparser.h"
# include "htmlgen.h"

TEST_CASE("Parsing plain text produces HTML paragraph", "[MdParser]"){
    MdParser parser;
    HTMLGenerator generator;
    parser.addPlugin(&generator);
    parser.parseLine(L"JustSomeText");
    parser.endParsing();
    REQUIRE(wcscmp(generator.getText(), L"<p>JustSomeText</p>") == 0);
}

TEST_CASE("Line breaks become spaces in an HTML paragraph", "[MdParser]"){
    MdParser parser;
    HTMLGenerator generator;
    parser.addPlugin(&generator);
    parser.parseLine(L"My line");
    parser.parseLine(L"was broken");
    parser.parseLine(L"in three.");
    parser.endParsing();
    REQUIRE(
        wcscmp(
            generator.getText(), L"<p>My line was broken in three.</p>"
        ) == 0
    );
}
