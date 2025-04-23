import collections

def prime_factor(n):
    factors = []  # Start with an empty list
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    e = collections.Counter(factors)
    return dict(e)

def etf(m):
    factors = prime_factor(m)
    result = m  # Start with m
    for p in factors:
        result *= (1 - 1/p)  # Multiply by (1 - 1/p) for each distinct prime
    return int(result)  # Convert to integer since φ(m) is always an integer

def main():
    a = 5
    m = 12
    phi_m = etf(m)  # Avoid shadowing the function name
    print("φ(m) =", phi_m)
    if a**phi_m % m == 1:
        print(f"Since {a}^{phi_m} ≡ 1 (mod {m}), {a} and {m} are coprime.")
    else:
        print(f"Since {a}^{phi_m} ≢ 1 (mod {m}), {a} and {m} are not coprime.")

if __name__ == "__main__":
    main()