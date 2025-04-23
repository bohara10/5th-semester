def find_primitive_roots(modulus):
    candidates = list(range(1, modulus))
    primitive_roots = []
    for candidate in candidates:
        generated = []
        for exponent in range(modulus):
            generated.append(pow(candidate, exponent, modulus))
        unique_generated = sorted(list(set(generated)))
        if unique_generated == candidates:
            primitive_roots.append(candidate)
    return primitive_roots
 
def run():
    try:
        n = int(input("Input a prime number to find its primitive roots: "))
        if n < 2:
            print("Error: Please input a prime number greater than 1.")
            return
        results = find_primitive_roots(n)
        if results:
            print(f"The primitive roots of {n} are: {results}")
        else:
            print(f"No primitive roots found for {n}.")
    except ValueError:
        print("Error: Please input a valid integer.")

if __name__ == "__main__":
    run()