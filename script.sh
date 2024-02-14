#! /bin/bash

t0=$(date +%s)
match=0

make 1> /dev/null 
./anag $1

echo "------------------------"

cat tmp.txt | sort | uniq > ${1}_anagrams.txt

while  read line ; do
	echo -n "$line : "
	grep ^$line$ data/french_dico_utf8.txt > /dev/null && echo -e "\033[1;32m$line\033[m" && match=$((match+1)) || echo "no match"
done < ${1}_anagrams.txt

make fclean 1> /dev/null && rm tmp.txt

echo "------------------------"
t1=$(date +%s)
echo time elapsed : $(($t1 - $t0))
echo "matches : $match"