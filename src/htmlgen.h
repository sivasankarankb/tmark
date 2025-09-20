# ifndef HTMLGEN_H
# define HTMLGEN_H

# include <string>
# include "mdparser.h"

class HTMLGenerator: public MdParserPlugin{
    std::wstring text;

    public:

    void addTextElement(const std::wstring &text);
    void startParagraph();
    void endParagraph();
    std::wstring &getText();
};

# endif
