#! /bin/bash

ESC='\e['

RED=31
GREEN=32
YELLOW=33
BLUE=34

RESULT=0

PRINT_COLOR() {
	if [ $1 -eq $RED ] ; then
		printf "${ESC}${RED}m %s ... %s ${ESC}m\n" $2 $3
	elif [ $1 -eq $GREEN ] ; then
		printf "${ESC}${GREEN}m %s ... %s ${ESC}m\n" $2 $3
	elif [ $1 -eq $BLUE ] ; then
		printf "${ESC}${BLUE}m %s ... %s ${ESC}m\n" $2 $3
	elif [ $1 -eq $YELLOW ] ; then
		printf "${ESC}${YELLOW}m %s ... %s ${ESC}m\n" $2 $3
	else
		printf "%s ... %s\n" $2 $3
	fi
}

_RESULT() { 
	echo ; echo "[$1]" ; echo
	for json_file in $2
	do
		./miniRT ${json_file} && echo 
		if [ $? -eq $3 ] ; then
			PRINT_COLOR $GREEN $json_file OK
		else
			PRINT_COLOR $RED $json_file KO
			RESULT=1
		fi
	done
}

_ONLY_KO() { 
	echo ; echo "[$1]" ; echo
	for json_file in $2
	do
		./miniRT ${json_file} > /dev/null 2>&1
		if [ $? -ne $3 ] ; then
			PRINT_COLOR $RED $json_file KO
			RESULT=1
		fi
	done
}

EXEC() {
	$1 SUCCESS './test/rt_to_json/success/*.rt' 0
	$1 FAILED './test/rt_to_json/error/*.rt' 1
}

# EXEC _RESULT
EXEC _ONLY_KO
exit $RESULT
