# include <cwchar>
# include "catch2/catch_test_macros.hpp"
# include "mdparser.h"

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

class ParaLogger: public MdParserPlugin{
    wchar_t outText[80];

    public:

    ParaLogger(){
        wcscpy(this->outText, L"\0");
    }

    void addTextElement(const wchar_t *text){
        wcscat(this->outText, text);
        wcscat(this->outText, L",");
    }

    void startParagraph(){
        wcscat(this->outText, L"ps,");
    }

    void endParagraph(){
        wcscat(this->outText, L"pe,");
    }

    wchar_t *getText(){
        return this->outText;
    }
};

TEST_CASE("Parsing plain text produces para and text events", "[MdParser]"){
    MdParser parser;
    ParaLogger logger;
    parser.addPlugin(&logger);
    parser.parseLine(L"JustSomeText");
    parser.endParsing();
    REQUIRE(wcscmp(logger.getText(), L"ps,JustSomeText,pe,") == 0);
}

TEST_CASE("Line breaks become spaces in a paragraph", "[MdParser]"){
    MdParser parser;
    ParaLogger logger;
    parser.addPlugin(&logger);
    parser.parseLine(L"My line");
    parser.parseLine(L"was broken");
    parser.parseLine(L"in three.");
    parser.endParsing();
    REQUIRE(
        wcscmp(
            logger.getText(), L"ps,My line was broken in three.,pe,"
        ) == 0
    );
}
