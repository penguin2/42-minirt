#! /bin/bash

cd .. && make


EXEC() { 
	echo ; echo "[$1] [$2]" ; echo
	for json_file in $3
	do
		echo -n "${json_file} ... "
		./miniRT ${json_file}
		# ./miniRT ${json_file} > /dev/null 2>&1
		if [ $? -eq $4 ] ; then
			echo 'OK'
		else
			echo 'KO'
		fi
	done
}

EXEC SUCCESS DICT './test_json/success_json/dict/*.json' 0
EXEC SUCCESS LIST './test_json/success_json/list/*.json' 0
EXEC SUCCESS MIXTURE './test_json/success_json/mixture/*.json' 0
EXEC ERROR DICT './test_json/error_json/dict/*.json' 1
EXEC ERROR LIST './test_json/error_json/list/*.json' 1
EXEC ERROR MIXTURE './test_json/error_json/mixture/*.json' 1
