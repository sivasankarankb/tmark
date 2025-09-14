# include <cwchar>
# include "htmlgen.h"

void HTMLGenerator::addTextElement(const wchar_t *text){
    wcscpy(this->text, text);
}

wchar_t *HTMLGenerator::getText(){
    return this->text;
}
