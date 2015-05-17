#ifndef HAKO_COMMON_CALLBACK_H
#define HAKO_COMMON_CALLBACK_H


namespace Hako
{
	template <typename TReturn, typename... TCallbackArgs>
	class Callback
	{
	public:
		virtual TReturn call(TCallbackArgs... args) = 0;
	};


	template <typename TReturn, typename... TCallbackArgs>
	class FunctionCallback : public Hako::Callback<TReturn, TCallbackArgs...>
	{
	public:
		void init(TReturn(*function)(TCallbackArgs...))
		{
			m_function = function;
		}


		TReturn call(TCallbackArgs... args) override
		{
			return m_function(args...);
		}


	protected:
		TReturn(*m_function)(TCallbackArgs...);
	};


	template <class T, typename TReturn, typename... TCallbackArgs>
	class MemberCallback : public Hako::Callback<TReturn, TCallbackArgs...>
	{
	public:
		void init(T* instance, TReturn(T::*member_function)(TCallbackArgs...))
		{
			m_instance = instance;
			m_member_function = member_function;
		}


		TReturn call(TCallbackArgs... args) override
		{
			return (m_instance->*m_member_function)(args...);
		}


	protected:
		TReturn(T::*m_member_function)(TCallbackArgs...);
		T* m_instance;
	};
}


#endif
