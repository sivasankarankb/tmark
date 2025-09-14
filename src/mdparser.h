# ifndef MDPARSER_H
# define MDPARSER_H

# include <cstddef>

class MdParserPlugin{
    public:
    virtual void addTextElement(const wchar_t *text);
};

class MdParser{
    MdParserPlugin *plugin = NULL;

    public:
    void addPlugin(MdParserPlugin *plugin);
    void parseLine(const wchar_t *source);
};

# endif
