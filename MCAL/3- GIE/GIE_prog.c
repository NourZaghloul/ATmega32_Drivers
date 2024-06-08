#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_reg.h"
#include "GIE_interface.h"


void GIE_voidEnableGlobal(void)
{
	__asm volatile ("SEI");			/*INLINE ASSEMBLY: Set I-Bit*/
}

void GIE_voidDisableGlobal(void)
{
	__asm volatile ("CLI");			/*INLINE ASSEMBLY: Clear I-Bit*/
}
