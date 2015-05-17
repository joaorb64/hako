#ifndef HAKO_COMMON_CALLBACK_H
#define HAKO_COMMON_CALLBACK_H


namespace Hako
{
	template <typename TReturn, typename... TCallbackArgs>
	class Callback
	{
	public:
		void init(void* user_data, TReturn(*function)(void*, TCallbackArgs...))
		{
			m_user_data = user_data;
			m_function  = function;
		}


		TReturn call(TCallbackArgs... args)
		{
			return m_function(m_user_data, args...);
		}


	protected:
		TReturn(*m_function)(void*, TCallbackArgs...);
		void* m_user_data;
	};
}


#endif
