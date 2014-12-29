/*
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
#include "foreach.inc"

#if defined _inc_acm
    #endinput
#endif
#define _inc_acm

#define CALLBACK:%1(%2) \
	forward %1(%2); \
		public %1(%2)

#define GetPlayerWarnings(%0) \
	fakemoneyWarnings[%0]

#define MAX_WARNINGS    (3)

forward OnPlayerFakeMoney(playerid, oldmoney, newmoney);

new
    fakemoneyWarnings[MAX_PLAYERS],
    exCash[MAX_PLAYERS];

public OnPlayerConnect(playerid)
{
    SetPVarInt(playerid, "acm_cash", 0);
    #if defined _ACM_OnPlayerConnect
        _ACM_OnPlayerConnect(playerid);
    #endif
    return 1;
}
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect _ACM_OnPlayerConnect
#if defined _ACM_OnPlayerConnect
    forward _ACM_OnPlayerConnect(playerid);
#endif

public OnGameModeInit()
{
	SetTimer("IFFakeMoney", 100, true);
    #if defined _ACM_OnGameModeInit
        _ACM_OnGameModeInit(playerid);
    #endif
    return 1;
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnPlayerUpdate _ACM_OnGameModeInit
#if defined _ACM_OnGameModeInit
    forward _ACM_OnGameModeInit(playerid);
#endif

CALLBACK:IFFakeMoney(playerid)
{
	foreach(new i: Player)
	{
	    new _get_cash = GetPlayerMoney(i);
	    if(_get_cash != _ACM_GetPlayerMoney(i))
	    {
	        fakemoneyWarnings[playerid]++;
	       	CallLocalFunction("OnPlayerFakeMoney", "iii", i, _ACM_GetPlayerMoney(i), GetPlayerMoney(i));
	        ResetPlayerMoney(i);
	        GivePlayerMoney(i, _ACM_GetPlayerMoney(i));
	    }
	}
    return 1;
}

stock _ACM_GivePlayerMoney(playerid, money)
{
    exCash[playerid] = GetPVarInt(playerid, "acm_cash");
    SetPVarInt(playerid, "acm_cash", exCash[playerid]+=money);
    return GivePlayerMoney(playerid, money);
}

#if defined _ALS_GivePlayerMoney
    #undef GivePlayerMoney
#else
    #define _ALS_GivePlayerMoney
#endif

#define GivePlayerMoney _ACM_GivePlayerMoney

stock _ACM_ResetPlayerMoney(playerid)
{
    SetPVarInt(playerid, "acm_cash", 0);
    return ResetPlayerMoney(playerid);
}

#if defined _ALS_ResetPlayerMoney
    #undef ResetPlayerMoney
#else
    #define _ALS_ResetPlayerMoney
#endif

#define ResetPlayerMoney _ACM_ResetPlayerMoney

stock _ACM_GetPlayerMoney(playerid) return GetPVarInt(playerid, "acm_cash");

#if defined _ALS_GetPlayerMoney
    #undef GetPlayerMoney
#else
    #define _ALS_GetPlayerMoney
#endif

#define GetPlayerMoney _ACM_GetPlayerMoney
