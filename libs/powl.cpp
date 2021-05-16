/// Name: powl
/// Description: power of long long
/// Guarantee: ll powl(ll base, int p) {

long long powl(long long base, int p) {
    if (p == 0) return 1;
    
    long long res = base;
    for(int i = 2; i <= p; i++) {
        res *= base;
    }
    return res;
}