/*in case u need to save values greater than 2e18 use int128. 
it stores to 2^128 - 1
*/


__int128 read() {//used to read or cin int128 variable ex __int 128 a; a=read();
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x) {//used to print cout the int128 variable ex print(a)
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}//use endl not '\n' to end the line to avoid problems

bool cmp(__int128 x, __int128 y) { return x > y; }//used to compare if first num greater than the second num
