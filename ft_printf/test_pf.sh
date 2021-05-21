#!/bin/bash
echo -e "\033[32;1m"NORM"\033[m"
read $a
norminette ./*.c ./*.h ./libft/*.c ./libft/*.h

echo -e "\033[32;1m"pft"\033[m"
read $a
git clone https://github.com/gavinfielder/pft.git
cd pft
make re
./test
cd ..

echo -e "\033[32;1m"42TESTERS-PRINTF"\033[m"
read $a
git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
cd 42TESTERS-PRINTF
./runtest.sh
cd ..

echo -e "\033[32;1m"PFT_2019"\033[m"
read $a
git clone https://github.com/gavinfielder/pft.git pft_2019 && echo "pft_2019/" >> .gitignore && cd pft_2019 && rm unit_tests.c && rm options-config.ini && git clone https://github.com/cclaude42/PFT_2019.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp
make re
./test
cd ..

rm -rf pft/ 42TESTERS-PRINTF/ pft_2019/

echo -e "\033[32;1m"PRINTF_TESTER"\033[m"
read $a
git clone https://github.com/Kwevan/FT_PRINTF_TESTER tests451 && cd tests451 && bash run.sh
cd ..
rm -rf tests451/
