#!/bin/sh

arg_1="-Wall"
arg_2="-Wextra"
arg_3="-Werror"

declare -A out_checksums

for a1 in "$arg_1" "$arg_2" "$arg_3"; do
	for a2 in "$arg_1" "$arg_2" "$arg_3"; do
		for a3 in "$arg_1" "$arg_2" "$arg_3"; do

			if [[ "$a1" != "$a2" && "$a1" != "$a3" && "$a2" != "$a3" ]]; then
				echo "* $a1, $a2, $a3"

				out_filename="${a1/-}_${a2/-}_${a3/-}.out"

				cc $a1 $a2 $a3 *.c -o "${out_filename}"

				out_checksum=$(md5sum "${out_filename}" | awk '{print $1}')

				if [[ -v out_checksums[${out_checksum}] ]]; then
					((out_checksums[${out_checksum}]++))
				else
					out_checksums[${out_checksum}]=1
				fi
			fi
		done
	done
done

printf "\n"

if [[ ${#out_checksums[@]} -eq 1 ]]; then
	echo "All output files are exactly the same."
else
	echo "All output files are different:"
fi

printf "\n"

for out_checksum in "${!out_checksums[@]}"; do
	echo "checksum: ${out_checksum}, count: ${out_checksums[${out_checksum}]}"
done
