bool is_perfect_square(ll x)//check if the number x is a perfect square or not.
{
    ll y = (ll)sqrtl(x);
    while(y * y < x) y++;
    while(y * y > x) y--;
    return x == y * y;
}
