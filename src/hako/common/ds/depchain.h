#ifndef HAKO_COMMON_DS_DEPCHAIN_H
#define HAKO_COMMON_DS_DEPCHAIN_H


#include "refvector.h"
#include <hako/common/debug.h>


namespace Hako
{
	namespace DS
	{
		// A contiguous-memory list which allows setting dependencies
		// between items in order to calculate an order for parallel
		// computations.
		template <typename T>
		class DependencyChain : public Hako::DS::RefVector<T>
		{
		public:
			typedef typename RefVector<T>::Reference Reference;


		protected:
			class Dependency
			{
				friend class DependencyChain<T>;

			protected:
				Reference this_item;
				Reference depends_on;
			};


			class Exclusivity
			{
				friend class DependencyChain<T>;

			protected:
				Reference this_item;
				Reference is_exclusive_to;
			};


		public:
			void init(Hako::MemCallbacks mem_callbacks, const unsigned int capacity)
			{
				HAKO_ASSERT(!this->initialized, "init() was already called");

				this->Hako::DS::RefVector<T>:: init(mem_callbacks, capacity);
				this->dependency_list         .init(mem_callbacks, 0);
				this->exclusivity_list        .init(mem_callbacks, 0);

				HAKO_ONLYINDEBUG( this->initialized = true; )
			}


			void add_dependency(Reference what_item, Reference depends_on)
			{
				Dependency dep;
				dep.this_item  = what_item;
				dep.depends_on = depends_on;
				this->dependency_list.add(dep);
			}


			void add_exclusivity(Reference what_item, Reference is_exclusive_to)
			{
				Exclusivity excl;
				excl.this_item       = what_item;
				excl.is_exclusive_to = is_exclusive_to;
				this->exclusivity_list.add(excl);
			}


		protected:
			HAKO_ONLYINDEBUG( bool initialized = false; )

			Hako::DS::Vector<Dependency>  dependency_list;
			Hako::DS::Vector<Exclusivity> exclusivity_list;
		};
	}
}


#endif
