## Introduction ##
אינקלוד זה יאפשר לכם לחסום את האנטי צ'יט כסף

## Credits ##
* [Y_Less](http://forum.sa-mp.com/showthread.php?t=441293) - Hook Method 7
* [_Application_](http://www.fxp.co.il/member.php?u=782565) - Include developer

## Callback - Form of use##
	
/*
                                    Test Script
	                             <-------------->
	                             
							    OnPlayerFakeMoney
						     Creation: _Application_
							    Date: 27/12/2014
						    	   Version: 1.0
						    	   
									Callback:
				native OnPlayerFakeMoney(playerid, oldmoney, newmoney);
				
				                    Function:
    					     GetPlayerWarnings(playerid)
				
*/
#include "a_samp.inc"
#include "OnPlayerFakeMoney.inc"

new pName[MAX_PLAYERS][MAX_PLAYER_NAME+1];

public OnPlayerConnect(playerid)
{
	GetPlayerName(playerid, pName[playerid], MAX_PLAYER_NAME);
	return GivePlayerMoney(playerid, 250000), 1;
}

public OnPlayerFakeMoney(playerid, oldmoney, newmoney)
{
	new string[128];
	if(GetPlayerWarnings(playerid) >= MAX_WARNINGS)
	{
	    format(string, sizeof(string), "the player [ID: %d]%s faked money [%d] times.",playerid, pName[playerid], GetPlayerWarnings(playerid));
	    SendClientMessageToAdmin(0xFF0000FF, string);
	}
	format(string, sizeof(string), "[ID: %d]%s | Orginal Money: $%d | All Money: $%d | Fake Money: $%d.", playerid, pName[playerid], oldmoney, newmoney, (newmoney - oldmoney));
	return SendClientMessageToAdmin(0xFF0000FF, string);
}

stock SendClientMessageToAdmin(color, const message[])
{
	for(new i; i < MAX_PLAYERS; i++) if(IsPlayerConnected(i) && IsPlayerAdmin(i))
	{
		SendClientMessage(i, color, message);
	}
	return 1;
}
