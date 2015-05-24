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
			this->user_data = user_data;
			this->function  = function;
		}


		TReturn call(TCallbackArgs... args)
		{
			return this->function(this->user_data, args...);
		}


	protected:
		TReturn(*function)(void*, TCallbackArgs...);
		void* user_data;
	};
}


#endif
