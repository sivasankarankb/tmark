# ifndef MDPARSER_H
# define MDPARSER_H

# include <cstddef>

class MdParserPlugin{
    public:
    virtual void addTextElement(const wchar_t *text);
    virtual void startParagraph();
    virtual void endParagraph();
};

class MdParser{
    MdParserPlugin *plugin = NULL;
    bool firstLine = true;
    wchar_t textBuffer[80];

    public:
    void addPlugin(MdParserPlugin *plugin);
    void parseLine(const wchar_t *source);
    void endParsing();
};

# endif
