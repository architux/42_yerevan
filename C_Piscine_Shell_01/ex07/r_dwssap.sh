#!/bin/sh
cat /etc/passwd | \
grep -Ev "^#|^$" | \
sed -n 'n;p' | \
cut -d: -f1 | \
rev | \
sort -r | \
sed -n "${FT_LINE1},${FT_LINE2}p" | \
paste -s -d, | \
sed 's/,/, /g;s/$/./'
