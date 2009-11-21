#ifndef _NGX_HTTP_JS_MACROSES_INCLUDED_
#define _NGX_HTTP_JS_MACROSES_INCLUDED_


#define LOG(mess, args...) { fprintf(stderr, mess, ##args); fprintf(stderr, " at %s:%d\n", __FILE__, __LINE__); }
// #define LOG(mess, args...)

// #define LOG2(mess, args...) { fprintf(stderr, mess, ##args); fprintf(stderr, " at %s:%d\n", __FILE__, __LINE__); }
#define LOG2(mess, args...)

// #define TRACE() { fprintf(stderr, "%s() at %s:%d\n", __FUNCTION__, __FILE__, __LINE__); }
// #define TRACE() { fprintf(stderr, "%s()\n", __FUNCTION__); }
#define TRACE()

#define TRACE_REQUEST(func) \
ngx_log_debug2(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "%s(cx=%p, r=%p)", func, r);

// #define TRACE_REQUEST_METHOD()
// ngx_log_debug5(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "Request#%s(cx=%p, r=%p, argc=%d, argv=%p)", __FUNCTION__ + 7, cx, r, argc, argv);

#define TRACE_REQUEST_METHOD() \
ngx_log_debug5(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "Request#%s(r=%p, argc=%d)", __FUNCTION__ + 7, r, argc);

#define GET_PRIVATE(private) \
assert(cx); \
assert(this); \
if ( (private = JS_GetInstancePrivate(cx, this, private_class, NULL)) == NULL ) \
{ \
	JS_ReportError(cx, "wrapper object has NULL private pointer in %s\n%s: %u", __FUNCTION__, __FILE__, __LINE__); \
	return JS_FALSE; \
}

// Just like the throw keyword :)
#define THROW(mess, args...) { JS_ReportError(cx, mess, ##args); return JS_FALSE; }

// Enshure wrapper
// #define E(expr, mess, args...) if (!(expr)) { LOG(#expr); THROW(mess, ##args); return JS_FALSE; }
#define E(expr, mess, args...) if (!(expr)) { THROW(mess, ##args); return JS_FALSE; }



#define NCASE_COMPARE(ngxstring, cstring) ((ngxstring).len == sizeof(cstring) - 1 \
	&& ngx_strncasecmp((ngxstring).data, (u_char *)(cstring), sizeof(cstring) - 1) == 0)

#define CASE_COMPARE(ngxstring, cstring) ((ngxstring).len == sizeof(cstring) - 1 \
	&& ngx_strcasecmp((ngxstring).data, (u_char *)(cstring), sizeof(cstring) - 1) == 0)


#define ngx_assert(expr, mess, args...) \
if (!(expr)) \
{ \
	ngx_log_error(NGX_LOG_EMERG, ngx_cycle->log, 0, mess, ##args); \
	ngx_debug_point(); \
}

#endif