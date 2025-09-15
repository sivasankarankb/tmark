# include <cstddef>
# include <cwchar>
# include "mdparser.h"

void MdParserPlugin::addTextElement(const wchar_t *text){

}

void MdParserPlugin::startParagraph(){

}

void MdParserPlugin::endParagraph(){
    
}

void MdParser::parseLine(const wchar_t *source){
    if(this->plugin != NULL){
        if(this->firstLine == true){
            this->plugin->startParagraph();
            this->firstLine = false;
        }

        else{
            wcscat(this->textBuffer, L" ");
        }

        wcscat(this->textBuffer, source);
    }
}

void MdParser::addPlugin(MdParserPlugin *plugin){
    this->plugin = plugin;
}

void MdParser::endParsing(){
    if(this->plugin != NULL){
        this->plugin->addTextElement(this->textBuffer);
        this->plugin->endParagraph();
    }
}
