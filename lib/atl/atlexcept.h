
#ifndef __ATLEXCEPT_H__
#define __ATLEXCEPT_H__


//FIXME: Enable when RaiseException is marked as NORETURN
//DECLSPEC_NORETURN
inline void AtlThrowImp(HRESULT hr)
{
#ifdef ATLTRACE
    ATLTRACE(hr);
#endif

#ifdef _ATL_NO_EXCEPTIONS

    ATLASSERT(false);

    RaiseException(
        hr == E_OUTOFMEMORY ? STATUS_NO_MEMORY : EXCEPTION_ILLEGAL_INSTRUCTION,
        EXCEPTION_NONCONTINUABLE, 0, NULL
        );

#else

    // FIXME: This is horribly wrong, we should implement CException!
    throw;

#endif

}



#ifndef AtlThrow
#define AtlThrow(x) AtlThrowImp(x)
#endif

#endif
