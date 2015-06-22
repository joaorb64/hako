#ifndef HAKO_REFERENCES_H
#define HAKO_REFERENCES_H


#include <hako/common/mem.h>
#include <hako/common/debug.h>


namespace Hako
{
	/*template <typename T>
	class RcPtr
	{
	public:
		~RcPtr()
		{
			if (this->previous != nullptr)
				this->previous->next = this->next;

			if (this->next != nullptr)
				this->next->previous = this->previous;

			if (this->previous == nullptr && this->next == nullptr)
			{
				this->data->~T();
				this->engine->get_mem_callbacks().free_callback(this->data);
				this->data   = nullptr;
				this->engine = nullptr;
			}
		}


		RcPtr()
		{
			this->engine    = nullptr;
			this->previous  = nullptr;
			this->next      = nullptr;
			this->data      = nullptr;
		}


		static RcPtr<T> make_from_ptr(Hako::Engine* engine, T* ptr)
		{
			RcPtr<T> result;
			result.engine    = engine;
			result.data      = ptr;
			return result;
		}


		static RcPtr<T> make_new(Hako::Engine* engine)
		{
			RcPtr<T> result;
			result.engine    = engine;
			result.data      = new ((T*)engine->get_mem_callbacks().alloc_callback(sizeof(T), 32)) T();
			return result;
		}


		RcPtr<T>& operator = (const RcPtr<T>& other)
		{
			if (this != &other)
			{
				this->~RcPtr();
                this->data   = other.data;
                this->engine = other.engine;

                this->previous = &other;
                this->next     = other.next;
                if (other.next != null)
					other.next = other.next->previous = this;
				other.next     = this;
			}
			return *this;
		}


	protected:
		Hako::Engine* engine;
		RcPtr<T>      previous, next;
		T*            data;
	};*/
}


#endif
