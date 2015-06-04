#ifndef HAKO_REFERENCES_H
#define HAKO_REFERENCES_H


#include <hako/common/mem.h>
#include <hako/common/debug.h>


namespace Hako
{
	namespace Reference
	{
		template <typename T>
		class Unique
		{
		public:
			~Unique()
			{
				HAKO_ASSERT(!this->borrowed, "attempting to destroy a unique reference while borrowed");
				this->free_callback.call(this->data);
				this->data     = nullptr;
				this->borrowed = false;
			}



			void init(T* data, Hako::MemFreeCallback free_callback)
			{
				HAKO_ASSERT(data != nullptr, "attempting to create a unique reference to null");
				this->data          = data;
				this->borrowed      = false;
				this->free_callback = free_callback;
			}



			T* operator ->()
			{
				HAKO_ASSERT(this->data != nullptr, "attempting to access a unique reference to null");
				return this->data;
			}

		protected:
			T*                    data;
			bool                  borrowed;
			Hako::MemFreeCallback free_callback;
		};



		template <typename T>
		class Borrowed
		{
		public:
			~Borrowed()
			{
				if (this->unique_source != nullptr)
				{
					this->unique_source->borrowed = false;
					this->unique_source           = nullptr;
				}
			}



			void borrow(Unique<T>* unique_ref)
			{
				HAKO_ASSERT(this->unique_ref != nullptr, "unique reference cannot be null");
				HAKO_ASSERT(!this->unique_ref->borrow, "attempting to double-borrow from a unique reference");
				this->unique_source           = unique_ref;
				this->unique_source->borrowed = true;
				this->data                    = unique_ref->get();
			}



			void init_from_raw(T* data)
			{
				HAKO_ASSERT(this->unique_ref != nullptr, "borrowed pointer cannot be null");
				this->data          = data;
				this->unique_source = nullptr;
			}



			T* operator ->()
			{
				return this->data;
			}

		protected:
			T*         data;
			Unique<T>* unique_source;


			Borrowed(Borrowed& b) = delete;
		};


		template <typename T>
		class Shared
		{
		protected:
			T data;
		};


		template <typename T>
		class Weak
		{
		protected:
			T data;
		};
	}
}


#endif
