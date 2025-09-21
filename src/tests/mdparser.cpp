# include <string>
# include "catch2/catch_test_macros.hpp"
# include "mdparser.h"

TEST_CASE(
    "Parser plugins accept text elements",
    "[MdParserPlugin]"
){
    MdParserPlugin plugin;
    plugin.addTextElement(std::wstring(L"text"));
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
    parser.parseLine(std::wstring(L"JustSomeText"));
}

TEST_CASE("Ending parse with no plugin installed is allowed", "[MdParser]"){
    MdParser parser;
    parser.endParsing();
}

class ParaLogger: public MdParserPlugin{
    std::wstring outText;

    public:

    void addTextElement(const std::wstring &text){
        this->outText.append(text);
        this->outText.append(L",");
    }

    void startParagraph(){
        this->outText.append(L"ps,");
    }

    void endParagraph(){
        this->outText.append(L"pe,");
    }

    const std::wstring &getText(){
        return this->outText;
    }
};

TEST_CASE("Parsing plain text produces para and text events", "[MdParser]"){
    MdParser parser;
    ParaLogger logger;
    parser.addPlugin(logger);
    parser.parseLine(std::wstring(L"JustSomeText"));
    parser.endParsing();
    REQUIRE(logger.getText().compare(L"ps,JustSomeText,pe,") == 0);
}

TEST_CASE("Line breaks become spaces in a paragraph", "[MdParser]"){
    MdParser parser;
    ParaLogger logger;
    parser.addPlugin(logger);
    parser.parseLine(std::wstring(L"My line"));
    parser.parseLine(std::wstring(L"was broken"));
    parser.parseLine(std::wstring(L"in three."));
    parser.endParsing();
    REQUIRE(
        logger.getText().compare(L"ps,My line was broken in three.,pe,") == 0
    );
}
