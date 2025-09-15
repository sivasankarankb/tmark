# include <cstddef>
# include "mdparser.h"

void MdParserPlugin::addTextElement(const wchar_t *text){

}

void MdParserPlugin::startParagraph(){

}

void MdParserPlugin::endParagraph(){
    
}

void MdParser::parseLine(const wchar_t *source){
    if(this->plugin != NULL){
        plugin->startParagraph();
        plugin->addTextElement(source);
        plugin->endParagraph();
    }
}

void MdParser::addPlugin(MdParserPlugin *plugin){
    this->plugin = plugin;
}