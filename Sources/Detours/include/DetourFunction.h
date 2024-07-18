#include <windows.h>
#include <stdbool.h>

#if defined(__cplusplus)
extern "C"
{
#endif
typedef void (*DetourCallback)();

BOOL DetourFunction2(const char* target_module, const char* target_function, DetourCallback detour_func);
BOOL DetourFunction(PVOID* target, PVOID detour_func);
BOOL RestoreFunction(PVOID* target, PVOID detour_func);

#if defined(__cplusplus)
}
#endif
