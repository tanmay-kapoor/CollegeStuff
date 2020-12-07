import java.util.*;

class RSA {
    boolean isPrime(int num) {
        int i = 2;
        while (i < num) {
            if (num % i == 0) {
                return false;
            }
            i++;
        }
        return true;
    }

    int gcd(int a, int b) {
        int max = a > b ? a : b;
        int min = a < b ? a : b;
        int rem = max % min;

        while (rem != 0) {
            max = min;
            min = rem;
            rem = max % min;
        }
        return min;
    }

    public static void main(String[] args) {
        RSA ob = new RSA();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number to encrypt : ");
        int num = sc.nextInt();
        int p, q;
        boolean notPrime;
        do {
            notPrime = false;
            System.out.print("Enter p and q : ");
            p = sc.nextInt();
            q = sc.nextInt();

            if (!ob.isPrime(p) || !ob.isPrime(q)) {
                System.out.println("p and q must be prime numbers!\n");
                notPrime = true;
            }
        } while (notPrime);

        int n = p * q;
        int phi = (p - 1) * (q - 1);

        int e = 2;
        while (e < phi) {
            if (ob.gcd(e, phi) == 1) {
                break;
            }
            e++;
        }
        double d = (1 / (double) e) % phi;
        double c = Math.pow(num, e);
        double m = Math.pow(c, d);
        c = c % n;
        m = Math.round(m % n);
        System.out.println("\nEncrypted message = " + c);
        System.out.println("Decrypted message = " + m);
    }
}