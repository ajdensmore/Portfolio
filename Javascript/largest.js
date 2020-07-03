class DisjointSet { // union-find
    constructor(val, size=1) {
        this.val = val;
        this.size = size;
        this.parent = this;
    }
    find() {
        return this.parent === this ? this : this.parent = this.parent.find();
    }
    union(b) {
        let a = this.find();
        b = b.find();
        if (a === b) return a; // In same set
        if (a.size < b.size) { // Keep depth of set-tree small
            b.size += a.size;
            return a.parent = b;
        }
        a.size += b.size;
        return b.parent = a;
    }
}

var largestComponentSize = function(a) {
    // Collect all primes whose square is not greater than 100000,
    // and create empty sets for each of them, unionfind-enabled.
    const primes = [
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
        101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
        199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313
    ].map(prime => new DisjointSet(prime, 0));
    let largePrimes = new Map;

    for (let i = 0; i < a.length; i++) {
        let input = new DisjointSet(a[i]);
        let val = input.val;
        for (let p = 0; p < primes.length; p++) {
            let prime = primes[p];
            let primeVal = prime.val;
            if (primeVal > val) break; // Crucial for speed!
            if (val % primeVal === 0) { // Prime is a divisor of the input
                prime.union(input); // Put input in the same set as the prime
                do {
                    val /= primeVal;
                } while (val % primeVal === 0);
            }
        }
        // Deal with primes larger than in the predefined list.
        // Those greater than 50000 can never be a factor of another value in the input, 
        // so they would stay lonely in their own set. We can ignore those.
        if (val > 1 && val <= 50000) {
            let prime = largePrimes.get(val);
            if (prime) { // Put in same set as other numbers that have this prime factor
                prime.union(input);
            } else { // Create a new singleton set for this prime
                largePrimes.set(val, input);
            }
        }
    }

    // Identify the size of the largest set
    let maxSize = 1; // Since input array is guaranteed to be non-empty, this is the minimum
    const maximise = (prime) => maxSize = Math.max(maxSize, prime.find().size);
    primes.forEach(maximise);
    largePrimes.forEach(maximise);

    return maxSize;
};