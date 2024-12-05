find ./lib -name "*.*" -exec iconv --verbose -f utf-8 -t windows-1251 -o {} {} \;
find . -name "main.*" -exec iconv --verbose -f utf-8 -t windows-1251 -o {} {} \;
