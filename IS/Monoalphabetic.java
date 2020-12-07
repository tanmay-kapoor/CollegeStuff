import java.util.*;

class Monoalphabetic {
    String operation(String text, String s1, String s2) {
        String ans = "";
        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);
            int index = s1.indexOf(Character.toLowerCase(ch));
            if (index != -1) {
                char letter = s2.charAt(index);
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
        Monoalphabetic ob = new Monoalphabetic();
        String text, alphabet = "abcdefghijklmnopqrstuvwxyz", changed = "thxlogcsaydrwqfevzukinbpmj";
        int ch;

        do {
            System.out.print("1. Encrypt\n2. Decrypt\nEnter choice : ");
            ch = sc.nextInt();
            sc.nextLine();

            switch (ch) {
                case 1:
                    System.out.print("\nText : ");
                    text = sc.nextLine();
                    System.out.println("Encrypted text : " + ob.operation(text, alphabet, changed));
                    break;

                case 2:
                    System.out.print("\nEncrypted text : ");
                    text = sc.nextLine();
                    System.out.println("Decrypted text : " + ob.operation(text, changed, alphabet));
                    break;
            }
        } while (ch < 1 || ch > 2);
    }
}
