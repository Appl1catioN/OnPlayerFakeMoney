## Introduction ##
מכיוון שרובכם (רוב המתכנתים) יוצרים את האנטי צ'יט שלכם עם שימוש בפונקציות חדשות, מה שאומר
שכל מתכנת אשר מוריד את האנטי צ'יט שלכם צריך גם לערוך את הפונקציות המקוריות בפונקציות החדשות שהגדרתם,
מעובדה זו החלטתי ליצור אחת נורמאלית ולפרסם לכם אותה כאן, לא תצטרכו להשתמש מעכשיו בפונקציות חדשות,
אלה בפונקציות המקוריות של הסאמפ!, כמו כן יצרתי אירוע חדש אשר מתקיים כל פעם שזוהה שחקן שהשתמש עם אנטי צ'יט כסף,
בנוסף גם פונקציה שמקבלת את מספר הפעמים ששחקן השתמש באנטי צ'יט, אז קדימה חברים למה אתם מחכים?

## Credits ##
* [Y_Less](http://forum.sa-mp.com/showthread.php?t=441293) - Hook Method 7
* [_Application_](http://www.fxp.co.il/member.php?u=782565) - Include developer

## Callback ##
	
	public OnPlayerFakeMoney(playerid, oldmoney, newmoney)
	{
		new string[128];
		format(string, sizeof(string), "the player [ID: %d]%s faked money [%d] times.",playerid, pName[playerid], GetPlayerWarnings(playerid));
		SendClientMessageToAdmin(0xFF0000FF, string);
		return 1;
	}

## Function ##
GetPlayerWarnings(playerid) - קבלת מספר האזהרות כנ"ל

## Changelog ##
[28-12-2014 | v1.0] - נכון לעכשיו גרסת הבטא!
