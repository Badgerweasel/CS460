//
// Created by Ali A. Kooshesh on 2/5/19.
//

#include <iostream>
#include "SymTab.hpp"

extern bool debug;

SymTab::~SymTab() {
    symTab.clear();
}

void SymTab::setValueFor(std::string vName, TypeDescriptor *value) {
    // Define a variable by setting its initial value.
    if(debug) {
        std::cout << vName << " <- ";
        if(value->type() == TypeDescriptor::INTEGER)
        {
            std::cout << dynamic_cast<NumberDescriptor*>(value)->value.intValue << std::endl;
        }
        else if(value->type() == TypeDescriptor::STRING)
        {
            std::cout << dynamic_cast<StringDescriptor*>(value)->value << std::endl;
        }
    }

    symTab[vName] = value;
}

bool SymTab::isDefined(std::string vName) {
    return symTab.find(vName) != symTab.end();
}

TypeDescriptor* SymTab::getValueFor(std::string vName) {
    if( ! isDefined(vName)) {
        if(debug)
            std::cout << "SymTab::getValueFor: " << vName << " has not been defined.\n";
        exit(1);
    }
    if(debug) {
        TypeDescriptor *val = symTab.find(vName)->second;
        if(val->type() == TypeDescriptor::INTEGER)
            std::cout << "SymTab::getValueFor: " << vName << " contains " << dynamic_cast<NumberDescriptor*>(symTab.find(vName)->second)->value.intValue << std::endl;
        else if(val->type() == TypeDescriptor::STRING)
            std::cout << "SymTab::getValueFor: " << vName << " contains " << dynamic_cast<StringDescriptor*>(symTab.find(vName)->second)->value << std::endl;
    }
    return symTab.find(vName)->second;
}
/*
std::string SymTab::getValueString(std::string vName) {
    if( ! isDefined(vName)) {
        if(debug)
            std::cout << "SymTab::getValueFor: " << vName << " has not been defined.\n";
        exit(1);
    }
    if(debug)
        std::cout << "SymTab::getValueFor: " << vName << " contains " << symTab.find(vName)->second << std::endl;
    return symTab.find(vName)->second->val.stringValue;
}*/

