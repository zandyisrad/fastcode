#pragma once

#ifndef REFERENCE_H
#define REFERENCE_H

#include "value.h"

class reference_apartment {
public:
	value* value;
	reference_apartment* next_apartment;
	reference_apartment(class value* value, reference_apartment* next_apartment = nullptr);
	~reference_apartment();

	//adds a reference to it and all it's child reference apartments
	void add_reference();

	//adds a reference to it and all it's child reference apartments, adds the amount of parent references
	void add_reference(reference_apartment* parent);

	//adds a reference to it and all it's child reference apartments
	void remove_reference();

	//adds a reference to it and all it's child reference apartments, removes the amount of parent references
	void remove_reference(reference_apartment* parent);

	//checks whether the reference apartment can be deleted
	inline bool can_delete() {
		return this->references == 0;
	}

	//sets the reference apartments value
	void set_value(class value* value);
private:
	unsigned int references;

	//gets the TOP level children, does NOT get it's childrens children
	reference_apartment** get_children(unsigned int* children_size);
};

#endif // !REFERENCE_H