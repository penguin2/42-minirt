#! /bin/bash

cd .. && make

ESC='\e['

RED=31
GREEN=32
YELLOW=33
BLUE=34


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
	echo ; echo "[$1] [$2]" ; echo
	for json_file in $3
	do
		./miniRT ${json_file} $4 && echo 
		if [ $? -eq 0 ] ; then
			PRINT_COLOR $GREEN $json_file OK
		else
			PRINT_COLOR $RED $json_file KO
		fi
	done
}

_ONLY_KO() { 
	echo ; echo "[$1] [$2]" ; echo
	for json_file in $3
	do
		./miniRT ${json_file} $4 > /dev/null 2>&1
		if [ $? -ne 0 ] ; then
			PRINT_COLOR $RED $json_file KO
		fi
	done
}

EXEC() {
	$1 SUCCESS DICT './test_json/success_json/dict/*.json' 0
	$1 SUCCESS LIST './test_json/success_json/list/*.json' 0
	$1 SUCCESS MIXTURE './test_json/success_json/mixture/*.json' 0
	$1 ERROR DICT './test_json/error_json/dict/*.json' 1
	$1 ERROR LIST './test_json/error_json/list/*.json' 1
	$1 ERROR MIXTURE './test_json/error_json/mixture/*.json' 1
}

# EXEC _RESULT
EXEC _ONLY_KO
