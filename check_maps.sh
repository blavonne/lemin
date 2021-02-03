#!/bin/bash
#colors-------------------------------------------------------------------------
green=\\e[1\;32m
end_c=\\e[0m

for ((i=1; i<16; i++)); do
	echo -e "${green}Map i$i:${end_c}"
	./lem-in ./maps/i$i
done

#for ((v=1; v<4; v++)); do
#	echo -e "${green}Map v$v:${end_c}"
#	./lem-in ./maps/v$v
#done