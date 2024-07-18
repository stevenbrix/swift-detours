#include <windows.h>
#include <stdbool.h>

#if defined(__cplusplus)
extern "C"
{
#endif

typedef void (WINAPI *RaiseFailFastExceptionCallback)(PEXCEPTION_RECORD _Nullable, PCONTEXT _Nullable, DWORD);
extern BOOL DetourRaiseFailFastException(RaiseFailFastExceptionCallback _Nonnull);

#if defined(__cplusplus)
}
#endif