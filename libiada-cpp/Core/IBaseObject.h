#pragma once

#include <string>

/// Base interface for all storage classes.
/// Requires implementation of comparison and cloning methods.
class IBaseObject
{
public:
	/// Creates clone of this object
	/// Copy of this object
	virtual IBaseObject* Clone() = 0;
	///Compare method
	///Object to compare to
	///true of objects are equal and false otherwise
	virtual bool operator ==(IBaseObject& other) = 0;

	virtual std::string ToString() = 0;
};