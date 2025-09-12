# include <iostream>
# include <cwchar>
# include "catch2/catch_test_macros.hpp"
# include "mdparser.h"

class ParserLoggingPlugin: public MdParserPlugin{
    wchar_t text[80];

    public:

    void addTextElement(const wchar_t *text){
        wcscpy(this->text, text);
    }

    wchar_t *getText(){
        return this->text;
    }
};

TEST_CASE(
    "Parser plugins accept text elements",
    "[MdParserPlugin]"
){
    MdParserPlugin plugin;
    plugin.addTextElement(L"text");
}

TEST_CASE(
    "Parser logging plugin logs text element",
    "[ParserLoggingPlugin]"
){
    ParserLoggingPlugin plugin;
    plugin.addTextElement(L"text");
    REQUIRE(wcscmp(plugin.getText(), L"text") == 0);
}

TEST_CASE("Parsing with no plugin installed is allowed", "[MdParser]"){
    MdParser parser;
    parser.parseLine(L"JustSomeText");
}

TEST_CASE("Parsing plain text produces text element", "[MdParser]"){
    MdParser parser;
    ParserLoggingPlugin plugin;
    parser.addPlugin(&plugin);
    parser.parseLine(L"JustSomeText");
    REQUIRE(wcscmp(plugin.getText(), L"JustSomeText") == 0);
}
