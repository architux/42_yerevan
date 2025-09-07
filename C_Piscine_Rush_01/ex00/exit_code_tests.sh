#!/bin/sh
RED_COLOR="\033[31m"
BRIGHT_RED_COLOR="\033[1;31m"
YELLOW_COLOR="\033[33m"
GREEN_COLOR="\033[32m"
BRIGHT_GREEN_COLOR="\033[1;32m"
RESET_COLOR="\033[0m"

command='./rush01 ; printf "output exit code: $?"'
printf "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__NO_CLUES_STRING${RESET_COLOR}\n"
printf "clues: -\n"
printf "implemented exit code: 1\n"
printf "${YELLOW_COLOR}command: ${command%% ; *}${RESET_COLOR}\n"
printf "$(eval $command)\n\n"

command='./rush01 " " ; printf "output exit code: $?"'
printf "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__NO_CLUES_TO_PARSE${RESET_COLOR}\n"
printf "clues: 0\n"
printf "implemented exit code: 2\n"
printf "${YELLOW_COLOR}command: ${command%% ; *}${RESET_COLOR}\n"
printf "$(eval $command)\n\n"

command='./rush01 "1 2 3 4 3" ; printf "output exit code: $?"'
printf "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__INVALID_CLUES_COUNT${RESET_COLOR}\n"
printf "clues: 5\n"
printf "implemented exit code: 3\n"
printf "${YELLOW_COLOR}command: ${command%% ; *}${RESET_COLOR}\n"
printf "$(eval $command)\n\n"

command='./rush01 "4 3 2 1 1 2 2 2 4 3 2 1" ; printf "output exit code: $?"'
printf "clues: 12\n"
printf "implemented exit code: 3\n"
printf "${YELLOW_COLOR}command: ${command%% ; *}${RESET_COLOR}\n"
printf "$(eval $command)\n\n"

command='./rush01 "4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3 4 3 2 1 1 2 2 2 4 3" ; printf "output exit code: $?"'
printf "clues: 40\n"
printf "implemented exit code: 3\n"
printf "${YELLOW_COLOR}command: ${command%% ; *}${RESET_COLOR}\n"
printf "$(eval $command)\n\n"

command='./rush01 "1 2 2 2 4 3 2 1 4 3 2 1 1 2 2 2" ; printf "output exit code: $?"'
printf "${BRIGHT_RED_COLOR}EXIT_CODE__ERROR__NO_SOLUTION_FOUND${RESET_COLOR}\n"
printf "clues: 16\n"
printf "implemented exit code: 4\n"
printf "${YELLOW_COLOR}command: ${command%% ; *}${RESET_COLOR}\n"
printf "$(eval $command)\n\n"

command='./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" ; printf "output exit code: $?"'
printf "${BRIGHT_GREEN_COLOR}EXIT_CODE__SUCCESS${RESET_COLOR}\n"
printf "clues: 16\n"
printf "implemented exit code: 0\n"
printf "${YELLOW_COLOR}command: ${command%% ; *}${RESET_COLOR}\n"
printf "$(eval $command)\n\n"
