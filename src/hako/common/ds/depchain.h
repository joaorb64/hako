#ifndef HAKO_COMMON_DS_DEPCHAIN_H
#define HAKO_COMMON_DS_DEPCHAIN_H


#include <hako/common/debug.h>


namespace Hako
{
	namespace DS
	{
		// A contiguous-memory list which allows setting dependencies
		// between items in order to calculate an order for parallel
		// computations.
		template <typename T>
		class DependencyChain
		{
		public:
			// Holds data which allows an item to be accessed or referenced.
			class Reference
			{

			};
		};
	}
}


#endif
