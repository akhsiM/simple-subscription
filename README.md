# Background

I wrote this simple C module for the third assignment that I had to complete for my CS50 online course. This was my first time getting hands-on with writing a substitution cipher so I found this very interesting.

I may need to refer back to this in the future. This is why I have decided to upload it to my Git.

# Specification

The program can be compiled with `gcc`. We need `-lcs50` at the end to include the CS50 training wheel library.
```bash
$ gcc substitution.c -o substitution -lcs50
```

The program accepts a single command-line argument which is the key to use for the substitution. It can be used like this:
```bash
$ ./substitution vchprzgjntlskfbdqwaxeuymoi
plaintext: Hello
ciphertext: Jrssb
```

Some rules:
1. There has to be one command-line, which is to be used as the key for the substitution. The key is case-insensitive.
2. Key has to contain non-repeating 26 alphabetic characters.

