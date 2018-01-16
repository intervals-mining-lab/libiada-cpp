#pragma once
#include <vector>
#include "AbstractSequence.h"
class BaseSequence :
	public AbstractSequence
{
public:
	///Initializes a new instance of the BaseSequence class.
	///int length is the length of sequence
	BaseSequence(int length) { ClearAndSetNewLength(length); };

	/// Initializes a new instance of the BaseSequence class with 0 length.
	BaseSequence() {};

	///Initializes a new instance of the BaseSequence class from list of elements.
	///vector elements
	BaseSequence(std::vector<IBaseObject> elements)
	{
		ClearAndSetNewLength(elements.size);
		for (int i = 0; i < this->building.size; i++)
		{
			this->Set(&elements[i], i);
		}
	}

	BaseSequence(std::string source)
	{
		ClearAndSetNewLength(source.length);
		for (int i = 0; i < source.length; i++)
		{
			this->Set(/*ValueString*/, i);
		}
	}

	///Getter id
	long int getId() { return this->Id; };
private:
	///Sequence id (from database)
	long int Id;
protected:
	std::vector<int> building; 
	/*TODO: Alphabet alphabet*/
	
};

