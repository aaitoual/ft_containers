template <bool value, typename T>
struct enable_if
{
	typedef void type;
}


template <bool, typename T>
struct enable_if<true>
{
	typedef T type;
}

