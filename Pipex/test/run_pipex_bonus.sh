#!/bin/bash

clear
cd ..
make bonus
echo "FIN MAKE BONUS"
cd test

while true
do
	clear
	echo "============  FILE_IN  ==============="
	cat file_in_1
	echo "============  RUN CMD  ==============="
	echo "../pipex file_in_1 \"cat\" \"tr 'a-zA-Z0-9' 'd-za-cD-ZA-C!%*\#&§?:+'\" file_out_1"
	echo "======================================"
	../pipex file_in_1 "cat" "tr 'a-zA-Z0-9' 'd-za-cD-ZA-C!%*\#&§?:+'" file_out_1
	echo "============  FILE_OUT  ============="
	cat file_out_1
	echo "======================================"
	echo "FIN DU CRYPT"
	echo "======================================"
	rm file_out_1
	echo "============  FILE_IN  ==============="
	cat file_in_2
	echo "============  RUN CMD  ==============="
	echo "../pipex file_in_2 \"cat\" \"tr 'd-za-cD-ZA-C!%*\#&§?:+' 'a-zA-Z0-9'\" file_out_2"
	echo "======================================"
	../pipex file_in_2 "cat" "tr 'd-za-cD-ZA-C!%*\#&§?:+' 'a-zA-Z0-9'" file_out_2
	echo "============  FILE_OUT  ============="
	cat file_out_2
	echo "======================================"
	echo "FIN DU DECRYPT"
	echo "======================================"
	rm file_out_2
	echo "============  HERE_DOC  ==============="
	echo "../pipex here_doc \"toto\" \"cat\" \"tr a i\" file_out"
	echo "======================================"
	../pipex here_doc "toto" "cat" "tr a i" file_out <<-toto
	je suis le here_doc
	je suis le here_doc
	je suis le here_doc
	je suis le here_doc
	TOTO
	non c esst toto
	toto
	echo "============  FILE_OUT  ============="
	cat file_out
	echo "======================================"
	echo "FIN DU TEST HERE_DOC"
	echo "======================================"
	rm file_out
	echo "============  HERE_DOC 2 ============="
	echo "=========  FILE_HERE_DOC  ============"
	cat here_doc
	echo "============  RUN CMD  ==============="
	echo "../pipex here_doc \"toto\" \"cat\" \"tr a i\" file_out < here_doc"
	echo "======================================"
	../pipex here_doc "toto" "cat" "tr a i" file_out < here_doc
	echo "============  FILE_OUT  ============="
	cat file_out
	echo "======================================"
	echo "FIN DU TEST HERE_DOC"
	echo "======================================"
	rm file_out
	sleep 5
done
