# include <iostream>
# include "mdparser.h"

void MdParserPlugin::addTextElement(const wchar_t *text){

}

void MdParser::parseLine(const wchar_t *source){
    if(this->plugin != NULL){
        plugin->addTextElement(source);
    }
}

void MdParser::addPlugin(MdParserPlugin *plugin){
    this->plugin = plugin;
}