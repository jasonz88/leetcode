
int rand2()
{
    return rand() > (RAND_MAX >> 1);
}

int randn(int n)
{
    if (n == 1) return rand2();
    return randn(n - 1) && rand2();
}
