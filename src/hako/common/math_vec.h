#ifndef HAKO_COMMON_MATH_VEC_H
#define HAKO_COMMON_MATH_VEC_H


namespace Hako
{
	namespace Math
	{
		template <int N>
		class Vec
		{
		public:
			float element[N];

			Vec()          { for (int i = 0; i < N; i++) element[i] = 0;   }
			Vec(float val) { for (int i = 0; i < N; i++) element[i] = val; }
		};
	}
}


#endif
