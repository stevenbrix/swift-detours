#include "DetourFunction.h"
#include "detours.h"

static BOOL detourImpl(PVOID *target, PVOID detour_func, BOOL attach) {
  if (DetourTransactionBegin() != NO_ERROR) {
    return FALSE;
  }

  if (DetourUpdateThread(GetCurrentThread()) != NO_ERROR) {
    goto abort;
  }

  if (attach) {
    if (DetourAttach((PVOID *)target, detour_func) != NO_ERROR) {
      goto abort;
    }
  } else {
    if (DetourDetach((PVOID *)target, detour_func) != NO_ERROR) {
      goto abort;
    }
  }

  if (DetourTransactionCommit() != NO_ERROR) {
    goto abort;
  }

  return TRUE;

abort:
  DetourTransactionAbort();
  return FALSE;
}
BOOL DetourFunction2(const char* target_module, const char* target_function, DetourCallback detour_func) {
  HMODULE module = GetModuleHandleA(target_module);
  if (module == NULL) {
    return FALSE;
  }

  PVOID target = GetProcAddress(module, target_function);
  if (target == NULL) {
    return FALSE;
  }

  return DetourFunction(&target, detour_func);

}
BOOL DetourFunction(PVOID *target, PVOID detour_func) {
  return detourImpl(target, detour_func, TRUE);
}

BOOL RestoreFunction(PVOID *target, PVOID detour_func) {
  return detourImpl(target, detour_func, FALSE);
}
