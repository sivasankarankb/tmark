# include <string>
# include "htmlgen.h"

void HTMLGenerator::addTextElement(const std::wstring &text){
    this->text.append(text);
}

void HTMLGenerator::startParagraph(){
    this->text.append(L"<p>");
}

void HTMLGenerator::endParagraph(){
    this->text.append(L"</p>");
}

std::wstring &HTMLGenerator::getText(){
    return this->text;
}
