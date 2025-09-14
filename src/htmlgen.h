# ifndef HTMLGEN_H
# define HTMLGEN_H

# include "mdparser.h"

class HTMLGenerator: public MdParserPlugin{
    wchar_t text[80];

    public:

    void addTextElement(const wchar_t *text);
    wchar_t *getText();
};

# endif
