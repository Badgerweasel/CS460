//
// Created by Ali A. Kooshesh on 2/5/19.
//

#ifndef EXPRINTER_SYMTAB_HPP
#define EXPRINTER_SYMTAB_HPP

#include <string>
#include <map>
#include <vector>

// This is a flat and integer-based symbol table. It allows for variables to be
// initialized, determines if a give variable has been defined or not, and if
// a variable has been defined, it returns its value.

struct TypeDescriptor{

    enum types {INTEGER, DOUBLE, BOOL, STRING};

    TypeDescriptor(types type) : _type{type} {}

    types &type() { return _type; }

    virtual ~TypeDescriptor() {}

protected:
    types _type;
};

struct NumberDescriptor: TypeDescriptor{
    NumberDescriptor(types descType) : TypeDescriptor(descType) {}
    union{
        int intValue;
        double doubleValue;
        short boolValue;
    } value;
};

struct StringDescriptor: TypeDescriptor{
    StringDescriptor(types descType) : TypeDescriptor(descType) {}
    std::string value;
};

struct ArrayDescriptor: TypeDescriptor{
    ArrayDescriptor(types descType) : TypeDescriptor(descType) {}
    std::vector<int> valueInt;
    std::vector<std::string > valueString;

    void switchDataType(types descType){
        if(_type == TypeDescriptor::INTEGER){
            valueInt.clear();
        }
        else{
            valueString.clear();
        }
        _type = descType;
    }
};

class SymTab {
public:
    ~SymTab();
    void setValueFor(std::string vName, TypeDescriptor *value);
    //void setValueString(std::string vName, std::string value);
    bool isDefined(std::string vName);
    TypeDescriptor* getValueFor(std::string vName);
    std::string getValueString(std::string vName);

private:
    std::map<std::string, TypeDescriptor *> symTab;
};



#endif //EXPRINTER_SYMTAB_HPP
