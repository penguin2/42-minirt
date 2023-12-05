#! /bin/bash

RESULT=0

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
	echo ; echo "[$1]" ; echo
	for json_file in $2
	do
		$4 ${json_file} && echo 
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
		$4 ${json_file} > /dev/null 2>&1
		if [ $? -ne $3 ] ; then
			PRINT_COLOR $RED $json_file KO
			RESULT=1
		fi
	done
}

EXEC_JSON() {
	$1 SUCCESS './test/json_to_json_object/success/*' 0 "./miniRT"
	$1 FAILED './test/json_to_json_object/error/*' 1 "./miniRT"
}

EXEC_SCENE() {
	$1 SUCCESS './test/json_object_to_scene/success/*' 0 "./miniRT"
	$1 FAILED './test/json_object_to_scene/error/*/*' 1 "./miniRT"
}

EXEC_RT() {
	$1 SUCCESS './test/rt_to_json/success/*/*' 0 "./miniRT"
	rm ./test/rt_to_json/success/*/*.json
	$1 FAILED './test/rt_to_json/error/*/*' 1 "./miniRT"
	rm ./test/rt_to_json/error/*/*.json
}

EXEC_RT_BONUS() {
	$1 SUCCESS './test/rt_to_json/success_bonus/*/*' 0 "./miniRT_bonus"
	$1 SUCCESS_JSON './test/rt_to_json/success_bonus/*/*.json' 0 "./miniRT_bonus"
	rm ./test/rt_to_json/success_bonus/*/*.json
	$1 FAILED './test/rt_to_json/error_bonus/*/*' 1 "./miniRT_bonus"
	$1 FAILED_JSON './test/rt_to_json/error_bonus/*/*.json' 1 "./miniRT_bonus"
	rm ./test/rt_to_json/error_bonus/*/*.json
}

if [ $# != 2 ] ; then
	echo "please two command line argument"
	exit 1
elif [ $1 == 'KO' ] ; then
	FUNC=_ONLY_KO
elif [ $1 == 'OK' ] ; then
	FUNC=_RESULT
else
	echo "please enter argument1 [OK, KO]"
	exit 1
fi

if [ $2 == 'json' ] ; then
	EXEC_JSON $FUNC
elif [ $2 == 'scene' ] ; then
	EXEC_SCENE $FUNC
elif [ $2 == 'rt' ] ; then
	EXEC_RT $FUNC
elif [ $2 == 'rt_bonus' ] ; then
	EXEC_RT_BONUS $FUNC
elif [ $2 == 'scene_to_json' ] ; then
	EXEC_RT $FUNC
elif [ $2 == 'scene_to_json_bonus' ] ; then
	EXEC_RT_BONUS $FUNC
else
	echo "please enter argument2 [json, scene, rt]"
	exit 1
fi
exit $RESULT

