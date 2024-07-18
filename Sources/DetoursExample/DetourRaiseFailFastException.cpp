#include <DetourRaiseFailFastException.h>
#include "DetourFunction.h"

#include <stdio.h>
#include <strsafe.h>
#include <windows.h>

RaiseFailFastExceptionCallback g_raiseFailFastExceptionCallback = NULL;
RaiseFailFastExceptionCallback TrueRaiseFailFastException = RaiseFailFastException;

void WINAPI DetouredRaiseFailFastException(PEXCEPTION_RECORD record, PCONTEXT context, DWORD flags)
{
  (*g_raiseFailFastExceptionCallback)(record, context, flags);

  TrueRaiseFailFastException(record, context, flags);
}

BOOL DetourRaiseFailFastException(RaiseFailFastExceptionCallback callback)
{
  if (g_raiseFailFastExceptionCallback != NULL) {
    return FALSE;
  }
  g_raiseFailFastExceptionCallback = callback;
  return DetourFunction((PVOID*)&TrueRaiseFailFastException, (PVOID)DetouredRaiseFailFastException);
}
