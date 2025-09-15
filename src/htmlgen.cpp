# include <cwchar>
# include "htmlgen.h"

HTMLGenerator::HTMLGenerator(){
    wcscpy(this->text, L"\0");;
}

void HTMLGenerator::addTextElement(const wchar_t *text){
    wcscat(this->text, text);
}

void HTMLGenerator::startParagraph(){
    wcscat(this->text, L"<p>");
}

void HTMLGenerator::endParagraph(){
    wcscat(this->text, L"</p>");
}

wchar_t *HTMLGenerator::getText(){
    return this->text;
}
