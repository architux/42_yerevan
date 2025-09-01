#!/usr/bin/python
import subprocess
from itertools import permutations

Ws = ["-Wall", "-Wextra", "-Werror"]

out_checksums = {}

for p in permutations(Ws):
	print(f"* {', '.join(p)}")

	try:
		out_filename = f"{'_'.join(p).replace('-', '')}.out"
		command = f"cc {' '.join(p)} *.c -o '{out_filename}'"
		result = subprocess.run(command, shell=True, capture_output=True, text=True, check=True)

	except subprocess.CalledProcessError as e:
		print(f"  Command failed: {e}")
		print(f"  stderr: {e.stderr}")
	except FileNotFoundError:
		print("  Command not found. Make sure it's in PATH.")

	try:
		command = f"md5sum '{out_filename}'"
		checksum = subprocess.run(command, shell=True, capture_output=True, text=True, check=True).stdout.split()[0]

		if checksum in out_checksums.keys():
			out_checksums[checksum] += 1
		else:
			out_checksums[checksum] = 1

	except subprocess.CalledProcessError as e:
		print(f"  Command failed: {e}")
		print(f"  stderr: {e.stderr}")
	except FileNotFoundError:
		print("  Command not found. Make sure it's in PATH.")

print()

if len(out_checksums.keys()) == 1:
	print("All output files are exactly the same.")
else:
	print(f"All output files are different: {out_checksums}")

print()

for checksum in out_checksums.keys():
	print(f"checksum: {checksum}, count: {out_checksums[checksum]}")
