/**
 *	u_stringify.h | generic stringify function generator
 * -------------------------------------------------------------------------- */

#if !defined(U_UTILS_FLAG)

# define U_UTILS_FLAG

# if !defined(_U_CONCAT)
#  define	_U_CONCAT(a, b)	a##b
# endif
# if !defined(U_CONCAT)
#  define	U_CONCAT(a, b)			_U_CONCAT(a, b)
# endif

# define	U_FUNC_NAME(type)		U_CONCAT(type, _stringify)

# define	U_NULL_STRUCT			((STRUCT_TYPE *)(0))
# define	U_FIELD(name)			U_NULL_STRUCT->name
# define	U_OFFSET(name)			((unsigned long)&(U_FIELD(name)))

# define	U_ARRAY_SIZE(a)			(sizeof(a) / sizeof(a[0]))
# define	U_FOREACH(v, a)			for (v = a; v < a + U_ARRAY_SIZE(a); ++v)

#endif // U_UTILS_FLAG

/* ENUM STRINGIFICATION ------------------------------------------------------ */
#if defined(ENUM_TYPE)

# if !defined(ENUM_LIST)
#  error "ENUM_LIST must be defined."
# endif

# define U_ENUM_NAME(type)	U_CONCAT(type, _e)

typedef enum U_ENUM_NAME(ENUM_TYPE) ENUM_TYPE;

enum U_ENUM_NAME(ENUM_TYPE)
{
	#define	U_ENUM_VALS(k, v)	k = v,
	ENUM_LIST(U_ENUM_VALS)
	#undef U_ENUM_VALS
};

static const char	*U_FUNC_NAME(ENUM_TYPE)(ENUM_TYPE ENUM_VAR)
{
	#ifdef ENUM_SPEC
	# define U_ENUM_IF(cond, v)	if (cond) { return ((v)); }
	ENUM_SPEC(U_ENUM_IF)
	# undef U_ENUM_IF
	#endif

	static struct pair { ENUM_TYPE k; const char *v; } pairs[] = 
	{
		#define U_ENUM_STRINGS(k, v) {(k), (#k)},
		ENUM_LIST(U_ENUM_STRINGS)
		#undef	U_ENUM_STRINGS
	};
	
	struct pair	*pair;

	U_FOREACH(pair, pairs)
	{
		if (pair->k == ENUM_VAR)
			return (pair->v);
	}
	return ("UNKNOWN");
}

# undef	ENUM_TYPE
# undef	ENUM_LIST
# undef	ENUM_SPEC

#endif // ENUM_TYPE
/* -------------------------------------------------------------------------- */
