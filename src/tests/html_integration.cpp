# include <string>
# include "catch2/catch_test_macros.hpp"
# include "mdparser.h"
# include "htmlgen.h"

TEST_CASE("Parsing plain text produces HTML paragraph", "[MdParser]"){
    MdParser parser;
    HTMLGenerator generator;
    parser.addPlugin(&generator);
    parser.parseLine(std::wstring(L"JustSomeText"));
    parser.endParsing();
    REQUIRE(generator.getText().compare(L"<p>JustSomeText</p>") == 0);
}

TEST_CASE("Line breaks become spaces in an HTML paragraph", "[MdParser]"){
    MdParser parser;
    HTMLGenerator generator;
    parser.addPlugin(&generator);
    parser.parseLine(std::wstring(L"My line"));
    parser.parseLine(std::wstring(L"was broken"));
    parser.parseLine(std::wstring(L"in three."));
    parser.endParsing();
    REQUIRE(
        generator.getText().compare(
            L"<p>My line was broken in three.</p>"
        ) == 0
    );
}
