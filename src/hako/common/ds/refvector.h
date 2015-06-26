#ifndef HAKO_COMMON_DS_REFVECTOR_H
#define HAKO_COMMON_DS_REFVECTOR_H


#include "vector.h"
#include <hako/common/debug.h>


namespace Hako
{
	namespace DS
	{
		// A contiguous-memory list from which items are accessed using
		// a custom reference type, which keeps their validity even after
		// the list is changed/reallocated.
		template <typename T>
		class RefVector
		{
		public:
			typedef unsigned int IdentifierType;


			class Reference
			{
				friend class RefVector<T>;

			protected:
				IdentifierType item_identifier;
				unsigned int   cached_generation;
				unsigned int   cached_index;
			};


			void init(Hako::MemCallbacks mem_callbacks, const unsigned int capacity)
			{
				HAKO_ASSERT(!this->initialized, "init() was already called");
				this->data        .init(mem_callbacks, capacity);
				this->identifiers .init(mem_callbacks, capacity);

				this->current_generation = 1;
				this->current_identifier = 1;
				HAKO_ONLYINDEBUG( this->initialized = true; )
			}


			// Retrieves the raw pointer to storage.
			T* get_data_ptr()
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				return this->data.get_data_ptr();
			}


			// Retrieves the number of elements stored.
			unsigned int get_length()
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				return this->data.get_length();
			}


			// Appends an element to the end of the list, growing the storage space
			// if necessary.
			Reference add(T element)
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");

				unsigned int index = this->data.add(element);

				this->identifiers.add(this->current_identifier);

				HAKO_ONLYINDEBUG( unsigned int last_identifier = this->current_identifier; )
				this->current_identifier += 1;
				HAKO_ASSERT(this->current_identifier > last_identifier, "refvector identifier overflow");

				return this->make_reference_to_index(index);
			}


			// Retrieves an element using the given Reference.
			T& get_element(Reference* ref)
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");

				// Get by cached index, if the generation is the same.
				if (ref->cached_generation == this->current_generation)
				{
					HAKO_ASSERT(ref->cached_index < this->get_length(), "Reference corrupted, out of range");
					return this->data.get_data_ptr()[ref->cached_index];
				}

				// Or, search for the item with the given identifier.
				else
				{
					bool found = false;
					unsigned int found_index = 0;
					for (unsigned int i = 0; i < this->get_length(); i++)
					{
						if (this->identifiers[i] == ref->item_identifier)
						{
							found = true;
							found_index = i;
							break;
						}
					}

					if (!found)
						HAKO_ERROR("reference points to invalid item");

                    // Update the Reference cache.
                    *ref = this->make_reference_to_index(found_index);
                    return this->data.get_data_ptr()[found_index];
				}
			}


			// Retrieves an element at the given position.
			T& get_element_by_index(const unsigned int index)
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				HAKO_ASSERT(index < this->element_num, "index out of range");
				return this->data[index];
			}


			// Retrieves an element at the given position.
			T& operator [] (const unsigned int index)
			{
				return this->get_element_by_index(index);
			}


		protected:
			Reference make_reference_to_index(const unsigned int index)
			{
				Reference ref;
				ref.cached_generation = this->current_generation;
				ref.cached_index      = index;
				ref.item_identifier   = this->identifiers[index];
				return ref;
			}


			HAKO_ONLYINDEBUG( bool initialized = false; )

			Hako::DS::Vector<T>              data;
			Hako::DS::Vector<IdentifierType> identifiers;
			unsigned int                     current_generation;
			IdentifierType                   current_identifier;
		};
	}
}


#endif
