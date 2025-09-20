# include <cstddef>
# include <string>
# include "mdparser.h"

void MdParserPlugin::addTextElement(const std::wstring &text){

}

void MdParserPlugin::startParagraph(){

}

void MdParserPlugin::endParagraph(){
    
}

void MdParser::parseLine(const std::wstring &source){
    if(this->plugin != NULL){
        if(this->firstLine == true){
            this->plugin->startParagraph();
            this->firstLine = false;
        }

        else{
            this->textBuffer.append(L" ");
        }

        this->textBuffer.append(source);
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
