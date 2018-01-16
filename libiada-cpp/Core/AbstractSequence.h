#pragma once

#include <string>

#include "IBaseObject.h"

///The abstract sequence
class AbstractSequence :public IBaseObject
{
public:
	///Indexer. Return elements by index
	///int index - index of element
	IBaseObject* __get(int index)
	{
		return Get(index);
	}
	///Set value to element with that index
	void __set(IBaseObject* value, int index)
	{
		return Set(value, index);
	}
	///The length of sequence
	virtual int GetLength() = 0;
	///Sets or replaces element in specified position.
	///IBaseObject* item is element to set
	///int index is position in sequence
	virtual void Set(IBaseObject* item, int index) = 0;
	///Gets element by index.
	///int index is index of element
	virtual IBaseObject* Get(int index) = 0;
	/// Remove element from given position.
	virtual void RemoveAt(int index) = 0;
	/// Delete element from given position.
	virtual void DeleteAt(int index) = 0;
	/// Deletes chain (building and alphabet) and creates new empty chain with given length.
	///int length is new length
	virtual void ClearAndSetNewLength(int length) = 0;
	/// Creates clone of this chain.
	virtual IBaseObject* Clone() = 0;
	/// Converts sequence to string. Empty string
	std::string ToString() { return ""; }
	/// Converts sequence to string.
	/// delimiter is delimiter added between elements.
	/// return sequence as <see cref="string"/>.
	std::string ToString(std::string delimiter)
	{
		//Create empty string
		std::string builder = "";
		//Get length of all elements
		int length = GetLength();
		for (int i = 0; i < length; i++)
		{
			//Add (string)element and delimiter
			builder += __get(i)->ToString;
			builder += delimiter;
		}
		//Return result without last delimiter
		//For Example builder="1,2,3,4," will return "1,2,3,4"
		return builder.substr(0, std::string::npos - delimiter.length);
	}
};
