# ifndef MDPARSER_H
# define MDPARSER_H

# include <cstddef>
# include <string>

class MdParserPlugin{
    public:
    virtual void addTextElement(const std::wstring &text);
    virtual void startParagraph();
    virtual void endParagraph();
};

class MdParser{
    MdParserPlugin *plugin = NULL;
    bool firstLine = true;
    std::wstring textBuffer;

    public:
    void addPlugin(MdParserPlugin &plugin);
    void parseLine(const std::wstring &source);
    void endParsing();
};

# endif
