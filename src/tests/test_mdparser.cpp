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

TEST_CASE(
    "Parser plugins accept paragraph start and end events",
    "[MdParserPlugin]"
){
    MdParserPlugin plugin;
    plugin.startParagraph();
    plugin.endParagraph();
}

TEST_CASE("Parsing with no plugin installed is allowed", "[MdParser]"){
    MdParser parser;
    parser.parseLine(L"JustSomeText");
}

TEST_CASE("Ending parse with no plugin installed is allowed", "[MdParser]"){
    MdParser parser;
    parser.endParsing();
}

TEST_CASE("Parsing plain text produces HTML paragraph", "[MdParser]"){
    MdParser parser;
    HTMLGenerator generator;
    parser.addPlugin(&generator);
    parser.parseLine(L"JustSomeText");
    parser.endParsing();
    REQUIRE(wcscmp(generator.getText(), L"<p>JustSomeText</p>") == 0);
}

TEST_CASE("Line breaks become spaces in a paragraph", "[MdParser]"){
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
