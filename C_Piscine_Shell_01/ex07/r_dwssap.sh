#!/bin/sh
cat /etc/passwd | \
sed '/^#/d' | \
tail -n +2 | \
cut -d: -f1 | \
xargs -I {} sh -c 'echo {} | rev' | \
sort -r | \
sed -n "${FT_LINE1},${FT_LINE2}p" | \
paste -s -d ';' | sed 's/;/, /g' | \
sed 's/$/./'

