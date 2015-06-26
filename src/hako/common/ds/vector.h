#ifndef HAKO_COMMON_DS_VECTOR_H
#define HAKO_COMMON_DS_VECTOR_H


#include <hako/common/debug.h>
#include <hako/common/mem.h>


namespace Hako
{
	namespace DS
	{
		// A contiguous-memory list data structure.
		template <typename T>
		class Vector
		{
		public:
			~Vector()
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				this->mem_callbacks.free_callback.call(this->data);
			}


			// Initializes the vector storage.
			void init(Hako::MemCallbacks mem_callbacks, const unsigned int capacity)
			{
				HAKO_ASSERT(!this->initialized, "init() was already called");
				this->mem_callbacks    = mem_callbacks;
				this->data             = nullptr;
				this->element_capacity = 0;
				this->element_num      = 0;
				HAKO_ONLYINDEBUG( this->initialized = true; )
				this->ensure_capacity(capacity);
			}


			// Retrieves the raw pointer to storage.
			T* get_data_ptr()
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				return this->data;
			}


			// Retrieves the number of elements stored.
			unsigned int get_length()
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				return this->element_num;
			}


			// Retrieves a reference to an element at the given position.
			T& get_element(const unsigned int index)
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				HAKO_ASSERT(index < this->element_num, "index out of range");
				return this->data[index];
			}


			T& operator [] (const unsigned int index)
			{
				return get_element(index);
			}


			// Appends an element to the end of the list, growing the storage space
			// if necessary.
			unsigned int add(T element)
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				ensure_capacity(this->element_num + 1);
				this->data[this->element_num] = element;
				this->element_num += 1;
				return this->element_num - 1;
			}


			// Ensures that the vector's capacity is larger than or equal to
			// the given value, growing the storage space if necessary.
			void ensure_capacity(const unsigned int capacity)
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				if (capacity > this->element_capacity)
				{
					this->data = (T*)this->mem_callbacks.realloc_callback.call(
						this->data,
						sizeof(T) * this->element_capacity,
						32,
						sizeof(T) * capacity,
						32);
				}
			}


			// Sets the number of elements to the given value, growing the
			// storage space if necessary.
			void set_length(const unsigned int length)
			{
				HAKO_ASSERT(this->initialized, "init() must be called before");
				ensure_capacity(length);
				this->element_num = length;
			}


		protected:
			HAKO_ONLYINDEBUG( bool initialized = false; )

			T*           data;
			unsigned int element_num;
			unsigned int element_capacity;

			Hako::MemCallbacks mem_callbacks;
		};
	}
}


#endif


