#ifndef HAKO_COMMON_DS_FLATMAP_H
#define HAKO_COMMON_DS_FLATMAP_H


#include <hako/common/debug.h>
#include <hako/common/mem.h>
#include "vector.h"


namespace Hako
{
	namespace DS
	{
		// A contiguous-memory list of key-value pairs.
		template <typename TKey, typename TValue>
		class FlatMap
		{
		protected:
			struct Pair
			{
				TKey   key;
				TValue value;
			};


		public:
			~FlatMap()
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
			}


			// Initializes the flatmap storage.
			void init(Hako::MemCallbacks mem_callbacks, const unsigned int capacity)
			{
				HAKO_ASSERT(!this->initialized, "init() was already called");
				this->internal_storage.init(mem_callbacks, capacity);
				HAKO_ONLYINDEBUG( this->initialized = true; )
			}


			// Retrieves the raw pointer to storage.
			Hako::DS::Vector<Pair>* get_data_ptr()
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				return this->internal_storage.get_data_ptr();
			}


			// Retrieves the number of pairs stored.
			unsigned int get_length()
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				return this->internal_storage.get_length();
			}


			TValue& access(const TKey key)
			{
				unsigned int found_at = -1;
				for (unsigned int i = 0; i < this->internal_storage.get_length(); i++)
				{
					if (this->internal_storage.get_data_ptr()[i].key == key)
					{
						found_at = i;
						break;
					}
				}

				HAKO_ASSERT(found_at != -1, "key was not found in flatmap");

				return this->internal_storage.get_data_ptr()[found_at].value;
			}


			// Appends a pair to the end of the list, growing the storage space
			// if necessary.
			unsigned int add(TKey key, TValue value)
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				Pair pair;
				pair.key   = key;
				pair.value = value;
				return this->internal_storage.add(pair);
			}


			// Ensures that the flatmap's capacity is larger than or equal to
			// the given value, growing the storage space if necessary.
			void ensure_capacity(const unsigned int capacity)
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				this->internal_storage.ensure_capacity(capacity);
			}


			// Sets the number of pairs to the given value, growing the
			// storage space if necessary.
			void set_length(const unsigned int length)
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				this->internal_storage.set_length(length);
			}


		protected:
			HAKO_ONLYINDEBUG( bool initialized = false; )


			Hako::DS::Vector<Pair> internal_storage;
		};
	}
}


#endif


