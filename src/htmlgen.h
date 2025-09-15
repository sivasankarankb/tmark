# ifndef HTMLGEN_H
# define HTMLGEN_H

# include "mdparser.h"

class HTMLGenerator: public MdParserPlugin{
    wchar_t text[80];

    public:

    HTMLGenerator();
    void addTextElement(const wchar_t *text);
    void startParagraph();
    void endParagraph();
    wchar_t *getText();
};

# endif
