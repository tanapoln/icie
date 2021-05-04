/// Name: gcd
/// Description: GCD
/// Guarantee: int gcd(int a, int b) {
int gcd(int a, int b) {
    int r = a % b;
    if (r == 0) return b;
    return gcd(b, r);
}
