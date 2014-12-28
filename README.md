## Introduction ##
אינקלוד זה יאפשר לכם לחסום את האנטי צ'יט כסף

## Credits ##
* [Y_Less](http://forum.sa-mp.com/showthread.php?t=441293) - Hook Method 7
* [_Application_](http://www.fxp.co.il/member.php?u=782565) - Include developer

## Callback - Form of use##

public OnPlayerFakeMoney(playerid, oldmoney, newmoney)
{
	new string[128];
 	format(string, sizeof(string), "the player [ID: %d]%s faked money [%d] times.",playerid, pName[playerid], GetPlayerWarnings(playerid));
  	SendClientMessageToAdmin(0xFF0000FF, string);
	return 1;
}
