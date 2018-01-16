#pragma once
#include <string>

#include "../IBaseObject.h"

class ValueString : IBaseObject
{
public:
	///Initializes a new instance of the ValueString class.
	///value is the value
	ValueString(std::string value);
	///Initializes a new instance of the ValueString class.
	///The char value of element
	ValueString(char value);
	///Getter value
	std::string getValue() { return this->Value; };

	static operator std::string(ValueString from) { return from.getValue(); };

	IBaseObject* Clone() { return new ValueString(this->Value); };

	bool operator ==(IBaseObject& other);

	std::string ToString();
private:
	///The value
	std::string	Value;

};