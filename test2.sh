#!/bin/bash
echo -e "\033[32;1m"NORM"\033[m"
read $a
norminette ./*.c ./*.h

echo -e "\033[32;1m"WAR MACHINE v2019"\033[m"
read $a
git clone https://github.com/C4r4c0l3/gnl-war-machine-v2019.git
cd gnl-war-machine-v2019/
sed -i "" 's/..\/..\/get_next_line/..\//' my_config.sh
./grademe.sh
cd ..

echo -e "\033[32;1m"42CURSUS GNL TESTS"\033[m"
read $a
git clone https://github.com/mrjvs/42cursus_gnl_tests.git
cd 42cursus_gnl_tests/
sed -i "" 's/..\/get_next_line/..\//' Makefile
./make
cd ..

echo -e "\033[32;1m"GNLKILLER"\033[m"
read $a
git clone https://github.com/DontBreakAlex/gnlkiller.git
cp get_next_line.c gnlkiller/
cp get_next_line.h gnlkiller/
cp get_next_line_bonus.c gnlkiller/
cd gnlkiller/
./run.sh
cd ..

echo -e "\033[32;1m"42TESTERS-GNL"\033[m"
read $a
git clone https://github.com/Mazoise/42TESTERS-GNL.git
cd 42TESTERS-GNL/
./all_tests_with_bonus.sh
cd ..

echo -e "\033[32;1m"GNLTESTER"\033[m"
read $a
git clone https://github.com/Tripouille/gnlTester.git
cd gnlTester/
./make a
cd ..

rm -rf gnlTester/ 42TESTERS-GNL/ gnlkiller/ 42cursus_gnl_tests/ gnl-war-machine-v2019/ GNL-lover
