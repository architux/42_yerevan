#!/bin/sh
OUTPUT_BASE="gtaio luSnemf"

FT_NBR1_DECIMAL="$(
	printf '%s' "${FT_NBR1}" |
	tr "'\\\\\"?!" "01234" |
	xargs -I{} printf '%s\n' 'obase=10; ibase=5; {}' |
	bc
)"

FT_NBR2_DECIMAL="$(
	printf '%s' "${FT_NBR2}" |
	tr "mrdoc" "01234" |
	xargs -I{} printf '%s\n' 'obase=10; ibase=5; {}' |
	bc
)"

OUTPUT_BASE13="$(
	printf '%s' "${FT_NBR1_DECIMAL} + ${FT_NBR2_DECIMAL}" |
	xargs -I{} printf '%s\n' "ibase=10; obase=13; {}" |
	bc
)"

unset OUTPUT
for i in $(seq "$(printf '%s' "${OUTPUT_BASE13}" | wc -c)"); do
	OUTPUT_BASE_INDEX="$(
		printf '%s' "${OUTPUT_BASE13}" |
		cut -c "${i}" |
		xargs -I{} printf '%s\n' "obase=10; ibase=13; {}" |
		bc
	)"
	CHAR="$(printf '%s' "${OUTPUT_BASE}" | cut -c "$((OUTPUT_BASE_INDEX + 1))")"
	OUTPUT="${OUTPUT}${CHAR}"
done

printf '%s\n' "${OUTPUT}"
