#!/bin/bash

while true
do
	clear
	echo "============  FILE_IN  ==============="
	cat file_in_1
	echo "============  RUN CMD  ==============="
	echo "file_in_1 \"cat\" \"tr 'a-zA-Z0-9' 'd-za-cD-ZA-C!%*\#&§?:+'\" file_out_1"
	echo "======================================"
	./pipex file_in_1 "cat" "tr 'a-zA-Z0-9' 'd-za-cD-ZA-C!%*\#&§?:+'" file_out_1
	echo "============  FILE_OUT  ============="
	cat file_out_1
	echo "======================================"
	echo "FIN DU CRYPT"
	echo "======================================"
	rm file_out_1
	echo "============  FILE_IN  ==============="
	cat file_in_2
	echo "============  RUN CMD  ==============="
	echo "./pipex file_in_2 \"cat\" \"tr 'd-za-cD-ZA-C!%*\#&§?:+' 'a-zA-Z0-9'\" file_out_2"
	echo "======================================"
	./pipex file_in_2 "cat" "tr 'd-za-cD-ZA-C!%*\#&§?:+' 'a-zA-Z0-9'" file_out_2
	echo "============  FILE_OUT  ============="
	cat file_out_2
	echo "======================================"
	echo "FIN DU DECRYPT"
	echo "======================================"
	rm file_out_2
	sleep 5
done
