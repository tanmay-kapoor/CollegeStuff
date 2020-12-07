import java.util.*;

class CaesarCipher {
    String alphabet = "abcdefghijklmnopqrstuvwxyz";

    String operation(String s, int shift) {
        String ans = "";
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            int index = alphabet.indexOf(Character.toLowerCase(ch));

            if (index != -1) {
                char letter = alphabet.charAt((index + shift) % 26);
                if (Character.isUpperCase(ch)) {
                    ans += Character.toUpperCase(letter);
                } else {
                    ans += letter;
                }
            } else {
                ans += ch;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        CaesarCipher ob = new CaesarCipher();
        int ch, shift;
        String s;

        do {
            System.out.print("1. Encrypt\n2. Decrypt\nEnter choice : ");
            ch = sc.nextInt();
            sc.nextLine();

            switch (ch) {
                case 1:
                    System.out.print("\nText : ");
                    s = sc.nextLine();
                    System.out.print("Shift : ");
                    shift = sc.nextInt();
                    System.out.println("Encrypted text : " + ob.operation(s, shift));
                    break;

                case 2:
                    System.out.print("\nEncrypted text : ");
                    s = sc.nextLine();
                    System.out.print("Shift : ");
                    shift = sc.nextInt();
                    System.out.println("Decrypted text : " + ob.operation(s, 26 - shift));
                    break;

                default:
                    System.out.println("Invalid choice\n");
            }
        } while (ch < 1 || ch > 2);
    }
}
