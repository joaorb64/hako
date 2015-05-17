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
				HAKO_ASSERT(m_initialized, "init() must be called before");
				m_mem_callbacks.m_free.call(m_data);
			}


			// Initializes the vector storage.
			void init(Hako::MemCallbacks mem_callbacks, unsigned int capacity)
			{
				m_mem_callbacks    = mem_callbacks;
				m_data             = nullptr;
				m_element_capacity = 0;
				m_element_num      = 0;
				HAKO_ONLYINDEBUG( m_initialized = true; )
				ensure_capacity(capacity);
			}


			// Retrieves the raw pointer to storage.
			T* get_data_ptr()
			{
				HAKO_ASSERT(m_initialized, "init() must be called before");
				return m_data;
			}


			// Retrieves the number of elements stored.
			unsigned int get_length()
			{
				HAKO_ASSERT(m_initialized, "init() must be called before");
				return m_element_num;
			}


			// Retrieves a reference to an element at the given position.
			T& get_element(unsigned int index)
			{
				HAKO_ASSERT(m_initialized, "init() must be called before");
				HAKO_ASSERT(index < m_element_num, "index out of range");
				return m_data[index];
			}


			// Appends an element to the end of the list, growing the storage space
			// if necessary.
			unsigned int add(T element)
			{
				HAKO_ASSERT(m_initialized, "init() must be called before");
				ensure_capacity(m_element_num + 1);
				m_data[m_element_num] = element;
				m_element_num += 1;
				return m_element_num - 1;
			}


		protected:
			HAKO_ONLYINDEBUG( bool m_initialized = false; )

			T*           m_data;
			unsigned int m_element_num;
			unsigned int m_element_capacity;

			Hako::MemCallbacks m_mem_callbacks;


			void ensure_capacity(unsigned int capacity)
			{
				HAKO_ASSERT(m_initialized, "init() must be called before");
				if (capacity > m_element_capacity)
				{
					m_data = (T*)m_mem_callbacks.m_realloc.call(
						m_data,
						sizeof(T) * m_element_capacity,
						32,
						sizeof(T) * capacity,
						32);
				}
			}
		};
	}
}


#endif


