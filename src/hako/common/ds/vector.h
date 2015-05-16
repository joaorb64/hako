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
				HAKO_ASSERT(m_initialized_elements, "init_elements must be called before");
				m_free_function->call(m_data);
			}


			// Initializes memory-management functions.
			void init_mem(
				Hako::MemAllocCallback* alloc_function,
				Hako::MemReallocCallback* realloc_function,
				Hako::MemFreeCallback* free_function)
			{
				m_alloc_function   = alloc_function;
				m_realloc_function = realloc_function;
				m_free_function    = free_function;
				HAKO_ONLYINDEBUG( m_initialized_mem = true; )
			}


			void init_elements(unsigned int capacity)
			{
				HAKO_ASSERT(m_initialized_mem, "init_mem must be called before");
				m_data = nullptr;
				m_element_capacity = 0;
				m_element_num      = 0;
				HAKO_ONLYINDEBUG( m_initialized_elements = true; )
				ensure_capacity(capacity);
			}


			T* get_data_ptr()
			{
				HAKO_ASSERT(m_initialized_elements, "init_elements must be called before");
				return m_data;
			}


			unsigned int get_length()
			{
				HAKO_ASSERT(m_initialized_elements, "init_elements must be called before");
				return m_element_num;
			}


			T& get_element(unsigned int index)
			{
				HAKO_ASSERT(m_initialized_elements, "init_elements must be called before");
				HAKO_ASSERT(index < m_element_num, "index out of range");
				return m_data[index];
			}


			unsigned int add(T element)
			{
				HAKO_ASSERT(m_initialized_elements, "init_elements must be called before");
				ensure_capacity(m_element_num + 1);
				m_data[m_element_num] = element;
				m_element_num += 1;
				return m_element_num - 1;
			}


		protected:
			HAKO_ONLYINDEBUG( bool m_initialized_mem = false; )
			HAKO_ONLYINDEBUG( bool m_initialized_elements = false; )

			T*           m_data;
			unsigned int m_element_num;
			unsigned int m_element_capacity;

			Hako::MemAllocCallback*   m_alloc_function;
			Hako::MemReallocCallback* m_realloc_function;
			Hako::MemFreeCallback*    m_free_function;


			void ensure_capacity(unsigned int capacity)
			{
				HAKO_ASSERT(m_initialized_elements, "init_elements must be called before");
				if (capacity > m_element_capacity)
				{
					m_data = (T*)m_realloc_function->call(
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


