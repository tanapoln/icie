/// Name: prime_sieve
/// Description: Compute prime using seive method
/// Guarantee: void compute_prime() {
const int N = 1e6;
bool PRIME[N+1];

void compute_prime() {
    fill(PRIME, PRIME+(N+1), 1);
    PRIME[0] = 0;
    PRIME[1] = 0;
    for(int i = 2; i <= N; i++) {
        if (!PRIME[i]) continue;
        for (int k = i + i; k <= N; k += i)
            PRIME[k] = 0;
    }
}
