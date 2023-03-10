#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# include <cstdint>

namespace ft
{
    // nil??
    // struct nil {};
    const class nullptr_t 
    {
        private:
            void operator&(void) const;

        public:
            template <typename T>
            operator T*(void) const { return 0; }

        template <typename T, typename U>
            operator T U::*(void) const { return 0; }
    } nil = {};

    // enable_if
    template <bool cond, typename T = void>
    struct enable_if {};

    template <typename T>
    struct enable_if<true, T> 
    {
	    typedef T type;
    };

    // remove_cv (constant and volatile)
    template <typename T>
    struct remove_cv { typedef T type; };

    template <typename T>
    struct remove_cv<const T> { typedef T type; };

    template <typename T>
    struct remove_cv<volatile T> { typedef T type; };

    template <typename T>
    struct remove_cv<const volatile T> { typedef T type; }; 

    // integral constant
    template <typename T, T v>
    struct integral_constant 
    {
        typedef T                       value_type;
        typedef integral_constant       type;
        static const value_type         value = v;

        operator value_type(void) const { return value; }
    };

    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;

    // is_integral_base
    template <typename> 
    struct is_integral_base : public false_type {};
    
    template <> struct is_integral_base<bool>           : public true_type {};
    template <> struct is_integral_base<std::int8_t>    : public true_type {};
    template <> struct is_integral_base<std::int16_t>   : public true_type {};
    template <> struct is_integral_base<std::int32_t>   : public true_type {};
    template <> struct is_integral_base<std::int64_t>   : public true_type {};
    template <> struct is_integral_base<std::uint8_t>   : public true_type {};
    template <> struct is_integral_base<std::uint16_t>  : public true_type {};
    template <> struct is_integral_base<std::uint32_t>  : public true_type {};
    template <> struct is_integral_base<std::uint64_t>  : public true_type {};

    // is_integral
    template <typename T>
    struct is_integral : public is_integral_base<typename remove_cv<T>::type> {};
} // namespace ft

#endif