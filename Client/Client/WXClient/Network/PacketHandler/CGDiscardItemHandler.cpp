#include "StdAfx.h"
#include "CGDiscardItem.h"

UINT CGDiscardItemHandler::Execute(CGDiscardItem* pPacket, Player* pPlayer )
{
	__ENTER_FUNCTION

		return PACKET_EXE_CONTINUE;

	__LEAVE_FUNCTION

		return PACKET_EXE_ERROR;
}