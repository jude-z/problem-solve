int solution(int n)
{
    int res = 0;
    while (n) {
        if (n % 2) {
            n--;
            res++;
        }
        else
            n /= 2;
    }
    return res;
}