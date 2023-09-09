//Modify this file to change what commands output to your statusbar, and recompile using the make command.  
static const Block blocks[] = { 
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",		"echo '[  '$(xdotool getactivewindow getwindowname)'  ]'",	2,		0},
	{";",		"",							0,		0},
	{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
	//{"| CPU:", "echo $((100 - $(mpstat | tail -1 | rev | cut -c 1-5 | rev ))) ",			1,		0},
	{"| Vol:", "amixer sget Master | grep 'Mono:' | awk -F'[][]' '{ print $2 }' ",			0,		30},
	{"| Bat:", "cat /sys/class/power_supply/BAT0/capacity",			120,		0},
	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
};
// | grep -Eo '^[0-9L]*.[0-9]{2}'

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
