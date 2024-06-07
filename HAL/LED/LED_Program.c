


#include "../../LIB/include/bit_math.h"
#include "../../LIB/include/std_types.h"

#include "../../MCAL/DIO/include/DIO_Interface.h"

#include "include/LED_Cfg.h"
#include "include/LED_Interface.h"
#include "include/LED_Private.h"



void HLED_voidSetLedStatus(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin,LED_STATUS A_LedStatus)
{
	MDIO_voidSetPinStatus(A_DIOPort, A_DIOPin, A_LedStatus);
}

void HLED_voidToggleLedStatus(DIO_PORTS A_DIOPort, DIO_PINS A_DIOPin)
{
	MDIO_voidTogglePinValue(A_DIOPort, A_DIOPin);
}
